// createUnsorted.c
// Chapter 23
// Learn C Programming - Fundamentals of C
//
// This program builds upon getoptFiles.c
//
// Demonstrate how to use fgets() and fputs() in a *useful* way,
// removing and adding '\n' as needed to each.
//
// compile with: 
//
//    cc createUnsorted.c -o createUnsorted -Wall -Werror -std=c11
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // for getopt
#include <sys/errno.h>  // for errno
#include <ctype.h>

const int stringMax = 80;

void  usage(   char* cmd );
int   getName( FILE* inFileDesc , char** ppStr );
void  putName( char* pStr ,       FILE*  outFileDesc );
char* trimStr( char* pStr );


int main(int argc, char *argv[]) {
  int   ch;
  FILE* inputFile  = NULL;
  FILE* outputFile = NULL;
  
  while( ( ch = getopt( argc , argv , "i:o:h" ) ) != -1 )  {
    switch (ch)  {
      case 'i':
        if( NULL == ( inputFile = fopen( optarg , "r") ) )  {
          fprintf( stderr, "input file \"%s\": %s\n", optarg, strerror(errno));
          exit( EXIT_FAILURE );
        }
        fprintf( stderr , "Using \"%s\" for input.\n" , optarg );
        break;
      case 'o':
        if( NULL == ( outputFile = fopen( optarg , "a" ) ) )  {
          fprintf( stderr, "output file \"%s\": %s\n", optarg, strerror(errno));
          exit( EXIT_FAILURE );
        }
        fprintf( stderr , "Using \"%s\": for output.\n" , optarg );
        break;
      case '?':
      case 'h':
      default:
        usage( argv[0] );
        break;
    }
  }
  
  if( !inputFile )  {
    inputFile = stdin;
    fprintf( stderr , "Using stdin for input.\n" );
  }
  
  if( !outputFile )  {
    outputFile = stdout;
    fprintf( stderr , "Using stdout for output.\n" );
  }
  
  char  nameBuffer[ stringMax ];
  char* pName = nameBuffer;
  
  while( getName( inputFile , &pName ) )  {
    putName( pName , outputFile );
    pName = nameBuffer;            // Reset pName to beginning of buffer 
  }                                // (it could have changed).

  fprintf( stderr , "Closing files.\n" );
  fclose(  inputFile );
  fflush(  outputFile );
  fclose(  outputFile );
}


void usage( char* cmd )
{
  fprintf( stderr , "usage: %s [-i inputFileName] [-o outputFileName]\n" , cmd );
  fprintf( stderr , "       If -i inputFileName is not given, stdin is used.\n" );
  fprintf( stderr , "       If -o outputFileName is not given stdout is used.\n\n" );
  exit( 0 );
}


  // getName -- Read nameString (a full line)
  //            If input is from stdin, give prompt.
  //            Trim excess whitespace before and after string
  //            (including <newline> which fgets() preserves).
  //  parametrs:
  //    inFileDesc - input stream
  //    nameStr    - array of characters allocated by caller
  //  returns:
  //    length of nameStr. 0, or empty string, means end of input.
  //
int getName( FILE* inFileDesc , char** ppStr )  {
  static int numNames = 0; 
         int len;

  memset( *ppStr , 0 , stringMax );

  if( stdin == inFileDesc )
    fprintf( stdout , "Name %d: ", numNames+1 );

  fgets( *ppStr , stringMax , inFileDesc );
  
  *ppStr = trimStr( *ppStr );  // Here's where *ppStr could change.

  len = strlen( *ppStr );
  if( len ) numNames++;
  return len; 
}


  // putName - write nameString, appending <newline>
  //
void putName( char* pStr , FILE* outFileDesc )  {
  fputs( pStr , outFileDesc );
  fputc( '\n' , outFileDesc );
}


  // trimStr - trims beginning and end of a string
  // 
  // Parameter:
  //    pStr pointer to string to be trimmed.
  // Returns:
  //   A pointer to the beginning of the trimmed string.
  //    
char* trimStr( char* pStr )  {
  int first , last , len ;
  first = last = len = 0;

    // Left Trim
    // Find 1st non-whitespace char; pStr will point to that.
  len = strlen( pStr );
  while( isspace( pStr[ first ] ) )
    first++;
  pStr += first;

  len = strlen( pStr ); // Get new length after Left Trim.
  if( len )  {             // Check for empty string. e.g. "   " trimmed to nothing.
      // Right Trim
      // Find 1st non-whitespace char; pStr will point to that.
    last = len-1; // off-by-1 adjustment.
    while( isspace( pStr[ last ] ) )
      last--;
    pStr[ last+1 ] = 0;   // Terminate trimmed string.
  }
  return pStr;
}

  // eof