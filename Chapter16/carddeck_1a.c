// carddeck_1a.c
// Chapter 16
// <book title>
//
// carddeck_1a.c builds upon carddeck_0.c.
// In this version, we add an array of structures, called Deck
// and some functions to manipulate the Deck array.
// 
// compile with cc carddeck_1a.c -o carddeck_1a -Wall -Werror =std=c11
//


#include <stdio.h>
#include <stdbool.h>
#include <string.h>    // for strcpy() and strcat()


  // Useful constants (avoid "magic numbers" whose meaning is
  // sometimes vague and whose values may change). Use these instead
  // of literals; when you need to change these, they are applied
  // everywhere.
  //
const int  kCardsInDeck = 52;  // For now, 52 cards in a deck. This will change
                               // depending upon the card game and the # of wild
                               // cards, etc.
const int  kCardsInSuit = 13;  // For now, kCardsInDeck / 4. This will change
                               // depending upon the card game.

const bool kWildCard    = true;
const bool kNotWildCard = false;


  // ============================================
  // Definitions related to a Card
  //
  // Card Suits
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


  // Operations on a Card
  //
void InitializeCard( Card* pCard , Suit s , Face f , bool w );
void PrintCard(      Card* pCard );
void CardToString(   Card* pCard , char pCardStr[20] );


int main( void ) 
{
  Card deck[ kCardsInDeck ];

  Card* aCard = &deck[3];
  aCard->suit      = spade;
  aCard->suitValue = (int)spade;
  aCard->face      = five;
  aCard->faceValue = (int)five;
  aCard->isWild    = kNotWildCard;

  PrintCard( &deck[3] );
  printf( "\n" );
}


  // ============================================
  // Operations on a Card
  // ============================================


void InitializeCard( Card* pCard, Suit s , Face f , bool w )
{
  pCard->suit = s; 
  pCard->suitValue = (int)s;
  
  pCard->face = f;
  pCard->faceValue = (int)f;
  
  pCard->isWild = w;
}


void PrintCard( Card* pCard )
{
  char cardStr[20] = {0};
  CardToString( pCard , cardStr );
  printf( "%18s" , cardStr );
}


void CardToString( Card* pCard , char pCardStr[20] )
{
  switch( pCard->face )
  {
    case two:   strcpy( pCardStr , "    2 " ); break;
    case three: strcpy( pCardStr , "    3 " ); break;
    case four:  strcpy( pCardStr , "    4 " ); break;
    case five:  strcpy( pCardStr , "    5 " ); break;
    case six:   strcpy( pCardStr , "    6 " ); break;
    case seven: strcpy( pCardStr , "    7 " ); break;
    case eight: strcpy( pCardStr , "    8 " ); break;
    case nine:  strcpy( pCardStr , "    9 " ); break;
    case ten:   strcpy( pCardStr , "   10 " ); break;
    case jack:  strcpy( pCardStr , " Jack " ); break;
    case queen: strcpy( pCardStr , "Queen " ); break;
    case king:  strcpy( pCardStr , " King " ); break;
    case ace:   strcpy( pCardStr , "  Ace " ); break;
    default:    strcpy( pCardStr , "  ??? " ); break;
  }
  switch( pCard->suit )
  {
    case spade:   strcat( pCardStr , "of Spades  "); break;
    case heart:   strcat( pCardStr , "of Hearts  "); break;
    case diamond: strcat( pCardStr , "of Diamonds"); break;
    case club:    strcat( pCardStr , "of Clubs   "); break;
    default:      strcat( pCardStr , "of ???s    "); break;
  }
}

  //  eof
