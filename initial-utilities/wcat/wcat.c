#include <stdio.h>
#include <stdlib.h>

#define FILESIZE 50
#define NC 0     //No Comment State
#define C  1   //Comment State
#define PROC 2   //Pre Open Comment State
#define PTOC 3  //Post Open Comment State
#define ST 4    //String State
#define C1 5    //Second Comment state


int main()

{

    FILE *fp;
    char output[FILESIZE];
    char clearOutput[FILESIZE];
    char filename[100];
    char  cc;                                  //Current character
    int lc =1;                                 //Line Count
                              //Starting state = No comment state
    char temp = '\n';
    int count = 0;
    int endCount = 0;
    int endloop = 0;

	printf("Enter file name to read: ");
	scanf("%s", filename);
    fp = fopen(filename, "r");

                     //Open File
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }

    cc= fgetc(fp);

    while (cc!= EOF ){

        if(cc == '\n'){
			lc++;
        }
        cc= getc(fp);
      }

		if(cc == EOF){
			for(int i = 0; i<FILESIZE; i++){
				output[i]= NULL;
        }

    }
    output[count]= '\0';
    printf("%s",output);

    fclose(fp);

    return 0;
}