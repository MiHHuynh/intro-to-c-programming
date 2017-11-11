#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// clearstream consumes the rest of the characters in a stream
// Input - none; Returns - none
static void clearstream();

// calculatorIntro gives starting information with intro and menu choices
// Input - none; Returns - none
static void calculatorIntro();

// getMenuChoice handles reading & validation of user-given value for the menu choice
// It prompts user repeatedly until valid choice is given.
// Input - none; Returns - the menu choice in the form of an int
static int getMenuChoice();

// getInput handles reading & validation of user-given values for the numbers that we will be doing the math on
// If division is chosen, extra validation occurs to deny attempt at division by zero
// It prompts user repeatedly until valid choice is given.
// Input - the menu choice in the form of an int
// Returns - statically allocated array of 2 floats as given by the user
static float *getInputForChoice(int);

// calculate takes in user's choice of what kind of math to do and the numbers given and performs the operation
// Input - int and pointer to array of floats containing user-given numbers, int representing size of array; Returns - none
static void calculate(int, float*, int);

// waitForEnter prompts user to hit enter key
// Input - none; Returns - none
static void waitForEnter();


int main(void) {
	while (1) {
		calculatorIntro();
		int choice = getMenuChoice();
		if (choice == -1) {
			printf("\nInput stream closed. Exiting. Please restart the program.\n");
			break;
		} else if (choice == 0) {
			printf("\nThank you for using Michelle Huynh's Handy Calculator.\n");
			break;
		} else {
	 		float *pNumbers = getInputForChoice(choice);
	 		if (pNumbers == NULL) {
	 			printf("\nInput stream closed. Exiting. Please restart the program.\n");
	 			break;
	 		}

	 		// We are assuming, at this point, that pNumbers should contain two floats
	 		// as described in comments for getInputForChoice.

			calculate(choice, pNumbers, 2);
			waitForEnter();
		}
	}
}

static void clearstream() {
	char c;
	do { c = getchar(); } while (c != '\n' && c != EOF);
}

static void waitForEnter() {
	printf("Press enter to continue...\n");
	char enter;
	do {
		clearstream();
		enter = getchar();
	} while (enter != '\r' && enter != '\n');
}

static void calculatorIntro() {
	printf("Welcome to Michelle Huynh's Handy Calculator\n\n");
	printf("\t1. Addition\n");
	printf("\t2. Subtraction\n");
	printf("\t3. Multiplication\n");
	printf("\t4. Division\n");
	printf("\t5. Exit\n\n");
}

static int getMenuChoice() {
	int input;
	printf("What would you like to do? ");

	//This handles case in which scanf takes in EOF.
	int res = scanf("%d", &input);
	if (res == EOF) {
		return -1;
	}

	if (input == 5) {
		return 0;
	}

	//If scanf doesn't take in a valid input, repeat process of asking for input.
	while (res != 1 || input > 5 || input < 1) {
		printf("That is not a valid choice. Please re-enter: ");
		clearstream();
		res = scanf("%d", &input);
		if (input == 5) {
			return 0;
		}
	}

	return input;
}

static float *getInputForChoice(int choice) {
	// This switch block prints a different statement depending
	// on which operation user wants done.
	switch(choice) {
		case 1:
			printf("Please enter two numbers to add separated by a space: ");
			break;
		case 2:
			printf("Please enter two numbers to subtract separated by a space: ");
			break;
		case 3:
			printf("Please enter two numbers to multiply separated by a space: ");
			break;
		case 4:
			printf("Please enter two numbers to divide separated by a space: ");
			break;
		default:
			printf("Invalid choice %d given.", choice);
			break;
	}

	static float numbers[2];
	int res = 0;
	clearstream();
	while (res != 2) {
		res = scanf("%f %f", &numbers[0], &numbers[1]);
		if (res == EOF) {
			return NULL;
		}
		if (res == 2 && choice == 4 && numbers[1] == 0 && numbers[0] != numbers[1]) {
			// if scanf successfully took in numbers, but we are doing division
			// and the second number is zero but the first number is not also zero,
			// we must ask for different input because we cannot divide by zero.

			printf("You can't divide by zero. Please re-enter both numbers: ");
			res = 0;

			// clear stream by consuming rest of characters so next scanf can take in fresh values
			clearstream();
			// at this point, stdin is empty.
		} else if (res != 2) {
			printf("Error reading your numbers. Please try again: ");
			// clear stream by consuming rest of characters so next scanf can take in fresh values
			clearstream();
			// at this point, stdin is empty.
		}	
	}
	return numbers;
}

static void calculate(int choice, float a[], int n) {
	assert (n == 2);

	switch(choice) {
		case 1:
			printf("\nResult of adding %f with %f is %.2f.\n\n", a[0], a[1], a[0]+a[1]);
			break;
		case 2:
			printf("\nResult of subtracting %f from %f is %.2f.\n\n", a[0], a[1], a[0]-a[1]);
			break;
		case 3:
			printf("\nResult of multiplying %f with %f is %.2f.\n\n", a[0], a[1], a[0]*a[1]);
			break;
		case 4:
			printf("\nResult of dividing %f with %f is %.2f.\n\n", a[0], a[1], a[0]/a[1]);
			break;
		default:
			printf("Unable to complete operation. Exiting.");
			break;
	}
}