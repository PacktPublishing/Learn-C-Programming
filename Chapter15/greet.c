// greet.c
// Chapter 15
// <book title>
//
// Demonstrate how to 
// 1) use a string more than once
// 2) manipulate each element of a string with while()...
//
// compile with: cc greet.c -o greet -Wall -Werror -std=c11
//

#include <stdio.h>
#include <ctype.h>

int main( void )
{  
  char greeting[] = "hello, world!" ;
  printf( "%s\n" , greeting );
  
  int i = 0;
  while( greeting[i] != '\0' ) {
    greeting[i] = toupper( greeting[i] );
    i++;
  }
  printf( "%s\n" , greeting );
}