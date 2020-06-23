// array3.c
// Chapter 11
// <book title>
//
// Demonstrate using arrays in functions and 
// as parameters to functions..
//
// build with:
//      cc array3.c -o array3 -lm -Wall -Werror -std=c11

#include <stdio.h>
#include <math.h>

#include "array3.h"


int main( void )
{
  int array1[] = { 3 , 4 , 6 , 8, 13 , 17 , 18 , 19 };
  int array2[] = { 34 , 88 , 32 , 12 , 10 };

  int size = sizeof( array1 ) / sizeof( int );
  printf( "array1: range, mean, & standard deviation\n" );
  printf( "    range = [%d..%d]\n" , 
          findMin( size , array1 ) ,
          findMax( size , array1 ) );
  printf( "     mean = %g\n" ,  findMean( size , array1 ) );
  printf( "  std dev = %g\n\n", findStdDev( size , array1 ) );


  size = sizeof( array2 ) / sizeof( int );
  printf( "array2: range, mean, & standard deviation\n" );
  printf( "    range = [%d..%d]\n" , 
          findMin( size , array2 ) ,
          findMax( size , array2 ) );
  printf( "     mean = %g\n" ,  findMean( size , array2 ) );
  printf( "  std dev = %g\n\n", findStdDev( size , array2 ) );
} 


int findMin( int size , int a[] )
{
  int min = a[0];  
  for( int i = 1 ; i < size ; i++ )
    if( a[i] < min )   min = a[i];
  return min;  
}


int findMax( int size , int a[] )
{
  int max = a[0];  
  for( int i = 1 ; i < size ; i++ )
    if( a[i] > max )  max = a[i];
  return max;  
}


double findMean( int size , int a[] )
{
  double sum  = 0.0;
  for( int i = 0 ; i < size ; i++ )
  {
    sum += a[i];
  }
  double mean = sum / size;
  return mean;
}


double findStdDev( int size , int a[] )
{
    // Compute variance.
  
  double mean     = findMean( size , a );
  double sum      = 0.0;
  double variance = 0.0;
  
  for( int i = 0; i < size ; i++ )
  {
    sum += pow( (a[i] - mean) , 2 );
  }
  variance = sum / size;

    // Compute standard deviation from variance.

  double stdDev = sqrt( variance );
  return stdDev;
}

  // eof
  
