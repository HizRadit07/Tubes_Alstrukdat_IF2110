#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>
#include <string.h>

int main(){
    char fname[20] = "wahanatemp.txt";
    FILE * fptr = fopen (fname, "r"); 
	printf("\n The content of the file %s is  :\n",fname);
	char str1 = fgetc(fptr);
	while (str1 != EOF)
		{
			printf ("%c", str1);
			str1 = fgetc(fptr);
		}
    printf("\n\n");
    printf ("%c", str1);
    fclose (fptr);
    return 0;
}