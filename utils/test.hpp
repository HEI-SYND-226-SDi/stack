#pragma once
#include <functional>
#include <iostream>

inline void test(const char* const name, std::function<bool()> function) {
    bool testPassed = function();
    std::cout << name << ":" << ( testPassed ? "PASSED" : "FAILED") << "\n";
    if (!testPassed) exit(1);
}
