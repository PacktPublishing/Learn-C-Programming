
// shapes.c
// Chapter 8
// <book title>
//
// Demonstrate defining and using enumerated types with 
// the switch statement.
// 


#include <stdio.h>

const char* nameTriangle  = "triangle";
const char* nameSquare    = "square";
const char* nameRectangle = "rectangle";
const char* nameTrapezoid = "trapezoid";
const char* namePentagon  = "pentagon";
const char* nameHexagon   = "hexagon";
const char* nameOctagon   = "octagon";
const char* nameCircle    = "circle";
const char* nameUnknown   = "unknown";

enum shape
{ 
  triangle, 
  square, 
  rectangle, 
  trapezoid, 
  pentagon, 
  hexagon, 
  octagon, 
  circle
};

void        PrintShapeInfo( enum shape aShape );
const char* GetShapeName(   enum shape aShape );


int main( void )
{
  PrintShapeInfo( triangle );
  PrintShapeInfo( square );
  PrintShapeInfo( rectangle );
  PrintShapeInfo( trapezoid );
  PrintShapeInfo( pentagon );
  PrintShapeInfo( hexagon );
  PrintShapeInfo( octagon );
  PrintShapeInfo( circle );
  return 0;
}


void PrintShapeInfo( enum shape aShape)
{
  int nSides = 0;
  switch( aShape )
  { 
    case triangle: 
      nSides = 3;
      break;
    case square:
    case rectangle:
    case trapezoid:
      nSides = 4;
      break;
    case pentagon: 
      nSides = 5;
      break;
    case hexagon: 
      nSides = 6;
      break;
    case octagon:
      nSides = 8;
      break;
    case circle:
      printf( "A circle has an infinite number of sides\n" );
      return;
      break;
    default:
      printf( "UNKNOWN SHAPE TYPE\n" );
      return;
      break;
  }
  printf( "A %s has %d sides\n" , GetShapeName( aShape) , nSides );
}

const char* GetShapeName( enum shape aShape)
{
  const char * name;
  switch( aShape )
  { 
    case triangle:  name = nameTriangle;  break;
    case square:    name = nameSquare;    break;
    case rectangle: name = nameRectangle; break;
    case trapezoid: name = nameTrapezoid; break;
    case pentagon:  name = namePentagon;  break;
    case hexagon:   name = nameHexagon;   break;
    case octagon:   name = nameOctagon;   break;
    case circle:    name = nameCircle;    break;
    default:        name = nameUnknown;   break;
  }
  return name;
}

  //  eof
  
