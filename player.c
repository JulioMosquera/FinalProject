#include <stdio.h>

#include "player.h"

Player initPlayer(int loc[2], int ml, int s, int sm)
{
    Player newPlayer;

    newPlayer.location[0] = loc[0];
    newPlayer.location[1] = loc[1];
    newPlayer.movesLeft = ml;
    newPlayer.score = 0;
    newPlayer.scoreMultipler = 1;
    return newPlayer;
}

Player moverplayer(Player p, int loc[2])
{
  p.location[0] = loc[0];
  p.location[1] = loc[1];
  return p;
}

Player updateScore(Player p, int s)
{
  int tempscore = s * p.scoreMultipler;
  p.score = p.score + tempscore;
  return p;
}

Player addMultipler(Player p)
{
  p.scoreMultipler += 1;
  return p;
}
