// example_gnu_getopts_long.c
// Chapter 20
// Learn C Programming
//
// Demonstrate how to 
// * retrieve arguments entered on the command line using the C Standard
//   Library routine getopt_long().
// * use flag arguments with no parameters
// * use required arguments
// * use optional arguments with default setting (can be set to something else.
//
// compile with:
//
//   cc example_gnu_getopts_long.c -o showArgs -Wall -Werror -std=c11
//
// Sample inputs:
//
//   example_gnu_getopts_long --verbose -a -b --num=3 --size=10 --delete=Bye-bye \
//                            -c Hello -f AFile.dat Red Green Blue
//   (try others yourself)
//

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

  /* Flag set by ‘--verbose’. */
static int verbose_flag;
static int num_flag;

static struct option long_options[] =
    {
        /* These options set a flag. */
      {"verbose", no_argument,       &verbose_flag, 1},
      {"brief",   no_argument,       &verbose_flag, 0},
        /* These options don’t set a flag.
           We distinguish them by their indices. */
      {"add",     no_argument,       0, 'a'},
      {"append",  no_argument,       0, 'b'},
      {"delete",  required_argument, 0, 'd'},
      {"create",  required_argument, 0, 'c'},
      {"file",    required_argument, 0, 'f'},
      {"number",  optional_argument, &num_flag, 1},
      {"size",    optional_argument, 0 , 's'},
      {0, 0, 0, 0}
    };

int main (int argc, char **argv)
{
  int c;

  while (1) {
        /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "abc:d:f:s:",
                       long_options, &option_index);

        /* Detect the end of the options. */
      if (c == -1)
        break;

      switch (c)  {
        case 0:
            /* If this option set a flag, do nothing else now. */
//          if (long_options[option_index].flag != 0)
//            break;
          printf ("option %s", long_options[option_index].name);
          if( optarg )
            printf (" with arg %s", optarg);
          printf( "\n" );
          break;

        case 'a':
          puts ("Option -a");
          break;

        case 'b':
          puts ("Option -b");
          break;

      case 'n':
        printf( "Option -n");
        if( optarg ) printf( " with value %s" , optarg );
        printf( "\n" );
        break;

      case 'c':
          printf ("Option -c with value `%s'\n", optarg);
          break;

        case 'd':
          printf ("Option -d with value `%s'\n", optarg);
          break;

        case 'f':
          printf ("Option -f with value `%s'\n", optarg);
          break;

        case 's':
          printf( "Option -s");
          if( optarg ) printf( " with value %s" , optarg );
          printf( "\n" );
          break;

        case '?':
          /* getopt_long already printed an error message. */
          break;

        default:
          abort ();
        }
    }

  /* Instead of reporting ‘--verbose’
     and ‘--brief’ as they are encountered,
     we report the final status resulting from them. */
  if (verbose_flag)
    puts ("verbose flag is set");

  /* Print any remaining command line arguments (not options). */
  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  exit (0);
}

  // eof
