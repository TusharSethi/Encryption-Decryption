#ifndef HEADER  /// Checks whether the given token has been #defined earlier in the file or in an included file. If not, it includes the code between it and the closing #endif statement.
#define HEADER  /// Defines a token for the included code [HEADER].

/// Including files
#include "encrypt.c"
#include "decrypt.c"
#include "read.c"

/// Encryption tape
char thread[16][16] = { "07B65DA31C29F4E8","C16D87A0B235F9E4","A926D31CEF704B85","E7A3B85C102D649F",
                        "C8B34DA96120E5F7","9173D50A2B4C6E8F","BAC9426013DEF578","4C25A1E78D0F3B69",
                        "964FAB3280C1D5E7","76C523AB490D1E8F","3654CE71B2A8D9F0","75391DAC48FBE602",
                        "AB68427E5DF3C109","0162C3B458E9AD7F","A98B73C610F2D4E5","0B3641A579C8D2EF" };

/// Declaration of variables
int n,i,j,k,count,decimal;
char source_filename[20],destination_filename[20],keyword[20],character;
FILE *source,*destination;

/// Declaration of functions

/// Functions in encrypt.c
int bitXor(int,int);  /// Returns the resultant of the XOR operation between the two passed integer values.
void decimal_to_binary();
void half_binary_to_decimal(int,int,int);
void decimal_to_hexadecimal();
void encrypt();

/// Functions in decrypt.c
void hexadecimal_to_decimal(int);
void decimal_to_half_binary(int,int,int);
void binary_to_decimal();
void decrypt();

/// Functions in read.c
void read();

#endif          /// HEADER
