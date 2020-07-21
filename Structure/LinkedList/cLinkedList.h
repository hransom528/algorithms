#ifndef C_LINKED_LIST 
#define C_LINKED_LIST

// Node type, represents one item in list
struct node {
        int value;
        struct node* next;
};
typedef struct node node_t;

void printList(node_t *head);

node_t *newNode(int value);

node_t *appendHead(node_t **head, node_t *item);

void appendAfterNode(node_t *indexNode, node_t *insertNode);

void removeNode(node_t **head, node_t *removal);

node_t *findNode(node_t *head, int val);
#endif
