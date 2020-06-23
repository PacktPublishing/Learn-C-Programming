//  printDistance2.c
//  Chapter 4: Using Variables and Assignment
//  Learn C Programming
// 
//  A better function that demonstrates the use of 
//  assignment via actual parameters and
//  explicit assignment inside the function.
//
//  This one is better because 
//  1) actual parameter name is meaningful of its use, and 
//  2) local variable yards is explicitly declared so its
//     value and use are clear.
//
// Compile with:
//
//    cc printDistance2.c -Wall -Werror -std=c11
//
 
#include(<stdio.h>

  // Function prototypes.
void printDistance( double );

int(main( void )
{
  double feet = 5280.0;
  printDistance( feet );
  printf( "feet = %12.3g\n" , feet );
  return 0;
}

  // Given feet, print the distance in feet and yards.
  //
void printDistance( double feet )
{
  double yards = feet / 3.0;
  
  printf( "The distance in feet is %12.3g\n"  , feet );
  printf( "The distance in yards is %12.3g\n" , yards );
}

  // <eof>
  
