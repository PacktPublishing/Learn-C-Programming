// open_close_string.c
// Chapter 22
// Learn C Programming - Fundamentals of C
//
// Demonstrate how to 
// 1) open a file for reading,
// 2) open a file for writing
// 3) close input file
// 4) flush output file before closing
// 5) close output file.
// 6) use of errno and strerror() function.
//
// compile with: cc open_close_string.c -o open_close_string -Wall -Werror -std=c11
//


#include <stdio.h>
#include <stdlib.h>     // for exit
#include <string.h>
#include <sys/errno.h>  // for errno


int main( void ) {
  FILE* inputFile;
  FILE* outputFile;
  
  char inputFilename[] = "./input.data";
  char outputFilename[] = "./output.data";
  
  inputFile = fopen( inputFilename , "r" );
  if( NULL == inputFile )  {
    fprintf( stderr, "input file: %s: %s\n", inputFilename , strerror( errno ) );
    exit( 1 );
  }
  
  outputFile = fopen( outputFilename , "w" );
  if( NULL == outputFile )  {
    fprintf( stderr, "input file: %s: %s\n", outputFilename , strerror( errno ) );
    exit( 1 );
  }
  
    // Files now open for reading and writing.

  fprintf( stdout , "\"%s\" opened for reading.\n" , inputFilename );
  fprintf( stdout , "\"%s\" opened for writing.\n" , outputFilename );
  
  fprintf( stderr , "Do work here.\n" );
  
  fprintf( stderr , "Closing files.\n" );
  fclose(  inputFile );
  fflush( outputFile );
  fclose( outputFile );
}

  // eof
  