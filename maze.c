#include <stdio.h>
#include <string.h>

#include "ascii_Arts&Mazes.c"

void PrintScoreboard();

int main(void)
{

  printf("Hello World\n");
  printf("%s", maze1[0]);
  //Hello
  
  PrintScoreboard();

  return 0;
}


//Todo: update PrintScoreboard to show proper values
void PrintScoreboard() {
  printf(" ------------------------------------------------------\n");
  printf("|                    SCOREBOARD                        |\n");
  printf("|------------------------------------------------------|\n");
  printf("| Score      |          |  Location X   |              |\n");
  printf("|------------------------------------------------------|\n");
  printf("| Multiplier |          |  Location Y   |              |\n");
  printf("|------------------------------------------------------|\n");
  printf("| Moves Left |          |                              |\n");
  printf(" ------------------------------------------------------\n");
}


