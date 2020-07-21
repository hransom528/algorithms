// Implementation of the Binary Search algorithm in C
// Harris Ransom

/** Includes **/
#include <stdio.h>
#include <stdlib.h> 

/** Functions **/
int binSearch(int arr[], int arrSize, int value) {
	int bottom = 0;
	int top = (arrSize - 1);
	
	while (bottom <= top) {
		int middle = (int) ((top + bottom) / 2); // Gets middle index
		if (arr[middle] < value) {		 // Cuts bottom
			bottom = middle + 1;
		}
		else if (arr[middle] > value) {		 // Cuts top
			top = middle - 1;
		}
		else {					 // Middle == value
			return middle;
		}
	}
	return -1; 					 // Failure
}

/** MAIN **/
int main() {
	int testArr[] = {1, 3, 9, 11, 15, 19, 29};
	int len = (sizeof(testArr) / sizeof(int));
	int test1 = 25;
	int test2 = 15;
	
	printf("\nTest case 1: %d\n", binSearch(testArr, len, test1));
	printf("Test case 1: %d\n", binSearch(testArr, len, test2));
	return 0;
}
