// FizzBuzz number solver written in C
// Harris Ransom

/** Includes **/
#include <stdbool.h>
#include <stdio.h>

/** Functions **/
// Determiens if number is FizzBuzz
bool isFizzBuzz(int num) {
	if ((num % 3 == 0) && (num % 5 == 0) && (num > 0)) {
		return true;
	}
	else {
		return false;
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
	int fizzBuzz[100];
	int len = sizeof(fizzBuzz) / sizeof(int);
	short index = 0;
	int num = 0;
	
	// Gets first 100 FizzBuzz nums
	while (index < 100) {
		if (isFizzBuzz(num)) {
			fizzBuzz[index] = num;
			index++;
		}
		num++;
	}
	
	// Outputs
	printf("First 100 FizzBuzz numbers: \n");
	printArr(fizzBuzz, len);
	return 0;
}
