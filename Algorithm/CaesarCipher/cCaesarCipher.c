// Implements a Caesar Cipher in C
// Harris Ransom

/** Includes **/
#include <stdio.h>
#include <string.h>

/** Functions **/
// Shifts given character by given key
char cipher(char letter, int key) {
	if (letter >= 'a' && letter <= 'z') {		 // Uppercase
		letter += key;
		if (letter > 'z') {
			letter = letter - 'z' + 'a' - 1; // Loops character around
		}
		
	}
	else if (letter >= 'A' && letter <= 'Z') {	 // Lowercase
		letter += key;
		if (letter > 'Z') {
			letter = letter - 'Z' + 'A' - 1; // Loops character around
		} 
	}
	return letter;
}

// Unshifts given character by given key
char decipher(char letter, int key) {
	if (letter >= 'a' && letter <= 'z') {		 // Uppercase
		letter -= key;
		if (letter < 'a') {
			letter = letter + 'z' - 'a' + 1; // Loops character around
		}
		
	}
	else if (letter >= 'A' && letter <= 'Z') {	 // Lowercase
		letter -= key;
		if (letter > 'a') {
			letter = letter + 'Z' - 'A' + 1; // Loops character around
		} 
	}
	return letter;
}

/** MAIN **/
int main(int argc, char **argv) {
	// Input
	char message[100];
	int key;
	printf("Enter message to cipher: ");
	fgets(message, 100, stdin);
	printf("Enter shift value (key): ");
	scanf("%d", &key);	
	
	// Ciphers (encrypts)
	for (int i = 0; message[i] != '\0'; i++) {
		message[i] = cipher(message[i], key);
	}
	printf("Message after cipher: %s", message);
	
	// Deciphers (decrypts)
	for (int i = 0; message[i] != '\0'; i++) {
		message[i] = decipher(message[i], key);
	}
	printf("Decrypted message: %s", message);
	return 0;
}

