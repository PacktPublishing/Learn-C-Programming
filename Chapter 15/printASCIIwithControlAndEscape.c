// printASCIIwithControlAndEscape.c
// Chapter 15
// <book title>
//
// Demonstrate how to 
// 1) builds upon printASCIIwithControl.c
// 2) print the ASCII values 0 through 127
//    a) uses a lookup table to print control character escape sequences.
//
// compile with: cc printASCIIwithControlAndEscape.c -o printASCIIwithControlAndEscape -Wall -Werror -std=c11
//


#include <stdio.h>
#include <stdlib.h>


int main( void )
{
  char* ctrl[] = { "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL" ,
                   " BS", " HT", " LF", " VT", " FF", " CR", " SO", " SI" ,
                   "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB" ,
                   "CAN", " EM", "SUB", "ESC", " FS", " GS", " RS", " US"  };
  char format[] = {  '0' ,   0  ,   0  ,   0  ,   0  ,   0  ,   0  ,  'a' , 
                     'b' ,  't' ,  'n' ,  'v' ,  'f' ,  'r' ,   0  ,   0 , 
                      0  ,   0  ,   0  ,   0  ,   0  ,   0  ,   0  ,   0 , 
                      0  ,   0  ,   0  ,  'e' ,   0  ,   0  ,   0  ,   0  };
  char c1 , c2 , c3 , c4;

  printf("                Table of 7-Bit ASCII and \n");
  printf("             Single-Byte UTF-8 Character Sets  \n\n");

  printf("|  Control Characters |    Printable Characaters (except DEL)   |\n" );
  printf("|---------------------|-----------------------------------------|\n" );
  printf("| SYM Fmt Ch Dec  Hex | Ch Dec  Hex | Ch Dec  Hex | Ch Dec  Hex |\n" );
  printf("|---------------------|-------------|-------------|-------------|\n" );
 
  for( int i = 0 ; i < 32; i++)
  {
    c1 = i;
    c2 = i+32;
    c3 = i+64;
    c4 = i+96;
 
    char fmtStr[] = "   ";
    if( format[i] )
    {
      fmtStr[1] = '\\';
      fmtStr[2] = format[i];
    }

    printf( "| %s %s ^%c %3d %#4x " ,
             ctrl[i] , fmtStr , c3 , c1 , c1 );
    printf( "|  %c %3d %#x " ,
              c2 , c2 , c2 );
    printf( "|  %c %3d %#x |" ,
              c3 , c3 , c3 );
    if( c4 != 127 ) {
      printf( "|  %c %3d %#x |\n" ,
              c4 , c4 , c4  );
     } else {
        printf( "|%s %3d %#x |\n" ,
               "DEL" , c4 , c4 );
     }
  }
  c1 = 0x7;
  printf("%c%c%c", c1 , c1 , c1);  
}

  /* eof */
