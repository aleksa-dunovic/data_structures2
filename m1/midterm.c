/* CP264 Spring 2021 Midterm */

/*
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

/**
 * ---------------------------------
 * I certify that I completed the midterm according to academic honesty guidelines.
 * I attest that I did not use any external help, neither in person nor virtually.
 * I understand that plagiarizing will lead to my failure in the course, in addition to
 * other penalties according to the University policies.
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 * If you have any comments to the instructor
 * put it in this box
 *
 * ---------------------------------
 */

//---- Do not change imports -----------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "midterm.h"
//---------------------------------------------

//----------------- Task 1 ---------------------
int replace_char(char *file_name, char letter1, char letter2) {
	FILE *in_file;
	int counter;
	int matches = 0;
	char c;

	in_file = fopen(file_name, "r+");
	//file cant open
	if (in_file == NULL) {
		printf("Error (remove_letter): unable to open file %s\n", file_name);
		return -1;
	}

	//input is invalid
	if (!(isalpha(letter1) && !isalpha(letter2))) {
		printf("Error (remove_letter): invalid input characters\n");
		return -1;
	}

	//get the first character
	c = fgetc(in_file);
	counter = 0;

	//loop while c exists
	while (c) {
		//if we reach the new line char we need to increment the counter and move on to the next value
		//this code is very ugly if i had more time i would've combined into an if-else instead of using continue
		if (c == '\n') {
			c = fgetc(in_file);
			counter++;
			counter++;
			continue;
		}
		//check if the current letter matches any of cases of the provided letter
		if (tolower(c) == tolower(letter1) && toupper(c) == toupper(letter1)) {
			//if yes then we go to the current position marked by counter and update the letter
			fseek(in_file, counter, SEEK_SET);
			fprintf(in_file, "%c", letter2);
			fseek(in_file, 0, SEEK_CUR);
			matches++;
		}

		//get the next letter
		c = fgetc(in_file);

		// i don't think this is necessary because the while condition will fail either way, but i don't have the courage to change it now
		if (feof(in_file)) {
			break;
		}

		counter++;
	}
	fclose(in_file);
	return matches;

}

//----------------- Task 2 ---------------------
void update_array(int **array, const int size, int multiplier) {

	//check if multiplier is valid
	if (multiplier <= 0) {
		printf("Error (update_array): invalid multiplier\n");
		return;
	}

	int temp[size]; //stores original values of the array

	//fill the temp array
	for (int i = 0; i < size; i++) {
		temp[i] = (*array)[i];
	}

	//expand the array
	*array = (int*) realloc(*array, sizeof(int) * (size * multiplier));

	//iterate through and fill array based on new size
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < multiplier; j++) {
			(*array)[(i * multiplier) + j] = temp[i];
		}
	}

	return;
}

//----------------- Task 3 ---------------------
char* sentence_to_words(char *sentence) {
	char *s = NULL;
	int count = 0;
//case 1: null pointer
	if (!sentence) {
		printf("Error (sentence_to_words): invalid input\n");
		s = "";
		return s;
	}
//case 2: empty string
	if (strlen(sentence) == 0) {
		printf("This is an empty sentence\n");
		printf("No words found\n");
		s = "";
		return s;
	}

//determine number of words
	char *token = NULL, *temp = NULL;

	//created a copy of sentence so i can count the number of words before looping through
	char s1[strlen(sentence) + 1];
	strcpy(s1, sentence);

	token = strtok(s1, " ");
	while (token) {
		count++;
		token = strtok(NULL, " ");
	}

//case with one word
	if (count == 1) {
		printf("This is a single word sentence\n");
		token = strtok(sentence, " ");
		printf("word: %s\n", token);

		//allocate the memory for last
		int size = strlen(token);
		s = (char*) malloc((size + 1));
		for (int i = 0; i < size + 1; i++)
			s[i] = token[i];

// case with two or more words
	} else {
		printf("This is a multi-word sentence:\n");
		token = strtok(sentence, " ");
		count = 1;

		//loop through until the end of the sentence and print all words
		while (token) {
			temp = token;
			printf("word %d: %s\n", count, token);
			token = strtok(NULL, " ");
			count++;
		}

		//allocate the memory for last
		int size = strlen(temp);
		s = (char*) malloc((size + 1));
		for (int i = 0; i < size + 1; i++)
			s[i] = temp[i];
	}
	return s;
}

//----------------- Task 4 ---------------------
void update_pointers(float *array, const int size, float **ptr1, float **ptr2,
		char mode) {

//null array
	if (!array) {
		printf("Error (update_pointers): Null array\n");
		return;
	}

//size 0 or less
	if (size <= 0) {
		printf("Error (update_pointers): invalid size\n");
		return;
	}
//double pointers are null
	if (!(ptr1 && ptr2)) {
		printf("Error (update_pointers): invalid pointer\n");
		return;
	}

//double pointer references are null
	if (!(*ptr1 && *ptr2)) {
		printf("Error (update_pointers): invalid pointer\n");
		return;
	}
//mode invalid
	if (!(mode == 'a' || mode == 'z')) {
		printf("Error (update_pointers): invalid mode\n");

		return;
	}

	float min, max;
	min = array[0];
	max = array[0];

// figure out the min and max, then assign to pointers
	for (int i = 1; i < size; i++) {
		if (max < array[i]) {
			max = array[i];
			*ptr1 = &(array[i]);
		}
		if (min > array[i]) {
			min = array[i];
			*ptr2 = &(array[i]);
		}
	}

// flip the pointers for mode a
	if (mode == 'a') {
		float *temp;
		temp = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = temp;
	}
	return;
}

