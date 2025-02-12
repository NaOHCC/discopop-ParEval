// Driver for 23_histogram_first_letter_counts for CUDA and HIP
// /* For each letter in the alphabet, count the number of strings in the vector s that start with that letter.
//    Assume all strings are in lower case. Store the output in `bins` array.
//    Use CUDA to compute in parallel. The kernel is launched with at least N threads.
//    Example:
// 
//    input: ["dog", "cat", "xray", "cow", "code", "type", "flower"]
//    output: [0, 0, 3, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0]
// */
// __global__ void firstLetterCounts(const char **s, size_t N, size_t bins[26]) {

#include <array>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
#include <vector>

#include "utilities.hpp"
#include "baseline.hpp"
#include "generated-code.cuh"   // code generated by LLM


struct Context {
    char **d_s;
    size_t *d_bins;
    std::vector<char *> tmp_s;
    std::vector<std::string> h_s;
    std::array<size_t, 26> h_bins;
    size_t N;
    dim3 blockSize, gridSize;
};

void reset(Context *ctx) {
    fillRandString(ctx->h_s, 2, 10);
    ctx->h_bins.fill(0);

    for (int i = 0; i < ctx->N; i += 1) {
        FREE(ctx->tmp_s[i]);    // free previous device string
        ALLOC(ctx->tmp_s[i], ctx->h_s[i].size() * sizeof(char));    // create new space
        COPY_H2D(ctx->tmp_s[i], ctx->h_s[i].c_str(), ctx->h_s[i].size() * sizeof(char)); // copy over
    }

    COPY_H2D(ctx->d_s, ctx->tmp_s.data(), ctx->N * sizeof(char *));
    COPY_H2D(ctx->d_bins, ctx->h_bins.data(), 26 * sizeof(size_t));
}

Context *init() {
    Context *ctx = new Context();

    ctx->N = DRIVER_PROBLEM_SIZE;
    ctx->blockSize = dim3(1024);
    ctx->gridSize = dim3((ctx->N + ctx->blockSize.x - 1) / ctx->blockSize.x); // at least enough threads

    ctx->h_s.resize(ctx->N);
    ctx->tmp_s.resize(ctx->N);

    ALLOC(ctx->d_s, ctx->N * sizeof(char *));
    ALLOC(ctx->d_bins, 26 * sizeof(size_t));

    // less than ideal, but since reset is called right away and it frees the
    // memory first, we need to create some here to avoid free-ing unallocated memory
    for (int i = 0; i < ctx->N; i += 1) {
        ALLOC(ctx->tmp_s[i], 10 * sizeof(char));
    }

    reset(ctx);
    return ctx;
}

void NO_OPTIMIZE compute(Context *ctx) {
    firstLetterCounts<<<ctx->gridSize, ctx->blockSize>>>(const_cast<const char **>(ctx->d_s), ctx->N, ctx->d_bins);
}

void NO_OPTIMIZE best(Context *ctx) {
    correctFirstLetterCounts(ctx->h_s, ctx->h_bins);
}

bool validate(Context *ctx) {
    const size_t TEST_SIZE = 1024;
    dim3 blockSize = dim3(1024);
    dim3 gridSize = dim3((TEST_SIZE + blockSize.x - 1) / blockSize.x); // at least enough threads

    std::vector<std::string> h_s(TEST_SIZE);
    std::array<size_t, 26> correct, test;

    std::vector<char *> tmp_s(TEST_SIZE);
    char **d_s;
    size_t *d_bins;

    ALLOC(d_s, TEST_SIZE * sizeof(char *));
    ALLOC(d_bins, 26 * sizeof(size_t));

    const size_t numTries = MAX_VALIDATION_ATTEMPTS;
    for (int i = 0; i < numTries; i += 1) {
        // set up input
        fillRandString(h_s, 2, 3);
        correct.fill(0);
        test.fill(0);

        for (int j = 0; j < TEST_SIZE; j += 1) {
            ALLOC(tmp_s[j], h_s[j].size() * sizeof(char));    // create new space
            COPY_H2D(tmp_s[j], h_s[j].c_str(), h_s[j].size() * sizeof(char)); // copy over
        }
        COPY_H2D(d_s, tmp_s.data(), TEST_SIZE * sizeof(char *));
        COPY_H2D(d_bins, correct.data(), 26 * sizeof(size_t));

        // compute correct result
        correctFirstLetterCounts(h_s, correct);

        // compute test result
        firstLetterCounts<<<gridSize, blockSize>>>(const_cast<const char**>(d_s), TEST_SIZE, d_bins);
        SYNC();

        // copy back
        COPY_D2H(test.data(), d_bins, 26 * sizeof(size_t));
        
        if (!std::equal(correct.begin(), correct.end(), test.begin())) {
            for (int j = 0; j < TEST_SIZE; j += 1) {
                FREE(tmp_s[j]);
            }
            FREE(d_s);
            FREE(d_bins);
            return false;
        }
    }

    for (int j = 0; j < TEST_SIZE; j += 1) {
        FREE(tmp_s[j]);
    }
    FREE(d_s);
    FREE(d_bins);
    return true;
}

void destroy(Context *ctx) {
    for (int i = 0; i < ctx->N; i += 1) {
        FREE(ctx->tmp_s[i]);
    }
    FREE(ctx->d_s);
    FREE(ctx->d_bins);
    delete ctx;
}
