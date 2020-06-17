  // casting.c
  // Chapter 5
  // <book title>
  // 
  // Program to demonstrate casting
  // for predictable results.
  
#include <stdio.h>

int main( void )
{
  int    numerator   = 33;
  int    denominator =  5;
  double result;
  
  
  result = numerator / denominator; 
  printf( "Truncation:    %d / %d = %.2g\n" , numerator , denominator , result );
  
  result = (double) numerator / denominator;
  printf( "No truncation: %.2f / %d = %.2f\n" , (double)numerator , denominator , result );

  result = numerator / (double)denominator;
  printf( "               %d / %.2f = %.2f\n" , numerator , (double)denominator , result );
  
  return 0;
}

   //  eof
