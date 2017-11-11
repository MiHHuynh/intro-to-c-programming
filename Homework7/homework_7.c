#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void clearstream();

//gets number and handles errors
//input: none, returns valid number in form of float
static bool getNumber(float*);

//gets operator symbol and handles errors
//input: none, returns valid operator in form of char
static bool getOperator(char*);

static void ignoreWhiteSpace();

static void calculate(float, float, char);

static void exitOnEnter();

//solution1 is the easier and more straightforward solution to the problem
static void solution1();

//However, solution2 is more flexible in the case that you need to chain more than 2 numbers in the equation.
static void solution2();

int main(void) {

	//solution1();

	solution2();
}

static void solution1() {
	float num1;
	float num2;
	char op;

	printf("Welcome to Michelle Huynh's Advanced Calculator. Please enter a valid equation followed by enter:\n");
	while (1) {
		int res = scanf(" %f %c %f", &num1, &op, &num2);
		while (res != 3) {
			printf("\nNot a valid equation.\n");
			printf("Please enter a valid equation and press enter, or, press enter to exit.\n");
			exitOnEnter();
			res = scanf(" %f %c %f", &num1, &op, &num2);
		}
		calculate(num1, num2, op);
		printf("Please enter a valid equation and press enter, or, press enter to exit.\n");
		exitOnEnter();
	}

}

static void solution2() {
	float num1;
	float num2;
	char op;
	bool isNum1Successful = false;
	bool isOpSuccessful = false;
	bool isNum2Successful = false;

	printf("Welcome to Michelle Huynh's Advanced Calculator. Please enter a valid equation followed by enter:\n");

	while (1) {
		isNum1Successful = getNumber(&num1);
		isOpSuccessful = getOperator(&op);
		isNum2Successful = getNumber(&num2);

		if (!isNum1Successful || !isOpSuccessful || !isNum2Successful) {
			printf("\nNot a valid equation.\n");
			printf("Please enter a valid equation and press enter, or, press enter to exit.\n");
			exitOnEnter();
		}
		else {
			calculate(num1, num2, op);
			printf("Please enter a valid equation and press enter, or, press enter to exit.\n");
			exitOnEnter();
		}
	}
}

static void exitOnEnter() {
	clearstream();
	char enter;
	enter = getchar();
	if (enter == '\n') {
		exit(1);
	}
	else {
		ungetc(enter, stdin);
	}
}

static void clearstream() {
	char c;
	do { c = getchar(); } while (c != '\n' && c != EOF);
}

static void ignoreWhiteSpace() {
	char c;
	do { c = getchar(); } while (c == ' ');
	ungetc(c, stdin);
}

static bool getNumber(float *pNum1) {
	int res = 0;
	res = scanf(" %f", pNum1);
	if (res == EOF) {
		printf("Input stream closed. Exiting.\n");
		return false;
	} else if (res != 1) {
		  // if input is not valid, return 0, or false, to indicate input for num1 was unsuccessful
		return false;
	}
	 // at this point, input for num1 was successful, so 1/true is returned
	return true;
}

static bool getOperator(char *pOp) {
	const int res = scanf(" %c ", pOp);
	if (res == EOF) {
		printf("Input stream closed. Exiting.\n");
		return false;
	} else if (res != 1) {
		  // if input is not valid, return 0, or false, to indicate input for num1 was unsuccessful
		clearstream();
		return false;
		  // clear stream by consuming rest of characters so next scanf can take in fresh values
		  // at this point, stdin is empty.
	}
	 // at this point, input for num1 was successful, so 1/true is returned
	return true;
}

static void calculate(float num1, float num2, char op) {
	switch(op) {
		case '+':
		printf("%.2f %c %.2f = %.2f\n", num1, op, num2, num1+num2);
		break;
		case '-':
		printf("%.2f %c %.2f = %.2f\n\n", num1, op, num2, num1-num2);
		break;
		case '*':
		printf("%.2f %c %.2f = %.2f\n\n", num1, op, num2, num1*num2);
		break;
		case '/':
		if (num2 == 0 && num1 != 0) {
			printf("You can't divide by zero.\n\n");
			break;
		}
		else {
			printf("%.2f %c %.2f = %.2f\n\n", num1, op, num2, num1/num2);
			break;
		}
	}
}