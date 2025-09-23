#pragma once
#include <iostream>
#include <string>

#define RUN_TEST(func)                               \
    do {                                             \
        std::cout << "Running " << #func << "...\n"; \
        int result = func();                         \
        if (result == 0) {                           \
            std::cout << #func << " PASSED\n\n";     \
        } else {                                     \
            std::cerr << #func << " FAILED\n\n";     \
            total_failed++;                          \
        }                                            \
        total_run++;                                 \
    } while (0)

#define TEST_ASSERT(expr)                                                                              \
    do {                                                                                               \
        if (!(expr)) {                                                                                 \
            std::cerr << "    ❌ Assertion failed: " << #expr << " at line " << __LINE__ << std::endl; \
            return 1;                                                                                  \
        }                                                                                              \
    } while (0)