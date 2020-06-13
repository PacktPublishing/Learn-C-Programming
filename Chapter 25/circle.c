// circle.c
// Chapter 25
// Learn C Programming - Fundamentals of C
//
// Demonstrate various types of scope:
// 1. local scope
// 2. static scope
// 3. function prototype scope
// 4. external / file scope
// 5. global / multi-file scope
//
// NOTE: no header file is employed to show what the source file
//       looks like after preprocessing.
//
// Dependencies:
//
//   trig.c
//
// Compile with:
//
//    cc circle.c trig.c -o cirle -Wall -Werror -std=c18
//

#include <stdio.h>

  // === trig.h 
double circle_circumference( double diameter );
double circle_area( double radius );
double circle_volume( double radius );

extern const long double global_Pi;
  // ===

static const double unit_circle_radius = 1.0;

void circle( double radius);

int main( void ) {
  circle( -1.0 );
  circle(  2.5 );
}
  
void circle( double radius )  {
  double r = 0.0;
  double d = 0.0;

  if( radius <= 0.0 ) r = unit_circle_radius; 
  else                r = radius; 
  d = 2 * r;

  printf( " pi     (as literal) = 3.14159265358979323846L\n" );     // 20 decimals
  printf( " pi       (as float) = %9.7f\n" , (float)global_Pi );    // accurate to  7 decimals
  printf( " pi      (as double) = %18.16F\n" , (double)global_Pi ); // accurate to 16 decimals
  printf( " pi (as long double) = %22.20LF\n\n" , global_Pi );      // accurate to 19 decimals

  if( radius <= 0.0 ) printf( "Unit circle:\n" );
  else                printf( "Circle\n");
  
  printf( "         radius = %10.4f inches\n" , r );
  printf( "  circumference = %10.4f inches\n" , circle_circumference( d ) );
  printf( "           area = %10.4f square inches\n" , circle_area( r ) );
  printf( "         volume = %10.4f cubic inches\n\n" , circle_volume( r ) );
}
