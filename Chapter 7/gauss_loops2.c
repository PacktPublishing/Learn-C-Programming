  // gauss_loops2.c
  // Chapter 7
  // <book title>
  //
  // Demonstrate looping with:
  // 1. Counter-controlled looping with while()... C idioms.
  // 1. Counter-controlled looping with for()... C idioms
  // 3. Counter-controlled looping with do...while() C idioms.
  // 
  // The purpose here is to show looping with idiomatic C styles.
  // The minimum of local variables are used; the input parameter
  // is used/altered as appropriate. 
  //
  // Note how it can sometimes be clearer to count down rather 
  // than up. Remember to be certain for your loop ranges!
  //


#include <stdio.h>
#include <stdbool.h>


int sumNviaFor2(     int N );
int sumNviaWhile2(   int N );
int sumNviaDoWhile2( int N );


int main( void )
{
  int n = 100;

  printf( "The sum of 1..%d = %d (via while() ... loop 2)\n"  , n , sumNviaWhile2( n ) );
  printf( "The sum of 1..%d = %d (via for() ... loop 2)\n"    , n , sumNviaFor2( n ) );
  printf( "The sum of 1..%d = %d (via do...while() loop 2)\n" , n , sumNviaDoWhile2( n ) );

  return 0;
}


  // a more C-like While() ... loop
  //
int sumNviaWhile2( int N )
{
  int sum = 0;

  while( N )      // N: N down to 1 (stops at 0).
  {
    sum += N;
    N--;
  }

  return sum;
}


  // A more C-like For() ... loop.
  //
  // The for conditions are presented each on their own line.
  // This is not really useful when these statements are simple
  // but can be clearer as the for conditions get more complicated
  // with multiple indexs, multiple relations, and/or multiple counter
  // increments.
  //
int sumNviaFor2( int N )
{
  int sum = 0;

  for( int i = N ;  // range: 100..1
       i > 0 ;      // stops at 1.
       i--
     ) 
  {
    sum += i;       // No off-by-one.
  }

  return sum;
}


  // a more C-like Do ... While()
  //
int sumNviaDoWhile2( int N )
{
  int sum = 0;

  do {
    sum += N;
    N--;
  } while ( N );    // range: N down to 1 (stops at 0).

  return sum;
}


  // eof
