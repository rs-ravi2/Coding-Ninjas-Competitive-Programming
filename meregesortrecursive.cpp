#include <bits/stdc++.h>
using namespace std;

void merge(int *a, int start, int mid, int end) {
	int *b = new int[end - start + 1];
	int i = start, j = mid + 1, k = 0;

	while (i <= mid && j <= end) {
		if (a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}

	while (i <= mid) {
		b[k++] = a[i++];
	}

	while (j <= end) {
		b[k++] = a[j++];
	}

	for (i = start; i <= end; i++)
		a[i] = b[i - start];
}



void mergesort(int *a, int start, int end) {
	int mid;
	if (start < end) {
		mid = (start + end) / 2;
		mergesort(a, start, mid);
		mergesort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}

void mergeSort(int a[], int size) {
	if (size <= 1)
		return;
	int start = 0, end = size - 1;
	mergesort(a, start, end);
}

int main() {

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	//input
	int length;
	cin >> length;
	int* input = new int[length];
	for (int i = 0; i < length; i++)
		cin >> input[i];
	mergeSort(input, length);
	for (int i = 0; i < length; i++) {
		cout << input[i] << " ";
	}

	return 0;
}