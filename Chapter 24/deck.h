// deck.h
// Chapter 24
// Learn C Programming - Fundamentals of C
//
// Header file for deck.C
//
// To compile:
//   see main program source file: dealer.c
//


#ifndef _DECK_H_
#define _DECK_H_

#include "card.h"

enum {
  kCardsInDeck = 52
};


  // 
  // A Deck
  //
typedef struct  {
  Card  ordered[  kCardsInDeck ];
  Card* shuffled[ kCardsInDeck ];
  int   numDealt;
  bool  bIsShuffled;
} Deck;


  //
  // Operations on a Deck of Cards
  //
void  InitializeDeck(   Deck* pDeck );
void  ShuffleDeck(      Deck* pDeck );
Card* DealCardFromDeck( Deck* pDeck );
void  PrintDeck(        Deck* pDeck );


#endif
