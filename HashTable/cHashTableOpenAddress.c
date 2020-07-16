// Implementation of Hash Table data structure in C
// Harris Ransom

/** Includes **/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "cHashTableOpenAddress.h"

/** Defines **/
#define TABLE_SIZE 10
#define DELETED_NODE (person*) (0xFFFFFFFFFFFFFFFFUL)

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
        else if (hashTable[i] == DELETED_NODE) {
            printf("\t%i\t---<deleted>\n", i);
        }
        else {
            printf("\t%i\t%s\n", i, hashTable[i]->name);
        }
    }
    printf("End \n");
}

// Insert person into table
bool insert(person *p) {
    if (p == NULL) return false;            // If person is invalid
    int index = hash(p->name);              // Computes index with hash function
    for (int i = 0; i < TABLE_SIZE; i++) {  // Linear probing
        int try = (i + index) % TABLE_SIZE;
        if ((hashTable[try] == NULL) || (hashTable[try] == DELETED_NODE)) {       // Open spot found, insert person
            hashTable[try] = p;
            return true;
        }
    }
    return false;                           // No spot found
}

// Looks up person in table with name
person *lookup(char *name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;
        if (hashTable[try] == NULL)
            return NULL; // Not here
        if (hashTable[try] == DELETED_NODE) continue;
        if ((hashTable[try] != NULL) && (strncmp(hashTable[try]->name, name, MAX_NAME) == 0)) {
            return hashTable[try];
        }
    }
    return NULL; // Person not found
}

// Deletes person from table
person *deleteItem(char *name) {
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int try = (index + i) % TABLE_SIZE;
        if (hashTable[try] == NULL)
            return NULL; // Not here
        if (hashTable[try] == DELETED_NODE) continue;
        if ((hashTable[try] != NULL) && (strncmp(hashTable[try]->name, name, MAX_NAME) == 0)) {
            person *tmp = hashTable[try];
            hashTable[try] = DELETED_NODE;
            return tmp;
        }
    }
    return NULL; // Person not found
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