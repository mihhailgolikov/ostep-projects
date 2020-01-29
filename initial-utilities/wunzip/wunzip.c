#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// see if there are files to read, if not, exit unsuccessfully
	if (argc == 1) {
		printf("wunzip: file1 [file2 ...]");
	exit(1);
	}

	FILE * fp;
	char ch;
	int j;
	int repcount;
	
	//iterate through each file
	for (int i = 1; i < argc; i++)
	{
		fp = fopen(argv[i], "rb");

		do {
			//read the first 4 bytes which is equal to
			//count of character
			fread(&repcount, 4, 1, fp);
			//read the 5th byte, which is the character
			fread(&ch, 1, 1, fp);
			//print the character count times
			for (j = 0; j < repcount; j++) {
				putc(ch,stdout);
			}
			// original: aaaaaaaaaabbbb
			// unzipped: aaaaaaaaaabbbbbb
			// unzipped: aaaaaaaaaabbbb
			// unzipped: aaaaaaaaaabbbb
			// why does the second instance of a char add two extra chars?
		} while (!feof(fp));
	}
	fclose(fp);
}