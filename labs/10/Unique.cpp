#include "Unique.h"

void Unique::merge(int arr[], int left, int mid, int right, int length) {
	int temp[length];
	int indexL = left; int indexR = mid; int indexT = left;
	while (indexL < mid || indexR < right) { // Process every element of both arrays
		if (indexL < mid && indexR < right) { // Neither A[] nor B[] are exhausted
			// Add smaller element to temp[]
			if (arr[indexL] < arr[indexR]) temp[indexT++] = arr[indexL++];
			else temp[indexT++] = arr[indexR++];
		}
		// One array is exhausted, so just copy the remaining elements of the other
		else if (indexL == mid) temp[indexT++] = arr[indexR++]; 
		else if (indexR == right) temp[indexT++] = arr[indexL++]; 
	}
	// Copy from temp[] back to arr[]
	for (int i = left; i < right; ++i) arr[i] = temp[i];
}

// Sort the input array arr[] from index 'left' to index 'right'-1
void Unique::mergeSort(int arr[], int left, int right, int length) {
	if (right-left <= 1) return;
	int mid = (left+right)/2;
	mergeSort(arr, left, mid, length);
	mergeSort(arr, mid, right, length);
	merge(arr, left, mid, right, length);
}

bool Unique::unique(int* A, int n) {
	mergeSort(A, 0, n, n);
	for (int i = 0; i < n-1; ++i) if (A[i] == A[i+1]) return false;
	return true;
}
