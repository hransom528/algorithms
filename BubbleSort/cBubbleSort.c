// Implementation of the Bubble Sort algorithm in C
// Harris Ransom

/** Includes **/
#include <stdio.h>
#include <string.h>

/** Functions **/
int* bubbleSort(int arr[], int len) {
	int temp;
	
	for (int i = 0; i < len - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
		}
	}
	return arr;
}

/** MAIN **/
int main() {
	// Initialization
	int nums[] = {2, 1, 3, 4, 5};
	int len = (sizeof(nums) / sizeof(int));
	printf("Initial array: \n");
	for (int i = 0; i < len; i++) {
		printf("\tIndex %d - %d\n", i, nums[i]);
	}
	
	// Sorts array
	int *sorted = bubbleSort(nums, len);
	
	// Displays results
	printf("Bubble Sort results: \n");
	for (int i = 0; i < len; i++) {
		printf("\tIndex %d - %d\n", i, sorted[i]);
	}
	
	return 0;
} 
