// Implements Stack data structure with a linked list in C
// Harris Ransom

/** Includes**/
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/** Defines **/
#define STACK_EMPTY INT_MIN

// Linked List node
typedef struct node{
	int value;
	struct node *next;
} node;

typedef node *stack; 	// Stack implementation

/** Functions **/
// Adds (pushes) to top of stack
bool push(stack *myStack, int item) {
	node *newNode = malloc(sizeof(node));	   // Allocates new item
	if (newNode == NULL) return false; 	   // Malloc failed
	newNode->value = item;			   // Adds value
	newNode->next = *myStack;		   // Orders node at stack head
	*myStack = newNode;
	return true;
}

// Removes (pops) top of stack
int pop(stack *myStack) {
	if (*myStack == NULL) return STACK_EMPTY;  // If stack is empty
	int result = (*myStack)->value;		   // Gets result from head
	node *tmp = *myStack;			   // Gets pointer to head
	*myStack = (*myStack)->next;		   // Moves head to next item
	free(tmp);				   // Frees previous head
	return result;				   // Return popped item
	
}

/** MAIN **/
int main () {
	stack s = NULL;
	
	push(&s, 27);
	push(&s, 15);
	push(&s, 36);
	
	int t;
	while ((t = pop(&s)) != STACK_EMPTY) {
		printf("t = %d\n", t);
	}
	return 0;
}
