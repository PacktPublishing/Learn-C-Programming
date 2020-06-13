// bstr_trim.c
// Appendix
// Learn C Programming - Fundamentals of C
//
// Compare trimStr we created in Chapter 23 to 
// trim function available in bstrlib.
//
// Download bstrlib sources from 
//    http://bstring.sourceforge.net
// or
//    https://github.com/websnarf/bstrlib  
//
// Dependencies:
//
//   bstrlib.h
//   bstrlib.c
//
// Compile with: 
//
//   cc bstr_trim.c bstrlib.c -o bstr_trim -Wall -Werror -std=c11
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "bstrlib.h"

int  CTrimStr( char* pCStr );
int  BTrimStr( bstring b );

void testTrim( int testNum , char* pString );

int main( void )  {
  testTrim( 1 , "Hello, World!\n" );
  testTrim( 2 , "Box of frogs \t \n" );
  testTrim( 3 , " \t  Bag of hammers" );
  testTrim( 4 , "\t\t  Sack of ferrets\t\t   " );
  testTrim( 5 , "   \t\n\v\t\r   " );
  testTrim( 6 , "" );
  testTrim( 7 , "Goodbye, World!" );
}


void testTrim( int testNum , char* pInputString )
{
  size_t len;
  char testString[ strlen( pInputString ) + 1];
  
  strcpy( testString , pInputString );
  fprintf( stderr , "%1d. original: \"%s\" [len:%d]\n"   , testNum, testString ,
           (int)strlen( pInputString ) );

  strcpy( testString , pInputString );
  len = CTrimStr( testString );
  fprintf( stderr , "   CTrimStr: \"%s\" [len:%d]\n" , testString , (int)len ) ;

  bstring b = bfromcstr( pInputString );
  len = BTrimStr( b );
  fprintf( stderr , "   BTrimStr: \"%s\" [len:%d]\n\n" , (char*)b->data , (int)len );
}


int CTrimStr( char* pCStr )
{
  size_t first , last , lenIn , lenOut ;
  first = last = lenIn = lenOut = 0;
  
  lenIn = strlen( pCStr );   //
  char tmpStr[ lenIn+1 ];      // Create working copy.
  strcpy( tmpStr , pCStr );  // 
  char* pTmp = tmpStr;         // pTmp may change in Left Trim segment.
  
    // Left Trim
    // Find 1st non-whitespace char; pStr will point to that.
  while( isspace( pTmp[ first ] ) )
    first++;
  pTmp += first;

  lenOut = strlen( pTmp );     // Get new length after Left Trim.
  if( lenOut )  {              // Check for empty string.
                               //  e.g. "   " trimmed to nothing.
      // Right Trim
      // Find 1st non-whitespace char & set NUL character there.
    last = lenOut-1;           // off-by-1 adjustment.
    while( isspace( pTmp[ last ] ) )
      last--;
    pTmp[ last+1 ] = '\0';  // Terminate trimmed string.
  }
  lenOut = strlen( pTmp );     // Length of trimmed string.
  if( lenIn != lenOut )        // Did we change anything?
    strcpy( pCStr , pTmp );  // Yes, copy trimmed string back.
  return lenOut;
}

int BTrimStr( bstring b ) {
  btrimws( b );
  return b->slen;
}


