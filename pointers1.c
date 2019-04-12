// pointers1.c
// Chapter 13
// <book title>
//
// Demonstrate how to 
// 1) declare a pointer to int
// 2) get info about the pointer (its address, size)
// 3) assign targets to the pointer 
// 4) print out info about the targets.
//
// compile with: cc pointers1.c -o pointers1 -Wall -Werror -std=c11
//

#include <stdio.h>

int main( void ) 
{

  int height = 10;
  int width  = 20;
  int length = 40;

  int* pDimension = NULL;
  
  printf( "\nValues:\n\n");

  printf( "  sizeof(int) = %2lu\n" ,  sizeof(int) );
  printf( "  sizeof(int*) = %2lu\n" , sizeof(int*) );
  printf( "  [height, width, length] = [%2d,%2d,%2d]\n\n" ,
             height , width , length );
  printf( "  address of pDimension = %#lx\n" , 
             (unsigned long)&pDimension  );

  printf( "\nUsing address of each named variables...\n\n");

  pDimension = &height;
  printf( "      address of height = %#lx, value at address = %2d\n" , 
             (unsigned long)pDimension , *pDimension );
  pDimension = &width;
  printf( "      address of width  = %#lx, value at address = %2d\n" , 
             (unsigned long)pDimension , *pDimension );
  pDimension = &length;
  printf( "      address of length = %#lx, value at address = %2d\n" , 
             (unsigned long)pDimension , *pDimension );

}