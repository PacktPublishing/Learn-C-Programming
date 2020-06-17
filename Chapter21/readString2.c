// readString2.c
// Chapter 21
// Learn C Programming - Fundamentals of C
//
// Demonstrate how to read and write a string with
// gets() and puts().
// Compare this program to readString.c
//
// compile with: cc readString2.c -o readString2 -Wall -Werror -std=c11
//


#include <stdio.h>

const int bufferSize = 80;

int main( void )
{
  char stringBuffer[ bufferSize ];
  
  printf( "Enter a string: " );
  gets( stringBuffer );
  puts( "You entered: " );
  puts( stringBuffer );
}