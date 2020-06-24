// open_close_argv.c
// Chapter 22
// Learn C Programming
//
// Builds on open_close_fgetstr.c
// Demonstrate how to use argc and argv to get
// input and output filenames from command line.
//
// compile with: 
//
//     cc open_close_argv.c -o open_close_argv -Wall -Werror -std=c11
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>  // for errno


void usage( char* cmd )  {
  fprintf( stderr , "usage: %s inputFileName outputFileName\n" , cmd );
  exit( 0 );
}


int main( int argc, char *argv[] )  {
  FILE* inputFile  = NULL;
  FILE* outputFile = NULL;
  
  if( argc != 3 ) usage( argv[0] );

  if( NULL == ( inputFile = fopen( argv[1] , "r") ) )  {
    fprintf( stderr, "input file: %s: %s\n", argv[1], strerror(errno));
    exit( 1 );
  }
  fprintf( stderr , "%s opened for reading.\n" , argv[1] );

  if( NULL == ( outputFile = fopen( argv[2] , "w" ) ) )  {
    fprintf( stderr, "output file: %s: %s\n", argv[2], strerror(errno));
    exit( 1 );
  }
  fprintf( stderr , "%s opened for writing.\n" , argv[2] );

  fprintf( stderr , "Do work here.\n" );
  
  fprintf( stderr , "Closing files.\n" );
  fclose(  inputFile );
  fflush( outputFile );
  fclose( outputFile );
}

  // eof
