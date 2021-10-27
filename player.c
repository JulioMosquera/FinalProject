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

int gameOver(Player p)
{
  if(p.movesLeft < 0)
  {
    int restart[2] = {1,1};
    initPlayer(restart ,200, 0, 1);
    return 0;
  }
  else
  {
    return 1;
  }
}

int youWon(Player p)
{
  Player newPlayer = p;
  if(newPlayer.location[1] == 27 && newPlayer.location[0] == 57)
  {
    return 1;
  }
  else
  {
    return 0;
  }
  
}

Player CheckNextCharX(char curMaze[27][52], int i, Player p)
{
  Player newPlayer = p;
  int x = newPlayer.location[0];
  int y = newPlayer.location[1];
  if( i == 1)
  {
    if(curMaze[y][x + 1] != '#')
    {
      curMaze[y][x] = ' ';
      x++;
      newPlayer.location[0] = x;
      curMaze[y][x] = '&';
      newPlayer.movesLeft--;
      if(curMaze[y][x + 1] == '.')
      {
        newPlayer = updateScore(newPlayer, 5);
      }
      else if(curMaze[y][x + 1] == '*')
      {
        newPlayer = updateScore(newPlayer, 10);
      }
      else if(curMaze[y][x + 1] == '!')
      {
        newPlayer = updateScore(newPlayer, 15);
      }
      else if(curMaze[y][x + 1] == '$')
      {
        newPlayer = addMultipler(newPlayer);
      }
      else if(curMaze[y][x + 1] == '+')
      {
        newPlayer.movesLeft += 10;
      }
      else if(curMaze[y][x + 1] == '-')
      {
        newPlayer.movesLeft -= 10;
      }
      else if(curMaze[y][x + 1] == 'X')
      {
        youWon(newPlayer);
      }
  }
  if( i == 0)
  {
    if(curMaze[y][x - 1] != '#')
    {
      curMaze[y][x] = ' ';
      x--;
      newPlayer.location[0] = x;
      curMaze[y][x] = '&';
      newPlayer.movesLeft--;
    }
  }
  return newPlayer;
}
Player CheckNextCharY(char curMaze[27][52], int i, Player p)
{
  Player newPlayer = p;
  int x = newPlayer.location[0];
  int y = newPlayer.location[1];
  if( i == 1)
  {
    if(curMaze[y + 1][x] != '#')
    {
      curMaze[y][x] = ' ';
      y++;
      newPlayer.location[1] = y;
      curMaze[y][x] = '&';
      newPlayer.movesLeft--;
    }
  }
  if( i == 0)
  {
    if(curMaze[y - 1][x] != '#')
    {
      curMaze[y][x] = ' ';
      y--;
      newPlayer.location[1] = y;
      curMaze[y][x] = '&';
      newPlayer.movesLeft--;
    }
  }
  return newPlayer;
}