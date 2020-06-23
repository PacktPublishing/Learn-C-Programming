// printExtendedASCII.c
// Chapter 15
// Learn C Programming
//
// Demonstrate how to 
// 1) builds upon printASCII_version3.c
// 2) print the ASCII values 32 through 255
//
// compile with: 
//
//    cc printExtendedASCII.c -o printExtendedASCII -Wall -Werror -std=c11
//


/* 
 * Extended ASCII table for Apple operating systems.
 * see <http://ascii-table.com/ascii-extended-mac-list.php>
 */


#include <stdio.h>


int main( void )
{
  unsigned char c1 , c2 , c3 , c4 , c5 , c6 , c7 , c8 ;
  
  printf("                                     Table of 8-Bit ASCII, or\n"      );
  printf("                                  Vendor-specific Extended ASCII\n " );
  printf("                                  (excluding control characters)\n\n" );

  printf("|                                 Printable Characaters (plus DEL)                                |\n" );

  printf("| Ch Dec  Hex | Ch Dec  Hex | Ch Dec  Hex | Ch Dec  Hex | Ch Dec  Hex | Ch Dec  Hex | Ch Dec  Hex |\n" );
  printf("|-------------|-------------|-------------|-------------|-------------|-------------|-------------|\n" );

  for( int i = 0 ; i < 32; i++)
  {
    c1 = i;    // <-- Not used yet (a dummy assignment for now).
    c2 = i+32;
    c3 = i+64;
    c4 = i+96;
    c5 = i+128; // extended ASCII characters
    c6 = i+160;
    c7 = i+192;
    c8 = i+224;
    
    printf( "|  %c %3d %#x " ,
            c2 , c2 , c2 );
    printf( "|  %c %3d %#x " ,
            c3 , c3 , c3 );
   if( c4 == 127 ) {
      printf("|%s %3d %#x |" ,
              "DEL" , c4 , c4  );
    } else {
      printf("|  %c %3d %#x |" ,
              c4 , c4 , c4  );
    }

    // Print extended ASCII for your your system.
    //
    printf("  %c %3d %#x |  %c %3d %#x |  %c %3d %#x |  %c %3d %#x |" ,
            c5 , c5 , c5 ,
            c6 , c6 , c6 ,
            c7 , c7 , c7 ,
            c8 , c8 , c8  );
    printf( "\n" );
  }  // for
} // main

 //  eof
