#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack {
public:
    Stack(std::size_t capacity): storage_(new T[capacity]), capacity_(capacity) {}

    inline std::size_t capacity() const {
        return capacity_;
    }

    inline std::size_t size() const {
        return position_;
    }

    void push(const T& element) {
        position_++;
        if (position_ > capacity()){
            position_--;
            throw std::out_of_range("Not enough capacity");
        }
        storage_[position_-1] = element;
    }

    void push(T&& element) {
        position_++;
        if (position_ > capacity()){
            position_--;
            throw std::out_of_range("Not enough capacity");
        }
        storage_[position_-1] = std::move(element);
    }

    T pop() {
        position_--;
        if (position_ < 0){
            position_++;
            throw std::out_of_range("Stack is empty");
        }
        return std::move(storage_[position_]);
    }

private:
    T* storage_;
    std::size_t capacity_;
    std::size_t position_ = 0;
};
