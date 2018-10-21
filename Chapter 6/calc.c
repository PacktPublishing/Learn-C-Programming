  // calc.c
  // Chapter 6
  // <book title>
  //
  // Build a simple calculator using a function with
  // a switch statement.


#include <stdio.h>
#include <stdbool.h>


double calc( double operand1, double operand2 , char operator );


int main( void )
{
  calc(  1.0 ,  2.0 , '+' );
  calc( 10.0 ,  7.0 , '-' ); 
  calc(  4.0 ,  2.3 , '*' );
  calc(  5.0 ,  0.0 , '/' );
  calc(  5.0 ,  2.0 , '%' );
  calc(  1.0 ,  2.0 , '?' );
  
  return 0;
}


double calc( double operand1 , double operand2 , char operator )
{
  double result = 0.0;
  
  printf( "%g %c %g = " , operand1 , operator , operand2 );
  switch( operator )
  {
    case '+':
      result = operand1 + operand2;
      break;
    case '-':
      result = operand1 - operand2;
      break;
    case '*':
      result = operand1 * operand2;
      break;
    case '/':
      if( operand2 == 0.0 ) 
      {
        printf( "*** ERROR *** division by %g is undefined.\n" , operand2 );
        return result;
      } else {
        result = operand1 / operand2;
      }
      break;
    case '%':
      // Remaindering: assume operations on integers (cast first).
      result = (int) operand1 % (int) operand2;
      break;
    default:
      printf( "*** ERROR ***  unknown operator; operator must be + - * / or %%\n" );
      return result;
      break;
  }
  printf( "%g\n" , result );
  return result;
}

  //  eof

