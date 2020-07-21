// Reverses a given string, implemented in C
// Harris Ransom

/** Includes **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Defines **/
#define MAX_STRING 50
#define STRING_ARG 1

/** Functions **/
char* revStr(const char str[]) {
	int len = (int) strlen(str);				// Gets length of string param
	char *retStr = malloc(len * sizeof(char));	// Allocates space for retStr on heap
	int count = 0;                              // Counter for forward iteration

	// Iterates backwards through str
	for (int i = len - 1; i >= 0; i--) {
		retStr[count] = str[i];
		count++;
	}
	return retStr;
}

/** MAIN **/
int main (int argc, const char *argv[]) {
	// Gets string length
	int len = (int) strlen(argv[STRING_ARG]);

	// Detects how many arguments were passed in
	if ((argc - 1) > 1) {
		printf("Error: Too many arguments (%d), max 1", argc - 1);
		return 1;
	}
	else if ((argc - 1) < 1) {
		printf("Error: Too few arguments (%d), min 1", argc - 1);
		return 1;
	}

	// Detects size of argv[STRING_ARG]
	if (len > MAX_STRING) {
		printf("Error: String size (%d) greater than max string size (%d)", len, MAX_STRING);
		return 1;
	}

	// Reverses string
	char *str;
	str = revStr(argv[STRING_ARG]);
	printf("Reversed string: %s", str);

	return 0;
}
