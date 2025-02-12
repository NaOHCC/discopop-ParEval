// Driver for 09_fft_fft_out_of_place for CUDA and HIP
// /* Compute the discrete fourier transform of x. Store the result in output.
//    Use CUDA to compute in parallel. The kernel is launched with at least N threads.
//    Example:
// 
//    input: [1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0]
//    output: [{4,0}, {1,-2.42421}, {0,0}, {1,-0.414214}, {0,0}, {1,0.414214}, {0,0}, {1,2.41421}]
// */
// __global__ void fft(const cuDoubleComplex *x, cuDoubleComplex *output, size_t N) {

#include <algorithm>
#include <numeric>
#include <random>
#include <vector>

#include <cuComplex.h>

#include "utilities.hpp"
#include "baseline.hpp"
#include "generated-code.cuh"   // code generated by LLM


#if defined(USE_CUDA)
#include <thrust/device_vector.h>
#include <thrust/copy.h>
#include <thrust/sort.h>
#include <thrust/iterator/counting_iterator.h>
#include <thrust/iterator/permutation_iterator.h>
#endif

struct Context {
    DOUBLE_COMPLEX_T *d_x, *d_output;
    std::vector<DOUBLE_COMPLEX_T> tmp_x;
    std::vector<std::complex<double>> h_x, h_output;
    std::vector<double> real, imag;
    size_t N;
    dim3 blockSize, gridSize;
};

void reset(Context *ctx) {
    fillRand(ctx->real, -1.0, 1.0);
    fillRand(ctx->imag, -1.0, 1.0);

    for (size_t i = 0; i < ctx->N; i += 1) {
        ctx->h_x[i] = std::complex<double>(ctx->real[i], ctx->imag[i]);
        ctx->tmp_x[i] = MAKE_DOUBLE_COMPLEX(ctx->real[i], ctx->imag[i]);
    }

    COPY_H2D(ctx->d_x, ctx->tmp_x.data(), ctx->N * sizeof(DOUBLE_COMPLEX_T));
}

Context *init() {
    Context *ctx = new Context();

    ctx->N = DRIVER_PROBLEM_SIZE;
    ctx->blockSize = dim3(1024);
    ctx->gridSize = dim3((ctx->N + ctx->blockSize.x - 1) / ctx->blockSize.x); // at least enough threads

    ctx->tmp_x.resize(ctx->N);
    ctx->h_x.resize(ctx->N);
    ctx->h_output.resize(ctx->N);
    ctx->real.resize(ctx->N);
    ctx->imag.resize(ctx->N);

    ALLOC(ctx->d_x, ctx->N * sizeof(DOUBLE_COMPLEX_T));
    ALLOC(ctx->d_output, ctx->N * sizeof(DOUBLE_COMPLEX_T));

    reset(ctx);
    return ctx;
}

void NO_OPTIMIZE compute(Context *ctx) {
    fft<<<ctx->gridSize, ctx->blockSize>>>(ctx->d_x, ctx->d_output, ctx->N);
}

void NO_OPTIMIZE best(Context *ctx) {
    correctFft(ctx->h_x, ctx->h_output);
}

bool validate(Context *ctx) {
    const size_t TEST_SIZE = 1024;
    dim3 blockSize = dim3(1024);
    dim3 gridSize = dim3((TEST_SIZE + blockSize.x - 1) / blockSize.x); // at least enough threads

    std::vector<std::complex<double>> h_x(TEST_SIZE), correct(TEST_SIZE);
    std::vector<double> real(TEST_SIZE), imag(TEST_SIZE);
    std::vector<DOUBLE_COMPLEX_T> test(TEST_SIZE);
    DOUBLE_COMPLEX_T *d_x, *d_output;

    ALLOC(d_x, TEST_SIZE * sizeof(DOUBLE_COMPLEX_T));
    ALLOC(d_output, TEST_SIZE * sizeof(DOUBLE_COMPLEX_T));

    const size_t numTries = MAX_VALIDATION_ATTEMPTS;
    for (int i = 0; i < numTries; i += 1) {
        // set up input
        fillRand(real, -1.0, 1.0);
        fillRand(imag, -1.0, 1.0);

        for (size_t j = 0; j < TEST_SIZE; j += 1) {
            h_x[j] = std::complex<double>(real[j], imag[j]);
            test[j] = MAKE_DOUBLE_COMPLEX(real[j], imag[j]);
        }

        COPY_H2D(d_x, test.data(), TEST_SIZE * sizeof(DOUBLE_COMPLEX_T));

        // compute correct result
        correctFft(h_x, correct);

        // compute test result
        fft<<<gridSize, blockSize>>>(d_x, d_output, TEST_SIZE);
        SYNC();

        // copy back
        COPY_D2H(test.data(), d_output, TEST_SIZE * sizeof(DOUBLE_COMPLEX_T));
        
        for (int j = 0; j < TEST_SIZE; j += 1) {
            if (std::abs(correct[j].real() - test[j].x) > 1e-4 || std::abs(correct[j].imag() - test[j].y) > 1e-4) {
                FREE(d_x);
                FREE(d_output);
                return false;
            }
        }
    }
    FREE(d_x);
    FREE(d_output);
    return true;
}

void destroy(Context *ctx) {
    FREE(ctx->d_x);
    FREE(ctx->d_output);
    delete ctx;
}
