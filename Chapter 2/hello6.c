//
// hello6.c
// Chapter 2
// <book title>
//
// Breaking our program into a bunch of small functions.
//

#include <stdio.h>

void printAGreeting( char* greeting )
{
  printf( "%s" , greeting );
}

void printAComma( void )
{
  printf( ", " );
}

void printAnAddressee( char* aName )
{
  printf( "%s" , aName );
}

void printANewLine()
{
  printf( "\n" );
}

void printGreeting( char* aGreeting , char* aName )
{
  printAGreeting( aGreeting );
  printAComma();
  printAnAddressee( aName );
  printANewLine();
}

int main() 
{
  printGreeting( "Hi" , "Bub" );

  return 0; 
}

//  <eof>
