#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines max length of student name to be 100 characters.
#define STUDENT_NAME_MAX_LENGTH 100

// Defines quizzes/tests as enums, with first quiz being 0 and final being 6.
typedef enum QuizType {
	QUIZ_TYPE_QUIZ_FIRST = 0,
	QUIZ_TYPE_QUIZ_SECOND,
	QUIZ_TYPE_QUIZ_THIRD,
	QUIZ_TYPE_QUIZ_FOURTH,
	QUIZ_TYPE_MID_FIRST,
	QUIZ_TYPE_MID_SECOND,
	QUIZ_TYPE_FINAL,
	QUIZ_TYPE_COUNT
} QuizType;

// Defines Student structure to contain a name with a max length of STUDENT_NAME_MAX_LENGTH (100)
// and an array of test scores.
typedef struct Student {
	char name[STUDENT_NAME_MAX_LENGTH];
	int scores[QUIZ_TYPE_COUNT];
} Student;

// Defines GradedStudent structure to contain a name with a max length of STUDENT_NAME_MAX_LENGTH (100)
// and a single letter grade character.
typedef struct GradedStudent {
	char name[STUDENT_NAME_MAX_LENGTH];
	char letterGrade;
} GradedStudent;

// checkForArguments - checks to make sure program received both input and output files. Will exit if condition not met.
// Input: number of arguments + array containing argument names
// Output: n/a
static void checkForArguments(int argc, char *argv[]);

// countStudents - opens the file and counts the number of students
// Input: file pointer to file
// Output: number of students
static int countStudents(FILE* fp);

// getStudentsFromFileToStruct - takes students from file and assigns to array of Students
// Input: file pointer, array of Students, number of students
// Output: n/a
static void getStudentsFromFileToStruct(FILE* fp, Student* st, const int numStudents);

// alpha_comp - comparison function for qsort
static int alpha_comp(const void *a, const void *b);

// sortStudentsAlphabetically - contains qsort to sort array of GradedStudents into alphabetical order
// Input: array of GradedStudents, number of students
// Output: n/a
static void sortStudentsAlphabetically(GradedStudent *gradedStudents, int numStudents);

// getAvgGrade - gets the average grade given a set of grades
// Input: array of students, number of students, quiz type
// Output: average in float format
static float getAvgGrade(const Student* students, int numStudents, QuizType quizType);

// getMaxGrade - gets the highest grade given a set of grades
// Input: array of students, number of students, quiz type
// Output: max grade in float format
static float getMaxGrade(const Student* students, int numStudents, QuizType quizType);

// getMinGrade - gets the lowest grade given a set of grades
// Input: array of students, number of students, quiz type
// Output: min grade in float format
static float getMinGrade(const Student* students, int numStudents, QuizType quizType);

// calcNumberGrade - calculates final percentage number grade for student given weights of each test
// Input: array of students, array of weightings for grades
// Output: final grade percentage number for student as a float
static float calcNumberGrade(const Student* student, const float* weights);

// determineLetterGrade - gives the letter grade given the final percentage
// Input: percentage number grade as a float
// Output: letter grade from A-F
static char determineLetterGrade(float num);

// getGradedStudents - creates an array of GradedStudents to show names and corresponding letter grades
// Input: array of Students, number of students, array of weights
// Output: array of GradedStudents
static GradedStudent* getGradedStudents(const Student* students, int numStudents, const float* weights);

// printGradeStatsToConsole - prints average, min, and max grades for each quiz type onto the console
// Input: array of students, number of students
// Output: n/a
static void printGradeStatsToConsole(Student* students, int numStudents);

// printGradedStudentsToOutput - writes names and letter grades of GradedStudents to output file
// Input: array of GradedStudents, number of students, file pointer, name of file
// Output: n/a
static void printGradedStudentsToOutput(GradedStudent* gradedStudents, const int numStudents, FILE* ofp, char fileName[]);

int main(int argc, char *argv[]) {
	FILE *iFileptr, *oFileptr;
	int numStudents;
	float weights[QUIZ_TYPE_COUNT] = {0.1, 0.1, 0.1, 0.1, 0.2, 0.15, 0.25}; 

	checkForArguments(argc, argv);	

	//Give error message if input file cannot be opened
	if ( (iFileptr = fopen(argv[1], "r")) == NULL ) {
		printf("An error has occurred while trying to open input file %s. Exiting now. \n", argv[1]);
		exit(2);
	}

	//Give error message if output file cannot be opened
	if ( (oFileptr = fopen(argv[2], "w")) == NULL ) {
		printf("An error has occurred while trying to open output file %s. Exiting now. \n", argv[2]);
		exit(3);
	}

	numStudents = countStudents(iFileptr);
	Student* pStudents = malloc(numStudents * sizeof(Student));
	getStudentsFromFileToStruct(iFileptr, pStudents, numStudents);
	GradedStudent *gradedStudents = getGradedStudents(pStudents, numStudents, weights);
	sortStudentsAlphabetically(gradedStudents, numStudents);
	
	printf("Letter grades have been calculated for students listed in input file %s and written to output file %s.\n\n", argv[1], argv[2]);
	printGradeStatsToConsole(pStudents, numStudents);
	printGradedStudentsToOutput(gradedStudents, numStudents, oFileptr, argv[2]);

	free(gradedStudents);
	free(pStudents);
	fclose(iFileptr);
	fclose(oFileptr);
}

static void checkForArguments(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Usage: %s %s %s", argv[0], argv[1], argv[2]);
		exit(1);
	}
}

static int countStudents(FILE* fp) {
	//We first have to make sure that the file is being read from the beginning.
	rewind(fp);
	int count;
	char c;
	while (!feof(fp)) {
		c = fgetc(fp);
		if (c == '\n') {
			count += 1;
		}
	}

	//In order to allow for future readings of the file, rewind to beginning.
	rewind(fp);
	return count;
}

static void getStudentsFromFileToStruct(FILE* fp, Student* st, const int numStudents) {
	rewind(fp);
	while (!feof(fp)) {
		for (int i = 0; i < numStudents; ++i) {
			fscanf(fp, "%100[^,], %d, %d, %d, %d, %d, %d, %d\n", 
				st[i].name, 
				&st[i].scores[QUIZ_TYPE_QUIZ_FIRST], 
				&st[i].scores[QUIZ_TYPE_QUIZ_SECOND], 
				&st[i].scores[QUIZ_TYPE_QUIZ_THIRD], 
				&st[i].scores[QUIZ_TYPE_QUIZ_FOURTH],
				&st[i].scores[QUIZ_TYPE_MID_FIRST], 
				&st[i].scores[QUIZ_TYPE_MID_SECOND], 
				&st[i].scores[QUIZ_TYPE_FINAL]);
		}	
	}
	rewind(fp);
}

static int alpha_comp(const void *a, const void *b) {
    const Student *a_student = (Student *)a;
    const Student *b_student = (Student *)b;
    return strcmp(a_student->name, b_student->name);
}

static void sortStudentsAlphabetically(GradedStudent *gradedStudents, int numStudents) {
    qsort(gradedStudents, numStudents, sizeof(*gradedStudents), alpha_comp);
}

static float getAvgGrade(const Student* students, int numStudents, QuizType quizType) {
	float avg = 0;
	for (int i = 0; i < numStudents; i++) {
		avg += students[i].scores[quizType]; 
	}
	avg /= numStudents;
	return avg;
}

static float getMaxGrade(const Student* students, int numStudents, QuizType quizType) {
	int currentHighestGrade = 1;
	int maxGrade = 0;
	for (int i = 0; i < numStudents; i++) {
		if (students[i].scores[quizType] >= students[currentHighestGrade].scores[quizType]) {
			maxGrade = students[i].scores[quizType];
			currentHighestGrade = i;
		}		
	}
	return maxGrade;
}

static float getMinGrade(const Student* students, int numStudents, QuizType quizType) {
	int currentLowestGrade = 1;
	int minGrade = 0;
	for (int i = 0; i < numStudents; i++) {
		if (students[i].scores[quizType] <= students[currentLowestGrade].scores[quizType]) {
			minGrade = students[i].scores[quizType];
			currentLowestGrade = i;
		}		
	}
	return minGrade;
}

static float calcNumberGrade(const Student* student, const float* weights) {
	//Final quizType = quiz1*.1 + quiz2*.1 + quiz3*.1 + quiz4*.1 + midi*.2 + midii*.15 + final*.25
	float grade = 0.0f;
	for (QuizType quiz_type = QUIZ_TYPE_QUIZ_FIRST; quiz_type < QUIZ_TYPE_COUNT; quiz_type++) {
		grade += student->scores[quiz_type] * weights[quiz_type];
	}
	return grade;
}

static char determineLetterGrade(float num) {
	if (num <= 100 && num >= 90) {
		return 'A';
	}
	else if (num < 90 && num >= 80) {
		return 'B';
	}
	else if (num < 80 && num >= 70) {
		return 'C';
	}
	else if (num < 70 && num >= 60) {
		return 'D';
	}
	else if (num < 60) {
		return 'F';
	}
    return '?';

}

static GradedStudent* getGradedStudents(const Student* students, int numStudents, const float* weights) {
	GradedStudent *gradedStudents = (GradedStudent*)malloc(numStudents * sizeof(GradedStudent));
	for (int i = 0; i < numStudents; i++) {
		strcpy(gradedStudents[i].name, students[i].name);
		gradedStudents[i].letterGrade = determineLetterGrade(calcNumberGrade(&students[i], weights));
	}
	return gradedStudents;
}

static void printGradeStatsToConsole(Student* students, int numStudents) {
	printf("Grade statistics for these students are:\n\n");
	printf("\t\tQ1\tQ2\tQ3\tQ4\tM1\tM2\tFinal\n");

	printf("Average:");
	for (int i = 0; i < QUIZ_TYPE_COUNT; i++) {
		printf("\t%.2f", getAvgGrade(students, numStudents, i));
	}
	printf("\n");

	printf("Minimum:");
	for (int i = 0; i < QUIZ_TYPE_COUNT; i++) {
		printf("\t%.2f", getMinGrade(students, numStudents, i));
	}
	printf("\n");

	printf("Maximum:");
	for (int i = 0; i < QUIZ_TYPE_COUNT; i++) {
		printf("\t%.2f", getMaxGrade(students, numStudents, i));
	}
	printf("\n");
}


static void printGradedStudentsToOutput(GradedStudent* gradedStudents, const int numStudents, FILE* ofp, char fileName[]) {
	fprintf(ofp, "Letter grade for %d students given in %s file is:\n\n", numStudents, fileName);
	for (int i = 0; i < numStudents; i++) {
		fprintf(ofp, "%s\t\t%c\n", gradedStudents[i].name, gradedStudents[i].letterGrade);
	}
}