// test_trim.c
// Chapter 23
// Learn C Programming - Fundamentals of C
//
// This program tests the trimStr() and trimStrInPlace()
// functions.
// 
//   trimStr() returns a pointer to the beginning of the trimmed string,
//             modifying the original string.
//
//   trimStrInPlace() (1) copies the trimmed string back to the original 
//             string using same pointer and (2) returns length of the 
//             trimmed string. THIS IS PREFERRED FUNCTION TO USE.
//
// Compile with: 
//
//   cc test_trim.c -o test_trim -Wall -Werror -std=c11
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* trimStr(        char* pString );
int   trimStrInPlace( char* pString );

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
  size_t first , last , len ;
  first = last = len = 0;

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
    pString[ last+1 ] = 0;  // Terminate trimmed string.
  }
  return pString;
}


// trimStrInPlace - Trims beginning and end of a string.
//                  Creates a working copy of string, trims that, 
//                  and copies the trimmed string back to original.
//
//                  Because a trimmed string will always be the same 
//                  or fewer characters than the original, the only 
//                  side effect of this function is the modifiction of
//                  the original string in place. 
//
// Parameter:
//   pString - pointer of string to be trimmed/modified.
// Returns:
//   The length of the string after trimming.
//    
int trimStrInPlace( char* pString )
{
  size_t first , last , lenIn , lenOut ;
  first = last = lenIn = lenOut = 0;
  
  lenIn = strlen( pString );   //
  char tmpStr[ lenIn+1 ];      // Create working copy.
  strcpy( tmpStr , pString );  // 
  char* pTmp = tmpStr;         // pTmp may change in Left Trim segment.
  
    // Left Trim
    // Find 1st non-whitespace char; pStr will point to that.
  while( isspace( pTmp[ first ] ) )
    first++;
  pTmp += first;

  lenOut = strlen( pTmp );     // Get new length after Left Trim.
  if( lenOut )  {              // Check for empty string. e.g. "   " trimmed to nothing.
      // Right Trim
      // Find 1st non-whitespace char & set NUL character there.
    last = lenOut-1;           // off-by-1 adjustment.
    while( isspace( pTmp[ last ] ) )
      last--;
    pTmp[ last+1 ] = '\0';  // Terminate trimmed string.
  }
  lenOut = strlen( pTmp );     // Length of trimmed string.
  if( lenIn != lenOut )        // Did we change anything?
    strcpy( pString , pTmp );  // Copy trimmed string back to input string.
  return lenOut;
}


void testTrim( int testNum , char* pString )
{
  size_t len;
  char testString[ strlen( pString ) + 1];
  char* pTest;
  
  strcpy( testString , pString );
  fprintf( stderr , "%1d. original: \"%s\" [len:%d]\n"   , testNum, testString , (int)strlen(pString) );
  pTest = trimStr( testString );
  fprintf( stderr , "    trimStr: \"%s\" [len:%d]\n" , pTest ,  (int)strlen( pTest ));

  strcpy( testString , pString );
  len = trimStrInPlace( testString );
  fprintf( stderr , "   trimStr2: \"%s\" [len:%d]\n\n" , testString , (int)len ) ;
}
