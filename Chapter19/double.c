// double.c
// Chapter 19
// Learn C Programming
//
// Demonstrate how to 
// 1) print floating point in natural format nnnn.nnnn
// 2) print floating point in scientific notation
// 3) demonstrate G type conversion for optimal format of floating point
//
// compile with: 
//
//     cc double.c -o double -Wall -Werror -std=c11
//

#include <stdio.h>

int main( void )
{
   double aDouble = 987654321.987654321;
  
   printf( "Use of the %%f, %%e, and %%E format specifiers:\n" );
   printf( " Specifier Formatted Value\n" );
   printf( " %%f        [%f]    whatever\n"  ,                                 aDouble );
   printf( " %%.3f      [%.3f]       3 decimal places\n"  ,                    aDouble );
   printf( " %%.9f      [%.8f]  8 decimal places\n"  ,                         aDouble );
   printf( " %%.0f      [%.0f]           no decimal places\n"  ,               aDouble );
   printf( " %%#.0f     [%#.0f]          no decimal places, but decimal point\n" , aDouble );
   printf( " %%15.3f    [%15.3f]     3 decimals, 15 wide, left aligned]\n"  ,  aDouble );
   printf( " %%-15.3f   [%-15.3f]     3 decimals, 15 wide, right aligned\n"  , aDouble );
   printf( " %%e        [%e]        using exponential notation\n"  ,           aDouble );
   printf( " %%E        [%E]        using EXPONENTIAL notation\n"  ,           aDouble );
   printf( " %%.3e      [%.3e]           exponent with 3 decimal places\n"  ,  aDouble );
   printf( " %%15.3e    [%15.3e]     exponent with 3 decimals, 15 wide\n"  ,   aDouble );
   printf( " %%015.3e   [%015.3e]     exponent with 3 decimals, 15 wide, 0-fill\n" , aDouble );
   printf( " %% 15.3e   [% 15.3e]     exponent with 3 decimals, 15 wide, leave space for sign\n"  , aDouble );
   printf( " %%+15.3e   [%+15.3e]     exponent with 3 decimals, 15 wide, show sign\n" , aDouble );
   printf( " %%+015.3e  [%+015.3e]     exponent with 3 decimals, 15 wide, show sign, 0-fill\n" , aDouble );
   printf( " %%.0e      [%.0e]               exponent with no decimals\n"  ,   aDouble );
   printf( " %%15.0e    [%15.0e]     exponent 15 wide, no decimals\n\n"  ,     aDouble );

   printf( " %%a        [%a] hexidecimal version of double, exponent=2^p\n" ,   aDouble );
   printf( " %%A        [%A] HEXIDECIMAL version of double, exponent=2^P\n\n" , aDouble );

   printf( "Use of the %%g, and %%G format specifiers:\n" );
   printf( " Specifier             %%18.12g               %%18.3g" );
   printf( "                %%18.3G                  %%18g\n" );
   double k = aDouble * 1e-15;
   for( int i = 0 ; i < 10 ; i++, k *= 1000 )
     printf( "          [%18.12g]  [%18.3g]  [%18.3G]  [%18g]\n" ,
                        k , k , k , k );
}

  //  eof
