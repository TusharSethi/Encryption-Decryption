#include "header.h"

extern char source_filename[20],character;
extern FILE *source;

void read()
{
    printf("\nEnter the name of the file to be read: ");
    scanf("%s",&source_filename);
    source = fopen(source_filename, "r");

    if(source == NULL)
    {
        printf("Incorrect Filename...");
    }
    else
    {
        printf("\nThe contents of the file are:\n");
        while((character = fgetc(source)) != EOF)
            printf("%c",character);
    }
    fclose(source);
}
