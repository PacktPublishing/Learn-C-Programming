// readScanSet.c
// Chapter 21
// Learn C Programming - Fundamentals of C
//
// Demonstrate how to use a scan set to limit
// character inputs.
//
// compile with: cc readScanSet.c -o readScanSet -Wall -Werror -std=c11
//

#include <stdio.h>


// Test inputs:
//
// aayyeeuuiioo<return>
//
// aeimwouy<return>
//
// a e i o u y<return>
//


const int bufferSize = 80;


int main( void )
{
  char stringBuffer[ bufferSize ];
  printf( "Enter only vowels: " );
  scanf(  "%[aeiouy]" , stringBuffer );
  printf( "Processed string: [%s]\n\n" , stringBuffer );
}

  // eof
  