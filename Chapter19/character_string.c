// character_string.c
// Chapter 19
// Learn C Programming
//
// Demonstrate how to 
// 1) print a string using minimum field width, precision and alignment.
// 2) print sub-strings with pointer arithmetic.
// 3) print a character using minimum field width and alignment
//
// compile with:
//
//     cc character_string.c -o character_string -Wall -Werror -std=c11
//

#include <stdio.h>

int main( void )
{
   char  aChar = 'C' ;
   char* pStr  = "Learn to program with C" ;
  
   printf( "String output\n" );
   printf( " Specifier Formatted Value\n" );
   printf( " %%s       [%s]         everything\n" ,                       pStr );
   printf( " %%30s     [%30s]  everything right-aligned, field=30\n" ,    pStr );
   printf( " %%.10s    [%.10s]                      truncated to first 10 characters\n" ,    pStr );
   printf( " %%30.10s  [%30.10s]  only 10 chars right-aligned, field=30\n" , pStr );
   printf( " %%-30.10s [%-30.10s]  only 10 chars left-aligned, field=30\n\n" , pStr );
   printf( " %%*.*s    [%*.*s]  use width & precision in argument list\n\n" , 30 , 10 , pStr );

  printf( "Sub-string output\n" );
  printf( " %%.7s     [%.7s]       3rd word (using array offset)\n" ,              &pStr[9] );
  printf( " %%.12s    [%.12s]  3rd and 4th words (using pointer arithmetic)\n\n" ,  pStr + 9 );
  
  printf( "Character output\n" );
  printf( " %%c       [%c]             character\n" ,                    aChar );
  printf( " %%10c     [%10c]    character right-aligned, field=10\n" ,   aChar );
  printf( " %%-10c    [%-10c]    character left-aligned, field=10\n\n" , aChar );
}

  //  eof
