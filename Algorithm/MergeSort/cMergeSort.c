// Implementation of Merge Sort algorithm in C
// Harris Ransom

/** Includes **/
#include <stdio.h>

/** Functions **/
// Merges two subarrays of arr
void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	
	// Gets array sizes
	int len1 = m - l + 1;
	int len2 = r - m;
	
	// Creates temporary arrays
	int L[len1], R[len2];
	
	// Copies data to temp arrays
	for (int i = 0; i < len1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < len2; j++)
		R[j] = arr[m + j + 1];
		
	// Merges temporary arrays
	i = 0;	// Initial index of first subarray
	j = 0;	// Initial index of second subarray
	k = l;	// Initial index of new merged array
	while ((i < len1) && (j < len2)) {
		// Chooses larger element
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;	// Move to next available element in left subarray
		}
		else {
			arr[k] = R[j];
			j++;	// Move to next available element in right subarray
		}
		k++;	// Iterates to next spot in merged array
	}
	
	// Copy remaining elements if there are any
	while (i < len1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < len2) {
		arr[k] = R[j];
		j++;
		k++;
	}
	
}

// Merge Sort implementation
void mergeSort(int arr[], int l, int r) {
	if (r > l) {
		// Find middle
		int m = (l + r) / 2;
		
		// Sort first and second halves recursively
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		
		// Merge two halves back together
		merge(arr, l, m ,r);
	}
	
	
}

// Prints out given array
void printArr(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		if (i <= 9) {
			printf("\tIndex %d  - %d\n", i, arr[i]);
		}
		else {
			printf("\tIndex %d - %d\n", i, arr[i]);
		}
	}
}

/** MAIN**/
int main(int argc, char **argv) {
	// Initial array
	int arr[] = {9, 6, 3, 8, 5, 1, 7, 10, 2, 4};
	int len = sizeof(arr) / sizeof(int);
	printf("Initial array: \n");
	printArr(arr, len);
	
	// Sorts and prints array
	mergeSort(arr, 0, len - 1);
	printf("\nSorted array: \n");
	printArr(arr, len);
	return 0;
}
