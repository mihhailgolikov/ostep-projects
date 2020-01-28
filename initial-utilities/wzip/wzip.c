#include <stdio.h>
#include <stdlib.h>
#define SIZE (1024*1024)

int main(int argc, char *argv[]) {

    int c[4096]; 
	int	c2[4096];
    FILE *fp = fopen(argv[1], "r");



    while (!feof(fp)) {
        size_t bytes = fread(c, 4, sizeof(c), fp);
        if (bytes) {
			while(fread(c,4,sizeof(c), fp) == fread(c+1,4,sizeof(c+1), fp)) { // while the current character is the same as the next character
				fwrite(c, 4, bytes, stdout);
			}	
        }
    }

    //close file
    fclose(fp);

    return 0;

}