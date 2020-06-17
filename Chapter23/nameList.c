// nameList.c
// Chapter 23
// Learn C Programming - Fundamentals of C
//
//
// A family of singly-linked list routines to 
// perform insertion sort.
//
// Do not compile alone. No main(). Part of sortNames.c
//

#include "nameList.h"


NameList* CreateNameList( void ) {
  NameList* pNL = (NameList*)calloc( 1 , sizeof( NameList ));
  if( pNL == NULL ) OutOfStorage();
  return pNL;
}


ListNode* CreateListNode( char* pNameToAdd ) {
  ListNode* pNewNode = (ListNode*)calloc( 1 , sizeof( ListNode ) );
  if( pNewNode == NULL ) OutOfStorage();
  pNewNode->pData = (char*)calloc(1, strlen(pNameToAdd)+1 );
  if( pNewNode->pData == NULL ) OutOfStorage();
  strcpy( pNewNode->pData , pNameToAdd );
  return pNewNode;
}


void AddName(  NameList* pNames , char* pNameToAdd ) {
  ListNode* pNewName = CreateListNode( pNameToAdd );
  
  if( IsEmpty( pNames ) ) {  // Empty list. Insert as 1st item.
    pNames->pFirstNode = pNewName;
    (pNames->nodeCount)++;
    return;
  }
  
  (pNames->nodeCount)++;
  ListNode* curr;
  ListNode* prev;
  curr = prev = pNames->pFirstNode;
  while( curr ) {
      // Perform string comparison here.
    if( strcmp( pNewName->pData , curr->pData ) < 0 ) {
        // Found insertion point before an existing name.
      if( curr == pNames->pFirstNode) { // New names comes before all. Insert at front
        pNames->pFirstNode = pNewName;
        pNewName->pNext = curr;
      } else {                          // Insert somewhere in middle
        prev->pNext = pNewName;
        pNewName->pNext = curr;
      }
      return;
    }
    prev = curr;                       // Adjust pointers for next iteration.
    curr = prev->pNext;
  }
  prev->pNext = pNewName;              // New name comes after all. Insert at end.
}


void PrintNames( FILE * outputDesc , NameList* pNames ) {
  ListNode* curr = pNames->pFirstNode;
  while( curr ) {
    fputs( curr->pData , outputDesc );
    fputc( '\n'        , outputDesc );
    curr = curr->pNext;
  }
}


void DeleteNames( NameList* pNames )  {
  while( pNames->pFirstNode )  {
    ListNode* temp = pNames->pFirstNode;
    pNames->pFirstNode = pNames->pFirstNode->pNext;
    free( temp->pData );
    free( temp );
  }
}

bool IsEmpty( NameList* pNames ) {
  return pNames->nodeCount==0;
}


void OutOfStorage( void ) {
  fprintf( stderr , "### FATAL RUNTIME ERROR ### No Memory Available" );
  exit( EXIT_FAILURE );
}

  // eof
