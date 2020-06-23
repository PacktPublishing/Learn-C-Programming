  // prefixpostfix.c
  // Chapter 5: Exploring Operators and Expressions
  // Learn C Programming
  //
  // A program to illustrate when the prefix and postfix
  // increment operator changes the value of a variable.
  //
  // Confusion or doubt can be removed by making the
  // incrementation its own statement.
  //
  // Compile with:
  //
  //    cc prefixpostfix.c -o prefixpostfix -Wall -Werror -std=c11
  //

#include <stdio.h>

int main( void )
{
  int aValue = 5;

    // Demonstrate prefix incrementation.
    
  printf( "Initial: %d\n"   , aValue );
  printf( " Prefix: %d\n"   , ++aValue );  // Prefix incrementation.
  printf( "  Final: %d\n\n" , aValue );

    // Reset aValue.
    
  aValue = 5;

   // Demonstrate postfix incrementation.
   
  printf( "Initial: %d\n"   , aValue );
  printf( "Postfix: %d\n"   , aValue++ );   // Postfix incrementation.
  printf( "  Final: %d\n\n" , aValue );

    // A more predictable result: increment in isolation.
  aValue = 5;
  ++aValue;
  printf( "++aValue (alone) == %d\n" , aValue );

  aValue = 5;
  aValue++;
  printf( "aValue++ (alone) == %d\n" , aValue );
  
  return 0;
}

  // <eof>
  
