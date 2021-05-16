/*
 -------------------------------------
 File:    R1.c
 Project: R1
 Week 1 Reading
 -------------------------------------
 Author:  Aleksa Dunovic
 ID:      140271610
 Email:   duno1610@mylaurier.ca
 Version  2021-05-15
 -------------------------------------
 */
# include<stdio.h>
# include <limits.h>

void welcome();
void get_price();
void formatting();
int data_size();

int main() {
	setbuf(stdout, NULL);
	welcome();
	printf("\n");
	get_price();
	formatting();
	data_size();
	return 0;
}

void welcome() {
	printf("Hello C World!\n");
	printf("This is my first program!\n");

	return;
}

//Calculate the total price for a purchase
void get_price() {
	const int TAX = 13;
	float price, total;
	int quantity;
	char name[20];

	printf("Enter product price: ");
	scanf("%f", &price);

	printf("Enter number of purchased items: ");
	scanf("%d", &quantity);

	printf("Enter product name: ");
	scanf("%s", name);

	total = price * quantity;
	total = total + total * TAX / 100;
	printf("Total price for buying %d items of %s after tax is $%.2f", quantity,
			name, total);
	return;
}

void formatting() {
	char area_code = 'r';
	unsigned int heat_peak = 32;
	char cold_peak = -23;
	char area_name[] = "PiTown";
	short distance = 3430;
	unsigned long phone = 1119994444;
	const float PI = 3.14159274;
	const double PI_PRECISE = 3.1415926535897931;
	printf("I live in %s ", area_name);
	printf("in the area code %c ", area_code);
	printf("which is %hd yards from the metro station\n\n", distance);

	printf(
			"The first letter of my city is '%c' and the second letter is '%c'.\n",
			area_name[0], area_name[1]);
	printf("This is the same as the mathematical constant \"PI\"\n\n");
	printf("In math, the value of PI to seven digits = %.8f ", PI);
	printf("and to 16 digits is %.16lf\n\n", PI_PRECISE);

	printf("The coldest temperature in %s is %d while the hottest is %u\n\n",
			area_name, cold_peak, heat_peak);
	printf("If you ever visit %s call me at my cell number \"%lu\"", area_name,
			phone);
	return;
}

int data_size() {
	printf("%-25s%-10s%-25s%-25s\n", "Data Type", "Bytes", "Min", "Max");
	printf(
			"-------------------------------------------------------------------------------\n");
	printf("%-25s%-10d%-25d%-25d\n", "char", sizeof(char), CHAR_MIN, CHAR_MAX);
	printf("%-25s%-10d%-25d%-25d\n", "unsigned char", sizeof(unsigned char), 0,
	UCHAR_MAX);
	printf("\n");
	printf("%-25s%-10d%-25d%-25d\n", "short", sizeof(short), SHRT_MIN,
	SHRT_MAX);
	printf("%-25s%-10d%-25d%-25d\n", "unsigned short", sizeof(unsigned short),
			0,
			USHRT_MAX);
	printf("\n");
	printf("%-25s%-10d%-25d%-25d\n", "int", sizeof(int), INT_MIN, INT_MAX);
	printf("%-25s%-10d%-25d%-25u\n", "unsigned int", sizeof(unsigned), 0,
	UINT_MAX);
	printf("\n");
	printf("%-25s%-10d%-25ld%-25lu\n", "long", sizeof(long), LONG_MIN,
	LONG_MAX);
	printf("%-25s%-10d%-25d%-25lu\n", "unsigned long", sizeof(unsigned long), 0,
	ULONG_MAX);
	printf("\n");
	printf("%-25s%-10d%-25I64d%-25I64d\n", "long long", sizeof(long long),
	LLONG_MIN, LLONG_MAX);
	printf("%-25s%-10d%-25d%-25I64u\n", "unsigned long long",
			sizeof(unsigned long long), 0, (unsigned long long) ULLONG_MAX);
	return 0;
}

