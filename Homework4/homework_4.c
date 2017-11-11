#include <stdio.h>

void problem_1() {
	printf("For problem 4.1(a), the loop is executed 10 times.\n");
	printf("For problem 4.1(b), the loop is executed 9 times.\n");
	printf("For problem 4.1(c), the loop is executed 0 times.\n");
}

void problem_2() {
	//print the box using a while loop
	//-------------------- 20 hyphens
	//8 |
	printf("The box below is generated with a while loop.\n");
	int count = 0;
	while (count < 10) {
		if (count == 0 || count == 9) {
			printf("--------------------\n");
		}
		else {
			printf("|                  |\n");
		}
		count++;
	}
}

void problem_3() {
	//print the box using do while loop
	printf("The box below is generated with a do-while loop.\n");
	int count = 0;
	do {
		if (count == 0 || count == 9) {
			printf("--------------------\n");
		}
		else {
			printf("|                  |\n");
		}
		count++;		
	} while (count < 10);
}

void problem_4() {
	//print the box using a for loop
	printf("The box below is generated with a for loop.\n");
	for (int i = 0; i < 10; i++) {
		if (i == 0 || i == 9) {
			printf("--------------------\n");
		}
		else {
			printf("|                  |\n");
		}
	}
}

void problem_5() {
	//use variables for - and |; ask use for values of 
	//height, width, characters to draw instead of hardcoded
	//ask user to continue

	char vertical, horizontal;
	int height, width;
	char cont;

	do {
		//get vertical symbol
		printf("Enter a symbol for the vertical line, horizontal line,\nheight, and width separated by spaces: ");
		scanf("%c %c %d %d", &vertical, &horizontal, &height, &width);

		//how many rows will be printed
		for (int i = 0; i < height; i++) {
			//on the first and last row, print horizontal symbols
			if (i == 0 || i == height-1) {
				//print horizontal symbols "width" times
				for (int j = 0; j < width; j++) {
					printf("%c", horizontal);	
				}
				printf("\n");
			}
			else {
				//for rows not first and last, print the vertical symbol
				//and spaces
				printf("%c", vertical);
				//how many spaces between edges
				for (int k = 0; k < width-2; k++){
					printf(" ");
				}
				printf("%c\n", vertical);
			}
		}

		while (getchar() != '\n')
			continue;

		printf("\n\nContinue? Type 'y' for YES and 'n' for NO: ");
		scanf("%c", &cont);

		while (getchar() != '\n')
			continue;

	} while (cont == 'y');
}

int main (void) {
	problem_1();
	problem_2();
	problem_3();
	problem_4();
	problem_5();
	return 0;
}