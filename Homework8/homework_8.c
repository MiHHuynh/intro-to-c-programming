#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static void clearstream();

//Which asks the user to enter 7 temperatures for the week
static int *getTemperatures();

//Which prints the 7 temperatures for the week
static void printTemperatures(int weeklyTemp[]);

//which returns the maximum temperature of the week
static int getMax(int weeklyTemp[]);

//which returns the minimum temperature of the week
static int getMin(int weeklyTemp[]);

//which returns the average temperature of the week
static float getAverage(int weeklyTemp[]);

//prints minimum, maximum and average of the week using above function
static void printStatistics(int weeklyTemp[]);

/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////

//gets height of box
static int getHeight();

//gets width of box
static int getWidth();

//gets symbol that will be drawn repeatedly
static char getSymbol();

//which draws horizontal lines
static void drawHorizontalLine(int, char);

//which draws vertical lines
static void drawVerticalLines(int, int, char);

//which calls the drawHorizontalLine, and drawVerticalLine to draw the box
static void drawBox(int, int, char, char);

int main() {
	//Weekly Temperatures
	int *weeklyTemp = getTemperatures();
	printTemperatures(weeklyTemp);
	printStatistics(weeklyTemp);

	//Box Drawing
	int ht1 = getHeight();
	clearstream();
	int wd1 = getWidth();
	clearstream();
	printf("For the horizontal symbol, ");
	char hChar1 = getSymbol();
	clearstream();
	printf("For the vertical symbol, ");
	char vChar1 = getSymbol();
	clearstream();
	drawBox(ht1, wd1, hChar1, vChar1);

}

static void clearstream() {
	char c;
	do { c = getchar(); } while (c != '\n' && c != EOF);
}

/////////////////////////////////////////
/////////////////////////////////////////

// void problem_1() {
// 	int i, max = 0, min = 0;

// 	// find the max, min temperature
// 	for (i = 0; i < 7; i++) {
// 		if (i == 0)
// 			max = min = weeklyTemp[i];
// 		if (weeklyTemp[i] > max)
// 			max = weeklyTemp[i];
// 		if (weeklyTemp[i] < min)
// 			min = weeklyTemp[i];
// 	}
// 	printf("The Minimum temperature is: %d\n", min);
// 	printf("The Maximum temperature is: %d\n", max);

// 	// get average
// 	float total = 0, average;
// 	for (i = 0; i < 7; i++)
// 		total += weeklyTemp[i];
// 	average = total / 7;
// 	printf("The average temperage for the week is: %5.2f ", average);

// }

//Which asks the user to enter 7 temperatures for the week
static int *getTemperatures() {
	static int temps[7];
	for (int i = 0; i < 7; i++) {
		printf("Please enter a temp: ");
		scanf("%d", &temps[i]);
	}
	return temps;
}

//Which prints the 7 temperatures for the week
static void printTemperatures(int weeklyTemp[]) {
	for (int i = 0; i < 7; i++) {
		printf("\nThe temperature on day %d was %d\n", i + 1, weeklyTemp[i]);
	}
	printf("\n\n");
}

//which returns the maximum temperature of the week
static int getMax(int weeklyTemp[]) {
	int max = 0;

	// find the max temperature
	for (int i = 0; i < 7; i++) {
		if (i == 0)
			max = weeklyTemp[i];
		if (weeklyTemp[i] > max)
			max = weeklyTemp[i];
	}

	return max;
}

//which returns the minimum temperature of the week
static int getMin(int weeklyTemp[]) {
	int min = 0;

	// find the max, min temperature
	for (int i = 0; i < 7; i++) {
		if (i == 0)
			min = weeklyTemp[i];
		if (weeklyTemp[i] < min)
			min = weeklyTemp[i];
	}

	return min;
}

//which returns the average temperature of the week
static float getAverage(int weeklyTemp[]) {
	// get average
	float total = 0;
	float avg;
	for (int i = 0; i < 7; i++) {
		total += weeklyTemp[i];
	}
	avg = total / 7;
	return avg;
}

//prints minimum, maximum and average of the week using above function
static void printStatistics(int weeklyTemp[]) {
	printf("The max temperature is %d.\n", getMax(weeklyTemp));
	printf("The min temperature is %d.\n", getMin(weeklyTemp));
	printf("The average temperature for the week is: %5.2f.\n", getAverage(weeklyTemp));
}

/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////

static int getHeight() {
	int ht1;
	printf("\nPlease enter height of box: ");
	scanf("%d", &ht1);
	return ht1;
}

static int getWidth() {
	int wd1;
	printf("\nPlease enter width of box: ");
	scanf("%d", &wd1);
	return wd1;
}

static char getSymbol() {
	char symbol;
	printf("\nPlease enter the character to draw box: ");
	scanf("%c", &symbol);
	return symbol;
}

//which draws horizontal lines
static void drawHorizontalLine(int width, char symbol) {
	for (int i = 0; i < width; i++) {
		printf("%c", symbol);
	}
	printf("\n");	
}

//which draws vertical lines
static void drawVerticalLines(int height, int width, char symbol) {
	for (int i = 0; i < height-2; i++) {
		printf("%c", symbol);
		for(int j = 0; j < width-2; j++) {
			printf(" ");
		}
		printf("%c\n", symbol);
		
	}
}

//which calls the drawHorizontalLine, and drawVerticalLine to draw the box
static void drawBox(int height, int width, char hChar, char vChar) {
	drawHorizontalLine(width, hChar);
	drawVerticalLines(height, width, vChar);
	drawHorizontalLine(width, hChar);
}