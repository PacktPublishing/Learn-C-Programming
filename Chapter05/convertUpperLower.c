// convertUpperLower.c
// Chapter 5
// Learn C Programming
// 
// Program to convert a lower case letter to upper case
// and an upper case letter to lower case (operations on
// characters).
//
// Compile with:
//
//    cc convertUpperLower.c -o convertUpperLower -Wall -Werror -std=c11
//


#include <stdio.h>

int main( void ) 
{
  char lowerChar = 'b';
  char upperChar = 'M';

  char anUpper = lowerChar - 32;
  char aLower  = upperChar + 32;

  printf( "Lower case '%c' can be changed to upper case '%c'\n" ,
           lowerChar , anUpper );
  printf( "Upper case '%c' can be changed to lower case '%c'\n" ,
           upperChar , aLower );
}

  //  eof
