#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

static void clearstream() {
	char c;
	do { c = getchar(); } while (c != '\n' && c != EOF);
}

int getMenuChoice() {
	int input;

	printf("Welcome to sorting program:\n\n");
	printf("\t1. Title\n");
	printf("\t2. Rank\n");
	printf("\t3. Date\n");
	printf("\t4. Stars\n");
	printf("\t5. Likes\n\n");

	printf("Enter your choice between 1 and 5 only: ");

	int res = scanf("%d", &input);
	if (res == EOF) {
		printf("Input stream closed. Exiting.\n");
		exit(1);
	}
	while (res != 1 || input > 5 || input < 0) {
		printf("You have not entered a choice between 1 and 5. Try again.\nEnter your choice between 1 and 5 only: ");
		clearstream();
		res = scanf("%d", &input);
	}

	return input;
}

float *getTwoFloats() {
	static float floats[2];
	
	printf("Please enter float numbers separated by space and press enter: ");
	int res = 0;
	while (res != 2) {
		res = scanf("%f %f", &floats[0], &floats[1]);
		if (res == EOF) {
			printf("Input stream closed. Exiting.\n");
			exit(1);
		} else if (res != 2) {
			printf("\nError reading your input. Please try again: ");
			// clear stream by consuming rest of characters so next scanf can take in fresh values
			clearstream();
			// at this point, stdin is empty.
		}
	}
	return floats;
}

int main(void) {
	printf("You entered valid choice %d\n", getMenuChoice());
	printf("Thank you for giving your choice.\n");
	float *pFloats = getTwoFloats();
	printf("You entered %f and %f successfully.\n", *pFloats, *(pFloats+1));
}