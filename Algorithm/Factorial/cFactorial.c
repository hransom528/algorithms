// Factorial finder written in C
// Harris Ransom

/** Includes **/
#include <stdio.h>
#include <stdint.h>	// For int_fast64_t

/** Defines **/
#define MAX_NUM 20

/** Functions **/
int_fast64_t findFactorial(short num) {
	if (num <= 1) {
		return 1;
	}
	else if (num > MAX_NUM) { // Overflow
		return -1;
	}
	else {
		
		int_fast64_t result = num * findFactorial(num - 1);	// Recursively finds factorial
		return result;
	}
}

/** MAIN **/
int main(int argc, char **argv) {
	// Input
	short temp;
	printf("Enter number you wish to calculate the factorial for: ");
	scanf("%hi", &temp);
	while (temp > MAX_NUM) {
		printf("Please enter %d or lower: ", MAX_NUM);
		scanf("%hi", &temp);
	}
	
	// Results
	printf("Result of %hi!: %li\n", temp, findFactorial(temp));
	return 0;
}
