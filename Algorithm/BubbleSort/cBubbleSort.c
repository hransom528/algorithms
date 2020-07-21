// Implementation of the Bubble Sort algorithm in C
// Harris Ransom

/** Includes **/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/** Functions **/
int* bubbleSort(int arr[], int len) {
	int temp;
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < len - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = true;
			}
		}
	} while (swapped); // Continue sorting until no swaps made
	return arr;
}

/** MAIN **/
int main() {
	// Initialization
	int nums[] = {14, 2, 20, 18, 8, 15, 1, 10, 6, 17, 4, 13, 9, 19, 3, 12, 7, 16, 5, 11};
	int len = (sizeof(nums) / sizeof(int));
	printf("Initial array: \n");
	for (int i = 0; i < len; i++) {
		if (i <= 9) {
			printf("\tIndex %d  - %d\n", i, nums[i]);
		}
		else {
			printf("\tIndex %d - %d\n", i, nums[i]);
		}
	}
	
	// Sorts array
	int *sorted = bubbleSort(nums, len);
	
	// Displays results
	printf("Bubble Sort results: \n");
	for (int i = 0; i < len; i++) {
		if (i <= 9) {
			printf("\tIndex %d  - %d\n", i, sorted[i]);
		}
		else {
			printf("\tIndex %d - %d\n", i, sorted[i]);
		}
	}
	
	return 0;
} 
