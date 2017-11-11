#include <stdio.h>

void problem_1() {
	int radius = 2;
	double area;
	const double pi = 3.142;

	area = pi * radius * radius; printf("The area is: %5.2f\n", area);
}

void problem_2() {
	int radius;
	double area;
	double pi;

	//extra line feed
	printf("\n");
	printf("Enter the radius: ");
	scanf("%d", &radius);
	printf("Enter pi: ");
	scanf("%lf", &pi);

	area = pi * radius * radius;
	
	printf("The area is: ");
	printf("%5.2f\n", area);
}

void problem_3() {
	//extra line feed
	// printf("\n");
	// char lastName[20];
	// char yourInitial;

	// //extra line feed
	// printf("\n");
	// printf("Please enter your last name: ");
	// scanf("%19s", lastName); //gets 19 characters because last one is \n
	// while (getchar() != '\n')
	// 	continue;
	// printf("What is your first name?: ");
	// yourInitial = getchar(); //gets only one character
	// while (getchar() != '\n')
	// 	continue;
	// printf("Hello Mr. %c. %s\n", yourInitial, lastName);

	char firstName[20];
	char lastName[20];
	char city[20];
	double zip;

	printf("\n");
	printf("5185 is a fun course. \n\n");

	printf("Please enter your first name: ");
	scanf("%19s", firstName);
	while (getchar() != '\n')
		continue;
	printf("Please enter your last name: ");
	scanf("%19s", lastName);
	while (getchar() != '\n')
		continue;
	printf("Please enter your city: ");
	scanf("%19s", city);
	while (getchar() != '\n')
		continue;
	printf("Please enter your zip code: ");
	scanf("%lf", &zip);

	printf("First Name \tLast Name \tCity \tZip Code\n");
	printf("----------- \t--------- \t---- \t--------\n");
	printf("%s \t\t%s \t\t%s \t%5.0lf\n", firstName, lastName, city, zip);

}

void problem_4() {
	char addition[] = "Addition";
	char subtraction[] = "Subtraction";
	char multiplication[] = "Multiplication";
	char division[] = "Division";
	char exit[] = "Exit";
	int input;

	printf("\n");
	printf("1. %s\n", addition);
	printf("2. %s\n", subtraction);
	printf("3. %s\n", multiplication);
	printf("4. %s\n", division);
	printf("5. %s\n\n", exit);


	printf("What would you like to do?: ");
	scanf("%d", &input);
	printf("\n");
	switch (input) {
		case 1:
			printf("\tYou selected %s", addition);
			break;
		case 2:
			printf("\tYou selected %s", subtraction);
			break;
		case 3:
			printf("\tYou selected %s", multiplication);
			break;
		case 4:
			printf("\tYou selected %s", division);
			break;
		case 5: 
			printf("\tYou selected %s", exit);
			break;
	}
	printf("\n\nThank you for using my program.\n\n");

}

int main (void) {
	problem_1();
	problem_2();
	problem_3();
	problem_4();
	return 0;
}