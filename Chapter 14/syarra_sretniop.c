// syarra_sretniop.c  (this is a play on "arrays" and "pointers" reversed.
// Chapter 14
// <book title>
//
// This is a copy of arrays_pointers.c which spefically demonstrate how to 
// traverse the array _in_reverse_ using 3 methods:
//    a) using array notation incrementing index;
//    b) using pointer plus offset (pointer doesn't change); and
//    c) using incremented pointer (pointer changes).
//
// compile with: cc syarra_sretniop.c -o syarra_sretniop -Wall -Werror -std=c11
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

  // In this loop, we count down from arraySize. 
  // NOTE: because of the one-off issue, we can't use i, we have
  //       to use an adjusted index, j.
  //
  printf("\n(1) Array values using array notation (index is decremented):\n\n");

  for( int i = arraySize ; i > 0 ; i-- )
  {
    int j = i-1;
    printf( "  &(array[%1d]) = %#lx, array[%1d] = %1d, i++\n", 
            j , 
            (unsigned long)&(array[j]), 
            j , 
            array[j] );
  }

  // In this loop, only the index variable needs to be changed to count down 
  // from 4 (not 5 because of the one-off issue). We also need to adjust the 
  // stop value to -1 becuase *(pArray2+0) is the 1st value in the array.
  // 
  printf("\n(2) Array values using a pointer addition (offset is decremented):\n\n");

  for( int i = arraySize-1 ; i > -1 ; i-- )
  {
    printf( "  pArray2+%1d = %#lx, *(pArray2+%1d) = %1d, i++\n", 
            i , (unsigned long)(pArray2+i) ,
            i ,               *(pArray2+i) ); 
  }

  // In this loop, 
  //   a) the initialization expression has two operations --
  //      i is a counter from 0
  //      pArray1 starts at the last element of the array  
  // and
  //   b) the incremention expression has two operations.
  //      i is incremented
  //      pArray1 is decremented from last to first elements.
  // 
  printf("\n(3) Array values using pointer referencing (pointer is decremented):\n\n");

  int i;
  for( pArray1 = &array[arraySize-1], i = 0 ; 
       i < arraySize ; 
       i++ , pArray1-- )
  {
    printf( "  pArray1 = %#lx, *pArray1 = %1d, pArray1++\n", 
            (unsigned long)pArray1 , 
            *pArray1 );
  }
}

/* eof */