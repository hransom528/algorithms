// Happy Number solver in C++
// Harris Ransom

/** Includes **/
#include <iostream>

using namespace std;

/** Defines **/
#define NUM_HAPPY 10	// First number of happy nums to find
#define MAX_RUNS 1000	// Maximum number of loops before not happy
static int count = 0;	// Detects infinite loops

/** Functions **/
// Determines if a number is happy or not
bool isHappy(int num) {
	if (num <= 0) { 			// Must be positive 
		return false;
	}
	else {
		int temp = num;
		int rem;
		int sum = 0;
		
		// Calculates sum
		while (temp > 0) {
			rem = temp % 10;	// Gets remainder
			sum += (rem * rem); 	// Adds square to sum
			temp /= 10;		// Moves to next digit
		}
		
		// Determines if happy
		while ((sum != 1) && (sum != 4) && (count <= MAX_RUNS)){
			count++;
			sum = isHappy(sum);
		}
		count = 0;
		
		if (sum == 1) {
			return true;
		}
		else {
			return false;
		}
	}
 }

/** MAIN **/
int main(int argc, char *argv[]) {
	int temp;
	
	// Happy Number test
	cout << "Input number you want to test: " << endl;
	cin >> temp;
	while (temp <= 0) {
		cout << "Please input a number greater than 0: " << endl;
		cin >> temp;
	}
	if (isHappy(temp)) {
		printf("%d is a Happy Number\n", temp);
	}
	else {
		printf("%d is not a Happy Number\n", temp);
	}
	
	// Finds first NUM_HAPPY Happy Numbers
	temp = 0;
	int count = 0;
	int nums[NUM_HAPPY];
	bool found;
	
	while (temp < NUM_HAPPY) {
		found = false;
		while (!found) {
			if (isHappy(count)) {
				nums[temp] = count;
				found = true;
			}
			count++;
		}
		temp++;
	}
	
	// Outputs Happy Nums 
	printf("First %d Happy Nums: \n", NUM_HAPPY);
	for (int i = 0; i < NUM_HAPPY; i++) {
		if (i <= 9) { // Aligns dashes for single digit nums
			printf("\t%d  - %d\n", i + 1, nums[i]);
		}
		else {
			printf("\t%d - %d\n", i + 1, nums[i]);
		}
	}
	
	return 0;
}
