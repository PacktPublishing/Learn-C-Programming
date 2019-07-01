// arrayOfPointers.c
// Chapter 14
// <book title>
//
// Demonstrate how to 
// 1) an array name is interchangeable with a pointer to the same address
// 2) get info about the pointers and their values
// 3) traverse the array using 3 methods:
//    a) using array notation incrementing index;
//    b) using pointer plus offset (pointer doesn't change); and
//    c) using incremented pointer (pointer changes).
//
// compile with: cc arrayOfPointers.c -o arrayOfPointers -Wall -Werror -std=c11
//

#include <stdio.h>

int main( void)
{
    // Set everything up.

    // Standard 2D array.

  int arrayStd[3][5] = { { 11 , 12 , 13 , 14 , 15 } ,
                         { 21 , 22 , 23 , 24 , 25 } ,
                         { 31 , 32 , 33 , 34 , 35 } };
  
    // Array of pointers.
  
  int* arrayPtr[3] = { NULL };

    // Array sizes and pointer for pointer traversal.
    
  const int rows = 3;
  const int cols = 5;
  
  int* pInteger;
  
    // Sub-arrays.

  int array1[5]     = { 11 , 12 , 13 , 14 , 15 };
  int array2[5]     = { 21 , 22 , 23 , 24 , 25 };
  int array3[5]     = { 31 , 32 , 33 , 34 , 35 };

  arrayPtr[0] = array1;
  arrayPtr[1] = array2;
  arrayPtr[2] = array3;

    // Do traversals.
    
  printf( "Print both arrays using array notation, array[i][j].\n\n");
  
  for( int i = 0 ; i < rows ; i++ )
  {
    for( int j = 0 ; j < cols ; j++ )
    {
        printf( " %2d" , arrayStd[i][j]);
    }
    printf( "\n" );
  }
  printf("\n");
  
  for( int i = 0 ; i < rows ; i++ )
  {
    for( int j = 0 ; j < cols ; j++ )
    {
        printf( " %2d" , arrayPtr[i][j]);
    }
    printf( "\n" );
  }
  printf("\n");
  

  printf( "Print both arrays using pointers, *pInteger++.\n\n");

  pInteger = &(arrayStd[0][0]);
  for( int i = 0 ; i < rows ; i++ )
  {
    for( int j = 0 ; j < cols ; j++ )
    {
      printf( " %2d" , *pInteger++);
    }
    printf( "\n" );
  }
  printf("\n");
  
    // This line is here if you camment out "pInteger = arrayPtr[j];", below.
    // Otherwise, pInteger is reassigned with that statement and this one has no effect.
    
  pInteger = arrayPtr[0];

  for( int i = 0 ; i < rows ; i++ )
  {
 //   pInteger = arrayPtr[i];  // Get the pointer to the correct sub-array.
    
    for( int j = 0 ; j < cols ; j++ )
    {
      printf( " %2d" , *pInteger++);
    }
    printf( "\n" );
  }
  printf("\n");

//  Bonus:
//
//    Traversing 2D array as a single array of row*col elements.
//
//  printf("Because arrayStd is a contiguous block, we could also traverse\n");
//  printf("it as if it was a 3x5, or 15-element, 1D array.\n\n");
//  
//  pInteger = &(arrayStd[0][0]);
//  for( int i = 0 ; i < (rows*cols) ; i++)
//  {
//    printf( " %2d" , *pInteger++);
//    if( i%5 == 4 ) printf("\n");
//  }
//  printf("\n");

}