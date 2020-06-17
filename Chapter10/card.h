// card.h
// Chapter 10
// <book title>
//
// Demonstrate how to create header file of 
// typedefs, custom types, and function prototypes.
// 


typedef enum
{ 
  club  = 1, 
  diamond, 
  heart,
  spade 
} Suit;


typedef enum 
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
} Face;


typedef struct 
{
 Suit suit;
 int  suitValue;
 Face face;
 int  faceValue;
 bool isWild;
} Card;


typedef struct 
{
  int  cardsDealt;
  Card c1, c2, c3, c4, c5;
} Hand;


Hand addCard(    Hand oldHand , Card card );
void printHand(  Hand h );
void printHand2( Hand h );
void printCard(  Card c );


//  eof
