// showArgs.c
// Chapter 20
// <book title>
//
// Demonstrate how to 
// * retrieve arguments entered on the command line 
//
// compile with: cc showArgs.c -o showArgs -Wall -Werror -std=c11
//

#include <stdio.h>

int main(int argc, char *argv[])
{
    // argc will never be 0.
    // program name is always argv[0] 
      
  if( argc == 1 )  {
    printf( " No arguments given on command line.\n" );
    printf( " usage: %s <argument1> <argument2> ... <argumentN>\n\n" , argv[0] );  
    return 0;				
  }
  
  printf( "argument count = [%d]\n" , argc );
  for( int i = 0 ; i < argc ; i++ )  {
    if( i == 0 )
      printf( "executable = [%s]\n" , argv[i] );
    else
      printf( "argument %d = [%s]\n" , i , argv[i] );
  }
  printf( "\n" ); 
}