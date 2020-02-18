// linkedlisttester.c
// Chapter 18
// <book title>
//
// Demonstrate how to 
// 1) define structures for a linked list
// 2) define operations on that linked list
// 3) fully exercise (test) the link list implementation
//
// compile with: cc linkedlisttester.c -o linkedlisttester -Wall -Werror -std=c11
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// ======= For testing
typedef enum 
{
  eFront = 0 ,
  eBack
} eWhere;

typedef enum 
{ 
  eLook = 0 ,
  eInsert , 
  eDelete 
} eAction;

// =======List structures & function prototypes

typedef int ListData;

typedef struct _Node ListNode;
typedef struct _Node
{
  ListNode*  pNext;
  ListData*  pData;
} ListNode;


typedef struct
{
  ListNode*  pFirstNode;
  int        nodeCount;
} LinkedList;


LinkedList* CreateLinkedList();
bool        IsEmpty(    LinkedList* pList );
int         Size(       LinkedList* pList );

void       InsertNodeToFront(    LinkedList* pList , ListNode* pNode );
void       InsertNodeToBack(     LinkedList* pList , ListNode* pNode );
ListNode*  RemoveNodeFromFront(  LinkedList* pList );
ListNode*  RemoveNodeFromBack(   LinkedList* pList );
ListNode*  GetNode(    LinkedList* pList , int pos );
ListNode*  CreateNode( ListData* pData );
void       DeleteNode( ListNode* pNode );
void       PrintList(  LinkedList* pList ,
                       void (*printData)(ListData* pData ) );
void       PrintNode(  ListNode* pNode , 
                       void (*printData)(ListData* pData ) );

void       OutOfStorage( void );


// =======List function declarations

LinkedList*  CreateLinkedList()
{
  LinkedList* pLL = (LinkedList*) calloc( 1 , sizeof( LinkedList ) ); 
  if( pLL == NULL) OutOfStorage();
  return pLL;
}


bool  IsEmpty( LinkedList* pList )
{
  return( pList->nodeCount == 0 );  
}


int  Size( LinkedList* pList )
{
  return pList->nodeCount;
}


void  InsertNodeToFront( LinkedList* pList , ListNode* pNode )
{
  ListNode* pNext   = pList->pFirstNode;
  pList->pFirstNode = pNode;
  pNode->pNext      = pNext;

  pList->nodeCount++;
}

void InsertNodeToBack( LinkedList* pList , ListNode* pNode )
{
  if( IsEmpty( pList ) ) // list is empty
  {
    pList->pFirstNode = pNode;
  } else {
    ListNode* pCurr = pList->pFirstNode ; 
    while( pCurr->pNext != NULL )
    {
      pCurr = pCurr->pNext;
    }
    pCurr->pNext  = pNode;
  }
  pList->nodeCount++;
}


ListNode*  RemoveNodeFromFront( LinkedList* pList )
{
  if( IsEmpty( pList )) return NULL;
  
  ListNode* pCurr   = pList->pFirstNode;
  pList->pFirstNode = pList->pFirstNode->pNext;
  pList->nodeCount--;
  return pCurr;
}


ListNode* RemoveNodeFromBack( LinkedList* pList )
{
  if( IsEmpty( pList ) ) // list is empty
  {
    return NULL;
  } else {
    ListNode* pCurr = pList->pFirstNode ;
    ListNode* pPrev = NULL; 
    while( pCurr->pNext != NULL )
    {
      pPrev = pCurr;
      pCurr = pCurr->pNext;
    }
    pPrev->pNext = NULL;    
    pList->nodeCount--;
    
    return pCurr;
  }
}


ListNode*  GetNode( LinkedList* pList , int pos )
{
  ListNode* pCurr = pList->pFirstNode;
  if( pCurr == NULL ){
    return pList->pFirstNode;
  } else if ( pos == 0 ) {
    return pList->pFirstNode;
  } else {
    int i = 0;
    while( pCurr->pNext != NULL )
    {
      if( i == pos ) return pCurr;
      i++;
      pCurr = pCurr->pNext;
    }
    return pCurr;
  }
}


ListNode*  CreateNode( ListData* pData )
{
  ListNode* pNewNode = (ListNode*) calloc( 1 , sizeof( ListNode ) );
  if( pNewNode == NULL ) OutOfStorage();
  
  pNewNode->pData = pData;
  
  return pNewNode;
}


void  DeleteNode( ListNode* pNode )
{
  free( pNode->pData );
  free( pNode );
}


void  PrintList( LinkedList* pList , void (*printData)(ListData* pData ) )
{
  ListNode* pCurr = pList->pFirstNode;
  
  printf( "List has %2d entries: [" , Size( pList ) );
  while( pCurr != NULL )
  {
    PrintNode( pCurr , printData );
    pCurr = pCurr->pNext;
  }
  printf( "]\n" );
}


void PrintNode( ListNode* pNode , void(*printData)( ListData* pData ) )
{
  printData( pNode->pData );
}

void OutOfStorage( void )
{
  fprintf( stderr , "### FATAL RUNTIME ERROR ### No Memory Available" );
  exit( EXIT_FAILURE );
}


// =================================================
// main() function and
// test routines.

// ---- functions for the specific type of ListData (int)
void PrintInt( int* i )
{
  printf( "%2d ", *i );
}

ListData* CreateData( ListData d )
{
  ListData* pD = (ListData*)calloc( 1 , sizeof( ListData ) );
  if( pD == NULL )  OutOfStorage();
  *pD = d;
  return pD;
}
// ---- Test functions to exercise our linked list.

void TestCreateNodeAndInsert( LinkedList* pLL , ListData data ,  eWhere where )
{
  ListData* pData = CreateData( data );
  ListNode* pNode = CreateNode( pData );
  
  switch( where ) {
    case eFront: InsertNodeToFront( pLL , pNode ); break;
    case eBack:  InsertNodeToBack(  pLL , pNode ); break;
  }
}

ListData TestExamineNode( LinkedList* pLL , eWhere where )
{
  ListNode * pNode;
  switch( where ) {
    case eFront: pNode = GetNode( pLL , 0 ); break;
    case eBack:  pNode = GetNode( pLL , pLL->nodeCount ); break;
  }
  ListData data = *(pNode->pData);
  return data;
}

ListData TestRemoveNodeAndFree( LinkedList* pLL , eWhere where )
{
  ListNode * pNode;
  switch( where ) {
    case eFront: pNode = RemoveNodeFromFront( pLL ); break;
    case eBack:  pNode = RemoveNodeFromBack(  pLL ); break;
  }
  ListData data = *(pNode->pData);
  DeleteNode( pNode );
  return data;
}    

void TestPrintOperation( LinkedList* pLL , eAction action , ListData data , eWhere where )
{
  switch( action )
  {
    case eLook:
      data = TestExamineNode( pLL , where );
      printf( "Get %s node, see [%2d]. " , where==eFront ? "front" : " back" , data );
      break;
    case eInsert:
      printf( "Insert [%2d] to %s.     " , data , where==eFront ? "front" : " back" );
      TestCreateNodeAndInsert( pLL , data , where );
      break;
    case eDelete:
      data = TestRemoveNodeAndFree( pLL , where );
      printf( "Remove [%2d] from %s.   " , data , where==eFront ? "front" : " back" );
      break;
    default:
      printf( "::ERROR:: unknown action\n" );
      break;
  }
  PrintList( pLL , PrintInt );
}
//=======================================================================
int main( void )
{
  LinkedList* pLL = CreateLinkedList();
     
  printf( "\nUsing input{ 1  2  3  4 } " );
  int data1[]   = { 1 , 2 , 3 , 4 };
  int data1Size = 4;

  PrintList( pLL , PrintInt );  
  for( int i = 0 ; i < data1Size ; i++)  {
    TestPrintOperation( pLL , eInsert , data1[i] , eFront );
  }
  
  TestPrintOperation( pLL , eLook   , 0   , eFront );
  TestPrintOperation( pLL , eDelete , 0   , eBack );
  
  printf( "\nUsing input{ 31 32 33 }   " );
  PrintList( pLL , PrintInt );  
  int data2[]   = { 31 , 32 , 33 };
  int data2Size = 3;
  for( int i = 0 ; i < data2Size ; i++)  {
    TestPrintOperation( pLL , eInsert , data2[i] , eBack );
  }
  TestPrintOperation( pLL , eLook   , 0   , eBack );
  
  int count = pLL->nodeCount;
  for( int i = 0 ; i < count ; i++)
  {
    TestPrintOperation( pLL , eDelete, 0 , eFront );
  }
}

  // eof
  