#include <stdio.h>
#include <string.h>

#include "ascii_ArtsAndMazes.h"
#include "player.h"


int main(void)
{
  int startingLoc[2] = {0,0};
  Player curPlayer;
  curPlayer = initPlayer( startingLoc, 100, 0, 1);
  PrintScoreboard(curPlayer.score, curPlayer.scoreMultipler, curPlayer.movesLeft, curPlayer.location[0], curPlayer.location[1]);

  for(int i = 0; i < 27; i++)
  {
    for(int j = 0; j < 52; j++)
    {
      printf("%c", maze1[i][j]);
    }
  }


  return 0;
}

