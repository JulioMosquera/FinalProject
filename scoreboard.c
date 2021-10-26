#include <stdio.h>

void PrintScoreboard(int score, int multiplier, int moves, int locX, int locY) {
  printf(" ------------------------------------------------------\n");
  printf("|                    SCOREBOARD                        |\n");
  printf("|------------------------------------------------------|\n");
  printf("| Score      |    %i    |  Location X   |     %i       |\n", score, locX);
  printf("|------------------------------------------------------|\n");
  printf("| Multiplier |    %i    |  Location Y   |     %i       |\n", multiplier, locY);
  printf("|------------------------------------------------------|\n");
  printf("| Moves Left |    %i    |                              |\n", moves);
  printf(" ------------------------------------------------------\n");
}

