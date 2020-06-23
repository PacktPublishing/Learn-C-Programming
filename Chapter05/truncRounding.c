  // truncRounding.c
  // Chapter 5
  // Learn C Programming
  //
  // Program to demonstrate implicit type conversions:
  // truncation and rounding to/from long int and from/to double.
  //
  // Compile with:
  //
  //    cc truncRounding.c -o truncRounding -Wall -Werror -std=c11
  //

  
#include <stdio.h>

void doubleFunc(  double   dbl );
void longIntFunc( long int li );

int main( void )
{
  float       floatValue = 58.73;
  short int   intValue   = 13;
  
  longIntFunc(   intValue   );
  longIntFunc(   floatValue );  // possible truncation

  doubleFunc( floatValue );
  doubleFunc( intValue   ); 

  return 0;
}

void doubleFunc( double dbl )
{
  printf( "doubleFunc %.2f\n" , dbl );
}

void longIntFunc( long int li )
{
  printf( "longIntFunc   %ld\n" , li );
}

  //  eof
  
