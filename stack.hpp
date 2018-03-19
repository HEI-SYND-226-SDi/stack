#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack {
public:
	Stack(std::size_t capacity): storage_(new T[capacity]), capacity_(capacity) {}

    // Fix memory leak
    ~Stack()
    {
        delete[] storage_;
    }

	inline std::size_t capacity() const {
		return capacity_;
	}

	inline std::size_t size() const {
		return position_;
	}

	void push(const T& element) {
		if (position_ >= capacity_) throw std::out_of_range("Not enough capacity");	// index range from 0 to capactiy -1
		storage_[position_++] = element;
	}

	void push(T&& element) {
		if (position_ >= capacity_) throw std::out_of_range("Not enough capacity");	// > to >= because index range from 0 to capacity-1
		storage_[position_++] = std::move(element);
	}

	T pop() {

		if (position_ <= 0) throw std::out_of_range("Stack is empty");	// < to <= because stack is empty when pos=0
		return std::move(storage_[--position_]);	// changed to pre-decrement to avoid out of range indexes
	}

private:
	T* storage_;
	std::size_t capacity_;
	std::size_t position_ = 0;
};
