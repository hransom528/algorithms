// Implementation of the Insertion Sort algorithm in C
// Harris Ransom

/** Includes **/
#include <stdio.h>

/** Functions **/
// Insertion Sort implementation
void insertionSort(int arr[], int len) {
	for (int i = 1; i < len; i++) { 			// Cycles through whole array, moving over sorted portion
		int temp = arr[i];
		int index = i;
		while (index > 0 && temp < arr[index - 1]) {	// Moves backwards and inserts temp into appropriate position
			arr[index] = arr[index - 1]; 		// Shifts backwards
			index--;
		}
		arr[index] = temp; 				// Found spot to insert temp
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
int main(int argc, char **argv) {
	// Initial array
	int nums[] = {11, 6, 13, 5, 3, 14, 9, 1, 12, 8, 7, 15, 2, 10, 4};
	int len = sizeof(nums) / sizeof(int);
	printf("Array before sort: \n");
	printArr(nums, len);
	
	// Sorts and outputs
	insertionSort(nums, len);
	printf("Array after sort: \n");
	printArr(nums, len);
	return 0;
}
