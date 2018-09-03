//
// hello7.c
// Chapter 2
// <book title>
//
// Using function prototypes to call our functions in any
// order (before the compiler processes the function body).
// Sometimes this is called "top-down" function implementation.
//

#include <stdio.h>

// function prototypes

void printGreeting(    char* aGreeting , char* aName );
void printAGreeting(   char* greeting );
void printAnAddressee( char* aName );
void printAComma(   void );
void printANewLine( void );


int main() 
{
  printGreeting( "Hi" , "Bub" );

  return 0; 
}

void printGreeting( char* aGreeting , char* aName )
{
  printAGreeting( aGreeting );
  printAComma();
  printAnAddressee( aName );
  printANewLine();
}

void printAGreeting( char* greeting )
{
  printf( "%s" , greeting );
}

void printAnAddressee( char* aName )
{
  printf( "%s" , aName );
}

void printAComma( void )
{
  printf( ", " );
}

void printANewLine()
{
  printf( "\n" );
}

//  <eof>
