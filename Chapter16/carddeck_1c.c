// carddeck_1c.c
// Chapter 16
// Learn C Programming
//
// carddeck_1c.c builds upon carddeck_1b.c.
// In this version, we add an array of structures, called Deck
// and some functions to manipulate the Deck array.
// 
// compile with
//
//    cc carddeck_1c.c -o carddeck_1c -Wall -Werror =std=c11
//


#include <stdbool.h>   // for Boolean
#include <stdio.h>     // for printf()
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
  kCardsInSuit = 13   // For now, kCardsInDeck / 4. This will change
                      // depending upon the card game.
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

  // Card Faces
  //
typedef enum 
{ 
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


  // A Card
  //
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

  // ============================================
  // Definitions related to a Deck
  // 
  // A Deck
  
// For now, the deck will be declared as an array of Cards in main().

  // operations on a Deck (array of cards)
  //
void InitializeDeck( Card* pDeck );
void PrintDeck(      Card* pDeck );


int main( void ) 
{
  Card deck[ kCardsInDeck ];
  InitializeDeck( &deck[0] );
  PrintDeck(      &deck[0] );
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
