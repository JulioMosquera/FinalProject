#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ascii_ArtsAndMazes.h"
#include "player.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int main(void)
{
  int startingLoc[2] = {0,0};
  Player curPlayer;
  curPlayer = initPlayer( startingLoc, 100, 0, 1);
  PrintScoreboard(curPlayer.score, curPlayer.scoreMultipler, curPlayer.movesLeft, curPlayer.location[0], curPlayer.location[1]);

for(int i = 0; i < 27; i++){
 for(int j = 0; j < 52; j++){
   if(maze1[i][j] == '#'){
   printf(KRED"#");
   }
   else{
   printf(KWHT"%c",maze1[i][j]);
   }
   }
 
 }



  return 0;
}

