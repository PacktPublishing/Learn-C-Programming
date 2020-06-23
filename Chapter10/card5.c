// card5.c
// Chapter 10
// Learn C Programming
//
// Demonstrate how to create source file with its
// own header file of typedefs, custom types, and 
// function prototypes.
//
// Depends upon:
//
//    card.h
//
// Compile with:
//
//    cc card5.c -o card5 -Wall -Werror -std=c11
//


#include <stdio.h>
#include <stdbool.h>

#include "card.h"


int main( void ) 
{
  Hand h = {0};

  Card c1 = { spade   , (int)spade   , ten   , (int)ten   , false };
  Card c2 = { heart   , (int)heart   , queen , (int)queen , false };
  Card c3 = { diamond , (int)diamond , five  , (int)ten   , false };
  Card c4 = { club    , (int)club    , ace   , (int)ace   , false };
  Card c5 = { heart   , (int)heart   , jack  , (int)jack  , false };
  Card c6 = { club    , (int)club    , two   , (int)two   , false };
    
  h = addCard( h , c1 );
  h = addCard( h , c2 );
  h = addCard( h , c3 );
  h = addCard( h , c4 );
  h = addCard( h , c5 );
  h = addCard( h , c6 );
  
  printHand( h );
  printf("\n");
  printHand2( h );
  
  return 0;  
}


Hand addCard( Hand oldHand , Card card )
{
  Hand newHand = oldHand;
  switch( newHand.cardsDealt ) 
  {
    case 0:
      newHand.c1 = card;  newHand.cardsDealt++;  break;
    case 1:
      newHand.c2 = card;  newHand.cardsDealt++;  break;
    case 2:
      newHand.c3 = card;  newHand.cardsDealt++;  break;
    case 3:
      newHand.c4 = card;  newHand.cardsDealt++;  break;
    case 4:
      newHand.c5 = card;  newHand.cardsDealt++;  break;
    default:
      // Hand is full, what to do now?
      // ERROR --> Ignore new card.
      newHand = oldHand;
      break;
  }
  return newHand;
}

void printHand( Hand h )
{
  for( int i = 1; i < h.cardsDealt+1 ; i++ ) // 1..5
  {
    Card c;
    switch( i )
    {
      case 1: c = h.c1; break;
      case 2: c = h.c2; break;
      case 3: c = h.c3; break;
      case 4: c = h.c4; break;
      case 5: c = h.c5; break;
      default:  return; break;
    }
    printCard( c );
  }
}


void printHand2( Hand h )
{
  int dealt = h.cardsDealt;
  if( dealt == 0 ) return;
  printCard( h.c1 ); if( dealt == 1 ) return;  
  printCard( h.c2 ); if( dealt == 2 ) return;
  printCard( h.c3 ); if( dealt == 3 ) return;
  printCard( h.c4 ); if( dealt == 4 ) return;
  printCard( h.c5 ); return;
}


// yet another version of printHand
//
void printHand3( Hand h )
{
  for( int i = 1; i < h.cardsDealt+1 ; i++ ) // 1..5
  {
    switch( i )
    {
      case 1: printCard( h.c1 ); break;
      case 2: printCard( h.c2 ); break;
      case 3: printCard( h.c3 ); break;
      case 4: printCard( h.c4 ); break;
      case 5: printCard( h.c5 ); break;
      default:  return; break;
    }
    ;
  }
}


void printCard( Card c )
{
  switch( c.face )
  {
    case two:   printf( "    2 " ); break;
    case three: printf( "    3 " ); break;
    case four:  printf( "    4 " ); break;
    case five:  printf( "    5 " ); break;
    case six:   printf( "    6 " ); break;
    case seven: printf( "    7 " ); break;
    case eight: printf( "    8 " ); break;
    case nine:  printf( "    9 " ); break;
    case ten:   printf( "   10 " ); break;
    case jack:  printf( " Jack " ); break;
    case queen: printf( "Queen " ); break;
    case king:  printf( " King " ); break;
    case ace:   printf( "  Ace " ); break;
    default:    printf( "  ??? " ); break;
  }
  switch( c.suit )
  {
    case spade:   printf( "of Spades\n");   break;
    case heart:   printf( "of Hearts\n");   break;
    case diamond: printf( "of Diamonds\n"); break;
    case club:    printf( "of Clubs\n");    break;
    default:      printf( "of ???s\n");     break;
  }
}

//  eof
