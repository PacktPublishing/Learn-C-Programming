  // logical.c
  // Chapter 5
  // <book title>
  //
  // Program to print out logical operagtor
  // "truth" tables for !!, &&, and !
  //

  
#include <stdio.h>
#include <stdbool.h>


void printLogicalAND( bool z, bool o );
void printLogicalOR(  bool z, bool o );
void printLogicalNOT( bool z, bool o );


int main( void )
{
  bool one  = 1;
  bool zero = 0;

  printLogicalAND( zero , one );
  printLogicalOR(  zero , one );
  printLogicalNOT( zero , one );
  
  return 0;
}

void printLogicalAND( bool z, bool o )
{
  bool zero_zero = z && z ;
  bool zero_one  = z && o ;
  bool one_zero  = o && z ;
  bool one_one   = o && o ;

  printf( "AND | %1d | %1d\n"       , z , o );
  printf( "  %1d | %1d | %1d\n"     , z, zero_zero , zero_one );
    printf( "  %1d | %1d | %1d\n\n" , o , zero_one  , one_one );
  printf( "\n" );
}

void printLogicalOR( bool z, bool o )
{
  bool zero_zero = z || z ;
  bool zero_one  = z || o ;
  bool one_zero  = o || z ;
  bool one_one   = o || o ;

  printf( "OR  | %1d | %1d\n"     , z , o );
  printf( "  %1d | %1d | %1d\n"   , z , zero_zero , zero_one );
  printf( "  %1d | %1d | %1d\n\n" , o , zero_one  , one_one );
}

void printLogicalNOT( bool z, bool o )
{
  bool not_zero = !z ;
  bool not_one  = !o ;
  
  printf( "NOT \n" );
  printf( "  %1d | %1d \n"   , z , not_zero );
  printf( "  %1d | %1d \n\n" , o , not_one  );
}

  // eof 
