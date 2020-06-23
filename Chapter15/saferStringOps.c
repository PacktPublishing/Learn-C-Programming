// saferStringOps.c
// Chapter 15
// Learn C Programming
//
// Demonstrate how to 
// 1) use a string more than once
// 2) manipulate each element of a string with while()...
//
// compile with: 
//
//    cc saferStringOps.c -o saferStringOps -Wall -Werror -std=c11
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void myStringNCompare( char* s1 , char* s2 , int n);

int main( void )
{
  char salutation[] = "hello";
  char audience[]   = "everybody";
  printf( "%s, %s!\n", salutation , audience );
  
  int lenSalutation = strlen( salutation );
  int lenAudience   = strlen( audience );
  int lenGreeting1 = lenSalutation+lenAudience+1;
  char greeting1[lenGreeting1];
  
  strncpy( greeting1 , salutation , lenSalutation );
  strncat( greeting1 , audience   , lenAudience );
  printf( "%s\n" , greeting1 );
  
  char greeting2[7] = {0};
  strncpy( greeting2 , salutation , 3 );
  strncat( greeting2 , audience   , 3 );
  printf( "%s\n" , greeting2 );
 
  myStringNCompare( greeting1 , greeting2 , 7 );
  
  myStringNCompare( greeting1 , greeting2 , 3 );

  char* str1 = "abcde";
  char* str2 = "aeiou";
  char* str3 = "AEIOU";
  
  myStringNCompare( str1 , str2 , 3 );
  myStringNCompare( str2 , str3 , 5 );
}


void myStringNCompare( char* s1 , char* s2 , int n)
{
  int result = strncmp( s1 , s2 , n );

  char* pResultStr;
  if( result < 0 )      pResultStr = "less than (come before)";
  else if( result > 0 ) pResultStr = "greater than (come after)";
  else                  pResultStr = "equal to";
  printf( "First %d characters of %s are %s %s\n" , 
          n, s1 , pResultStr , s2 ); 
}

  //  eof
