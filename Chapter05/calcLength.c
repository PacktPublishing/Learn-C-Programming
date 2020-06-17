// calcLength.c
// Chapter 5
// <book title>
// 
// Program to demonstrate a complex expression
// two different ways. 
// First compute the value with a complex expression.
// Then compute the value again with a sequence of simple expressions.


#include <stdio.h>


int feetToInches( double feet )
{
  int inches = feet * 12;
  return inches;
}


int main(int argc, char *argv[]) 
{
  int aValue   = 8; 
  int aLength  = 0;

    // 3 additions in 1 statement (a complex statement)
    //
  aLength = 5 + aValue + feetToInches( 3.5 );
  printf( "Calculated length = %d\n" , aLength );

    // 3 additions in 3 statements accumulated in the variable aLength;
    // 
  aLength = 5;
  aLength = aLength + aValue;
  aLength = aLength + feetToInches( 3.5 );
  printf( "Calculated length = %d\n" , aLength );
}