//
// hello2.c
// Chapter 2
// <book title>
//
// Using a simple function that simply prints 2 characters.
//

#include <stdio.h>

void printComma()
{
  printf( ", " );
  return;
}

int main() 
{
  printf( "Hello" );
  printComma();
  printf( "world!\n" );
  return 0;
}

//  <eof>
