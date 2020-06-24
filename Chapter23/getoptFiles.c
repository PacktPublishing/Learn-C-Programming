// getoptFiles.c
// Chapter 23
// Learn C Programming
//
// Demonstrate how to use getopt() to 
// 1) open an input file or use stdin
// 2) open an output file or use stdout
// 
// This is a "template" program in that it can be used
// as the starting point for any number of different kinds
// of file-processing programs.
//
// compile with:
//
//     cc getoptFiles.c -o getoptFiles -Wall -Werror -std=c11
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // for getopt
#include <sys/errno.h>  // for errno


void usage( char* cmd )
{
  fprintf( stderr , "usage: %s [-i inputFileName] [-o outputFileName]\n" , cmd );
  fprintf( stderr , "       If -i inputFileName is not given, stdin is used.\n" );
  fprintf( stderr , "       If -o outputFileName is not given stdout is used.\n\n" );
  exit( 0 );
}


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
  
  fprintf( stderr , "Do work here.\n" );
  
  fprintf( stderr , "Closing files.\n" );
  fclose( inputFile );
  fflush( outputFile );
  fclose( outputFile );
}

  //  eof
