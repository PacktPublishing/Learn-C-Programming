// internalFormatting.c
// Chapter 21
// Learn C Programming
//
// Demonstrate how to perform internal data conversion
// using sscanf() and sprintf(). 
// This program is very similar to read2NumbersUsingResult.c whichg
// uses scanf().
//
// compile with:
//
//     cc internalFormatting.c -o internalFormatting -Wall -Werror -std=c11
//


#include <stdio.h>
#include <string.h>

const int bufferSize = 80;

int main( void )
{
  int     anInteger   = -1;
  double  aDouble     = -1.0;
  int     numScanned  = 0 , numPrinted = 0;
  
  char sIn[] = "1234 5678.9012";
  char sOut[ bufferSize ];
  memset( sOut , 0 , bufferSize );
  
  printf("Using sscanf() on [%s]\n" , sIn );
  numScanned = sscanf( sIn , "%d%lf" , &anInteger , &aDouble );
  printf( "sscanf() was able to assign %d values.\n" , numScanned );
  printf( "1. integer:  %d\n" , anInteger );
  printf( "2.  double:  %lf\n\n" , aDouble ); 
  
  puts( "Using sprintf() to format values to string buffer:" );
  numPrinted = sprintf( sOut , "integer=[%d] double=[%9.4lf]" , anInteger , aDouble );
  printf( "%d characters in output string \"%s\"\n"  , numPrinted , sOut );
}
