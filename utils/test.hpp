#pragma once
#include <functional>
#include <iostream>

inline void test(const char* const name, std::function<bool()> function) {
    bool testPassed = function();
    std::cout << name << ":" << ( testPassed ? " \033[32mPASSED\033[0m" : " \033[31mFAILED\033[0m") << "\n";
    if (!testPassed) {
        std::cout << "\n";
        exit(1);
    }
}
