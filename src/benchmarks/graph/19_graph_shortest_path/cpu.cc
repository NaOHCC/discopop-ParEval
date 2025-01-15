// Driver for 19_graph_shortest_path for Serial, OpenMP, MPI, and MPI+OpenMP
// /* Return the length of the shortest path from source to dest in the graph defined by the adjacency matrix A.
//    A is an NxN adjacency matrix stored in row-major.
//    Example:
// 
// 	 input: [[0, 1, 1, 0], [1, 0, 0, 1], [1, 0, 0, 1], [0, 1, 1, 0]], source=0, dest=3
//    output: 2
// */
// int shortestPathLength(std::vector<int> const& A, size_t N, int source, int dest) {

#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>
#include <vector>

#include "utilities.hpp"
#include "baseline.hpp"
#include "generated-code.hpp"   // code generated by LLM

struct Context {
    std::vector<int> A;
    size_t N;
    int source, dest;
};

void randomConnectedUndirectedGraph(std::vector<int> &A, size_t N) {
    std::vector<int> nodes(N);
    std::iota(nodes.begin(), nodes.end(), 0);
    std::random_shuffle(nodes.begin(), nodes.end());

    for (int i = 0; i < N-1; i += 1) {
        A[nodes[i] * N + nodes[i+1]] = 1;
        A[nodes[i+1] * N + nodes[i]] = 1;
    }

    for (int i = 0; i < N; i += 1) {
        int numEdges = rand() % (N - 1);
        for (int j = 0; j < numEdges; j += 1) {
            int other = rand() % N;
            if (other != i) {
                A[i * N + other] = 1;
                A[other * N + i] = 1;
            }
        }
    }
}

void reset(Context *ctx) {
    randomConnectedUndirectedGraph(ctx->A, ctx->N);
    ctx->source = rand() % ctx->N;
    
    do {
        ctx->dest = rand() % ctx->N;
    } while (ctx->dest == ctx->source);

    BCAST(ctx->A, INT);
    BCAST_PTR(&ctx->source, 1, INT);
    BCAST_PTR(&ctx->dest, 1, INT);
}

Context *init() {
    Context *ctx = new Context();

    ctx->N = DRIVER_PROBLEM_SIZE;
    ctx->A.resize(ctx->N * ctx->N);

    reset(ctx);
    return ctx;
}

void NO_OPTIMIZE compute(Context *ctx) {
    int sp = shortestPathLength(ctx->A, ctx->N, ctx->source, ctx->dest);
    (void)sp;
}

void NO_OPTIMIZE best(Context *ctx) {
    int sp = correctShortestPathLength(ctx->A, ctx->N, ctx->source, ctx->dest);
    (void)sp;
}

bool validate(Context *ctx) {
    const size_t TEST_SIZE = 512;

    std::vector<int> A(TEST_SIZE * TEST_SIZE);

    int rank;
    GET_RANK(rank);

    const size_t numTries = MAX_VALIDATION_ATTEMPTS;
    for (int trialIter = 0; trialIter < numTries; trialIter += 1) {
        // set up input
        randomConnectedUndirectedGraph(A, TEST_SIZE);
        int source = rand() % TEST_SIZE;
        int dest;
        do {
            dest = rand() % TEST_SIZE;
        } while (dest == source);
        
        BCAST(A, INT);
        BCAST_PTR(&source, 1, INT);
        BCAST_PTR(&dest, 1, INT);

        // compute correct result
        int correct = correctShortestPathLength(A, TEST_SIZE, source, dest);

        // compute test result
        int test = shortestPathLength(A, TEST_SIZE, source, dest);
        SYNC();

        // normalize "not-found" results
        if (correct == std::numeric_limits<int>::max() || correct < 0) {
            correct = -1;
        }
        if (test == std::numeric_limits<int>::max() || test < 0) {
            test = -1;
        }
        
        bool isCorrect = true;
        if (IS_ROOT(rank) && correct != test) {
            isCorrect = false;
        }
        BCAST_PTR(&isCorrect, 1, CXX_BOOL);
        if (!isCorrect) {
            return false;
        }
    }

    return true;
}

void destroy(Context *ctx) {
    delete ctx;
}
