// hello2.c
// Chapter 2
// Learn C Programming
//
// Using a simple function that simply prints 2 characters.
//
//
// Compile with:
//
//    cc hello2.c -Wall -Werror -std=c11
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
