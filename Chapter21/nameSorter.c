// nameSorter.c
// Chapter 21
// Learn C Programming - Fundamentals of C
//
// Demonstrates a simple "insertion sort" using an array.
// Input and output is primarily done with fgets() and fputs().
//
// compile with: cc nameSorter.c -o nameSorter -Wall -Werror -std=c11
//


#include <stdio.h>
#include <string.h> 
#include <stdbool.h>

const int listMax   = 100; 
const int stringMax =  80; 

typedef char string [ stringMax ]; 

void addName(    string* names , string newOne , int* listSize ); 
void printNames( string* names , int listSize ); 

void removeNewline( string s )  {
   int len = strlen( s );
   s[ len-1 ] = '\0';
}

int main( void )  {  
  string newName; 
  string nameList[ listMax ]; 
  int    numNames = 0; 

  while( printf( "Name: %d: ", numNames+1 ),
         fgets( newName , stringMax , stdin ),
         removeNewline( newName ) ,
         strlen( newName ) > 0 ) 
    addName( nameList , newName , &numNames ); 

  printNames( nameList , numNames ); 
}

void addName( string* names , string newName , int* pNumEntries )  { 
  if( *pNumEntries >= listMax )  {
    puts( "List is full!" );
    return; /* the array is full */ 
} else { 
    int  k     = 0;     /* k is position in list to insert newName. */
    bool found = false; /* When found is true, newName goes before an existing 
                           name in the list. */
     
      /* Scan through list looking for existing name that newName should come 
         before. If not found, k is the end of the list. */
    while( !found && k < *pNumEntries )
      found = (strcmp( newName, names[ k++ ] ) < 0);
       
    if( found )  {
         /* Move k back one place to insert newName at k-th position.*/ 
      k-- ;
         /* Move each exising name back in the list, making a space newName */
      for( int j = *pNumEntries ; j > k ; j-- )  {
        strcpy( names[ j ] , names[ j-1 ] ); 
      }
    }
      /* Insert new string in list at k-th position. */
    strcpy( names[ k ] , newName ); 
    (*pNumEntries)++; 
  } 
  return;
}

void printNames( string *names , int numEntries )
{ 
  printf("\nNumber of Entries: %d\n\n" , numEntries ); 
  for( int i = 0 ; i < numEntries ; i++ )  {
    fputs( names[i] , stdout );
    fputc( '\n' , stdout );
  }
} 

  // eof
