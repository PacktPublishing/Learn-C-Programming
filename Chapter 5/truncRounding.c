  // program truncRounding.
  // Chapter 5
  // <book title>
  //
  // Program to demonstrate implicit type conversions:
  // truncation and rounding to/from in from/to float.
  //
  
#include <stdio.h>

void floatFunc( float f );
void intFunc(   int   i );

int main( void )
{
  float floatValue = 57.5;
  int   intValue   = 13;
  
  intFunc(   intValue   );
  intFunc(   floatValue );  // possible truncation

  floatFunc( floatValue );
  floatFunc( intValue   ); 

  return 0;
}

void floatFunc( float f )
{
  printf( "floatFunc %.2f\n" , f );
}

void intFunc( int i )
{
  printf( "intFunc   %d\n" , i );
}

  //  eof
  
