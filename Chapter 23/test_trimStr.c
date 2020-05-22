// test_trim.c
// Chapter 23
// Learn C Programming - Fundamentals of C
//
// This program exercises the trimStr() function.
//
// Compile with: 
//
//   cc test_trim.c -o test_trim -Wall -Werror -std=c11
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* trimStr( char* pString );

int main( void )  {

  char string[80] = {0};

  strcpy(  string , "With charming ease, the quick brown fox jumps over the lazy dog.\n" );
  fprintf( stderr , "1. Test of \"normal\" string\n" );
  fprintf( stderr , "   before: \"%s\"\n"   , string );
  fprintf( stderr , "    after: \"%s\"\n\n" , trimStr( string ) );

  strcpy(  string , "Box of frogs \t \n" );
  fprintf( stderr , "2. Test of trailing whitespace\n" );
  fprintf( stderr , "   before: \"%s\"\n"   , string );
  fprintf( stderr , "    after: \"%s\"\n\n" , trimStr( string ) );

  strcpy(  string , " \t  Bag of hammers" );
  fprintf( stderr , "3. Test of leading whitespace\n" );
  fprintf( stderr , "   before: \"%s\"\n"   , string );
  fprintf( stderr , "    after: \"%s\"\n\n" , trimStr( string ) );

  strcpy(  string , "\t\t  Sack of ferrets\t\t   " );
  fprintf( stderr , "4. Test of leading & trailing whitespace\n" );
  fprintf( stderr , "   before: \"%s\"\n"   , string );
  fprintf( stderr , "    after: \"%s\"\n\n" , trimStr( string ) );

  strcpy(  string , "   \b\t   " );
  fprintf( stderr , "5. Test of whitespace only\n" );
  fprintf( stderr , "   before: \"%s\"\n"   , string);
  fprintf( stderr , "    after: \"%s\"\n\n" , trimStr( string ) );

  strcpy(  string , "" );
  fprintf( stderr , "6. Test of empty string\n" );
  fprintf( stderr , "   before: \"%s\"\n"   , string );
  fprintf( stderr , "    after: \"%s\"\n\n" , trimStr( string ) );
}

  // trimStr - Trims beginning and end of a string.
  //           Pointer to beginning of input string may be 
  //           modified; therefore, return value is essential.
  //
  // Parameter:
  //   pString - pointer to string to be trimmed.
  // Returns:
  //   A pointer to the beginning of the trimmed string.
  //    
char* trimStr( char* pString )
{
  int first = 0;
  int last  = 0;
  int len   = 0;

    // Left Trim
    // Find 1st non-whitespace char; pStr will point to that.
  while( isspace( pString[ first ] ) )
    first++;
  pString += first;

  len = strlen( pString ); // Get new length after Left Trim.
  if( len )  {             // Check for empty string. e.g. "   " trimmed to nothing.
      // Right Trim
      // Find 1st non-whitespace char & set NUL character there.
    last = len-1; // off-by-1 adjustment.
    while( isspace( pString[ last ] ) )
      last--;
    pStr[ last+1 ] = 0;  // Terminate trimmed string.
  }
  return pString;
}

