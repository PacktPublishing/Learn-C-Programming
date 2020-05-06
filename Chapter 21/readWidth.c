// readWidth.c
// Chapter 21
// Learn C Programming - Fundamentals of C
//
// Demonstrate how to use the field with specifier
// to read data elements (1st approximation). 
// See also readDAte.c for a better solution.
//
// compile with: cc readWidth.c -o readWidth -Wall -Werror -std=c11
//


#include <stdio.h>


// Test inputs:
//
// 01012020<return>
//
//   02   02   2021<return>
//
// 12252019<return>
//
//  9302019<return>
//
// 12 52020<return>
//
// 7/4/2019<return>
//


int main( void )
{
  int year , month , day;
  int numScanned;
    while( printf("Enter mmddyyyy (any other character to quit): "), 
        numScanned = scanf( "%2d%2d%4d" , &month , &day , &year ) ,
        numScanned > 0 )
     printf( "%d/%d/%d\n\n" , month , day , year );
  printf( "\nDone\n" );
}

  // eof
