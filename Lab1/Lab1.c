/*
 -------------------------
 Student Name: Aleksa Dunovic
 Student ID: 140271610
 Student email: duno1610@mylaurier.ca
 -------------------------
 */
# include<stdio.h>

// prototypes
void t1();
void t2();
void t3();

int main() {
	setbuf(stdout, NULL);
	t1();
	printf("\n");
	t2();
	printf("\n");
	t3();
	return 0;
}

void t1() {
//	Define variables
	int total, tall_trees, short_trees;
	char symbol = 84;
	const int val = 43;

// Get input
	printf("Enter number of tall trees: ");
	scanf("%d", &tall_trees);
	printf("Enter number of short trees: ");
	scanf("%d", &short_trees);
	total = tall_trees + short_trees;

// Print report
	printf("Number of %c trees = %d\n", symbol, tall_trees);
	printf("Number of %c trees = %d\n", (symbol - 1), short_trees);
	printf("Average height = %.2lf\n", ((double) val / total));
	return;
}

void t2() {
// Define variables
	unsigned int year;
	short month;
	int day;
	char university[30];

// Get input
	printf("Enter year: ");
	scanf("%u", &year);
	printf("Enter month: ");
	scanf("%hd", &month);
	printf("Enter day: ");
	scanf("%d", &day);
	printf("Enter University: ");
	scanf("%s", university);
	printf("\n");

// Print report
	printf("This is %s University\n", university);
	printf("Today is: %d/%d/%u\n", day, month, year);
	return;
}

void t3() {
// Print and format output
	printf("Hints for C Language:\n");
	printf("Insert \\n at end of printf for newline.\n");
	printf("Use \"double quote\" not 'single quotes' for strings.\n");
	printf("Use %%d for integer, %%f for float and %%lf for double.\n");
	return;
}
