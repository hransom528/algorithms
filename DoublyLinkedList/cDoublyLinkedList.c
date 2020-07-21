// Linked List data structure implementation in C with ints
// Harris Ransom

/** Includes **/
#include <stdio.h>
#include <stdlib.h>

/** Defines **/
// Node type, one item in list
struct node {
        int value;
        struct node *next;
        struct node *prev;
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
    result->prev = NULL;                        // Initializes default prev to null
}

// Adds node to head (front) of list
node_t *appendHead(node_t **head, node_t *item) {
    item->next = *head;          // Orders item before head
    if (*head != NULL) {
        (*head)->prev = item;   // Orders head after item
    }
    *head = item;               // Makes item new head
    item->prev = NULL;           // Makes head prev null
    return item;
}

// Adds node after given node in list
void appendAfterNode(node_t *indexNode, node_t *insertNode) {
    insertNode->next = indexNode->next;
    if (insertNode->next != NULL) {
        insertNode->next->prev = indexNode;
    }
    insertNode->prev = indexNode;
    indexNode->next = insertNode;
}

// Removes node from list
void removeNode(node_t **head, node_t *removal) {
        
        if (*head == removal) {
            *head = removal->next;
            if (*head != NULL) {
                (*head)->prev = NULL;
            }
            return;
        }
        else {
                removal->prev->next = removal->next;
                if (removal->next != NULL) { 
                        removal->next->prev = removal->prev;
                }
        }
        removal->next = NULL;
        removal->prev = NULL;
        free(removal);
        return;
}

// Clears entire linked list
void clearList(node_t **head) {
    node_t *current = *head;
    node_t *next = (*head)->next;
    while (next != NULL) {  
        removeNode(head, current);
        current = next;
        next = current->next;
    }
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
    
    // Prints out linked list
    printList(head);
    
    // Removes 13 and head
    removeNode(&head, temp);
    removeNode(&head, head);
    printf("Removed node with value 13 and head node\n");
    
    // Prints out list after removal
    printList(head);
    
    // Clears list
    clearList(&head);
    printf("List cleared");
    
    return 0;
}
