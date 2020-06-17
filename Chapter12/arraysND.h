// arrayND.h
// Chapter 12
// <book title>
//
// Header file for arrayND.c.
// 


  // Function prototypes.
  
void initialize2DArray(  int row , int col , int array[row][col] );
void print2DArray(       int row , int col , int array[row][col] );
void prettyPrint2DArray( int row , int col , int array[row][col] );
int  sum2DArray(         int row , int col , int array[row][col] );

void initialize3DArray(  int z , int y , int x , int array[z][y][x] );
void print3DArray(       int z , int y , int x , int array[z][y][x] );
void prettyPrint3DArray( int z , int y , int x , int array[z][y][x] );
int  sum3DArray(         int z , int y , int x , int array[z][y][x] );

//  eof
