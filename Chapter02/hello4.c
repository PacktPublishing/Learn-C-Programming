// hello4.c
// Chapter 2
// Learn C Programming
//
// Now we have 3 functions.
// 1st with no parameters.
// 2nd with 1 string parameter.
// 3rd with 2 string parameters.
// Pay attention to how they are called.
//
// Compile with:
//
//    cc hello4.c -Wall -Werror -std=c11
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

void printGreeting( char* greeting , char* addressee )
{
  printWord( greeting );
  printComma();
  printWord( addressee );
  printf( "!\n" );
}

int main() 
{
  printGreeting( "Hello" , "world" );
  printGreeting( "Good day" , "Your Royal Highness" );
  printGreeting( "Howdy" , "John Q. and Jane P. Doe" );
  printGreeting( "Hey" , "Moe, Larry, and Curly" );

  return 0; 
}

//  <eof>
