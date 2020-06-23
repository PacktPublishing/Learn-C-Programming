  // temp.c
  // Chapter 6
  // Learn C Programming
  //
  // Use multiple or chained if else statements to
  // convert from a range of values into a specific
  // message or unit.
  //
  // Compile with:
  //
  //    cc temp.c -o temp -Wall -Werror -std=c11
  //


#include <stdio.h>
#include <stdbool.h>


void describeTemp( double degreesF );


int main( void )
{
  describeTemp( 100.0 );
  describeTemp(  85.0 );
  describeTemp(  70.0 );
  describeTemp(  55.0 );
  describeTemp(  40.0 );
  describeTemp(  25.0 );
  describeTemp(  10.0 );
  describeTemp(  -5.0 );
  return 0;
}


void describeTemp( double degreesF )
{
  char * message;

  if(      degreesF >= 100.0 )  message = "hot! Stay in the shade.";
  else if( degreesF >=  80.0 )  message = "perfect weather for swimming.";
  else if( degreesF >=  60.0 )  message = "very comfortable.";
  else if( degreesF >=  40.0 )  message = "chilly.";
  else if( degreesF >=  20.0 )  message = "freezing, but good skiing weather.";
  else                          message = "way too cold to do much of anything!" ;
  printf( "%g°F is %s\n" , degreesF , message );
}

  // eof

