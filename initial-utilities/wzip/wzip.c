#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	// see if there are files to read, if not, exit unsuccessfully
	if (argc == 1) {
		printf("wzip: file1 [file2 ...]\n");
	exit(1);
	}

	FILE * fp;
	int repcount;
	char prev_char;
	char ch;
	
	
	//iterate through all file names
	for (int i = 1; i < argc; i++) {
		//initialize repcount variable to zero
		repcount = 0;
		//open the file
		fp = fopen(argv[i], "rb");
		// when you begin, the first char you encounter is set to prev_char
		prev_char = fgetc(fp);
		
		repcount++; // increment, traversing through each element in txt
		do { // do {...} while...
			
			ch = fgetc(fp); // set ch and the next char
			
			if (ch == prev_char) { // check if the current char is the same as the previous char, if so, increment repcount
				repcount++;
			}
			else {
				// if the current and previous char aren't the same,
				// the repetitions have fpished, so fwrite the number of repetitions
				// in binary, and the char that was repeated right after it
				fwrite(&repcount, 4, 1, stdout); // output int in binary
				fwrite(&prev_char, 1, 1, stdout); // output repeated char
				repcount = 0; // reset repcount for next char repetition, if there is one
			}
			prev_char = ch; // set previous char to current char
		} while (!feof(fp)); // while not end of file
	}
	fclose(fp);
}