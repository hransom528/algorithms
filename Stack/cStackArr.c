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

// Stack implementation
typedef struct{
	int stackArr[STACK_LENGTH];	// Array that contains stack structure
	int top;			// Index of top item
} stack;
    	

/** Functions **/
// Adds (pushes) to top of stack
bool push(stack *myStack, int item) {
	if (myStack->top >= STACK_LENGTH - 1) return false; 	// If stack is full
	myStack->top++;				     		// Updates stack index
	myStack->stackArr[myStack->top] = item;			// Adds item
	return true;
}

// Removes (pops) top of stack
int pop(stack *myStack) {
	if (myStack->top == EMPTY) return STACK_EMPTY;	   	// If stack is empty
	myStack->top--;				   	   	// Decrement top
	return myStack->stackArr[myStack->top + 1];	   	// Return popped item
	
}

/** MAIN **/
int main () {
	stack s;
	s.top = EMPTY;
	
	push(&s, 27);
	push(&s, 15);
	push(&s, 36);
	
	int t;
	while ((t = pop(&s)) != STACK_EMPTY) {
		printf("t = %d\n", t);
	}
	return 0;
}
