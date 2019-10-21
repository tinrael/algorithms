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
	const int INITIAL_CAPACITY = 4;
	int capacity;
	int size;

	void growCapacity();

	int getParentIndex(int i);

	int getLeftChildIndex(int i);

	void ascend(int index);

	void descend(int index);

public:
	static void heapSort(T* items, int length);

	Heap(int d);

	~Heap();

	void insert(T newItem);

	void increase(int index, T newItem);

	T exctractMax();

	void print();
};

template<typename T>
void Heap<T>::growCapacity() {
	capacity *= 2;
	T* newItems = new T[capacity];
	for (int i = 0; i < size; i++) {
		newItems[i] = items[i];
	}
	delete[] items;
	items = newItems;
}

template<typename T>
int Heap<T>::getParentIndex(int i) {
	return (i - 1) / d;
}

template<typename T>
int Heap<T>::getLeftChildIndex(int i) {
	return d * i + 1;
}

template<typename T>
void Heap<T>::ascend(int index) {
	if (index == 0) {
		return;
	}
	int parentIndex = getParentIndex(index);
	if (items[parentIndex] < items[index]) {
		swap(items[parentIndex], items[index]);
		ascend(parentIndex);
	}
}

template<typename T>
void Heap<T>::descend(int index) {
	int currentChildIndex = getLeftChildIndex(index);
	if (currentChildIndex >= size) {
		return;
	}
	int maxChildIndex = currentChildIndex;
	currentChildIndex++;
	for (int i = 1; i < d && currentChildIndex < size; i++) {
		if (items[maxChildIndex] < items[currentChildIndex]) {
			maxChildIndex = currentChildIndex;
		}
		currentChildIndex++;
	}
	if (items[index] < items[maxChildIndex]) {
		swap(items[index], items[maxChildIndex]);
		descend(maxChildIndex);
	}
}

template<typename T>
void Heap<T>::heapSort(T* items, int length) {
	Heap<T> heap(3);
	for (int i = 0; i < length; i++) {
		heap.insert(items[i]);
	}
	for (int i = 0; i < length; i++) {
		items[length - 1 - i] = heap.exctractMax();
	}
}

template<typename T>
Heap<T>::Heap(int d) {
	this->d = d;
	capacity = INITIAL_CAPACITY;
	items = new T[capacity];
	size = 0;
}

template<typename T>
Heap<T>::~Heap() {
	delete[] items;
}

template<typename T>
void Heap<T>::insert(T newItem) {
	if (size == capacity) {
		growCapacity();
	}
	items[size] = newItem;
	ascend(size);
	size++;
}

template<typename T>
void Heap<T>::increase(int index, T newItem) {
	if (newItem < items[index]) {
		throw logic_error("smaller element passed to increase() method");
	}
	items[index] = newItem;
	ascend(index);
}

template<typename T>
T Heap<T>::exctractMax() {
	if (size == 0) {
		throw logic_error("attempt to exctract from an empty heap");
	}
	T result = items[0];
	size--;
	items[0] = items[size];
	descend(0);
	return result;
}

template<typename T>
void Heap<T>::print() {
	for (int i = 0; i < size; i++) {
		cout << items[i] << " ";
	}
	cout << endl;
}
