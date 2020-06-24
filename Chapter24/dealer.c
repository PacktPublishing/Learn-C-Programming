// dealer.c
// Chapter 24
// Learn C Programming
//
// Demonstrate 
// 1) how to group data structures and functions that 
//    manipulate them into .c/.h pairs. 
// 2) use a common header file for all source files.
// 3) use preprocessor directives to eliminate redundant include file preprocessing
// 4) build a multi-file program 
//
// Dependencies:
//
//   card.h   card.c
//   hand.h   hand.c
//   deck.h   deck.c
//
// Compile with:
//
//    cc dealer.c card.c hand.c deck.c -o dealer -Wall -Werror -std=c11
//

#include "dealer.h"

int main( void )  {
  Deck  deck;
  Deck* pDeck = &deck;
  
  InitializeDeck( pDeck );
  PrintDeck(      pDeck );
  
  ShuffleDeck( pDeck );
  PrintDeck(   pDeck );
  
  Hand h1 , h2 , h3 , h4;
  
  Hand* hands[] = { &h1 , &h2 , &h3 , &h4 }; 

  for( int i = 0 ; i < kNumHands ; i++ )  {
    InitializeHand( hands[i] );
  }
  
  for( int i = 0 ; i < kCardsInHand ; i++ )  {
    for( int j = 0 ; j < kNumHands ; j++ )  {
      AddCardToHand( hands[j] , DealCardFromDeck( pDeck ) );
    }
  }
  PrintAllHands( hands );
  PrintDeck(     pDeck );
  
  return 0;  
}

  // eof

