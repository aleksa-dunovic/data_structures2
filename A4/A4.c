/*
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

#include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <stdlib.h>
# include "A4.h"

//-------------------------Task 1 ----------------------------

void format_city(char *city) {
	city[0] = toupper(city[0]);
	for (int i = 0; i < strlen(city); i++) {
		if (city[i] == ' ') {
			city[i + 1] = toupper(city[i + 1]);
			for (int j = i; j < strlen(city); j++) {
				city[j] = city[j + 1];
			}

		}
	}

	return;
}

void format_cities(char city_array[][MAX], const int size) {
	if (!city_array) {
		printf("Error(format_cities): array is NULL\n");
	} else if (size < 1) {
		printf("Error(format_cities): invalid size\n");
	} else {
		for (int i = 0; i < size; i++) {
			format_city(city_array[i]);
		}
	}
	return;
}

//-------------------------Task 2 ----------------------------

void format_str(const char *inStr, char *outStr) {
	if (!*inStr || !*outStr) {
		int middle, l, right;
		char temp;
		middle = strlen(inStr) / 2;

		printf("\tString Length = %d\n", strlen(inStr));

		// Middle Caps
		for (int i = 0; i < strlen(inStr); i++) {
			if (i != (strlen(inStr) - 1) && i != 0)
				outStr[i] = toupper(inStr[i]);
			else
				outStr[i] = tolower(inStr[i]);
		}
		printf("\tAfter middle caps = %s\n", outStr);

		// Split
		for (int i = strlen(inStr); i >= middle; i--) {
			outStr[i + 1] = outStr[i];
		}
		outStr[middle] = ' ';
		printf("\tAfter split = %s\n", outStr);

		// Left Reverse
		l = strlen(inStr) / 2;
		for (int i = 0; i < (l / 2); i++) {
			temp = outStr[i];
			outStr[i] = outStr[l - i - 1];
			outStr[l - i - 1] = temp;
		}
		printf("\tAfter First half reverse = %s\n", outStr);

		// Right Reverse
		if (strlen(inStr) % 2 == 0) {
			right = strlen(inStr) / 2;
		} else
			right = (strlen(inStr) / 2) + 1;

		for (int i = 0; i < right / 2; i++) {
			temp = outStr[l + 1 + i];
			outStr[l + 1 + i] = outStr[l + right - i];
			outStr[l + right - i] = temp;
		}
		printf("\tAfter Second half reverse = %s\n", outStr);
	}
	return;
}

//-------------------------Task 3 ----------------------------

int* get_multiples_array1(int *multiples, const int size) {
	if (!multiples) {
		printf("Error(get_multiples_array1): invalid array\n");
		return multiples;
	}
	if (size < 1) {
		printf("Error(get_multiples_array1): invalid size\n");
		return multiples;
	}

	int *arr = (int*) malloc(size * NUM * sizeof(int));

	int i, j, count;
	for (i = 0; i < size; i++) {
		count = 1;
		for (j = 0; j < NUM; j++) {
			*(arr + i * NUM + j) = 0;
			while (count < 1000) {
				if (count % *(multiples + i) == 0) {
					*(arr + i * NUM + j) = count;
					count++;
					break;
				} else
					count++;
			}

		}
	}

	return arr;
}

void print_multiples1(int *array, const int size) {
	if (!array) {
		printf("Error(print_multiples1): invalid array\n");
		return;
	}
	if (size < 1) {
		printf("Error(print_multiples1): invalid size\n");
		return;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < NUM; j++) {
			if (j != NUM - 1)
				printf("%3d ", *(array + i * NUM + j));
			else
				printf("%3d", *(array + i * NUM + j));
		}
		printf("\n");
	}
	return;
}

//-------------------------Task 4 ----------------------------
int** get_multiples_array2(int *multiples, const int size) {
//your solution here
	return NULL;
}

void print_multiples2(int **array, const int size) {
//your solution here
	return;
}
