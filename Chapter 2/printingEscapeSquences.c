// 
// printingEscapeSequences.c
// Chapter 2
// <book title>
//
// Demonstrate how escape sequences appear both
// in the source code and on the console.
//

#include <stdio.h>

int main( void )
{
  printf( "Hello, world without a new line" );
  printf( "Hello, world with a new line\n" );
  printf( "A string with \"quoted text\" inside of it\n\n" );

  printf( "Tabbed\tColumn\tHeadings\n" );
  printf( "The\tquick\tbrown\n" );
  printf( "fox\tjumps\tover\n" );
  printf( "the\tlazy\tdog.\n\n" );
  
  printf( "A line of text that\nspans three lines\nand completes the line\n\n" );
  
  return 0;
}

// <eof>
