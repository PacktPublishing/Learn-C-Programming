// arrays_pointers.c
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
// compile with: cc arrays_pointers.c -o arrays_pointers -Wall -Werror -std=c11
//

#include <stdio.h>

int main(int argc, char *argv[]) 
{
  const int arraySize = 5;
  int  array[5] = { 1 , 2 , 3 , 4 , 5 };
  int* pArray1  = array;
  int* pArray2  = &(array[0]);
  
  printf("Pointer values (addresses) from initial assignments:\n\n");
  
  printf( "      address of array = %#lx,    value at array = %d\n" , 
          (unsigned long)array ,
                        *array );
  printf( "  address of &array[0] = %#lx, value at array[0] = %d\n" ,
          (unsigned long)&array[0] ,
                          array[0] );
  printf( "    address of pArray1 = %#lx,  value at pArray1 = %#lx\n" , 
          (unsigned long)&pArray1 ,
          (unsigned long) pArray1 );
  printf( "    address of pArray2 = %#lx,  value at pArray2 = %#lx\n\n" , 
          (unsigned long)&pArray2 , 
          (unsigned long) pArray2 );

  printf("\n(1) Array values using array notation (index is incremented):\n\n");

  for( int i = 0; i < arraySize ; i++ )
    printf( "  &(array[%1d]) = %#lx, array[%1d] = %1d, i++\n", 
            i , 
            (unsigned long)&(array[i]), 
            i , 
            array[i] );

  printf("\n(2) Array values using a pointer addition (offset is incremented):\n\n");

  for( int i = 0 ; i < arraySize; i++  )
    printf( "  pArray2+%1d = %#lx, *(pArray2+%1d) = %1d, i++\n", 
            i , (unsigned long)(pArray2+i) ,
            i ,               *(pArray2+i) ); 

  printf("\n(3) Array values using pointer referencing (pointer is incremented):\n\n");

  for( int i = 0 ; i < arraySize ; i++ , pArray1++ )
    printf( "  pArray1 = %#lx, *pArray1 = %1d, pArray1++\n", 
            (unsigned long)pArray1 , 
            *pArray1 );
}

/* eof */