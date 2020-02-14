// heading.c
// Chapter 18
// <book title>
//
// Demonstrate how to use a static variable in 
// a function to print the next page number each time the
// function is called.
//
// compile with: cc heading.c -o heading -Wall -Werror -std=c11
//
#include <stdio.h>

void printHeading( const char* aHeading );

int main( void )  {
  printHeading( "Title Page" );
  printHeading( "Chapter 1 " );
  printHeading( "          " );
  printHeading( "          " );
  printHeading( "Chapter 2 " );
  printHeading( "          " );
  printHeading( "Conclusion" );
}

void printHeading( const char* aHeading )  {
  /* static */ int pageNo = 1;
  printf( "%s \t Page %d\n" , aHeading , pageNo);
  pageNo++;
}