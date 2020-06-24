// trig.c
// Chapter 25
// Learn C Programming
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
//   circle.c
//
// Compile with:
//
//    cc circle.c trig.c -o cirle -Wall -Werror -std=c18
//

  // === trig.h 
double circle_circumference( double diameter );
double circle_area( double radius );
double circle_volume( double radius );

extern const long double global_Pi;
  // ===
  

static double square( double d );
static double cube(  double d );

const long double global_Pi = 3.14159265358979323846L;


double circle_circumference( double diameter )  {
  double result = diameter * global_Pi;
  return result ;
}

double circle_area( double radius )  {
  double result = global_Pi * square( radius );
  return result;
}

double circle_volume( double radius )  {
  double result = 4.0/3.0*global_Pi*cube( radius );
  return result;
}


static double square( double d )  {
  double result = d * d;
  return result;
}

static double cube( double d ) {
  double result = d * d * d;
  return result;
}

  // eof

