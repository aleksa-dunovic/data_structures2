#include <stdio.h>
#include "R4.h"

void test_pointers1();
void test_pointers2();
void test_swap1();
void test_swap2();

int main() {
	setbuf(stdout, NULL);
//	test_pointers1();
//	test_pointers2();
	test_swap1();
	test_swap2();

	return 0;
}

void test_pointers1() {
	printf("------------------------------\n");
	printf("Start: Testing learn_pointers1:\n\n");
	learn_pointers1();
	printf("\n");

	printf("End: Testing learn_pointers1\n");
	printf("------------------------------\n");
	return;
}

void test_pointers2() {
	printf("------------------------------\n");
	printf("Start: Testing learn_pointers2:\n\n");
	learn_pointers2();
	printf("\n");

	printf("End: Testing learn_pointers2\n");
	printf("------------------------------\n");
	return;
}

void test_swap1() {
	int x = 10, y = 20;
	printf("------------------------------\n");
	printf("Start: Testing swap1:\n\n");
	swap1(x, y);
	printf("x = %d, y = %d", x, y);
	printf("\n");

	printf("End: Testing swap1\n");
	printf("------------------------------\n");
	return;
}

void test_swap2() {
	int x = 10, y = 20;
	printf("------------------------------\n");
	printf("Start: Testing swap1:\n\n");
	swap2(&x, &y);
	printf("x = %d, y = %d", x, y);
	printf("\n");

	printf("End: Testing swap1\n");
	printf("------------------------------\n");
	return;
}
