// Linked List data structure implementation in C with ints
// Harris Ransom

/** Includes **/
#include <stdio.h>
#include <stdlib.h>

/** Defines **/
// Node type, one item in list
struct node {
        int value;
        struct node* next;
};
typedef struct node node_t;

/** Functions **/
// Prints out linked list
void printList(node_t *head) {
        node_t *temp = head;
        while (temp != NULL) {
                if (temp->next == NULL) { // Prints out dash except for last node
                    printf("%d", temp->value);
                }
                else {
                    printf("%d - ", temp->value);
                }
                temp = temp->next;
        }
        printf("\n");
}

// Creates new node on heap from value
node_t *newNode(int value) {
    node_t *result = malloc(sizeof(node_t));    // Allocates memory for new node
    result->value = value;                      // Assigns value to new node
    result->next = NULL;                        // Initializes default next to null
}

// Adds node to head (front) of list
node_t *appendHead(node_t **head, node_t *item) {
    item->next = *head;     // Orders item before head
    *head = item;           // Makes item new head
    return item;
}

// Adds node after given node in list
void appendAfterNode(node_t *indexNode, node_t *insertNode) {
    insertNode->next = indexNode->next;
    indexNode->next = insertNode;
}

// Locates node with given value in list
node_t *findNode(node_t *head, int val) {
    node_t *temp = head;
    
    // Traverse list
    while (temp != NULL) { 
        if (temp->value == val)
            return temp;
        temp = temp->next;
    }
    
    // Return NULL if val not found
    return NULL;
}

/** MAIN **/
int main() {
    node_t *head = NULL;
    node_t *temp;
    
    // Nodes with values 0-24
    for (int i = 0; i < 25; i++) {
            temp = newNode(i);
            head = appendHead(&head, temp);
    }

    // Find node with value 13
    temp = findNode(head, 13);
    printf("Found node with value %d\n", temp->value);
    
    // Inserts node 75 after 13
    appendAfterNode(temp, newNode(75));
    
    // Prints out linked list by traversing through from head
    printList(head);
    return 0;
}
