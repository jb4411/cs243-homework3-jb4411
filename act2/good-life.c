/// http://www.dreamincode.net/forums/topic/55572-conways-game-of-life/
/// downloaded by copy-paste on 8/19/2015 and modified to use an infinite loop
/// and have different Rule functions.
///
/// This code needs serious work in these areas:
/// <ol>
/// <li>  syntax: there are a number of warnings that cause errors.
/// </li>
/// <li>  semantics: the game algorithm implementation is incorrect.
/// </li>
/// <li>  design: the implementation needs function and value refactoring.
/// </li>
/// <li>  style: formatting is poor; the mix of TAB and spaces indentation
/// needs correction, and spacing between tokens is inconsistent.
/// The course style puts the '{' at the end of the function header, not
/// on a line of its own. You should make the formatting consistent.
/// </li>
/// <li>  documentation: documentation is non-existent except for this block.
/// </li>
/// </ol>
/// @author Jesse Burdick-Pless jb4411 

#include <stdio.h>
#include <stdlib.h>

void header(void)
{
      printf("\n\t..Welcome to the Game of life..\n");
}

void copyArray(char src[20][20], char dest[20][20]){
    int row, col;
    for(row = 0; row<20; row++) {
	    for(col = 0; col<20; col++) {
		    dest[row][col] = src[row][col];
	    }
    }
}

void survivalRule(char life[][20])
	/// ^ fix 13: removed unused parameters 'x' and 'y'
{
      char newlife[20][20] = {{' '}};
      int row, col;
      copyArray(life, newlife);
      int neighbors = 0;
      for(row = 0; row<20; row++)
      {
         for(col = 0; col<20; col++)
         {
         //if(life[row][col] == '*')  /// fix 9: removed '&' and changed " to
	    if(row > 0) {
	       if(col > 0 && life[row - 1][col - 1] == '*')
                  ++neighbors;
               if(life[row - 1][col] == '*')
                  ++neighbors;
               if(col < 19 && life[row - 1][col + 1] == '*')
                  ++neighbors;
	    }
               if(col > 0 && life[row][col - 1] == '*')
                  ++neighbors;
               if(col <19 && life[row][col + 1] == '*')
                  ++neighbors;
	    if(row < 19) {
               if(col > 0 && life[row + 1][col - 1] == '*')
                  ++neighbors;
               if(life[row + 1][col] == '*')
                  ++neighbors;   
	       if(col < 19 && life[row + 1][col + 1] == '*')
                  ++neighbors;
	    }
            if(neighbors == 3) {
		    newlife[row][col] = '*'; /// fix 10: removed an '='
	    } else if(neighbors == 2 && life[row][col] == '*') {
		    newlife[row][col] = '*';
	    } else {
		    newlife[row][col] = ' ';
	    }
            neighbors = 0;
	 }
      } 
      copyArray(newlife, life);
      return;
}

void birthRule(char life[][20]) 
	/// ^ fix 12: removed unused parameters 'x' and 'y'
{
      int row, col;
      int neighbors = 0;
      for(row = 1; row<19; row++)
      {
         for(col = 1; col<19; col++)
         {
            if(life[row][col] == ' ') /// fix 8: removed '&' and changed " to '
            {
               if(life[row - 1][col - 1] == '*')
                  neighbors++;
               if(life[row - 1][col] == '*')
                  neighbors++;
               if(life[row - 1][col + 1] == '*')
                  neighbors++;
               if(life[row][col - 1] == '*')
                  neighbors++;
               if(life[row][col + 1] == '*')
                  neighbors++;
               if(life[row + 1][col - 1] == '*')
                  neighbors++;
               if(life[row + 1][col] == '*')
                  neighbors++;
               if(life[row + 1][col + 1] == '*')
                  neighbors++;
               if(neighbors == 3)
               {
                   life[row][col] = '*'; /// fix 7: removed an '='
               }
            }
         }
      }
      return;
}


int main(void)
{
      char life[20][20] = {{' '}}; /// fix 2: initlized array
      int orgs; /// fix 11: removed unused varible 'gens'
      int i = 0, row = 0, col = 0; /// fix 2: initlized varibles
      /// ^ fix 6: removed unused varibles 'a' and 'b'
      int count = 0;
      /// fix 17: removed unused varible 'int x'
      /// fix 16: removed unused varible 'int y'
      /// fix 5: removed unused varible 'char ans'

      header();

      printf("\nPlease enter the initial number of organisms: ");
      scanf("%i", &orgs);

      srand( 31 );
      
      while( i<orgs )
      {
          row = rand();
          row %= 20;
          col = rand();
          col %= 20;
	  if( life[row][col] != '*' ) {
              life[row][col] = '*'; /// fix 4: removed an '='
	      i++;
	  } 
      }
      
      for(row = 0; row<20; row++)
      {
          for(col = 0; col<20; col++)
          {
              if(life[row][col] != '*')
                  life[row][col] = ' '; /// fix 3: removed an '='
          }
      }

      for(row = 0; row<20; row++)
      {
          for(col = 0; col<20; col++)
          {
              printf("%c", life[row][col]); /// fix 1: changed %s to %c
          }
          puts(" ");
      }

      printf("\ngeneration: 0\n");

      while ( count < 100 ) {
          //birthRule(life); /// fix 14: removed excess arguments 'x' & 'y'
          survivalRule(life); /// fix 15: removed excess arguments 'x' & 'y'
          for(row = 0; row<20; row++)
          {
              for(col = 0; col<20; col++)
              {
                  printf("%c", life[row][col]); /// fix 1: changed %s to %c
              }
              puts(" ");
          }
          printf("\ngeneration: %d\n", count+1);
          count++;
      }

      return 0;
}

