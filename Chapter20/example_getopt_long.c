// example_getopt_long.c
// Chapter 20
// Learn C Programming
//
// Demonstrate how to 
// * retrieve arguments entered on the command line with the C Standard
//   Library routine getopts_long().
//
// compile with:
//
//     cc example_getopt_long.c -o example_getopt_long -Wall -Werror -std=c11
//
// sample inputs;
//
//  example_getopt_long -t "There and Back" -a "Bilbo Baggins"
//  example_getopt_long --author "Jeff Szuhay --title "Hello, world!"
//  example_getopt_long -a -t
//  example_getopt_long -b -c 
//

#include <stdio.h>
#include <getopt.h>


static struct option long_options[] = {
  {"title",  required_argument, NULL, 't'},
  {"author", required_argument, NULL, 'a'},
  {NULL, 0, NULL, 0}
};

typedef struct _book {
    char* title;
    char* author;
} Book;


int main(int argc, char *argv[]) {
  char ch;
  Book b;

  while( (ch = getopt_long( argc , argv , "t:a:" , long_options, NULL ) ) != -1 ) {
    switch (ch) {
      case 't': 
        b.title = optarg;
        break;
      case 'a':
        b.author = optarg;
        break;
      default:
        printf( "\nUsage: %s -title 'title' -author 'name'\n\n" , argv[0] );
        return 1;
        break;
    }
  }
  if( b.title )  printf( "Title is [%s]\n" , b.title );
  if( b.author ) printf( "Author is [%s]\n" , b.author );
  if( optind < argc )  {
     printf( "non-option ARGV-elements: " );
     while( optind < argc )
        printf( "%s ", argv[ optind++ ] );
     printf( "\n" );
   }
}

  // eof
