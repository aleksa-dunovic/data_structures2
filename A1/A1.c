/**
 * -------------------------
 * Student Name: Aleksa Dunovic
 * Student ID: 140271610
 * Student email: duno1610@mylaurier.ca
 * -------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <time.h>
# include <stdbool.h>

/**
 * CP264: Assignment 1 - Task 1
 * @param base_height
 * @param base_length
 * @param roof_height
 * @param door_height
 * @param door_length
 */

void calculate_cost(float base_height, float base_length, float roof_height,
		float door_height, float door_length) {

	// prices of materials
	float concrete = 84.79;
	float shingles = 11.91;
	float wood = 8.73;

	// area needed for each material
	float roof_area = base_length * roof_height * (0.5);
	float base_area = base_length * base_height - door_height * door_length;
	float door_area = door_height * door_length;

	// cost of each material
	float roof_cost = roof_area * shingles;
	float base_cost = base_area * concrete;
	float door_cost = door_area * wood;

	// print dimensions of house
	printf("House Drawing dimensions (meters):\n");
	printf("BH = %-9.3f", base_height);
	printf("BL = %-8.3f\n", base_length);
	printf("RH = %-8.3f", roof_height);
	printf("\nDH = %-9.3f", door_height);
	printf("DL = %-8.3f\n", door_length);

	// print are of each section
	printf("\nHouse dimensions (square meter):\n");
	printf("Door area = %8.3f\n", door_area);
	printf("Base area = %8.3f\n", base_area);
	printf("Roof area = %8.3f\n", roof_area);

	// print cost of each section and total cost
	printf("\nHouse cost (CAD):\n");
	printf("Door cost = $%8.3f\n", door_cost);
	printf("Base cost = $%8.3f\n", base_cost);
	printf("Roof cost = $%8.3f\n", roof_cost);
	printf("--------------------\n");
	printf("Total cost = $%.3f\n", door_cost + base_cost + roof_cost);
	return;
}

/**
 * CP264: Assignment 1 - Task 2
 *  [-:0):           Invalid
 *	[0:20):           No Promotion
 *	[20-35]:          Level 1 Promotion
 *	(35-50]:          Level 2 Promotion
 *	(50-100]:         No Promotion
 *	(100-200]+VIP:    Gold Promotion
 *	(100-200]-VIP:    Silver Promotion
 *	(200, -]:         Special Promotion
 * @param ticket
 * @param vip
 */
void find_promotion(short ticket, char vip) {
	if (vip == 'Y')
		printf("Ticket# VIP-%hd: ", ticket);
	else
		printf("Ticket# %hi: ", ticket);
	if (ticket < 0 || (vip != 'Y' && vip != 'N'))
		printf("Error(find_promotion): Invalid input - Code# -99");
	else if (ticket < 20 || (ticket > 50 && ticket <= 100))
		printf("No Promotion - Code# 0");
	else if (ticket <= 35 && ticket >= 20)
		printf("Level 1 Promotion - Code# 130");
	else if (ticket >= 35 && ticket <= 50)
		printf("Level 2 Promotion - Code# 240");
	else if (ticket > 100 && ticket <= 200 && vip == 'N')
		printf("Silver Promotion - Code# 700");
	else if (ticket > 100 && ticket <= 200 && vip == 'Y')
		printf("Gold Promotion - Code# 1110");
	else if (ticket > 200)
		printf("Special Promotion - Code# 3333");

	return;
}

/**
 * Assignment 1 - Task 3
 * @param num1 (short int)
 * @param num2 (short int)
 * @param opr + , - , * , / , % , ^ (char)
 * @return result (int)
 */
int mini_calculator(short num1, short num2, char opr) {
	int result;

	// If the operator is invalid goto Illegal
	if (opr != '+' && opr != '-' && opr != '*' && opr != '/' && opr != '%'
			&& opr != '^') {
		goto Illegal;
	}

	// Addition
	if (opr == '+')
		result = num1 + num2;

	// Subtraction
	if (opr == '-')
		result = num1 - num2;

	// Multiplication
	if (opr == '*')
		result = num1 * num2;

	// Division
	if (opr == '/') {
		// Cannot divide by 0
		if (num2 == 0)
			goto Illegal;
		result = num1 / num2;
	}

	// Modulus
	if (opr == '%') {
		// Cannot divide by 0
		if (num2 == 0)
			goto Illegal;
		// If either operand is negative do regular division
		if (num1 < 0 || num2 < 0) {
			result = num1 / num2;
			goto Finish;
			// Skips the Illegal step
		}
		result = num1 % num2;
	}

	// Exponent
	if (opr == '^') {
		// Second operand cannot be 0 or less
		if (num2 < 0)
			goto Illegal;
		result = pow(num1, num2);
	}

	goto Finish;
	// Allows us to skip the Illegal step

	Illegal: result = -99; // Sets the value -99 for all Illegal operations

	Finish: return result;
}

/**
 * Assignment 1 - Task 4
 * @param num1
 * @param num2
 * @param opr
 */
void mini_calculator2(short num1, short num2, char opr) {

	long result;

	printf("%hd %c %hd = ", num1, opr, num2);
	if ((num2 == 0 && (opr == '/' || opr == '%'))
			|| (opr != '+' && opr != '-' && opr != '*' && opr != '/'
					&& opr != '%' && opr != '^')) {
		printf("ERROR\n");
		return;
	}

	// Addition
	if (opr == '+')
		result = num1 + num2;

	// Subtraction
	if (opr == '-')
		result = num1 - num2;

	// Multiplication
	if (opr == '*')
		result = num1 * num2;

	// Division
	if (opr == '/') {
		if (num1 % num2 != 0) {
			printf("%.4f\n", (float) num1 / num2);
			return;
		}
		result = num1 / num2;
	}

	// Modulus
	if (opr == '%')
		result = num1 % num2;

	// Exponent
	if (opr == '^') {
		if (num2 < 0) {
			printf("%.4f\n", pow((float) num1, num2));
			return;
		}
		result = pow(num1, num2);
	}

	if (result > INT_MAX || result < INT_MIN)
		printf("OVERFLOW\n");
	else
		printf("%ld\n", result);

	return;
}

