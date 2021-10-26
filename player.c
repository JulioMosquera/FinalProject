#include <stdio.h>

#include "player.h"

Player initPlayer(int l[2], int ml, int s, int sm)
{
    Player newPlayer;

    newPlayer.location = l;
    newPlayer.movesLeft = ml;
    newPlayer.score = 0;
    newPlayer.scoreMultipler = 1;
    return newPlayer;
}

Player moverplayer(Player p, int l[2])
{
  p.location = l;
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
