/*
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char* encrypt(char *plaintext, int key) {
	if (key < 0) {
		printf("Error(encrypt): key cannot be negative\n");
		return plaintext;
	}

	//allocate memory for cipher
	int size = strlen(plaintext);
	char *cipher = (char*) malloc(size + 1);

	//handle keys greater than 26
	int n = key % 26;

	int i = 0;
	while (plaintext[i]) {
		//check if char is letter
		if (isalpha(plaintext[i])) {

			//check if the char is lowercase and apply shift
			if (tolower(plaintext[i]) == plaintext[i]) {
				cipher[i] = (((plaintext[i] - 'a') + n) % 26) + 'a';

			} //check if the char is uppercase, apply shift, and transform to upper
			else {
				cipher[i] = toupper(
						(((tolower(plaintext[i]) - 'a') + n) % 26) + 'a');
			}
		} else {
			cipher[i] = plaintext[i];
		}
		i++;
	}
	cipher[size] = '\0'; //add null char at the end

	return cipher;
}

char* decrypt(char *ciphertext, int key) {
	if (key < 0) {
		printf("Error(decrypt): key cannot be negative\n");
		return ciphertext;
	}

	//allocate memory for plaintext
	int size = strlen(ciphertext);
	char *plain = (char*) malloc(size + 1);

	//handle keys greater than 26
	char n = key % 26;

	int i = 0;
	while (ciphertext[i]) {
		//check if char is letter
		if (isalpha(ciphertext[i])) {
			//check if the char is lowercase and apply shift
			if (tolower(ciphertext[i]) == ciphertext[i]) {
				plain[i] = (((ciphertext[i] - 'a') + (26 - n)) % 26) + 'a';
			} //check if the char is uppercase, apply shift, and transform to upper
			else {
				plain[i] = toupper(
						(((tolower(ciphertext[i]) - 'a') + (26 - n)) % 26)
								+ 'a');
			}

		} else {
			plain[i] = ciphertext[i];
		}
		i++;
	}
	plain[size] = '\0'; //add null char at the end

	return plain;
}

//	printf("Test: %c\n", ((('x' - 'a') + 5) % 26) + 'a');
