// read2Numbers.c
// Chapter 21
// Learn C Programming - Fundamentals of C
//
// Demonstrate how to read an integer and a double
// using scanf() and %d and %lf format specifiers.
//
// compile with: cc read2Numbers.c -o read2Numbers -Wall -Werror -std=c11
//


#include <stdio.h>

// Test Input
// * 5 cases are given. 
// * Each test ends with the final <return>.
// * Notice how whitespace is important or ignored.
// * Notice how non-numbers terminate number parsing.
//
// 1234 5678.9012<return>
//
// <return>
//     1234<return>
//        5678.9012<return>
//
// 1234.5678<return>
//
// 1234 hello 5678.9012<return>
//
// hello 1234 5678.9012<return>
//


int main( void )
{
  int     anInteger   = -1;
  double  aDouble     = -1.0;
  
  printf( "Enter an integer and a decimal number: " );
  scanf( "%d%lf" , &anInteger , &aDouble );
  printf( "1. integer:  %d\n" , anInteger );
  printf( "2.  double:  %lf\n\n" , aDouble );    
}