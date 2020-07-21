// Implementation of a recursive Fibonacci sequence finder in C
// Harris Ransom

/** Includes **/
#include <stdio.h>

/** Defines **/
#define NUM_FIBS 25

/** Functions **/
// Recursive Fibonacci solver with given position
int fib(int pos) {
	if ((pos == 0) || (pos == 1))
		return pos;
	return fib(pos - 2) + fib(pos - 1);
}

/** MAIN **/
int main() {
	printf("Fibonacci Numbers (1 - %d): \n", NUM_FIBS);
	// Finds the first 25 Fibonacci numbers
	for (int i = 1; i <= NUM_FIBS; i++) {
		if (i <= 9) {	// Aligns first dashes with rest of list
			printf("\t%d  - %d\n", i, fib(i));
		}
		else {
			printf("\t%d - %d\n", i, fib(i));
		}
	}
	return 0;
}
