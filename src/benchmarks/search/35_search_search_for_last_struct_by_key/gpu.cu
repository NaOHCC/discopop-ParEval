// Driver for 52_transform_relu
// 
// struct Book {
//    const char *title;
//    int pages;
// };
// 
// /* Find the index of the last Book item in the vector books where Book.pages is less than 100.
//   Store the result in lastShortBookIndex.
//   Use CUDA to search in parallel. The kernel is launched with one thread for every book element.
//   Example:
//
//   input: [{title=\"Green Eggs and Ham\", pages=72}, {title=\"gulliver's travels\", pages=362}, {title=\"Stories of Your Life\", pages=54}, {title=\"Hamilton\", pages=818}]
//   output: 2
// */
// __global__ void findLastShortBook(const Book *books, size_t N, size_t *lastShortBookIndex) {

#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

#include "utilities.hpp"
#include "generated-code.cuh"   // code generated by LLM
#include "baseline.hpp"

#if defined(USE_CUDA)
#include <thrust/device_vector.h>
#include <thrust/copy.h>
#include <thrust/sort.h>
#include <thrust/iterator/counting_iterator.h>
#include <thrust/iterator/permutation_iterator.h>
#endif


struct Context {
    Book *books;
    size_t *outputIdx;
    size_t N;
    std::vector<Book> cpuBooks;
    std::vector<int> pages;
    dim3 blockSize, gridSize;
};

void reset(Context *ctx) {
    fillRand(ctx->pages, 1, 1000);
    for (int i = 0; i < ctx->N; i += 1) {
        std::string title = "Book " + std::to_string(i);
        ctx->cpuBooks[i].title = title.c_str();
        ctx->cpuBooks[i].pages = ctx->pages[i];
    }

    COPY_H2D(ctx->books, ctx->cpuBooks.data(), ctx->N * sizeof(Book));
}

Context *init() {
    Context *ctx = new Context();

    ctx->N = DRIVER_PROBLEM_SIZE;
    ctx->blockSize = dim3(1024);
    ctx->gridSize = dim3((ctx->N + ctx->blockSize.x - 1) / ctx->blockSize.x); // at least enough threads

    ALLOC(ctx->books, ctx->N * sizeof(Book));
    ALLOC(ctx->outputIdx, 1 * sizeof(size_t));
    ctx->cpuBooks.resize(ctx->N);
    ctx->pages.resize(ctx->N);

    reset(ctx);
    return ctx;
}

void NO_OPTIMIZE compute(Context *ctx) {
    findLastShortBook<<<ctx->gridSize,ctx->blockSize>>>(ctx->books, ctx->N, ctx->outputIdx);
}

void NO_OPTIMIZE best(Context *ctx) {
    size_t idx = correctFindLastShortBook(ctx->cpuBooks);
    (void)idx;
}

bool validate(Context *ctx) {

    const size_t numTries = MAX_VALIDATION_ATTEMPTS;
    for (int i = 0; i < numTries; i += 1) {
        std::vector<int> pages(1024);
        std::vector<Book> input(1024);
        fillRand(pages, 1, 1000);
        for (int j = 0; j < input.size(); j += 1) {
            input[j].title = ("Book " + std::to_string(j)).c_str();
            input[j].pages = pages[j];
        }

        // compute correct result
        size_t correctIdx = correctFindLastShortBook(input);

        // compute test result
        Book *input_d;
        ALLOC(input_d, input.size() * sizeof(Book));
        COPY_H2D(input_d, input.data(), input.size() * sizeof(Book)); // copy to device

        size_t *outputIdx_d;
        size_t tmpOutputIdx = 0;
        ALLOC(outputIdx_d, 1 * sizeof(size_t));
        COPY_H2D(outputIdx_d, &tmpOutputIdx, 1 * sizeof(size_t)); // copy to device

        dim3 blockSize = dim3(1024);
        dim3 gridSize = dim3((input.size() + blockSize.x - 1) / blockSize.x); // at least enough threads
        findLastShortBook<<<gridSize,blockSize>>>(input_d, input.size(), outputIdx_d);
        SYNC();

        size_t testResult;
        COPY_D2H(&testResult, outputIdx_d, 1 * sizeof(size_t));
        
        if (testResult != correctIdx) {
            FREE(input_d);
            FREE(outputIdx_d);
            return false;
        }
        FREE(input_d);
        FREE(outputIdx_d);
    }

    return true;
}

void destroy(Context *ctx) {
    FREE(ctx->books);
    FREE(ctx->outputIdx);
    delete ctx;
}


