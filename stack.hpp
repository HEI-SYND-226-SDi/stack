#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Stack
{
public:
	Stack(std::size_t capacity): storage_(new T[capacity]), capacity_(capacity)
	{
	}

	inline std::size_t capacity() const
	{
        return capacity_;
    }

	inline std::size_t size() const
	{
        return position_;
    }

	void push(const T& element)
	{
		if (position_ >= capacity_)
		{
			throw std::out_of_range("Not enough capacity");
		}
		else
		{
			// only if no overflow
			storage_[position_++] = element;
		}
    }

	void push(T&& element)
	{
		if (position_ >= capacity_)
		{
			throw std::out_of_range("Not enough capacity");
		}
		else
		{
			// only if no overflow
			storage_[position_++] = std::move(element);
		}
	}

	T pop()
	{
		if (position_ <= 0) // < become <= to test 0 too
		{
			throw std::out_of_range("Stack is empty");
		}
		else
		{
			return std::move(storage_[--position_]); // post decrement become post decrement
		}
    }

private:
    T* storage_;
    std::size_t capacity_;
    std::size_t position_ = 0;
};
