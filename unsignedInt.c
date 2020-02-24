// unsignedInt.c
// Chapter 19
// <book title>
//
// Demonstrate how to 
// 1) print unsigned values in octal, decimal, and hexadecimal
// 2) see what happens when you print negative numbers as unsigned values
// 3) explore powers of 2 and powers of 9
// 4) print out pointer values.
//
// compile with: cc unsignedInt.c -o unsignedInt -Wall -Werror -std=c11
//

#include <stdio.h>

int main( void ) 
{
  int      smallInt    = 12;
  int      largeInt    = (1024*1024*3)+(1024*2)+512+128+64+32+16+8+4+2+1;
  int      negativeInt = -smallInt;
  unsigned anUnsigned  =  130;

  printf( " Unsigned Printf \n" );
  printf( "  Base        Base-8        Base-10         Base-16         BASE-16\n" );
  printf( "  Name         octal        unsigned     hexadeximal     HEXIDECIMAL\n" );
  printf( "  Specifier     %%12o            %%12u            %%12x            %%12X \n" );
  printf( "       [%12o]  [%12u]  [%12x]  [%12X]\n" ,
                  smallInt , smallInt , smallInt , smallInt );
  printf( "       [%12o]  [%12u]  [%12x]  [%12X]\n" ,
                  largeInt , largeInt , largeInt , largeInt );
  printf( "       [%12o]  [%12u]  [%12x]  [%12X]\n\n" ,
                  anUnsigned , anUnsigned , anUnsigned , anUnsigned );
                     
  printf( "  Specifier      %%#o             %%#u             %%#x             %%#X\n");
  printf( "       [%#12o]  [%12u]  [%#12x]  [%#12X]\n" ,
                  smallInt , smallInt , smallInt , smallInt );
  printf( "       [%#12o]  [%12u]  [%#12x]  [%#12X]\n" ,
                  largeInt , largeInt , largeInt , largeInt );
  printf( "       [%#12o]  [%12u]  [%#12x]  [%#12X]\n\n" ,
                  anUnsigned , anUnsigned , anUnsigned , anUnsigned );
   
  printf( "  Negative Numbers as Unsigned:\n" );
  printf( "  -0   [%12o]  [%12u]  [%12x]  [%12X]\n" ,
                  -0 , -0 , -0 , -0 );
  printf( "  -1   [%12o]  [%12u]  [%12x]  [%12X]\n" ,
                  -1 , -1 , -1 , -1 );
  printf( "  -2   [%12o]  [%12u]  [%12x]  [%12X]\n" ,
                  -2 , -2 , -2 , -2 );
  printf( " -12   [%12o]  [%12u]  [%12x]  [%12X]\n\n" ,
                  negativeInt , negativeInt , negativeInt , negativeInt );


  printf( "Powers of 2: 2^0, 2^2, 2^4, 2^6, 2^8 , 2^10\n" );
  int k = 1;
  for( int i = 0 ; i < 6 ; i++ , k<<=2 )
  {
      printf( "       [%#12o]  [%12u]  [%#12x]  [%#12X]\n" ,
                      k , k , k , k );
  }
  printf( "\nPowers of 9: 9^1, 9^2, 9^3, 9^4\n" );
  printf( "  Specifier       %%o              %%u              %%x              %%X \n" );
  k = 9;
  for( int i = 0 ; i < 5 ; i++ , k*=9 )
  {
      printf( "       [%#12o]  [%12u]  [%#12x]  [%#12X]\n" ,
                      k , k , k , k );
  }

  printf( "\nPointer Output\n" );
  printf( " %%p       [%p]   pointer\n" ,     &smallInt );
  printf( " %%#lx     [%#lx]   using hex\n\n" ,  (unsigned long)&smallInt );
}