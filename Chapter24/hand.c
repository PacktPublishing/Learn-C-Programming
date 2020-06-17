// hand.c
// Chapter 24
// Learn C Programming - Fundamentals of C
//
// To compile:
//   see main program source file: dealer.c
//


#include "dealer.h"


  // ============================================
  // Operations on a Hand
  // ============================================


void InitializeHand( Hand* pHand )  {
  pHand->cardsDealt = 0;
  for( int i = 0; i < kCardsInHand ; i++ )  {
    pHand->hand[i] = NULL;
  }
}


void AddCardToHand( Hand* pHand , Card* pCard )  {
  if( pHand->cardsDealt == kCardsInHand ) return;
  
  pHand->hand[ pHand->cardsDealt ] = pCard;
  pHand->cardsDealt++;
}


void PrintHand( Hand* pHand , char* pLeadStr )  {
  for( int i = 0; i < kCardsInHand ; i++ )  {  // 1..5
    Card* pCard = pHand->hand[i];
    printf("%s" , pLeadStr );
    PrintCard( pCard );
    printf("\n");
  }
}


void PrintAllHands(  Hand* hands[ kNumHands ] )  {
  printf( "                  Hand 1: \n");
  PrintHand( hands[ 0 ] , "                  " );
  
  printf( "Hand 2: \n");
  PrintHand( hands[ 1 ], "  " );
  
  printf( "                                    Hand 3: \n");
  PrintHand( hands[ 2 ], "                                    " );
  
  printf( "                  Hand 4: \n" );
  PrintHand( hands[ 3 ] , "                  " );
  printf( "\n" );
}

 // eof