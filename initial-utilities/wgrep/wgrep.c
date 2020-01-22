#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

	int i; // loop incrementing variable used for counting files
	FILE *fp; // file pointer used for reading the files

	int key_found = 0; // 0 if the key has not been found; 1 if the key has been found
	int line_ct = 1; // var for line counting, starting at one, used for locating which line keyword was on and printing it
	char temp[120]; // used for holding the text that we are reading temporarily
	char c; // current character of text file




	for (i = 1; i < argc; i++) // for all of the arguments within the command prompt
	{
		fp = fopen(argv[i], "r"); // open each file that is declared by the user in the command line prompt, and make the file pointer point to it
		if (fp == NULL) // if the file pointer is null, then
		{
			fprintf(stderr, "The function 'wcat' can't open %s\n", argv[i]); //formatted as a compiler error, letting the user know which file cannot be opened
			exit(1); // current file not found, return unsuccessfully
			continue; // using continue to exit the loop when the condition is returned as false
		}

		while (fgets(temp, 120, fp) != NULL) { // fgets sets the char aray temp equal to the current line being read in the file,
											   //up to 120 char. per line, with a file poiner pointing to the current file
			
			if ((strstr(temp, str)) != NULL) { // if there is a match of our keyword str within the current line of the file
				printf("Wgrep has found a match on line: %d\n", line_ct); // TESTING LINE COUNTS!!!
				printf("\n%s\n", temp);
				
				key_found = 1;
				exit(key_found);
			}
			line_ct++;
		}
		fclose(fp); // make sure to close the file just to be safe, even though it is closed when wcat.c ends anyway
	}

}