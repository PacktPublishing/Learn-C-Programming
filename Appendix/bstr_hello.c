// bstr_hello.c
// Appendix
// Learn C Programming
//
// Demonstrate how to use bstrlib in "Hello, world!"
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
//    cc bstr_hello.c bstrlib.c -o bstr_hello -Wall -Werror -std=c11
//

#include <stdio.h>
#include "bstrlib.h"

int main( void )  {
  bstring b = bfromcstr ("Hello, World!");
  puts( (char*)b->data );  
}
