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
 
node *head = NULL; // Linked List head

/** Functions **/
// Adds (pushes) to top of stack
bool push(int item) {
	node *newNode = malloc(sizeof(node));	   // Allocates new item
	if (newNode == NULL) return false; 	   // Malloc failed
	newNode->value = item;			   // Adds value
	newNode->next = head;			   // Orders node at head
	head = newNode;
	return true;
}

// Removes (pops) top of stack
int pop() {
	if (head == NULL) return STACK_EMPTY;	   // If stack is empty
	int result = head->value;		   // Gets result from head
	node *tmp = head;			   // Gets pointer to head
	head = head->next;			   // Moves head to next item
	free(tmp);				   // Frees previous head
	return result;				   // Return popped item
	
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
