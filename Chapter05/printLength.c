// printLength.c
// Chapter 5
// Learn C Programming
// 
// Program to print a length in given meters as well as 
// in feed (converted from meters). Consideration must be 
// given to values effectively 1.0 feet but which will never
// be exactly 1.0 feet -- they'll be more like 1.0000000987 feet,
// or 1.0 for any practical purpose.
// We consider 1.0 feet within 4 significant digits.
//
// Compile with:
//
//    cc printLength.c -o printLength -Wall -Werror -std=c11
//


#include <stdio.h>

void printLength( double meters );

int main( void ) {
  printLength( 0.0 );
  printLength( 1.0 );
  printLength( 12.0 / 39.67 );
  printLength( 2.5 );
}

void printLength(  double meters ) {
  double feet = meters * 39.67 / 12.0;
  printf( "Length = %f meter%c\n" , 
           meters, 
           meters == 1.0 ? ' ' : 's'  );
  printf( "Length = %f %s\n\n" , 
          feet, 
          0.99995 < feet && feet < 1.00005 ? "foot" : "feet" );
}
