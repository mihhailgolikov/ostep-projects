#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE * fp; // file pointer used for reading in the .z file
	char ch; // the character to be repeated
	int repcount = 0; // number of repetitions for each character
	int i = 0; // file incrementing variable
	int j = 0; // char incrementing variable (to traverse and write out all of the chars)

	if (argc < 2) {
		printf("wunzip: file1 [file2 ...]"); // file not found 
		exit(1); // exit unsuccessfully
	}
	//loop through all the input files
	for (i = 1; i < argc; i++) {
		repcount = 0;
		//check if the file is present, else continue for next file
		if (!(fp = fopen(argv[i], "r"))) {
			printf("wunzip: searchterm [file...]\n"); // cannot open this file, lets try the next
			continue; // continues when condition is false
		}
		//read the opened file
		while (1) { // while(1) lets the loop run infinitely
			if (fread(&repcount, sizeof(repcount), 1, fp) <= 0) { 
			// if repcount is less than or equal to 0
			// you are, theoretically, printing a char ch 0 times, which is useless,
			// so break the loop (otherwise it runs infinitely)
				break;
			}
			if ((ch = fgetc(fp)) == EOF) {
			// if the current character in the file is the end of file, then
			// break the loop (otherwise it runs infinitely)
				break;
			}
			for (j = 0; j < repcount; j++) {
			// for the determined amount of repetitions, print the char that was
			// repeated, repcount times, to stdout
				//printf("%c", ch);      //used for testing
				putc(ch,stdout);
			}
			// reset the repetition count after done writing each respective char
			repcount = 0;
		}
		// close the file to avoid possible problems
		fclose(fp);
	}
}