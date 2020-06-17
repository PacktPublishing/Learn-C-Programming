// carddeck.c
// Chapter 16
// Learn C Programming - Fundamentals of C
//
// carddeck.c is the final version of carddeck_3.
// 
// compile with cc carddeck.c -o carddeck -Wall -Werror =std=c11
//


#include <stdbool.h>   // for Boolean
#include <stdio.h>     // for printf()
#include <string.h>    // for strcpy() and strcat()
#include <stdlib.h>    // for rand() and srand()
#include <time.h>      // for date().


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
  // Defintions related to a hand
  //
  // A Hand
  //
typedef struct 
{
  int   cardsDealt;
  Card* hand[ kCardsInHand ];
} Hand;

  // Operations on a Hand
  //
void InitializeHand( Hand* pHand );
void AddCardToHand(  Hand* pHand , Card* pCard );
void PrintHand(      Hand* pHand , char* pLeadStr );
void PrintAllHands(  Hand* hands[ kNumHands ] );


  // ============================================
  // Definitions related to a Deck
  // 
  // A Deck
  //
typedef struct
{
  Card  ordered[ kCardsInDeck ];
  Card* shuffled[ kCardsInDeck ];
  int   numDealt;
  bool  bIsShuffled;
} Deck;


  // Operations on a Deck of Cards
  //
void  InitializeDeck(   Deck* pDeck );
void  ShuffleDeck(      Deck* pDeck );
Card* DealCardFromDeck( Deck* pDeck );
void  PrintDeck(        Deck* pDeck );

  // At this point, we have only defined structures and 
  // declared functions (operations on those structures) for
  // * card
  // * hand
  // * deck
  //
  // For now, a hand loosely corresponds to a player.
  //
  // Nothing has been allocated and each function needs
  // to be fully defined.
  //
int main( void ) 
{
  Deck  deck;
  Deck* pDeck = &deck;
  
  InitializeDeck( pDeck );
  PrintDeck(      pDeck );
  
  ShuffleDeck( pDeck );
  PrintDeck(   pDeck );
  
  Hand h1 , h2 , h3 , h4;
  
#if 0
  InitializeHand( &h1 );
  InitializeHand( &h2 );
  InitializeHand( &h3 );
  InitializeHand( &h4 );
#else
  Hand* hands[] = { &h1 , &h2 , &h3 , &h4 }; 

  for( int i = 0 ; i < kNumHands ; i++ )
  {
    InitializeHand( hands[i] );
  }
#endif
  
  for( int i = 0 ; i < kCardsInHand ; i++ )
  {
#if 0
    AddCardToHand( &h1 , DealCardFromDeck( pDeck ) );
    AddCardToHand( &h2 , DealCardFromDeck( pDeck ) );
    AddCardToHand( &h3 , DealCardFromDeck( pDeck ) );
    AddCardToHand( &h4 , DealCardFromDeck( pDeck ) );
#else
    for( int j = 0 ; j < kNumHands ; j++ )
    {
      AddCardToHand( hands[j] , DealCardFromDeck( pDeck ) );
    }
#endif
  }
  PrintAllHands( hands );
  PrintDeck(     pDeck );
  
  return 0;  
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
  for( int i = 0; i < kCardsInHand ; i++ )
  {
    pHand->hand[i] = NULL;
  }
}


void AddCardToHand( Hand* pHand , Card* pCard )
{
  if( pHand->cardsDealt == kCardsInHand ) return;
  
  pHand->hand[ pHand->cardsDealt ] = pCard;
  pHand->cardsDealt++;
}


void PrintHand( Hand* pHand , char* pLeadStr )
{
  for( int i = 0; i < kCardsInHand ; i++ ) // 1..5
  {
    Card* pCard = pHand->hand[i];
    printf("%s" , pLeadStr );
    PrintCard( pCard );
    printf("\n");
  }
}


void PrintAllHands(  Hand* hands[ kNumHands ] )
{
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


  // ============================================
  // Operations on a Deck of Cards
  // ============================================


void InitializeDeck( Deck* pDeck )
{
  Face f[13] = { two   , three , four , five , six   , seven ,
                   eight , nine  , ten  , jack , queen , king  , ace };
  Card* pC;  
  for( int i = 0 ; i < kCardsInSuit ; i++ )
  {
    pC = &(pDeck->ordered[ i + (0*kCardsInSuit) ]);
    InitializeCard( pC , spade , f[i], kNotWildCard );
    
    pC = &(pDeck->ordered[ i + (1*kCardsInSuit) ]);
    InitializeCard( pC , heart , f[i], kNotWildCard );

    pC = &(pDeck->ordered[ i + (2*kCardsInSuit) ]);
    InitializeCard( pC , diamond , f[i], kNotWildCard );
   
    pC = &(pDeck->ordered[ i + (3*kCardsInSuit) ]);
    InitializeCard( pC , club , f[i], kNotWildCard );
  }
    
  for( int i = 0 ; i < kCardsInDeck ; i++ )
  { 
    pDeck->shuffled[i] = &(pDeck->ordered[i]);
  }

  pDeck->bIsShuffled = false;
  pDeck->numDealt    = 0;
}


void ShuffleDeck( Deck* pDeck )
{
  long randIndex;
#if 1
  srand( 8*1024*1024 ); // Just some number (8 megabits for giggles)
                        // The actual number doesn't matter (could be 1).
                        // this is handy for reproducibility and verifying
                        // your program as you developt it.
#else
  srand( time(NULL) ); // Seed our PRNG using time() function. Because time()
                        // ever increases, we'll get a different series each time
                        // we run the program.
#endif
  Card* pTmpCard;
  
    // Now, walk through the shuffled array, swapping the pointer
    // at a random card index in shuffuled with the pointer at the 
    // current card index.
    //
  for( int thisIndex = 0 ; thisIndex < kCardsInDeck ; thisIndex++ )
  {
      // get a random index
    randIndex = rand() % kCardsInDeck;  // get next random number between 0..52
    
      // swap card pointers between thisIndex and randIndex
    pTmpCard = pDeck->shuffled[ thisIndex ];
    pDeck->shuffled[ thisIndex ] = pDeck->shuffled[ randIndex ];
    pDeck->shuffled[ randIndex ] = pTmpCard;
  }
  pDeck->bIsShuffled = true;
}


Card* DealCardFromDeck( Deck* pDeck )
{
  Card* pCard = pDeck->shuffled[ pDeck->numDealt ];
  pDeck->shuffled[ pDeck->numDealt ] = NULL;
  pDeck->numDealt++;
  return pCard;  
}


void PrintDeck( Deck* pDeck )
{
  printf( "%d cards in the deck\n" , 
          kCardsInDeck );
  printf( "Deck %s shuffled\n", 
          pDeck->bIsShuffled ? "is" : "is not" );
  printf( "%d cards dealt into %d hands\n" , 
          pDeck->numDealt ,  kNumHands );

  if( pDeck->bIsShuffled == true )           // Deck is shuffled.
  {
    if( pDeck->numDealt > 0 )
    {
      printf( "The remaining shuffled deck:\n" );
    } else {
      printf( "The full shuffled deck:\n");
    }
    for( int i = pDeck->numDealt , j = 0 ; i < kCardsInDeck ; i++ , j++ )
    {
      printf( "(%2d)" , i+1 );
      PrintCard( pDeck->shuffled[ i ] );
      if( j == 3  )
      {
        printf( "\n" );
        j = -1;
      } else {
        printf( "\t");
      }
    }
  } else {                                    // Deck is not shuffled.
    printf( "The ordered deck: \n" );
    for( int i = 0 ; i < kCardsInSuit ; i++ )
    {
      int index  = i + (0*kCardsInSuit);
      printf( "(%2d)" , index+1 );
      PrintCard( &(pDeck->ordered[ index ] ) );
      
      index = i + (1*kCardsInSuit);
      printf( "   (%2d)" , index+1 );
      PrintCard( &(pDeck->ordered[ index ] ) );
  
      index = i + (2*kCardsInSuit);
      printf( "   (%2d)" , index+1 );
      PrintCard( &(pDeck->ordered[ i + (2*kCardsInSuit) ] ) );
  
      index = i + (3*kCardsInSuit);
      printf( "   (%2d)" , index+1 );
      PrintCard( &(pDeck->ordered[ index ] ) );
      printf( "\n" );
    }
  }
  printf( "\n\n" );
}

  // eof
