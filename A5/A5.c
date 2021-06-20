/*
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

#include <stdio.h>
#include "A5.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//---------------------- Task 1 ---------------------------------
void analyze_file(const char *filename, const char *filename2) {
	int count[7] = { 0 };
	int check = 0;
	count[0] = 1;
	count[1] = 1;
	char *token;
	FILE *f1;

	// Open file
	f1 = fopen(filename, "r");
	if (f1 == NULL) {

		printf("Error(analyze_file): Could not open file %s\n", filename2);
		return;
	}

// Read file

	while (fgets(token, 2, f1) != NULL) {
		if (*token == '\n') {
			if (check == 1)
				count[0]++;
			count[1]++;
			check = 1;
		} else {
			check = 0;
		}

		if (*token == ' ')
			count[2]++;

		if (*token != '\n' && *token != ' ' && *token != '\0') {
			count[3] = count[3] + 1;
			if (isalpha(*token)) {
				count[4]++;
			} else if (isdigit(*token)) {
				count[5]++;
			} else {
				count[6]++;
			}

		}

	}
	count[2] = count[2] + count[1] - count[0] + 1;
	fclose(f1);

//Write to file
	FILE *f2 = NULL;
	f2 = fopen(filename2, "a");
	fseek(f2, 1, SEEK_END);
	if (f2 == NULL) {
		printf("Error(analyze_file): Could not open file %s\n", filename2);
		return;
	}
	fprintf(f2, "Analyzing file %s:\n", filename);
	fprintf(f2, "#Paragraphs = %d\n", count[0]);
	fprintf(f2, "#lines = %d\n", count[1]);
	fprintf(f2, "#Words = %d\n", count[2]);
	fprintf(f2, "#Characters = %d\n", count[3]);
	fprintf(f2, "Alpha = %d\n", count[4]);
	fprintf(f2, "Numerical = %d\n", count[5]);
	fprintf(f2, "Other = %d\n\n", count[6]);

	fclose(f2);
	return;
}

//---------------------- Task 2 ---------------------------------
void format_file1(const char *in_file, const char *out_file) {
//your code here
	return;
}

//---------------------- Task 3 ---------------------------------
void format_file2(const char *in_file, const char *out_file) {
//your code here
	return;
}

//---------------------- Task 4 ---------------------------------
void get_city_details(const char *in_file, const char *out_file, char *city) {
//your code here
	return;
}

//---------------------- Task 5 ---------------------------------
void replace_is(const char *filename, char *new_str) {
//your code here
	return;
}

