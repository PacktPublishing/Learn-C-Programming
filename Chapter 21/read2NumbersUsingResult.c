// read2NumbersUsingResult.c
// Chapter 21
// Learn C Programming - Fundamentals of C
//
// Demonstrate how to use the result of scanf()
// to determine how many values were correctly converted.
//
// compile with: cc read2NumbersUsingResult.c -o read2NumbersUsingResult \
//                 -Wall -Werror -std=c11
//


#include <stdio.h>

// Test input (5 cases):
//
// 1. 1234 5678.9012<return>
// 2. <return>
//      1234<return>
//         5678.9012<return>
// 3. 1234.5678<return>
// 4. 1234 hello 5678.9012<return>
// 5.  <return>
//

int main( void )  {
  int     anInteger   = -1;
  double  aDouble     = -1.0;
  int     numScanned  =  0;
  
  printf( "Enter an integer and a decimal number: " );

  numScanned = scanf( "%d%lf" , &anInteger , &aDouble );

  printf( "scanf() was able to assign %d values.\n" , numScanned );
  if( numScanned > 0 ) printf( "1. integer:  %d\n" , anInteger );
  if( numScanned > 1 ) printf( "2.  double:  %lf\n" , aDouble );    
  printf( "\n" );
}