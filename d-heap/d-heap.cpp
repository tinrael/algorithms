#include "include/Heap.h"
#include <iostream>

void printArray(int* items, int length);

int main()
{
	int length;
	std::cin >> length;
	int* items = new int[length];
	for (int i = 0; i < length; i++) {
		items[i] = rand() % 1000;
	}
	printArray(items, length);
	Heap<int>::heapSort(items, length);
	printArray(items, length);
}

void printArray(int* items, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << items[i] << " ";
	}
	std::cout << std::endl;
}