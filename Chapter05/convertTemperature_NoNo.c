  // convertTempertature_NoNo.c
  // Chapter 5
  // Learn C Programming
  // 
  // Demonstrate what happens with the C compiler
  // when we declare multiple functions of the same
  // name but with different parameter and return
  // types.
  //
  // Compile with:
  //
  //    cc convertTemperature_NoNo.c -o convertTemperature_NoNo -Wall -Werror -std=c11
  //


#include <stdio.h>

double celsiusToFahrenheit( double degreesC );
double fahrenheitToCelcius( double degreesF );

int celsiusToFahrenheit( int degreesC );
int fahrenheitToCelcius( int degreesF );

double celsiusToFahrenheit( int degreesC );
double fahrenheitToCelcius( int degreesF );

int celsiusToFahrenheit( double degreesC );
int fahrenheitToCelcius( double degreesF );


int main( void )
{
    // It doesn't matter what happens here. We
    // need to see if the compiler will recognize
    // multiple versions of the same functions.
  return 0;
}

double celsiusToFahrenheit( double degreesC )
{ 
  double degreesF = (degreesC * 9.0 / 5.0 ) + 32;
  return degreesF;
}
double fahrenheitToCelcius( double degreesF )
{
  double degreesC = (degreesF - 32 ) * 5.0 / 9.0 ;
  return degreesC;
}


int celsiusToFahrenheit( int degreesC )
{ 
  int degreesF = (degreesC * 9 / 5 ) + 32;
  return degreesF;
}
int fahrenheitToCelcius( int degreesF )
{
  int degreesC = (degreesF - 32 ) * 5 / 9;
  return degreesC;
}


double celsiusToFahrenheit( int degreesC )
{
  double degreesF = (degreesC * 9.0 / 5.0 ) + 32;
  return degreesF;
}
double fahrenheitToCelcius( int degreesF )
{
  double degreesC = (degreesF - 32 ) * 5.0 / 9.0 ;
  return degreesC;
}


int celsiusToFahrenheit( double degreesC )
{ 
  int degreesF = (degreesC * 9 / 5 ) + 32;
  return degreesF;
}
int fahrenheitToCelcius( double degreesF )
{
  int degreesC = (degreesF - 32 ) * 5 / 9;
  return degreesC;
}

  //  eof
