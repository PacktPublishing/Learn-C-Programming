// card.h
// Chapter 24
// Learn C Programming
//
// Header file for card.c
//

#ifndef _CARD_H_
#define _CARD_H_

enum {
  kNotWildCard = 0,
  kWildCard    = 1,
  kCardsInSuit = 13
};

  //
  // Card Suits
  //
typedef enum  { 
  club  = 1, 
  diamond, 
  heart,
  spade 
} Suit;

  //
  // Card Faces
  //
typedef enum  { 
  one = 1,
  two , 
  three , 
  four , 
  five , 
  six , 
  seven , 
  eight , 
  nine , 
  ten , 
  jack , 
  queen , 
  king , 
  ace
} Face;


  //
  // A Card
  //
typedef struct  {
  Suit suit;
  int  suitValue;
  Face face;
  int  faceValue;
  bool isWild;
} Card;

  //
  // Operations on a Card
  //
void InitializeCard( Card* pCard , Suit s , Face f , bool w );
void PrintCard(      Card* pCard );
void CardToString(   Card* pCard , char pCardStr[20] );

#endif
