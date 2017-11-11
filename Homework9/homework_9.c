#include <stdio.h>
#include <stdlib.h>

// void printFileToScreen(FILE *fp);

// void writeNamesToOutputFile();

int main(int argc, char *argv[]) {
	FILE *iFileptr, *oFileptr;
	char firstName[200];
	char lastName[200];
	int scores[7];

	if (argc != 3) {
		printf("Usage: %s %s %s", argv[0], argv[1], argv[2]);
		exit(1);
	}
	else {
		printf("Input will be read from: %s\n", argv[1]);
		printf("Output will be written to: %s\n\n", argv[2]);

		iFileptr = fopen(argv[1], "r");
		oFileptr = fopen(argv[2], "w");

		//print name of input file to output file
		fprintf(oFileptr, "This is what is read from Input File: %s:\n\n", argv[1]);

		while (!feof(iFileptr)) {
			//read lines from input file
			fscanf(iFileptr, "%100s %100[^,], %d, %d, %d, %d, %d, %d, %d", 
				firstName, lastName, &scores[0], &scores[1], &scores[2], &scores[3], &scores[4], &scores[5], &scores[6]);

			//print to screen
			printf("%s %s, %d, %d, %d, %d, %d, %d, %d\n", 
				firstName, lastName, scores[0], scores[1], scores[2], scores[3], scores[4], scores[5], scores[6]);

			//print names to outputfile
			fprintf(oFileptr, "%s %s\n", firstName, lastName);
		}

		fclose(iFileptr);
		fclose(oFileptr);
	}
}

// void printFileToScreen(FILE *fp) {
// 	char firstName[200];
// 	char lastName[200];
// 	int scores[7];
// 	while (!feof(fp)) {
// 		fscanf(fp, "%100s %100[^,], %d, %d, %d, %d, %d, %d, %d", 
// 			firstName, lastName, &scores[0], &scores[1], &scores[2], &scores[3], &scores[4], &scores[5], &scores[6]);
// 		printf("%s %s, %d, %d, %d, %d, %d, %d, %d\n", 
// 			firstName, lastName, scores[0], scores[1], scores[2], scores[3], scores[4], scores[5], scores[6]);
// 	}
// }

// void writeNamesToOutputFile(FILE *ifp, FILE *ofp) {
// 	char firstName[200];
// 	char lastName[200];
// 	int scores[7];
// 	while (!feof(ifp)) {
// 		fscanf(ifp, "%100s %100[^,], %d, %d, %d, %d, %d, %d, %d", 
// 			firstName, lastName, &scores[0], &scores[1], &scores[2], &scores[3], &scores[4], &scores[5], &scores[6]);
// 		fprintf(ofp, "%s %s, %d, %d, %d, %d, %d, %d, %d\n", 
// 			firstName, lastName, scores[0], scores[1], scores[2], scores[3], scores[4], scores[5], scores[6]);
// 	}
// }