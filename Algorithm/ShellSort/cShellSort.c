// Implementation of Shell Sort algorithm in C
// Harris Ransom

/** Includes **/
#include <stdio.h>

/** Functions **/
// Shell sort implementation
void shellSort(int arr[], int len) {
	int temp;

	// Traverse gaps large to small
	for (int gap = len / 2; gap > 0; gap /= 2) {
		// Insertion sort for non-sorted elements
		for (int i = gap; i < len; i++) {
			temp = arr[i];	// Grabs element to be sorted

			// Shift elements until correct location found
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j-= gap)
				arr[j] = arr[j - gap];

			arr[j] = temp;	// Insert element at correct position
		}
	}
}

// Prints given array
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

/** MAIN **/
int main() {
	int nums[] = [7, 4, 2, 6, 10, 3, 5, 9, 1, 8];
	int len = sizeof(nums) / sizeof(int);
	printf("Initial array: ");
	printArr(nums, len);

	shellSort(nums, len);
	printf("Sorted array: ");
	printArr(nums, len);
}
