#include <stdio.h>
#include "draw.h"

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop
    

    fputs("Select which shape you want to print (Arrow = a, Triangle = t, Square = s, Chars = c) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    int f;                      /*for the font choice*/
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;
    
    // Given the user answer, select which method to call
    switch (c) {
    case 'a':
      puts("You selected Arrow");
      print_arrow(5,7);
      break;
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      puts("You selected chars:\n");
      fputs("for 11x16 font press 1... for 5x7 font press 2\n",stdout);
      fflush(stdout);
      while ((f = getchar()) == '\n');
      switch(f){
      case '1':
	 for (char c = 'A'; c < 'D'; c++)
	print_char_11x16(c);
      break;
      case '2':
	 for (char c = 'A';c<'D';c++)
	    print_char_5x7(c);
	  break;
      default:
	puts("incorrect input");
      break;
      }
    break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
