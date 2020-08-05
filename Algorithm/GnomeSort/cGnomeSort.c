 
// Implementation of Gnome Sort algorithm in C
// Harris Ransom

/** Includes **/
#include <stdio.h>

/** Functions **/
// Gnome sort implementation
void gnomeSort(int arr[], int len) {
	int i = 0;
    int temp;
    
    while (i < len) {
        if (i == 0) {
            i++;
        }
        if (arr[i] >= arr[i - 1]) {
            i++;
        }
        else {
            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
            i--;
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
	int nums[] = {7, 4, 2, 6, 10, 3, 5, 9, 1, 8};
	int len = sizeof(nums) / sizeof(int);
	printf("Initial array: \n");
	printArr(nums, len);

	gnomeSort(nums, len);
	printf("Sorted array: \n");
	printArr(nums, len);
}
