#include <stdio.h>
#include <string.h>

#include "ascii_Arts&Mazes.c"
#include "player.h"


int main(void)
{
  while (1)
  {
    for(int i = 0; i < 27; i++)
    {
      for(int j = 0; j < 52, j++)
      {
        printf("%c", maze1[i][j]);
      }
    }
  }


  return 0;
}
