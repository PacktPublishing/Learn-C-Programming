// printASCII_version2.c
// Chapter 15
// <book title>
//
// Demonstrate how to 
// 1) builds upon printASCII_version1.c
// 2) print the ASCII values 32 through 127 -- but doesn't handle DEL character
//
// compile with: cc printASCII_version1.c -o printASCII_version1 -Wall -Werror -std=c11
//


#include <stdio.h>


int main( void )
{
  char c1 , c2 , c3 , c4;
  
  printf("| Ch Dec  Hex | Ch Dec  Hex | Ch Dec  Hex |\n" ); 
  printf("|-------------|-------------|-------------|\n" );

  for( int i = 0 ; i < 32; i++)
  {
    c1 = i;    // <-- Not used yet (a dummy assignment for now).
    c2 = i+32;
    c3 = i+64;
    c4 = i+96;
    
    printf( "|  %c %3d %#x |  %c %3d %#x |  %c %3d %#x |" ,
              c2 , c2 , c2 ,
              c3 , c3 , c3 ,
              c4 , c4 , c4  );
    printf( "\n" );
  }  // for
}  // main

  /* eof */
