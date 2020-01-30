#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	char ch; // the character to be repeated
	// int filerepcount = 0;
	int i = 0;
	int repcount; // number of repetitions for each character
	char prev_char; // previous char used for  comparisons to determine if repetitions
					// should be ended or not

	if (argc < 2) {
		printf("wzip: file1 [file2 ...]\n"); // file not found
		exit(1); // exit unsuccessfully
	}

	//loop through all the files
	for (i = 1; i < argc; i++) {
		//reset repcount
		repcount = 0;
		if (!(fp = fopen(argv[i], "r"))) {
			printf("wzip: searchterm [file...]\n"); // cannot open this file, lets try the next
			continue; // continues when condition is false
		}
		
		ch = fgetc(fp); // get the first char in the file
		repcount++; // increment repcount
		prev_char = ch; // set the previous char to the current char in order to compare
						// in the while loop that follows
		while ((ch = fgetc(fp)) != EOF) {
			if (ch != prev_char) {
				// if the current and previous char aren't the same,
				// the repetitions have fpished, so fwrite the number of repetitions
				// in binary, and the char that was repeated right after it
				fwrite(&repcount, sizeof(repcount), 1, stdout); // output int in binary
				fprintf(stdout, "%c", prev_char); // output repeated char
				repcount = 0; // reset repcount for next char repetition, if there is one
			}
			// otherwise
			repcount++; // increment repcount
			prev_char = ch; // set previous char to current char
		}

		// handling files that end in '\n', so that seg faults
		if (repcount) {
			fwrite(&repcount, sizeof(repcount), 1, stdout);
			fprintf(stdout, "%c", prev_char);
		}

		fclose(fp);
	}
}