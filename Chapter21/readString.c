// readString.c
// Chapter 21
// Learn C Programming
//
// Demonstrate how to read a string with scanf().
// Compare to readString2.c
//
// compile with: 
//
//      cc readString.c -o readString -Wall -Werror -std=c11
//


#include <stdio.h>


// Test inputs:
//
// Anything up to the white space<return>
//
// Every_thing%before;any:white'space\(will%be read into an array.)<return>
//
//     Skipping initial white space.<return>
//

const int bufferSize = 80;

int main( void )
{
  char stringBuffer[ bufferSize ];
  
  printf( "Enter a string: " );
  scanf(  "%s" , stringBuffer );
  printf( "Processed string: [%s]\n\n" , stringBuffer );
}

  // eof
