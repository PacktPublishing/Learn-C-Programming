// nameList.h
// Chapter 23
// Learn C Programming
//
// Header file for nameList.c
//

#ifndef _SORT_NAMES_H_
#define _SORT_NAMES_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char   ListData;

typedef struct _Node ListNode;
typedef struct _Node {
  ListNode*  pNext;
  ListData*  pData;
} ListNode;

typedef struct {
  ListNode*  pFirstNode;
  int        nodeCount;
} NameList;

NameList*  CreateNameList();
ListNode*  CreateListNode( char* pNameToAdd );
void  AddName(     NameList* pNames , char* pNameToAdd );
void  DeleteNames( NameList* pNames );
bool  IsEmpty(     NameList* pNames );
void  PrintNames(  FILE* outputDesc ,  NameList* pNames );

void OutOfStorage( void );

#endif
