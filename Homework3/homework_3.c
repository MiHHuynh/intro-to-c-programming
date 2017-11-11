#include <stdio.h>
#include <math.h>

void problem_1() {
	int yourAge;
	printf("How old are you?: ");
	scanf("%d", &yourAge);
	if (yourAge < 13) {
		printf("You are a kid.\n");
	}
	else if (yourAge >= 13 && yourAge <=19) {
		printf("You are a teenager.\n");
	}
	else if (yourAge > 19) {
		printf("You are an adult.\n");
	}
}

void problem_2() {
	//line break
	float firstN, secondN;
	char op;
	char continueyn = 'y';

	while (continueyn == 'y') {
		printf("\n");
		printf("Type a number, operator, number --separated by spaces: ");
		scanf("%f %c %f", &firstN, &op, &secondN);
		if (op == '+') {
			printf("%f + %f = %f", firstN, secondN, firstN + secondN);
		}
		else if (op == '-') {
			printf("%f - %f = %f", firstN, secondN, firstN - secondN);
		}
		else if (op == '*') {
			printf("%f * %f = %f", firstN, secondN, firstN * secondN);
		}
		else if (op == '/') {
			printf("%f / %f = %f", firstN, secondN, firstN / secondN);
		}
		else if (op == '%') {
			printf("%f %% %f = %f", firstN, secondN, fmodf(firstN, secondN));
		}
		else {
			printf("Unknown operator.");
		}
		while (getchar() != '\n')
			continue;
		printf("\n\nContinue? (Type 'y' or 'n'): ");
		scanf("%c", &continueyn);
	}
	printf("\n\n");
}

void problem_3() {
	int firstN, secN, thirdN, tempmax, max;
	char cont = 'y';

	while (cont == 'y') {
		printf("Enter three integer numbers to find max of them. Separate them by a space: ");
		scanf("%d %d %d", &firstN, &secN, &thirdN);

		tempmax = (firstN > secN) ? firstN : secN;
		max = (tempmax > thirdN) ? tempmax : thirdN;

		printf("The max is: %d\n\n", max);
		while (getchar() != '\n')
			continue;
		printf("Continue? Type \'y\' for yes or \'n\' for no: ");
		scanf("%c", &cont);
	}
}

int main(void) {
	problem_1();
	problem_2();
	problem_3();
	return 0;
}