// carddeck_2b.c
// Chapter 16
// Learn C Programming
//
// carddeck_2b.c builds upon carddeck_2a.c.
// In this version, we add the hand structure using
// individual pointer variables to Cards.
// 
// compile with
//
//     cc carddeck_2b.c -o carddeck_2b -Wall -Werror -std-c11
//


#include <stdio.h>
#include <stdbool.h>
#include <string.h>    // for strcpy() and strcat()


  // Useful constants (avoid "magic numbers" whose meaning is
  // sometimes vague and whose values may change). Use these instead
  // of literals; when you need to change these, they are applied
  // everywhere.
  //
enum {
  kCardsInDeck = 52,  // For now, 52 cards in a deck. This will change
                      // depending upon the card game and the # of wild
                      // cards, etc.
  kCardsInSuit = 13,  // For now, kCardsInDeck / 4. This will change
                      // depending upon the card game.
  kCardsInHand =  5,  // For now, 5 cards dealt for each hange. This will
                      // change depending upon the card game.
  kNumHands    =  4   // For now, for hands per "table". This will change
                      // depending on the game we want to implement.
};

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
  Card*  pCard1;
  Card*  pCard2;
  Card*  pCard3;
  Card*  pCard4;
  Card*  pCard5;
} Hand;

  // Operations on a Hand
  //
void    InitializeHand( Hand* pHand );
void    AddCardToHand(  Hand* pHand , Card* pCard );
void    PrintHand(      Hand* pHand , char* pHandStr , char* pLeadStr );
Card**  GetCardInHand(  Hand* pHand , int   cardIndex );


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
  
  PrintHand( &h1 , "Hand 1:" , "                  " );
  PrintHand( &h2 , "Hand 2:" , "  " );
  PrintHand( &h3 , "Hand 3:" , "                                    " );
  PrintHand( &h4 , "Hand 4:" , "                  ");
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
  pHand->pCard1     = NULL;
  pHand->pCard2     = NULL;
  pHand->pCard3     = NULL;
  pHand->pCard4     = NULL;
  pHand->pCard5     = NULL;
}

void AddCardToHand( Hand* pHand , Card* pCard )
{
  int numInHand = pHand->cardsDealt;
  if( numInHand == kCardsInHand ) return;

  Card** ppC = GetCardInHand( pHand , numInHand );
  *ppC = pCard;  

  pHand->cardsDealt++;
}

void PrintHand( Hand* pHand , char* pHandStr , char* pLeadStr )
{
  printf( "%s%s\n" , pLeadStr , pHandStr );
  for( int i = 0; i < kCardsInHand ; i++ ) // 1..5
  {
    Card** ppCard = GetCardInHand( pHand , i );
    printf("%s" , pLeadStr );
    PrintCard( *ppCard );
    printf("\n");
  }
}


Card** GetCardInHand(  Hand* pHand , int cardIndex )
{
  Card** ppC;
  switch( cardIndex ) {
    case 0:  ppC = &(pHand->pCard1); break;
    case 1:  ppC = &(pHand->pCard2); break;
    case 2:  ppC = &(pHand->pCard3); break;
    case 3:  ppC = &(pHand->pCard4); break;
    case 4:  ppC = &(pHand->pCard5); break;
  }
  return ppC;
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
