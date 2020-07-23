// Implementation of Quick Sort algorithm in C
// Harris Ransom

/** Includes **/
#include <stdio.h>

/** Functions **/
// Helper function to pivot and partition array
int partition(int arr[], int start, int end) {
	int pivot = arr[end];
	int i = (start - 1);	// Tracks sorted elements
	int temp;
		
	// Iterates through array to partition elements
	for (int j = start; j < end; j++) {
		if (arr[j] <= pivot) {
			i++;	// Moves partition forward
				
			// Swaps smaller value and larger value
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
		
	// Swaps end of sorted with end of arr
	temp = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = temp;
		
	return i + 1;	// Return final sorted position
}

// Quick Sort implementation
void quickSort(int arr[], int start, int end) {
	if (start < end) {
		int index = partition(arr, start, end);	// Partitions array and grabs index
			
		// Recursively sort two partitions
		quickSort(arr, start, index - 1);
		quickSort(arr, index + 1, end);
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
	quickSort(nums, 0, len - 1);
	printf("Array after sort: \n");
	printArr(nums, len);
	return 0;
}
