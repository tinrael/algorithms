#include <iostream>

void quicksort(int* items, int p, int r);
int partition(int* items, int p, int r);
void swap(int* x, int* y);

int main()
{
	int items[] = { 5, 1, 6, -8, 2, 3, 9, -6 };
	int length = sizeof(items) / sizeof(items[0]);
	quicksort(items, 0, length - 1);
	for (int i = 0; i < length; i++) {
		std::cout << items[i] << " ";
	}
}

void quicksort(int* items, int from, int to) {
	if (from < to) {
		int q = partition(items, from, to); // partitioning index
		quicksort(items, from, q - 1);
		quicksort(items, q + 1, to);
	}
}

int partition(int* items, int from, int to) {
	int pivot = items[to];
	int i = from - 1;
	for (int j = from; j < to; j++) {
		if (items[j] <= pivot) {
			i++;
			swap(&items[i], &items[j]);
		}
	}
	swap(&items[i + 1], &items[to]);
	return i + 1;
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}