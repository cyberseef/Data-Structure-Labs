#pragma once
#include<iostream>

template<typename T>
class Container
{
private:
	int capacity;
	int counter;
	T* values;

public:
	Container(int capacity)
	{
		this->capacity = capacity;
		this->counter = counter;
		values = new T[capacity];	
	}

	bool isFull()
	{
		if (capacity == counter)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool insert(T value)
	{
		if (!isFull())
		{
			values[counter] = value;
			++counter;
			return true;
		}
		else
		{
			return false;
		}
	}

	T search(T value)
	{
		for (T i = 0; i < capacity; i++)
		{
			if (value == values[counter])
			{
				i = capacity;
				return 1;
			}
			else
			{
				++counter;
			}
		}
	}

	T remove(T value)
	{
		for (T i = 0; i < capacity; i++)
		{
			if (value == values[counter])
			{
				T j = i;
				i = capacity;
				T temp = values[counter+1];
				values[counter] = temp;
				++counter
			}
		}
	}

	bool isFull(T value)
	{
		T result = insert(value);
		if (result == false)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
