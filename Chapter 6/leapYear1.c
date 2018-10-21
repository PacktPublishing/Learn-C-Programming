  // leapyeari1.c
  // Chapter 6
  // <book title>
  //
  // Our first pass at a leap year program.
  // In this version, we use "fall through" logic
  // using return to end the evaluation.

#include <stdio.h>
#include <stdbool.h>

bool isLeapYear( int );

int main( void )
{
  int year;

  printf( "Determine if a year is a leap year or not.\n\n" );
  printf( "Enter year: ");
  scanf(  "%d" , &year );

   // A simple version.
   //
  if( isLeapYear( year ) )
    printf( "%d year is a leap year\n" , year );
  else
    printf( "%d year is not a leap year \n" , year );

   // A more C-like version.
  printf( "%d year is%sa leap year\n" , year , isLeapYear( year ) ? " " : " not " );

  return 0;
}

bool isLeapYear( int year )
{
    // Leap years not part of Gregorian calendar until after 1752.
    // Is year before 1751? 
    // Yes: return false.
    // No:  "fall through" to next condition.
    //
  if( year < 1751 )  return false;

    // Is year an multiple of 4? (remainder will be 0)
    // Yes: return true.
    // No:  "fall through" and return false.
    //
  if( (year % 4) == 0  ) return true;

  return false;
}

  // eof
