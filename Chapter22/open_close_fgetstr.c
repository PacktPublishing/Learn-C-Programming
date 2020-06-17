// open_close_fgetstr.c
// Chapter 22
// Learn C Programming - Fundamentals of C
//
// Builds on open_close_string.c
// Demonstrate how to get filenames for input and output 
// via prompt.
//
// compile with: cc open_close_fgetstr.c -o open_close_fgetstr -Wall -Werror -std=c11
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>  // for errno


int main(int argc, char *argv[]) {
  FILE* inputFile;
  FILE* outputFile;
  
  char inputFilename[80] = {0};
  char outputFilename[80] = {0};
 
  fprintf( stdout , "Enter name of input file: " ); 
  fscanf(  stdin  , "%80s" , inputFilename );
  inputFile = fopen( inputFilename , "r" );
  if( NULL == inputFile )  {
    fprintf( stderr, "input file: %s: %s\n", inputFilename , strerror( errno ) );
    exit( 1 );
  }
  
  fprintf( stdout , "Enter name of output file: " ); 
  fscanf(  stdin , "%80s" , outputFilename );
  outputFile = fopen( outputFilename , "w" );
  if( NULL == outputFile )  {
    fprintf( stderr, "input file: %s: %s\n", outputFilename , strerror( errno ) );
    exit( 1 );
  }

  fprintf( stdout , "\"%s\" opened for reading.\n" , inputFilename  );
  fprintf( stdout , "\"%s\" opened for writing.\n" , outputFilename );    
  fprintf( stderr , "Do work here.\n" );
  
  fprintf( stderr , "Closing files.\n" );
  fclose(  inputFile );
  fflush( outputFile );
  fclose( outputFile );
}

  // eof
  