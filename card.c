// card.c
// Chapter 9
// <book title>
//
// Demonstrate defining and using structured types.
// 


#include <stdio.h>
#include <stdbool.h>


enum Suit
{ 
  club  = 1, 
  diamond, 
  heart,
  spade 
};

enum Face 
{ 
  one = 1, 
  two, 
  three, 
  four, 
  five, 
  six, 
  seven, 
  eight, 
  nine, 
  ten, 
  jack, 
  queen, 
  king, 
  ace
};

struct Card 
{
 enum Suit suit;
 int       suitValue;
 enum Face face;
 int       faceValue;
 double    d;
 bool      isWild;
};

int main( void ) 
{
  struct Card card;

  printf( "  enum Suit is %lu bytes\n" , sizeof( enum Suit ) );
  printf( "  enum Face is %lu bytes\n" , sizeof( enum Face ) );
  printf( "        int is %lu bytes\n" , sizeof( int ) );
  printf( "       bool is %lu bytes\n" , sizeof( bool ) );

  printf( "struct Card is %lu bytes\n" , sizeof( struct Card ) );
  printf( "       card is %lu bytes\n" , sizeof( card ) );
  
  return 0;  
}

//  eof
