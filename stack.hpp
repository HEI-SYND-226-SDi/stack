#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack {
public:
	Stack(std::size_t capacity): storage_(new T[capacity]), capacity_(capacity) {

	}

	// returns capacitiy of stack
    inline std::size_t capacity() const {
        return capacity_;
    }

	// returns position in stack
    inline std::size_t size() const {
        return position_;
    }

	// Adding object t stack
    void push(const T& element) {
		if (position_ > capacity_) throw std::out_of_range("Not enough capacity");
        storage_[position_++] = element;
    }

	// Adding object t stack
    void push(T&& element) {
		if (position_ > capacity_) throw std::out_of_range("Not enough capacity");
        storage_[position_++] = std::move(element);
    }

	// Removing object from stack
    T pop() {
		if (position_ < 0) throw std::out_of_range("Stack is empty");
		return std::move(storage_[--position_]);						// First Fix position is incremented after having been wirtten in
	}

private:
    T* storage_;
    std::size_t capacity_;
    std::size_t position_ = 0;
};
