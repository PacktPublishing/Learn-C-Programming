  // summing1.c
  // Chapter 7
  // <book title>
  //
  // Demonstrate looping:
  // 1. 2 rather ugly brute-force methods.
  // 2. Gauss's single line calculation.
  // 3. Counter-controlled looping with while().
  // 4. Counter-controlled looping with for().
  // 5. Counter-controlled looping with do...while().
  
#include <stdio.h>
#include <stdbool.h>

int sum100bruteForce(  void );
int sum100bruteForce2( void );
int sumNviaGauss( int n );
int sumNviaFor( int n );
int sumNviaWhile( int n );
int sumNviaDoWhile( int n );
int sumNviaGoto( int n );


int main( void )
{
  int n = 100;
  printf( "The sum of 1..100 = %d (via brute force)\n"      , sum100bruteForce() );
  printf( "The sum of 1..100 = %d (via brute force2)\n"     , sum100bruteForce2() );
  printf( "The sum of 1..%d = %d (via Gaussian insight)\n"  , n , sumNviaGauss( n ) );
  printf( "The sum of 1..%d = %d (via while() loop)\n"      , n , sumNviaWhile( n ) );
  printf( "The sum of 1..%d = %d (via for() loop)\n"        , n , sumNviaFor( n ) );
  printf( "The sum of 1..%d = %d (via do...while() loop)\n" , n , sumNviaDoWhile( n ) );
  printf( "The sum of 1..%d = %d (via <gasp> goto)\n"       , n , sumNviaGoto( n ) );

  return 0;
}

int sum100bruteForce( void )
{
  int sum = 0;
  sum  = 1;
  sum += 2;
  sum += 3;
  sum += 4;
  sum += 5;
  sum += 6;
  sum += 7;
  sum += 8;
  sum += 9;
  sum += 10;
  
  sum += 11;
  sum += 12;
  sum += 13;
  sum += 14;
  sum += 15;
  sum += 16;
  sum += 17;
  sum += 18;
  sum += 19;
  sum += 20;
 
  sum += 21;
  sum += 22;
  sum += 23;
  sum += 24;
  sum += 25;
  sum += 26;
  sum += 27;
  sum += 28;
  sum += 29;
  sum += 30;

  sum += 31;
  sum += 32;
  sum += 33;
  sum += 34;
  sum += 35;
  sum += 36;
  sum += 37;
  sum += 38;
  sum += 39;
  sum += 40;

  sum += 41;
  sum += 42;
  sum += 43;
  sum += 44;
  sum += 45;
  sum += 46;
  sum += 47;
  sum += 48;
  sum += 49;
  sum += 50;

  sum += 51;
  sum += 52;
  sum += 53;
  sum += 54;
  sum += 55;
  sum += 56;
  sum += 57;
  sum += 58;
  sum += 59;
  sum += 60;

  sum += 61;
  sum += 62;
  sum += 63;
  sum += 64;
  sum += 65;
  sum += 66;
  sum += 67;
  sum += 68;
  sum += 69;
  sum += 70;

  sum += 71;
  sum += 72;
  sum += 73;
  sum += 74;
  sum += 75;
  sum += 76;
  sum += 77;
  sum += 78;
  sum += 79;

  sum += 80;
  sum += 81;
  sum += 82;
  sum += 83;
  sum += 84;
  sum += 85;
  sum += 86;
  sum += 87;
  sum += 88;
  sum += 89;
  sum += 90;

  sum += 91;
  sum += 92;
  sum += 93;
  sum += 94;
  sum += 95;
  sum += 96;
  sum += 97;
  sum += 98;
  sum += 99;
  sum += 100;

  return sum;  
}


int sum100bruteForce2( void )
{
  int sum = 0;
  int num = 1;
  sum  =   num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;  // 10
  
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;  // 20
  
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;  // 30
  
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;  // 40
  
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;  // 50
  
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;  // 60
  
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;  // 70
  
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;  // 80
  
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;  // 90
 
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;
  sum += ++num;  // 100

  return sum;  
}

  // The brilliant mathematician Gauss solved the tedious 
  // "busy work" problem of adding the numbers 1 to 100 with the 
  // following simple equation when he was in elementary school.
  // 
  // See http://mathcentral.uregina.ca/QQ/database/QQ.02.06/jo1.html
  // and https://trans4mind.com/personal_development/mathematics/series/sumNaturalNumbers.htm
  // for delightful explanations.
  //
int sumNviaGauss( int N )
{
  int sum = 0;
  sum = N * ( N+1 ) / 2;
  return sum;
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


int sumNviaGoto( int N )
{
  int sum = 0;

  int num = 0;

begin_loop:

  sum += (num+1);
  num++;
  
  if( num < N ) goto begin_loop;  // loop!
  // else fall-through out of loop. 
end_loop:  // label here only for convenience to know bounds of loop.

  return sum;
}


  // eof
