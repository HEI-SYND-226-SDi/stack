#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack {
public:
	Stack(std::size_t capacity): storage_(new T[capacity]), capacity_(capacity) {

	}

	~Stack()
	{

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
		if (position_ >= capacity_) throw std::out_of_range("Not enough capacity"); // Second Fix there is no positin nbr 3 in stack else it would need to be 4 big
		storage_[position_++] = element;
	}

	// Adding object t stack
	void push(T&& element) {
		if (position_ >= capacity_) throw std::out_of_range("Not enough capacity"); // Second Fix there is no positin nbr 3 in stack else it would need to be 4 big
		storage_[position_++] = std::move(element);
	}

	// Removing object from stack
    T pop() {
		if (position_ <= 0) throw std::out_of_range("Stack is empty");	// Third Fix if the position is 0 it can't go lower
		return std::move(storage_[--position_]);						// First Fix position is incremented after having been wirten in
	}

private:
    T* storage_;
    std::size_t capacity_;
    std::size_t position_ = 0;
};
