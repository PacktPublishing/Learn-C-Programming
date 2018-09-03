//
// hello3.c
// Chapter 2
// <book title>
//
// Using two functions, one function that takes no parameters,
// and one function that takes a string parameter.
//

#include <stdio.h>

void printComma()
{
  printf( ", " );
}

void printWord( char* word )
{
  printf( "%s" , word );
}

int main() 
{
  printWord( "Hello" );
  printComma();
  printWord( "world" );
  printf( "!\n" );

  return 0; 
}

//  <eof>
