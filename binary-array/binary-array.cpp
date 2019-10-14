#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

struct Node {
	int key;
	int data;
};

void sortBinaryArray1(Node* items, int length);
void sortBinaryArray2(Node* items, int length);
void sortBinaryArray3(Node* items, int length);

void swap(Node* a, Node* b);
void copyArray(Node* source, Node* destination, int length);
void printArray(Node* items, int length);

int main()
{
	int length;
	cin >> length;
	Node* items = new Node[length];
	for (int i = 0; i < length; i++) {
		items[i].key = rand() % 2;
		items[i].data = 100 + i;
	}
	printArray(items, length);
	sortBinaryArray3(items, length);
	printArray(items, length);
	delete[] items;
}

// stable sorting algorithm with time complexity O(n)
void sortBinaryArray1(Node* items, int length) {
	Node* result = new Node[length];
	int index = 0;
	for (int i = 0; i < length; i++) {
		if (items[i].key == 0) {
			result[index] = items[i];
			index++;
		}
	}
	for (int i = 0; i < length; i++) {
		if (items[i].key == 1) {
			result[index] = items[i];
			index++;
		}
	}
	copyArray(result, items, length);
	delete[] result;
}

// in-place sorting algorithm with time complexity O(n)
void sortBinaryArray2(Node* items, int length) {
	int leftIndex = 0;
	int rightIndex = length - 1;

	while (true) {
		while (leftIndex < length && items[leftIndex].key == 0) {
			leftIndex++;
		}
		while (rightIndex >= 0 && items[rightIndex].key == 1) {
			rightIndex--;
		}
		if (leftIndex > rightIndex) {
			break;
		}
		swap(&items[leftIndex], &items[rightIndex]);
	}
}

// in-place stable sorting algorithm
void sortBinaryArray3(Node* items, int length) {
	bool swapMade;
	for (int i = 1; i < length; i++) {
		swapMade = false;
		for (int j = 0; j < length - i; j++) {
			if (items[j].key > items[j + 1].key) {
				swap(&items[j], &items[j + 1]);
				swapMade = true;
			}
		}
		if (!swapMade) {
			break;
		}
	}
}

void swap(Node* a, Node* b) {
	Node tmp = *a;
	*a = *b;
	*b = tmp;
}

void copyArray(Node* source, Node* destination, int length) {
	for (int i = 0; i < length; i++) {
		destination[i] = source[i];
	}
}

void printArray(Node* items, int length) {
	for (int i = 0; i < length; i++) {
		cout << items[i].key << "-" << items[i].data << " ";
	}
	cout << endl;
}