// Implementation of the Cocktail Shaker Sort algorithm in C
// Harris Ransom

/** Includes **/
#include <stdbool.h>
#include <stdio.h>

/** Functions **/
// Cocktail sort implementation
void cocktailSort(int arr[], int len) {
	bool swapped = true;	// Tracks if a comparison has been made
	int start = 0;			// Tracks sorted section
	int end = len - 1;
	int temp;				// Used for swapping items

	// Sorts until no changes made
	while (swapped) {
		swapped = false;	// Reset swapped flag

		// Bubble sort left -> right
		for (int i = start; i < end; i++) {
			// Swaps if necessary
			if (arr[i] > arr[i + 1]) {
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				swapped = true;
			}
		}

		if (!swapped) break;	// If nothing moved, exit
		swapped = false;		// Otherwise, reset swapped flag
		end--;					// Decrement end counter

		// Bubble sort right -> left
		for (int i = end - 1; i >= start; i--) {
			// Swaps if necessary
			if (arr[i] > arr[i + 1]) {
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				swapped = true;
			}
		}

		start++;	// Increments start counter
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
	int nums[] = {7, 4, 2, 6, 10, 3, 5, 9, 1, 8};
	int len = sizeof(nums) / sizeof(int);
	printf("Initial array: \n");
	printArr(nums, len);

	cocktailSort(nums, len);
	printf("Sorted array: \n");
	printArr(nums, len);
}
