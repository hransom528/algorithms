#ifndef C_HASHTAB_OPENADDRESS
#define C_HASHTAB_OPENADDRESS

// Max name len
#define MAX_NAME 256

// Person item in table
typedef struct {
    char name[MAX_NAME]; // Used as hash input
    int age;
    //add other data later
} person;

unsigned int hash(char *name);

void initHashTable();

void printTable();

bool insert(person *p);

person *lookup(char *name);

person *deleteItem(char *name);
#endif