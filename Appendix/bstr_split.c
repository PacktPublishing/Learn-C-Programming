// bstr_split.c
// Appendix
// Learn C Programming
//
// Demonstrate how to split words into a 
// bstrList and print them out.
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
//    cc bstr_split.c bstrlib.c -o bstr_hello -Wall -Werror -std=c11
//

#include <stdio.h>
#include "bstrlib.h"

int main( void ) {
  bstring b = bfromcstr( "Hello, World and my Grandma, too!" );
  puts( (char*)b->data );

  struct bstrList *blist = bsplit( b , ' ' );

  printf( "num %d\n" , blist->qty );
  for( int i=0 ; i<blist->qty ; i++ )  {
    printf( "%d: %s\n" , i , bstr2cstr( blist->entry[i] , '_' ) );
  }
}
