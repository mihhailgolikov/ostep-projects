#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    char c[4096]; 
	int	c2[4096];
    FILE *fp = fopen(argv[1], "rb");

	int rep;



    while (!feof(fp)) {
        size_t bytes = fread(c, 1, sizeof(c), fp);
        if (bytes) {
			fwrite(c, 1, bytes, stdout); 
			printf("\n");
			
			if(fread(c,1,sizeof(c), fp) == fread(c+1,1,sizeof(c+1), fp)) { // while the current character is the same as the next character
				printf("if statement");
				rep++;
				if (fread(c,4,sizeof(c), fp) != fread(c+1,4,sizeof(c+1), fp)) { // used when the next char is different than current char, to break out of loop
					// fwrite the int and the char
					printf("rep number %d of char", &rep);
					rep = 0;
					break; // break out of it
				}
				break;
			}
			else
				fwrite(c, 1, bytes, stdout); 
			

        }
    }

    //close file
    fclose(fp);

    return 0;

}