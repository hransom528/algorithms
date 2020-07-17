// Implements Queue data structure with a linked list in C
// Harris Ransom

/** Includes**/
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/** Defines **/
#define QUEUE_EMPTY INT_MIN

// Linked List node
typedef struct node{
	int value;
	struct node *next;
} node;

// Queue implementation
typedef struct {
	node *head;
	node *tail;
} queue; 	

/** Functions **/
// Initializes given queue struct
void initQueue(queue *q) {
	q->head = NULL;
	q->tail = NULL;
}

// Adds (enqueues) item to tail of queue
bool enqueue(queue *q, int item) {
	node *newNode = malloc(sizeof(node));	// Allocates space for new node
	if (newNode == NULL) return false; 	// Malloc failed, return false
	newNode->value = item;
	newNode->next = NULL;		 	// Nothing after tail
	if (q->tail != NULL) {
		q->tail->next = newNode; 	// If queue has a tail, order it properly
	}
	q->tail = newNode;		 	// New item now tail
	if (q->head == NULL) q->head = newNode;	// Orders head if newNode is first item
	return true;
}

// Removes (dequeues) item from head of queue
int dequeue(queue *q) {
	if (q->head == NULL) return QUEUE_EMPTY;	// Queue empty
	node *tmp = q->head;				// Grabs current head
	int result = tmp->value;			// Save result to tmp
	q->head = q->head->next; 			// Orders head, removes item
	if (q->head == NULL) {
		q->tail = NULL; 			// Fixes tail if queue is empty
	}
	free(tmp);					// Frees tmp value holder
	return result;
}

/** MAIN **/
int main () {
	queue q;
	initQueue(&q);
	
	enqueue(&q, 27);
	enqueue(&q, 15);
	enqueue(&q, 36);
	
	int t;
	while ((t = dequeue(&q)) != QUEUE_EMPTY) {
		printf("t = %d\n", t);
	}
	return 0;
}
