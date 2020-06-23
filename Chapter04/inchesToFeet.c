  // inchesToFeet.c
  // Chapter 4: Using Variables and Assignment
  // Learn C Programming
  //
  // A function which demonstrates assignment via
  // return value.
  //
  // There are 2 assignments. 
  // 1 to the function expression and the 2nd to 
  // the variable feet via the = operator.
  //
  // Compile with:
  //
  //    cc inchesToFeet.c -Wall -Werror -std=c11
  //

#include <stdio.h>

double inchesToFeet( double );

int main( void )
{
  double inches = 1024.0;
  double feet   = 0.0;

  feet = inchesToFeet( inches );
  printf( "%12.3g inches is equal to %12.3g feet\n" , inches , feet );

  return 0;
}

  // Given inches, convert this to feet.
  //
double inchesToFeet( double someInches )
{
  double someFeet = someInches / 12.0;
  return someFeet;
}

  // <eof>
