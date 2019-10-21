#pragma once
#include <iostream>

using std::cout;
using std::endl;
using std::swap;
using std::logic_error;

template<typename T>
class Heap {
private:
	int d; // arity
	T* items;
	int capacity;
	int size;
	const static int INITIAL_CAPACITY = 11;

	void growCapacity() {

	}

	int getParentIndex(int i) {
		return (i - 1) / d;
	}

	void ascend(int index) {
		if (index == 0) {
			return;
		}
		size_t parentIndex = getParentIndex(index);
		if (items[parentIndex] < items[index]) {
			swap(items[parentIndex], items[index]);
			ascend(parentIndex);
		}
	}

	void descend(int index) {
		if (index == size - 1) {
			return;
		}
		
	}

public:
	Heap(int d) {
		this->d = d;
		capacity = INITIAL_CAPACITY;
		items = new T[capacity];
		size = 0;
	}

	~Heap() {
		delete[] items;
	}

	void insert(T newItem) {
		if (size == capacity) {
			growCapacity();
		}
		items[size] = newItem;
		ascend(size);
		size++;
	}

	void increase(int index, T newItem) {
		if (newItem < items[index]) {
			throw logic_error("smaller item passed to increase() method");
		}
		items[index] = newItem;
		ascend(index);
	}

	T exctractMax() {
		if (size == 0) {
			throw logic_error("attempt to exctract from an empty heap");
		}
		size--;
		T result = items[0];
		items[0] = items[size];
		descend(0);
		return result;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << items[i] << " ";
		}
		cout << endl;
	}
};
