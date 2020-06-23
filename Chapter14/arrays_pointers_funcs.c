// arrays_pointers_funcs.c
// Chapter 14
// Learn C Programming
//
// This is a copy of arrays_pointers.c which spefically demonstrate how to 
// traverse the array using the array as a function parameter using 2 methods:
//    a) a function with the array name using array notation;
//    b) a function with a pointer to 1st element using pointer arithmetic;
//    c) a function with the array name using pointer arithmetic; and
//    d) a function with a pointer to 1st element using array notation;
//
// compile with:
//
//    cc arrays_pointers_funcs.c -o arrays_pointers_funcs -Wall -Werror -std=c11
//

#include <stdio.h>

void traverse1( int size , int  arr[] );
void traverse2( int size , int* pArr );
void traverse3( int size , int  arr[] );
void traverse4( int size , int* pArr );


int main(int argc, char *argv[]) 
{
  const int arraySize = 5;
  int  array[5] = { 10 , 20 , 30 , 40 , 50 };
  
  printf("Pointer values (addresses) from initial assignments:\n\n");
  
  printf( "      address of array = %#lx,    value at array = %d\n" , 
          (unsigned long)array ,
                        *array );
  printf( "  address of &array[0] = %#lx, value at array[0] = %d\n" ,
          (unsigned long)&array[0] ,
                          array[0] );

  traverse1( arraySize , array );
  traverse2( arraySize , array ); 
  traverse3( arraySize , array );
  traverse4( arraySize , array ); 
}

// see printf() for function purpose.
//
void traverse1( int size , int arr[] )
{
  printf("\n(1) Function parameter is an array, using array notation:\n\n");

  for( int i = 0; i < size ; i++ )
    printf( "  &(array[%1d]) = %#lx, array[%1d] = %1d, i++\n", 
            i , 
            (unsigned long)&(arr[i]), 
            i , 
            arr[i] );
}


// see printf() for function purpose.
//
void traverse2( int size , int* pArr )
{ 
  printf("\n(2) Function parameter is a pointer, using pointer:\n\n");

  for( int i = 0 ; i < size ; i++ , pArr++ )
    printf( "  pArr = %#lx, *pArr = %1d, pArr++\n", 
            (unsigned long)pArr , 
            *pArr );
}


// see printf() for function purpose.
//
void traverse3( int size , int arr[] )
{
  printf("\n(3) Function parameter is an array, using pointer:\n\n");

  for( int i = 0 ; i < size ; i++ , arr++ )
    printf( "  arr = %#lx, *arr = %1d, arr++\n", 
        (unsigned long)arr , 
        *arr );
 }


// see printf() for function purpose.
//
void traverse4( int size , int* pArr )
{ 
  printf("\n(4) Function parameter is a pointer, using array notation :\n\n");

  for( int i = 0; i < size ; i++ )
    printf( "  &(pArr[%1d]) = %#lx, pArr[%1d] = %1d, i++\n", 
        i , 
        (unsigned long)&(pArr[i]), 
        i , 
        pArr[i] );
 }

  /* eof */
