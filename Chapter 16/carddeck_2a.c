// carddeck_2a.c
// Chapter 16
// <book title>
//
// carddeck_2a.c builds upon carddeck_1a.c.
// In this version, we add the hand structure using
// individual Card variables.
// 
// compile with cc carddeck_2a.c -o carddeck_2a -Wall -Werror =std=c11
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
const int  kCardsInHand = 5;   // For now, 5 cards dealt for each hange. This will
                               // change depending upon the card game.
const int  kNumHands    = 4;   // For now, for hands per "table". This will change
                               // depending on the game we want to implement.

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


  // =========================slu[e===================
  // Defintions related to a hand
  //
  // A Hand
  //
typedef struct 
{
  int   cardsDealt;
  Card  card1;
  Card  card2;
  Card  card3;
  Card  card4;
  Card  card5;
} Hand;

  // Operations on a Hand
  //
void   InitializeHand( Hand* pHand );
void   AddCardToHand(  Hand* pHand , Card* pCard );
void   PrintHand(      Hand* pHand , char* pLeadStr );
Card*  GetCardInHand(  Hand* pHand , int   cardIndex );


  // ============================================
  // Definitions related to a Deck
  // 
  // A Deck
  
// For now, the deck will be declared as an array of Cards in main().

  // operations on a Deck (array of cards)
  //
void  InitializeDeck(   Card*  pDeck );
Card* DealCardFromDeck( Card   pDeck[] , int index );
void  PrintDeck(        Card*  pDeck );


int main( void ) 
{
  Card deck[ kCardsInDeck ];
  Card* pDeck = deck;

  InitializeDeck( &deck[0] );
  
  Hand h1 , h2 , h3 , h4;
  
  InitializeHand( &h1 );
  InitializeHand( &h2 );
  InitializeHand( &h3 );
  InitializeHand( &h4 );
  
#if 1
  for( int i = 0 ; i < kCardsInHand ; i++ )
  {
    AddCardToHand( &h1 , DealCardFromDeck( pDeck , i    ) );
    AddCardToHand( &h2 , DealCardFromDeck( pDeck , i+13 ) );
    AddCardToHand( &h3 , DealCardFromDeck( pDeck , i+26 ) );
    AddCardToHand( &h4 , DealCardFromDeck( pDeck , i+39 ) );
  }
#endif
  
  printf(          "                  Hand 1: \n");
  PrintHand( &h1 , "                  " );
  printf(          "Hand 2: \n");
  PrintHand( &h2 , "  " );
  printf(          "                                    Hand 3: \n");
  PrintHand( &h3 , "                                    " );
  printf(          "                  Hand 4: \n" );
  PrintHand( &h4 , " z");
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

  // ============================================
  // Operations on a Hand
  // ============================================


void InitializeHand( Hand* pHand )
{
  pHand->cardsDealt = 0;
}

void AddCardToHand( Hand* pHand , Card* pCard )
{
  int numInHand = pHand->cardsDealt;
  if( numInHand == kCardsInHand ) return;

  Card* pC = GetCardInHand( pHand , numInHand );
  InitializeCard( pC , pCard->suit , pCard->face , pCard->isWild );  

  pHand->cardsDealt++;
}

void PrintHand( Hand* pHand , char* pLeadStr )
{
  for( int i = 0; i < kCardsInHand ; i++ ) // 1..5
  {
    Card* pCard = GetCardInHand( pHand , i );
    printf("%s" , pLeadStr );
    PrintCard( pCard );
    printf("\n");
  }
}


Card* GetCardInHand(  Hand* pHand , int cardIndex )
{
  Card* pC;
  switch( cardIndex ) {
    case 0:  pC = &(pHand->card1); break;
    case 1:  pC = &(pHand->card2); break;
    case 2:  pC = &(pHand->card3); break;
    case 3:  pC = &(pHand->card4); break;
    case 4:  pC = &(pHand->card5); break;
  }
  return pC;
}


  // ============================================
  // Operations on a Deck of Cards
  // ============================================


void InitializeDeck( Card* pDeck )
{
  Face f[] = { two   , three , four , five , six   , seven ,
               eight , nine  , ten  , jack , queen , king  , ace };
  Card* pC;  
  for( int i = 0 ; i < kCardsInSuit ; i++ )
  {
    pC = &(pDeck[ i + (0*kCardsInSuit) ]);
    InitializeCard( pC , spade , f[i], kNotWildCard );
    
    pC = &(pDeck[ i + (1*kCardsInSuit) ]);
    InitializeCard( pC , heart , f[i], kNotWildCard );

    pC = &(pDeck[ i + (2*kCardsInSuit) ]);
    InitializeCard( pC , diamond , f[i], kNotWildCard );
 
    pC = &(pDeck[ i + (3*kCardsInSuit) ]);
    InitializeCard( pC , club , f[i], kNotWildCard );
  }
}


Card* DealCardFromDeck( Card pDeck[] , int index )
{
  Card* pCard = &pDeck[ index ];
  return pCard;  
}


void PrintDeck( Card* pDeck )
{
  printf( "%d cards in the deck\n\n" , 
          kCardsInDeck );
  printf( "The ordered deck: \n" );
  for( int i = 0 ; i < kCardsInSuit ; i++ )
  {
    int index  = i + (0*kCardsInSuit);
    printf( "(%2d)" , index+1 );
    PrintCard( &(pDeck[ index ] ) );
    
    index = i + (1*kCardsInSuit);
    printf( "   (%2d)" , index+1 );
    PrintCard( &(pDeck[ index ] ) );

    index = i + (2*kCardsInSuit);
    printf( "   (%2d)" , index+1 );
    PrintCard( &(pDeck[ i + (2*kCardsInSuit) ] ) );

    index = i + (3*kCardsInSuit);
    printf( "   (%2d)" , index+1 );
    PrintCard( &(pDeck[ index ] ) );
    printf( "\n" );
  }
  printf( "\n\n" );
}

  //  eof
