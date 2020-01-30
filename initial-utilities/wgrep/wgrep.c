#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

	int i; // loop incrementing variable used for counting files
	FILE *fp; // file pointer used for reading the files

	int key_found = 0; // 0 if the key has not been found; 1 if the key has been found
	int line_ct = 1; // var for line counting, starting at one, used for locating which line keyword was on and printing it
	char temp[120]; // used for holding the line of text (even long ones) that we are reading temporarily
	char c; // current character of text file


	char *str = argv[1]; // used for taking our keyword from the first command line argument

	if (argc < 2) { // if wgrep recieves no command line arguments, then
			printf("wgrep: searchterm [file...]\n"); // nothing was found
			exit(1); // exit unsuccessfully
			}

	// if the only two args are the prog name and a search term, then take input from stdin
	if (argc == 2) {
		while (fgets(temp, 120, stdin) != NULL) { /* fgets sets the char aray temp equal to the current line being read in the file,
											   up to 120 char. per line, with the input, in this case, being taken from stdin */
			
			if ((strstr(temp, str)) != NULL) { // if there is a match of our keyword str within the current line of the file
				// printf("Wgrep has found a match on line: %d\n", line_ct); // the function found a match on line...
				printf("\n%s\n", temp); // print the line where the match was found
				
				exit(0); // string found! using stdin, exits safely because no other "files" (stdins) to check
			}
			line_ct++; // increment line count to go through every line
		}
	}

	for (i = 2; i < argc; i++){ // for all of the arguments within the command prompt
		fp = fopen(argv[i], "r"); // open each file that is declared by the user in the command line prompt, and make the file pointer point to it
		if (fp == NULL) // if the file pointer is null, then
		{
			printf("wgrep: cannot open file\n"); // letting the user know file cannot be opened
			exit(1); // current file not found, return unsuccessfully
			continue; // using continue to exit the loop when the condition is returned as false
					//  as there may be more than one file, one of which could be valid
		}

		while (fgets(temp, 120, fp) != NULL) { /* fgets sets the char aray temp equal to the current line being read in the file,
											   up to 120 char. per line, with a file poiner pointing to the current file
											   thus, while the line is not null (file hasnt ended) the while loop continues */
			
			if ((strstr(temp, str)) != NULL) { // if there is a match of our keyword str within the current line of the file
				//printf("Wgrep has found a match on line: %d\n", line_ct); // the function found a match on line...
				printf("\n%s\n", temp); // print the line where the match was found
				}
				line_ct++; // increment line count to go through every line
			}
			
			fclose(fp); // make sure to close the file just to be safe, even though it is closed when wgrep.c ends anyway
		}
		exit(0); // exits successfully after reading each file and possibly finding a match!
}