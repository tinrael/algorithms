#pragma once
#include <algorithm>

using std::swap;

template<typename T>
class Heap {
private:
	int d; // arity
	T* items;
	size_t capacity;
	size_t size;
	const static int INITIAL_CAPACITY = 4;

	void growCapacity() {

	}

	size_t getParentIndex(size_t i) {
		return i - 1 / d;
	}

	void ascend(size_t index) {
		if (index == 0) {
			return;
		}
		size_t parentIndex = getParentIndex(index);
		if (items[parentIndex] < items[index]) {
			swap(items[parentIndex], items[index]);
			ascend(parentIndex);
		}
	}

public:
	Heap(size_t d) {
		this->d = d;
		capacity = INITIAL_CAPACITY;
		T* items = new T[capacity];
		size = 0;
	}

	~Heap() {
		delete[] items;
	}

	void insert(T newItem) {
		if (size == capacity) {
			growCapacity();
		}
		items[size] = T;
		ascend(size);
		size++;
	}

	


};
