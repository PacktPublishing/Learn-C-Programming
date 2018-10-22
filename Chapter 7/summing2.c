  // summing2.c
  // Chapter 7
  // <book title>
  //
  // Demonstrate looping:
  // 1. Counter-controlled looping with while()
  // 1. Counter-controlled looping with for()
  // 3. Counter-controlled looping with do...while()
  // 
  // We've removed the brute force functions. They just aren't 
  // interesting.
  
#include <stdio.h>
#include <stdbool.h>

int sumNviaFor( int N );
int sumNviaWhile( int N );
int sumNviaDoWhile( int N );


int main( void )
{
  int n = 100;
  printf( "The sum of 1..%d = %d (via while() loop)\n"      , n , sumNviaWhile( n ) );
  printf( "The sum of 1..%d = %d (via for() loop)\n"        , n , sumNviaFor( n ) );
  printf( "The sum of 1..%d = %d (via do...while() loop)\n" , n , sumNviaDoWhile( n ) );

  return 0;
}


  // a more C-like While-loop
  //
int sumNviaWhile( int N )
{
  int sum = 0;

  while( N )      // n: n down to 0.
  {
    sum += N;
    N--;
  }

  return sum;
}


int sumNviaFor( int N )
{
  int sum = 0;

  for( int i = 0 ;
       i < N ; 
       i++
     )                              // i: 0..9 (it's a C thing)
  {
    sum += (i+1);                   // Off-by-one: shift 0..9 to 1..10.
  }

  return sum;
}

  // a more C-
int sumNviaDoWhile( int N )
{
  int sum = 0;

  do {
    sum += N;
    N--;
  } while ( N );    // n: n down to 0.

  return sum;
}
F

  // eof
