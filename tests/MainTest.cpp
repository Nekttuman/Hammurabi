#include <cassert>
#include <print>

#include "TestRunner.h"

// tests:
int userInteractionTest();
int randomTest();

int main() {
    int total_run = 0, total_failed = 0;

    RUN_TEST(userInteractionTest);
    RUN_TEST(randomTest);

    std::print(" Ran {}  tests, {} failed.\n", total_run, total_failed);

    return total_failed == 0 ? 0 : 1;
}