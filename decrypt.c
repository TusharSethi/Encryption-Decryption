#include "header.h"

extern char thread[16][16];
extern int n,i,j,k,count,decimal;
extern FILE *source,*destination;
extern char source_filename[20],destination_filename[20],keyword[20];

void hexadecimal_to_decimal(int a)
{
    for(j=0;j<16;j++)
    {
        if(data.hexadecimal[a][0] == thread[j][0])
        {
            for(k=1;k<16;k++)
            {
                if(data.hexadecimal[a][k] != thread[j][k])
                    break;
            }
            if(k == 16)
            {
                decimal = j;
                break;
            }
        }
    }
}

void decimal_to_half_binary(int a,int b,int c)
{
    count = c;
    for(j=a;j<b;j++)
    {
        if(decimal/count == 1)
        {
            decimal -= count;
            data.binary[j] = 1;
        }
        else
        {
            data.binary[j] = 0;
        }
        count /= 2;
    }
}

void binary_to_decimal()
{
    data.decimal = 0;
    key.character = keyword[i%n];
    key.decimal = (int)key.character;
    count = 1;
    for(j=7;j>=0;j--)
    {
        key.binary[j] = key.decimal % 2;
        key.decimal /= 2;

        data.binary[j] = bitXor(data.binary[j],key.binary[j]);

        data.decimal += data.binary[j] * count;
        count *= 2;
    }
}

void decrypt()
{
    printf("\nEnter filename of the file to be decrypted: ");
    scanf("%s",&source_filename);
    source = fopen(source_filename, "r");

    printf("Enter filename of the file to store decrypted text: ");
    scanf("%s",&destination_filename);
    destination = fopen(destination_filename, "w");

    printf("Enter the key: ");
    scanf("%s",&keyword);
    n = strlen(keyword);

    while(fgets(data.hexadecimal[0],17,source) != NULL)
    {
        hexadecimal_to_decimal(0);
        decimal_to_half_binary(0,4,8);

        fgets(data.hexadecimal[1],17,source);
        hexadecimal_to_decimal(1);
        decimal_to_half_binary(4,8,8);

        binary_to_decimal();

        data.character = (char)data.decimal;
        fputc(data.character,destination);
        i++;
    }
    printf("Data was decrypted successfully...");
    fclose(source);
    fclose(destination);
}
