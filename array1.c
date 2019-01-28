// array1.c
// Chapter 11
// <book title>
//
// Demonstrate how to declare and initialize
// arrays..
// 

#include <stdio.h>


int main( void )
{
  int   anArray[10]  = {0}; // Initialize the whole thing to 0.

  int typeSize   = sizeof( int );
  int arraySize  = sizeof( anArray );
  int elementNum = arraySize / typeSize;

  printf( "      sizeof(int) = %2d bytes\n"   , typeSize  );
  printf( "  sizeof(anArray) = %2d bytes\n"   , arraySize  );
  printf( "  anArray[] has %d elements\n\n" , elementNum ); 

     // Dynamically allocate array size via initialization.

  float lengthArray[] = { 1.0 , 2.0 , 3.0 , 4.0 , 3.0 , 2.0 , 1.0 };
  
  typeSize   = sizeof( float );
  arraySize  = sizeof( lengthArray );
  elementNum = arraySize / typeSize;
 
  printf( "        sizeof(float) = %2d bytes\n"   , typeSize  );
  printf( "  sizeof(lengthArray) = %2d bytes\n"   , arraySize  );
  printf( "   lengthArray[] has %d elements\n"  , elementNum );  
} 