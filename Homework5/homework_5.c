#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

static void clearstream() {
	char c;
	do { c = getchar(); } while (c != '\n' && c != EOF);
}

void problem_1() {
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

	printf("You entered valid choice %d", input);
	printf("\nThank you for giving your choice.\n");
}

void problem_2() {
	float input1, input2;
	printf("Please enter float numbers separated by space and press enter: ");

	int res = 0;
	while (res != 2) {
		res = scanf("%f %f", &input1, &input2);
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

	printf("You entered %f and %f successfully.\n\n", input1, input2);

}

void problem_3() {
						//0  1   2   3   4   5   6
	int weeklytemp[] = { 69, 70, 71, 68, 66, 71, 70 };
	// we assume that weeklytemp has at least one element
	const int sizeofarr = sizeof(weeklytemp)/sizeof(weeklytemp[0]);
	int max = 0;
	int min = 0;
	float total = 0;
	float average = 0;
	int currentmaxindex = 1;
	int currentminindex = 1;

	for (int j = 0; j < sizeofarr; j++) {
		printf("The temperature on day %d is %d\n", j + 1, weeklytemp[j]);
	}

	//find the max by comparing each value to a current max
	for (int i = 0; i < sizeofarr; i++) {
		if (weeklytemp[i] >= weeklytemp[currentmaxindex]) {
			max = weeklytemp[i];
			currentmaxindex = i;
		}		
	}

	//find the min by comparing each value to a current min
	for (int i = 0; i < sizeofarr; i++) {
		if (weeklytemp[i] <= weeklytemp[currentminindex]) {
			min = weeklytemp[i];
			currentminindex = i;
		}		
	}

	//calculate the avg temp
	for (int i = 0; i < sizeofarr; i++) {
		average += ( (float)(weeklytemp[i]) / sizeofarr);
	}
	//average = average/sizeofarr;

	printf("\n\nThe Minimum temperature is: %d\n", min);
	printf("The Maximum temperature is: %d\n", max);
	printf("The average temperature for the week is: %f\n", average);
}

int main(void) {
	problem_1();
	problem_2();
	problem_3();
}