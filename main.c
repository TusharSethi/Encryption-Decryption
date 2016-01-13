#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "header.h"

int main()
{
    int choice;
    void switch_case(int);

    do
    {
        system("cls");
        printf("Data encryption and decryption program.\n");
        printf("\nMenu:-");
        printf("\nPress 1 for data encryption.");
        printf("\nPress 2 for data decryption.");
        printf("\nPress 3 to read data from a file.");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch_case(choice);

        printf("\n\nDo you wish to continue ?");
        printf("\nPress 1 for Yes.");
        printf("\nPress 2 for No.");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
    }while(choice == 1);
    return 0;
}

void switch_case(int a)
{
    switch(a)
        {
        case 1:
            encrypt();
            break;

        case 2:
            decrypt();
            break;

        case 3:
            read();
            break;

        default:
            printf("\nInvalid Choice...");
            break;
        }
}
