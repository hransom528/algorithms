// Implements a Stack data structure via an array in C
// Harris Ransom

/** Includes**/
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

/** Defines **/
#define STACK_LENGTH 5
#define EMPTY -1
#define STACK_EMPTY INT_MIN

int stackArr[STACK_LENGTH]; 	// Array that contains stack structure
int top = EMPTY; 	    	// Index of top item

/** Functions **/
// Adds (pushes) to top of stack
bool push(int item) {
	if (top >= STACK_LENGTH - 1) return false; // If stack is full
	top++;					   // Updates stack index
	stackArr[top] = item;			   // Adds item
	return true;
}

// Removes (pops) top of stack
int pop() {
	if (top == EMPTY) return STACK_EMPTY;	   // If stack is empty
	top--;					   // Decrement top
	return stackArr[top + 1];		   // Return popped item
	
}

/** MAIN **/
int main () {
	push(10);
	push (27);
	push (82);
	
	int t;
	while ((t = pop()) != STACK_EMPTY) {
		printf("t = %d\n", t);
	}
	return 0;
}
