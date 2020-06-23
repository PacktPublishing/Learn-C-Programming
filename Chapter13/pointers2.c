// pointers2.c
// Chapter 13
// Learn C Programming
//
// This program builds upon program pointers1.c
//
// Demonstrates how to use pointers in functions (parameters
// and in function body). Also shows what "side effects" are.
//
// Specifically 
// 1) clean up printf() statements by moving them out of 
//    main() and into functions.
// 2) use pointers in fuction parameters 
//    (copy the pointer value instead of copying the target value)
// 3) use the function pointers to access targets
// 4) demonstrate "side effects" by changing value of targets
//    (this changes them outside of the function) 
// 4) call the new functions with pointer variables.
//
// Compile with:
//
//     cc pointers2.c -o pointers2 -Wall -Werror -std=c11
//

#include <stdio.h>

void showInfo( int height, int width , int length )
{
  printf( "  sizeof(int)  = %2lu\n" ,  sizeof(int) );
  printf( "  sizeof(int*) = %2lu\n" , sizeof(int*) );
  printf( "  [height, width, length] = [%2d,%2d,%2d]\n\n" ,
             height , width , length ); 
}


void showVariable( char* pId , int* pDim )
{
  printf( "      address of %s = %#lx, value at address = %2d\n" , 
             pId,
             (unsigned long)pDim , 
             *pDim );
}

int main( void ) 
{
  int height = 10;
  int width  = 20;
  int length = 40;

  int*  pDimension = NULL;
  char* pIdentifier = NULL;
  
  printf( "\nValues:\n\n");

  showInfo( height , width , length );

  printf( "  address of pDimension = %#lx\n" , 
             (unsigned long)&pDimension  );

  printf( "\nUsing address of each named variables...\n\n");

  pIdentifier = "height";
  pDimension = &height;
  showVariable( pIdentifier , pDimension );
  pIdentifier = "width ";
  pDimension = &width;
  showVariable( pIdentifier , pDimension );
  pIdentifier = "height";
  pDimension = &length;
  showVariable( pIdentifier , pDimension );
}

  //  eof

