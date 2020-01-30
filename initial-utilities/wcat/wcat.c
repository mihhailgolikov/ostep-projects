#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int i; // incrementer/counting variable for the amount of files to be read/amnt. of arguments 
	FILE *fp; // declaration of file pointer in order to be able to open file
	char c; // the current character thats being looked at/written  (originally int c).

	if (argc < 2) { // if wcat recieves no command line arguments, then
			exit(0); // exit 0 (AS SPECIFIED, which seems counterintuitive)
		}

	for (i = 1; i < argc; i++) // for all of the arguments within the command prompt
	{
		fp = fopen(argv[i], "r"); // open each file that is declared by the user in the command line prompt, and make the file pointer point to it
		if (fp == NULL) // if the file pointer is null, then
		{
			printf("wcat: cannot open file\n"); //formatted as a compiler error, letting the user know which file cannot be opened
			exit(1); // exit unsuccessfully
			continue; // using continue to exit the loop when the condition is returned as false, as not all of the files have to return an error
		}

		while ((c = getc(fp)) != EOF) // while the current character is NOT the end of the file
			putchar(c); // write the contents that are being read as an output in the console
		
		exit(0); // exit successfully
		fclose(fp); // make sure to close the file just to be safe, even though it is closed when wcat.c ends anyway
	}

}