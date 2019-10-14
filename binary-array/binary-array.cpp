#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

void sortBinaryArray1(Node* items, int length);

void copyArray(Node* source, Node* destination, int length);
void printArray(Node* items, int length);

struct Node {
	int key;
	int data;
};

int main()
{
	int length;
	cin >> length;
	Node* items = new Node[length];
	for (int i = 0; i < length; i++) {
		items[i].key = rand() % 2;
		//items[i].data = rand() % 900 + 100;
		items[i].data = 100 + i;
	}
	printArray(items, length);
	sortBinaryArray1(items, length);
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