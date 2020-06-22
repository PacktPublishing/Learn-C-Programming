// array2.c
// Chapter 11
// <book title>
//
// Demonstrate arroy bounds issues.
// 


#include <stdio.h>


int main( void )
{
  int i, j, k;
  i = j = k = 0;
  int   anArray[10]  = {0}; // Initialize the whole thing to 0.
  int x, y , z;
  x = 11;
  y = 12;
  z = 13;
  
//  anArray[ 11 ] = 7; // Compiler error!
  anArray[ x]  = 0;  // No compiler error, but runtime error!
} 
