  // gauss_loops.c
  // Chapter 7
  // Learn C Programming
  //
  // Demonstrate looping:
  // 1. Counter-controlled looping with while().
  // 2. Counter-controlled looping with for().
  // 3. Counter-controlled looping with do...while().
  //
  // Compile with:
  //
  //    cc gauss_loops.c -o gauss_loops -Wall -Werror -std=c11
  //


#include <stdio.h>
#include <stdbool.h>


int sumNviaFor(     int n );
int sumNviaWhile(   int n );
int sumNviaDoWhile( int n );
int sumNviaGoto(    int n );


int main( void )
{
  int n = 100;

  printf( "The sum of 1..%d = %d (via while() ... loop)\n"  , n , sumNviaWhile( n ) );
  printf( "The sum of 1..%d = %d (via for() ... loop)\n"    , n , sumNviaFor( n ) );
  printf( "The sum of 1..%d = %d (via do...while() loop)\n" , n , sumNviaDoWhile( n ) );

  return 0;
}


int sumNviaWhile( int N )
{
  int sum = 0;

  int num = 0;
  while( num < N )      // num: 0..99 (100 is not less than 100)
  {
    sum += (num+1);       // Off-by-one: shift 0..99 to 1..100.
    num++;
  }
  
  return sum;
}


int sumNviaFor( int N )
{
  int sum = 0;

  for( int num = 0 ; num < N ; num++ )  // num: 0..99 (it's a C thing)
  {
    sum += (num+1);                       // Off-by-one: shift 0..99 to 1..100.
  }

  return sum;
}


int sumNviaDoWhile( int N )
{
  int sum = 0;

  int num = 0;
  do {
    sum += (num+1);         // Off-by-one: shift 0..99 to 1..100.
    num++;
  } while ( num < N );    // num: 0..99 (100 is not less than 100).

  return sum;
}


  // eof
