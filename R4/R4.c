/**
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>

void learn_pointers1() {
	int x = 10, *ptr1 = &x;
	double y = 10.5;
	double *ptr2 = &y;

	printf("int x = 10, ptr1 = &x;\n");
	printf("Printing x = %d\n", x);
	printf("Printing &x in hex= %p and in decimal = %lu\n", &x,
			(unsigned long) &x);

	printf("Printing *(&x) = %d\n", *(&x));
	printf("Printing sizeof(x) = %d\n", sizeof(x));

	printf("Printing *ptr1 = %d\n", *ptr1);
	printf("Printing ptr1 in hex = %p and in decimal =%lu\n", ptr1,
			(unsigned long) ptr1);

	printf("Printing &ptr1 in hex = %p and in decimal = %lu\n", &ptr1,
			(unsigned long) &ptr1);
	printf("Printing sizeof(ptr1) = %d\n", sizeof(ptr1));
	printf("Printing sizeof(*ptr1) = %d\n", sizeof(*ptr1));

	printf("\n");
	printf("double y = 10.5, ptr2 = &y;\n");
	printf("Printing y = %.2f\n", y);
	printf("Printing &y in hex= %p and in decimal = %lu\n", &y,
			(unsigned long) &y);

	printf("Printing *(&y) = %.2f\n", *(&y));
	printf("Printing sizeof(y) = %d\n", sizeof(y));

	printf("Printing *ptr2 = %.2f\n", *ptr2);
	printf("Printing ptr2 in hex = %p and in decimal =%lu\n", ptr2,
			(unsigned long) ptr2);

	printf("Printing &ptr1 in hex = %p and in decimal = %lu\n", &ptr2,
			(unsigned long) &ptr2);
	printf("Printing sizeof(ptr2) = %d\n", sizeof(ptr2));
	printf("Printing sizeof(*ptr2) = %d\n", sizeof(*ptr2));

}

void learn_pointers2() {
	int x[3] = { 10, 20, 30 };
	int *ptr1 = x;

	printf("x[3]= { 10, 20, 30 }, *ptr1 = x;\n");
	printf("Printing x[0] = %d\n", x[0]);
	printf("Printing x = %lu\n", (unsigned long) x);
	printf("Printing &x in hex= %p and in decimal = %lu\n", &x,
			(unsigned long) &x);
	printf("Printing sizeof(x) = %d\n", sizeof(x));
//
	printf("Printing *ptr1 = %d\n", *ptr1);
	printf("Printing ptr1 in hex = %p and in decimal =%lu\n", ptr1,
			(unsigned long) ptr1);

	printf("Printing &ptr1 in hex = %p and in decimal = %lu\n", &ptr1,
			(unsigned long) &ptr1);
	printf("Printing sizeof(ptr1) = %d\n", sizeof(ptr1));
	printf("Printing sizeof(*ptr1) = %d\n", sizeof(*ptr1));
//
	printf("*ptr1[1] = %d\n", ptr1[1]);
	printf("*(ptr1 + 2) = %d\n", *(ptr1 + 2));
	printf("*(x + 2) = %d\n", *(x + 2));
	ptr1++;
	printf("Printing *ptr1 after ptr++ = %d\n", *ptr1);
	ptr1--;
	printf("Printing *ptr1 after ptr-- = %d\n", *ptr1);
	ptr1 = &x[2];
	printf("Printing *ptr1 after ptr1=&x[2]; = %d\n", *ptr1);
	(*ptr1)++;
	printf("Printing *ptr1 after (*ptr1)++; = %d\n", *ptr1);

}

void swap1(int num1, int num2) {
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
	return;
}

/**
 * x = 10 /0xAA
 * y = 20 //0xBB
 *
 * int *ptr1 = &x, *ptr2 = &y;
 * ptr1 = 0xAA;
 * ptr1 --> x;
 * ptr2 = 0xBB
 * ptr --> y;
 *
 * swap2( ptr1, ptr2)
 */
void swap2(int *num1, int *num2) {
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	return;
}

void reverse_array(int *array, const int size) {
	if (array == NULL) {
		printf("Error(reverse_array): NULL pointer\n");
		return;
	}
	if (size <= 0) {
		printf("Error(reverse_array): invalid size\n");
		return;
	}

	int i, temp[size];

	for (i = 0; i < size; i++)
		temp[i] = array[size - i - 1];
	for (i = 0; i < size; i++)
		array[i] = temp[i];

	return;
}
