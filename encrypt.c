#include "header.h"

struct datatypes
{
    int decimal;
    int binary[8];
    char character;
    char hexadecimal[2][16];
}data,key;

extern char thread[16][16];
extern int n,i,j,count,decimal;
extern FILE *source,*destination;
extern char source_filename[20],destination_filename[20],keyword[20];

int bitXor(int a,int b)
{
    if(a == b)
        return 0;
    else
        return 1;
}

void decimal_to_binary()
{
    for(j=7;j>=0;j--)
    {
        data.binary[j] = data.decimal % 2;
        data.decimal /= 2;

        key.binary[j] = key.decimal % 2;
        key.decimal /= 2;

        data.binary[j] = bitXor(data.binary[j],key.binary[j]);
    }
}

void half_binary_to_decimal(int a,int b,int c)
{
    decimal = 0;
    count = c;

    for(j=a;j<b;j++)
    {
        decimal += count*data.binary[j];
        count /= 2;
    }
}

void decimal_to_hexadecimal()
{
    for(j=0;j<16;j++)
    {
        data.hexadecimal[0][j] = thread[decimal][j];
        fputc(data.hexadecimal[0][j],destination);
    }
}

void encrypt()
{
    printf("\nEnter filename of file to be encrypted: ");
    scanf("%s",&source_filename);
    source = fopen(source_filename, "r");

    printf("Enter filename of file to store the encrypted data: ");
    scanf("%s",&destination_filename);
    destination = fopen(destination_filename, "w");

    printf("Enter the keyword: ");
    scanf("%s",&keyword);
    n = strlen(keyword);

    while((data.character = fgetc(source)) != EOF)
    {
        key.character = keyword[i%n];
        data.decimal = (int)data.character;
        key.decimal = (int)key.character;

        decimal_to_binary();
        half_binary_to_decimal(0,4,8);
        decimal_to_hexadecimal();
        half_binary_to_decimal(4,8,8);
        decimal_to_hexadecimal();

        i++;
    }

    printf("Data was encrypted successfully...");
    fclose(source);
    fclose(destination);
}
