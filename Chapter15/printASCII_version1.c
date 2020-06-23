// printASCII_version1.c
// Chapter 15
// Learn C Programming
//
// Demonstrate how to 
// 1) builds upon showChar.c
// 2) print the ASCII values 32 through 64
//
// compile with: 
//
//    cc printASCII_version1.c -o printASCII_version1 -Wall -Werror -std=c11
//


#include <stdio.h>


int main( void )
{
  char c2;
  for( int i = 32 ; i < 64 ; i++ )
  {
    c2 = i;
    printf("%c %3d %#x\n" , c2 , c2 ,c2 );
  }
}  

  // eof
