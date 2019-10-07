#include <iostream>

void match(int* nuts, int* bolts, int from, int to);
int partition(int* items, int from, int to, int pivot);
void swap(int* a, int* b);

int main()
{
	int nuts[] = { 5, 3, 4, 1, 7, 6, 2 };
	int bolts[] = { 7, 6, 3, 1, 5, 4, 2 };
	int length = sizeof(nuts) / sizeof(nuts[0]);
	match(nuts, bolts, 0, length - 1);
	for (int i = 0; i < length; i++) {
		std::cout << "nut " << nuts[i] << " - " << bolts[i] << " bolt" << std::endl;
	}
}

void match(int* nuts, int* bolts, int from, int to) {
	if (from < to) {
		int q = partition(nuts, from, to, bolts[to]);
		partition(bolts, from, to, nuts[q]);
		match(nuts, bolts, from, q - 1);
		match(nuts, bolts, q + 1, to);
	}
}

int partition(int* items, int from, int to, int pivot) {
	int i = from - 1;
	for (int j = from; j < to; j++) {
		if (items[j] < pivot) {
			i++;
			swap(&items[i], &items[j]);
		}
		else if (items[j] == pivot) {
			swap(&items[j], &items[to]);
			j--;
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