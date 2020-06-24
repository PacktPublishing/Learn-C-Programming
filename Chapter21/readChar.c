// readChar.c
// Chapter 21
// Learn C Programming
//
// Demonstrate how to read a character between 2 integers
// without and with a space in the format specifier.
//
// compile with:
//
//     cc readChar.c -o readChar -Wall -Werror -std=c11
//


#include <stdio.h>


// test inputs:
//
//   123m   456<return>
//   123   m456<return>
//   123  w  456<return>
//


int main( void )
{
  char aChar;
  int  anInt1, anInt2;
  int  numScanned;
  
  printf( "1st: Enter <integer><char><integer>: " );
  numScanned = scanf(  "%d%c%d" , &anInt1 , &aChar , &anInt2 );
  printf( "Values scanned = %d. Character selected: [%c]\n" ,
           numScanned , aChar );

  printf( "2nd: Enter <integer> <char> <integer>: " );
  numScanned = scanf(  "%d %c%d" , &anInt1 , &aChar , &anInt2 );
  printf( "Values scanned = %d. Character selected: [%c]\n\n" ,
                   numScanned , aChar );
}

  //  eof
