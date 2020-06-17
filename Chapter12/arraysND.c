// arraysND.c
// Chapter 12
// <book title>
//
// Demonstrate how to declare, initialize, and 
// manipulate 2D and 3D arrays.
//
// Pretty printing functions included which add
// row and column headings (as array offsets).
// 


#include <stdio.h>
#include <stdbool.h>
#include "arraysND.h"

int main( void ) 
{
  const int size1D = 5;
  const int size2D = 4;
  const int size3D = 3;
  
  bool pretty = true;

  int array2D[size2D][size1D];
  int array3D[size3D][size2D][size1D];
  
  int total = 0;
  
  initialize2DArray(  size2D , size1D , array2D );
  if( !pretty ) print2DArray(       size2D , size1D , array2D );
  else          prettyPrint2DArray( size2D , size1D , array2D );
  total = sum2DArray( size2D , size1D , array2D );
  printf( "Total for array2D is %d\n\n" , total );
  
  initialize3DArray(  size3D , size2D , size1D , array3D );
  if( !pretty) print3DArray(       size3D , size2D , size1D , array3D );
  else         prettyPrint3DArray( size3D , size2D , size1D , array3D );
  total = sum3DArray( size3D , size2D , size1D , array3D );
  printf( "Total for array3D is %d\n\n" , total );
  
}


void initialize2DArray( int row , int col , int array[row][col] )
{
  for( int j = 0 ; j < row ; j++ )   // j : 0..(row-1)
  {
    for( int i = 0; i < col ; i++ )  // i : 0..(col-1)
    {
      array[j][i] = (10*(j+1)) + (i+1);
 //     array[j][i] = (10*j) + i;
    }
  }
}


void initialize3DArray( int z , int y , int x , int array[z][y][x] )
{
  for( int k = 0 ; k < z ; k++ )    // k : 0..(z-1)
  {
    for( int j = 0 ; j < y ; j++ )  // j : 0..(y-1)
    {
      for( int i = 0; i < x ; i++ ) // i : 0..(x-1)
      {
        array[k][j][i] = (100*(k+1)) + (10*(j+1)) + (i+1);
//        array[k][j][i] = (100*k) + (10*j) + i;
      }
    }
  }
}


void print2DArray( int row , int col , int array[row][col] )
{
  for( int j = 0 ; j < row ; j++ )   // j : 0..(row-1)
  {
    for( int i = 0; i < col ; i++ )  // i : 0..(col-1)
    {
      printf("%4d" , array[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}


void prettyPrint2DArray( int row , int col , int array[row][col] )
{
    // Print column offsets as heading.
  printf("   ");
  for( int i = 0; i < col ; i++) printf(" [%1d]", i);
  printf("\n");
  
  for( int j = 0 ; j < row ; j++ )   // j : 0..(row-1)
  {
      // Print row offset as lead-in.
    printf("[%1d]", j);
    
    for( int i = 0; i < col ; i++ )  // i : 0..(col-1)
    {
      printf("%4d" , array[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}


void print3DArray( int z , int y , int x , int array[z][y][x] )
{
  for( int k = 0 ; k < z ; k++ )    // k : 0..(z-1)
  {
    for( int j = 0 ; j < y ; j++ )  // j : 0..(y-1)
    {
      for( int i = 0; i < x ; i++ ) // i : 0..(x-1)
      {
        printf("%4d" , array[k][j][i]);
      }
      printf("\n");
    }
    printf("\n");
  }
}


void prettyPrint3DArray( int z , int y , int x , int array[z][y][x] )
{
  for( int k = 0 ; k < z ; k++ )    // k : 0..(z-1)
  {
      // Print z offset as lead-in.
    printf("[%1d]", k );
      // Print x offset as heading.
    printf("    ");
    for( int i = 0; i < x ; i++) printf(" [%1d]", i);
    printf("\n");

    for( int j = 0 ; j < y ; j++ )  // j : 0..(y-1)
    {
        // Print y offset as lead-in. 
      printf("    [%1d]", j);
      for( int i = 0; i < x ; i++ ) // i : 0..(x-1)
      {
        printf("%4d" , array[k][j][i]);
      }
      printf("\n");
    }
    printf("\n");
  }
}


int sum2DArray( int row , int col , int array[row][col] )
{
  int sum = 0;
  for( int j = 0 ; j < row ; j++ )   // j : 0..(row-1)
  {
    for( int i = 0; i < col ; i++ )  // i : 0..(col-1)
    {
      sum += array[j][i];
    }
  }
  return sum;
}


int sum3DArray( int z , int y , int x , int array[z][y][x] )
{
  int sum = 0;
  for( int k = 0 ; k < z ; k++ )    // k : 0..(z-1)
  {
    for( int j = 0 ; j < y ; j++ )  // j : 0..(y-1)
    {
      for( int i = 0; i < x ; i++ ) // i : 0..(x-1)
      {
        sum += array[k][j][i];
      }
    }
  }
  return sum;
}


//  eof
