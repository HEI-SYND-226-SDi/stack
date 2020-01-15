#include <functional>
#include <iostream>
#include <memory>
#include <vector>

#include "stack.hpp"
#include "utils/test.hpp"

static std::vector<void*> allocations_;

void* operator new[](std::size_t size) {
    auto memory = malloc(size);
    allocations_.push_back(memory);
    return memory;
}

void operator delete[](void *memory) noexcept {
    allocations_.erase(allocations_.begin(),allocations_.end());
    free(memory);
}

int main() {
    std::cout << "\n\n"
              << "*************************\n"
              << "* Running unit tests... *\n"
              << "*************************\n";

    test(" -> Stack functionality", []() {
        Stack<int> stack(3);
        try {
            stack.push(1);
            stack.push(2);
            stack.push(3);
        } catch (std::out_of_range) {
            return false;
        }
        if (stack.pop() != 3) {
            return false;
        }
        if (stack.pop() != 2) {
            return false;
        }
        if (stack.pop() != 1) {
            return false;
        }
        return true;
    });

    test(" -> Push to full stack with move semantics", []() {
        Stack<int> stack(3);
        try {
            stack.push(0);
            stack.push(0);
            stack.push(0);
        } catch (std::out_of_range) {
            return false;
        }
        try {
            stack.push(0);
        } catch (std::out_of_range) {
            return true;
        }
        return false;
    });

    test(" -> Push to full stack with copy semantics", []() {
        int a = 0;
        Stack<int> stack(3);
        try {
            stack.push(a);
            stack.push(a);
            stack.push(a);
        } catch (std::out_of_range) {
            return false;
        }
        try {
            stack.push(a);
        } catch (std::out_of_range) {
            return true;
        }
        return false;
    });

    test(" -> Pop from empty stack", []() {
        Stack<int> stack(3);
        try {
            stack.push(0);
            stack.push(0);
            stack.pop();
            stack.pop();
        } catch (std::out_of_range) {
            return false;
        }
        try {
            stack.pop();
        } catch (std::out_of_range) {
            return true;
        }
        return false;
    });

    test(" -> Push to stack with 0 capacity", []() {
        Stack<int> stack(0);
        try {
            stack.push(0);
        } catch (std::out_of_range) {
            return true;
        }
        return false;
    });

    test(" -> Pop from stack with 0 capacity", []() {
        Stack<int> stack(0);
        try {
            stack.pop();
        } catch (std::out_of_range) {
            return true;
        }
        return false;
    });

    test(" -> Memory leaks", []() {
        return allocations_.size() == 0;
    });

    std::cout << "** \033[32mALL TESTS PASSED, congrat!\033[0m **";

    return 0;
}
