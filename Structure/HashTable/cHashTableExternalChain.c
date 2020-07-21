// Implementation of Hash Table data structure in C
// Harris Ransom

/** Includes **/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/** Defines **/
#define TABLE_SIZE 10
#define DELETED_NODE (person*) (0xFFFFFFFFFFFFFFFFUL)
#define MAX_NAME 256    // Max name len

// Person item in table
typedef struct {
    char name[MAX_NAME]; // Used as hash input
    int age;
    //add other data later
    struct person *next;
} person;

person *hashTable[TABLE_SIZE]; // Hash table data structure of type person

/** Functions **/
// Hash function
unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hashVal = 0;

    // Totals ASCII values from string, then multiplies/maps value to index
    for (int i = 0; i < length; i++) {
        hashVal += name[i];
        hashVal = (hashVal * name[i]) % TABLE_SIZE;
    }
    return hashVal;
}

// Initializes table
void initHashTable() {
    // Empties table and initializes to null pointers
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Outputs table contents
void printTable() {
    printf("Start: \n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == NULL) {
            printf("\t%i\t---\n", i);
        }
        else {
            printf("\t%i\t", i);
            person *tmp = hashTable[i];
            while (tmp != NULL) {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End \n");
}

// Insert person into table
bool insert(person *p) {
    if (p == NULL) return false;            // If person is invalid
    int index = hash(p->name);              // Computes index with hash function
    p->next = hashTable[index];             // Adds person to linked list
    hashTable[index] = p;
    return true;                           
}

// Looks up person in table with name
person *lookup(char *name) {
    int index = hash(name);
    person *tmp = hashTable[index];
    while ((tmp != NULL) && (strncmp(tmp->name, name, MAX_NAME) != 0)) {
        tmp = tmp->next;
    }
    return tmp;
}

// Deletes person from table
person *deleteItem(char *name) {
    int index = hash(name);
    person *tmp = hashTable[index];
    person *prev = NULL;
    while ((tmp != NULL) && (strncmp(tmp->name, name, MAX_NAME) != 0)) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    if (prev == NULL) {
        hashTable[index] = tmp->next;// Deletes head
    }
    else {
        prev->next = tmp->next;
    }
    return tmp;
}

/** MAIN **/
int main() {
    initHashTable();
    printTable();

    person jacob  = {.name = "Jacob",  .age = 250};
    person kate   = {.name = "Kate",   .age = 26};
    person mpho   = {.name = "Mpho",   .age = 15};
    person sarah  = {.name = "Sarah",  .age = 53};
    person edna   = {.name = "Edna",   .age = 16};
    person maren  = {.name = "Maren",  .age = 25};
    person eliza  = {.name = "Eliza",  .age = 34};
    person robert = {.name = "Robert", .age = 2};
    person jane   = {.name = "Jane",   .age = 72};
 
    insert(&jacob);
    insert(&kate);
    insert(&mpho);
    insert(&sarah);
    insert(&edna);
    insert(&maren);
    insert(&eliza);
    insert(&robert);
    insert(&jane);
    printTable();

    // Finds Mpho (in table)
    person *tmp = lookup("Mpho");
    if (tmp == NULL) {
        printf("Not found!\n");
    }
    else {
        printf("Found %s\n", tmp->name);
    }

    // Finds George (not in table)
    tmp = lookup("George");
    if (tmp == NULL) {
        printf("Not found!\n");
    }
    else {
        printf("Found %s\n", tmp->name);
    }

    // Deletes Mpho
    deleteItem("Mpho");
    tmp = lookup("Mpho");
    if (tmp == NULL) {
        printf("Not found!\n");
    }
    else {
        printf("Found %s\n", tmp->name);
    }
    printTable();

    return 0;
}