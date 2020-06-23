  // gauss_goto.c
  // Chapter 7
  // Learn C Programming
  //
  // Demonstrate counter-controlled looping with goto
  // 1. Do ...  while() goto loop
  // 2. While() ... goto loop
  // 3. For() ... goto loop
  //
  // For each goto loop function, the corresponding C statement function 
  // is included for comparison.
  // 
  // Compile with:
  //
  //    cc gauss_goto.c -o gauss_goto -Wall -Werror -std=c11
  //
  
#include <stdio.h>
#include <stdbool.h>

int sumNviaWhile(      int N );
int sumNviaGoto_While( int N );

int sumNviaDoWhile( int N );
int sumNviaGoto_Do( int N );

int sumNviaGoto_For( int N );
int sumNviaFor(      int N );


int main( void )
{
  int n = 100;
  printf( "The sum of 1..%d = %d (via do-like goto loop)\n"    , n , sumNviaGoto_Do( n ) );
  printf( "The sum of 1..%d = %d (via while-like goto loop)\n" , n , sumNviaGoto_While( n ) );
  printf( "The sum of 1..%d = %d (via for-like goto loop)\n"   , n , sumNviaGoto_For( n ) );

  return 0;
}


  // ------------ DoWhile and Goto_Do

int sumNviaDoWhile( int N )
{
  int sum = 0;
  int num = 0;

  do 
  {
    sum += (num+1);      // Off-by-one: shift 0..99 to 1..100.
    num++;
  } while ( num < N );   // num: 0..99 (100 is not less than 100).
  
  return sum;
}


int sumNviaGoto_Do( int N )
{
  int sum = 0;
  int num = 0;

begin_loop:

  sum += (num+1);
  num++;
  
  if( num < N ) goto begin_loop; // loop!
  // else fall-through out of loop.

end_loop:

  return sum;
}


  // ------------ While and Goto_While

int sumNviaWhile( int N )
{
  int sum = 0;
  int num = 0;

  while( num < N )    // num: 0..99 (100 is not less than 100)
  {
    sum += (num+1);   // Off-by-one: shift 0..99 to 1..100.
    num++;
  } 

  return sum;
}


int sumNviaGoto_While( int N )
{
  int sum = 0;
  int num = 0;

begin_loop:

  if( !(num < N) ) goto end_loop;

  sum += (num+1);
  num++;

  goto begin_loop;

end_loop:

  return sum;
}


  // ------------ For and Goto_For

int sumNviaFor( int N )
{
  int sum = 0;
  for( int num = 0 ; num < N ; num++ )  // num: 0..99 (it's a C thing)
  {
    sum += (num+1);                     // Off-by-one: shift 0..99 to 1..100.
  }
  return sum;
}


int sumNviaGoto_For( int N)
{
  int sum = 0;
  int num = 0;

  int i = 0;                     // initialize counter

begin_loop:

  if( !(i < N) ) goto end_loop;  // test condition

  sum += (num+1);
  num++;
  
  i++;                           // counter increment
  goto begin_loop;

end_loop:

  return sum;
}


  // eof
