#include <stdio.h>

#include "player.h"

// Initializes player to the given location x = 1, y = 1;
// Score / Multiplier and timespent set to default values;

Player initPlayer(int loc[2], int ml, int s, int sm)
{
    Player newPlayer;

    newPlayer.location[0] = loc[0];
    newPlayer.location[1] = loc[1];
    newPlayer.movesLeft = ml;
    newPlayer.score = 0;
    newPlayer.scoreMultipler = 1;
    newPlayer.timeSpent = 0;
    return newPlayer;
}

// moves player to new location

Player moverplayer(Player p, int loc[2])
{
  p.location[0] = loc[0];
  p.location[1] = loc[1];
  return p;
}

// Multiplies the new score recieved by the multipliers
// obtained in game and adds it to the previous sum

Player updateScore(Player p, int s)
{
  int tempscore = s * p.scoreMultipler;
  p.score = p.score + tempscore;
  return p;
}

// Increases the score multiplier by 1

Player addMultipler(Player p)
{
  p.scoreMultipler += 1;
  return p;
}

// When the remaining moves becomes less than 0
// Displays the game over screen
// Resets player location and moves and sets it up for the next map

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

// When the player's location reaches the X which is located at the end of the map
// if you reach the end, return false
// else return true

int youWon(Player p)
{
  Player newPlayer = p;
  if(newPlayer.location[1] == 25 && newPlayer.location[0] == 49)
  {
    return 0;
  }
  else
  {
    return 1;
  }
  
}

// If the input is in the positive X direction
// // Checks what the next character on the board is
// If the next space the player is moving to is 
// # * ! $ + -
// Do the following to influence the game

// True was used to progress X or Y in the positive direction
// Whereas false was used to progress in the negative direction

Player CheckNextCharX(char curMaze[27][52], char origMaze[27][52], int i, Player p)
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
      if(origMaze[y][x] == '.')
      {
        newPlayer = updateScore(newPlayer, 5);
      }
      else if(origMaze[y][x] == '*')
      {
        newPlayer = updateScore(newPlayer, 10);
      }
      else if(origMaze[y][x] == '!')
      {
        newPlayer = updateScore(newPlayer, 15);
      }
      else if(origMaze[y][x] == '$')
      {
        newPlayer = addMultipler(newPlayer);
      }
      else if(origMaze[y][x] == '+')
      {
        newPlayer.movesLeft += 10;
      }
      else if(origMaze[y][x] == '-')
      {
        newPlayer.movesLeft -= 10;
      }
    }
  }
  // If the input is in the negative X direction
  // Same as above is applied
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
    if(origMaze[y][x] == '.')
      {
        newPlayer = updateScore(newPlayer, 5);
      }
      else if(origMaze[y][x] == '*')
      {
        newPlayer = updateScore(newPlayer, 10);
      }
      else if(origMaze[y][x] == '!')
      {
        newPlayer = updateScore(newPlayer, 15);
      }
      else if(origMaze[y][x] == '$')
      {
        newPlayer = addMultipler(newPlayer);
      }
      else if(origMaze[y][x] == '+')
      {
        newPlayer.movesLeft += 10;
      }
      else if(origMaze[y][x] == '-')
      {
        newPlayer.movesLeft -= 10;
      }
    }
  return newPlayer;
}
Player CheckNextCharY(char curMaze[27][52], char origMaze[27][52], int i, Player p)
{
  Player newPlayer = p;
  int x = newPlayer.location[0];
  int y = newPlayer.location[1];
  // If input is in the positive Y direction
  if( i == 1)
  {
    if(curMaze[y + 1][x] != '#')
    {
      curMaze[y][x] = ' ';
      y++;
      newPlayer.location[1] = y;
      curMaze[y][x] = '&';
      newPlayer.movesLeft--;
      if(origMaze[y][x] == '.')
      {
        newPlayer = updateScore(newPlayer, 5);
      }
      else if(origMaze[y][x] == '*')
      {
        newPlayer = updateScore(newPlayer, 10);
      }
      else if(origMaze[y][x] == '!')
      {
        newPlayer = updateScore(newPlayer, 15);
      }
      else if(origMaze[y][x] == '$')
      {
        newPlayer = addMultipler(newPlayer);
      }
      else if(origMaze[y][x] == '+')
      {
        newPlayer.movesLeft += 10;
      }
      else if(origMaze[y][x] == '-')
      {
        newPlayer.movesLeft -= 10;
      }
    }
  }
  // If input is in the negative Y direction
  if( i == 0)
  {
    if(curMaze[y - 1][x] != '#')
    {
      curMaze[y][x] = ' ';
      y--;
      newPlayer.location[1] = y;
      curMaze[y][x] = '&';
      newPlayer.movesLeft--;
      if(origMaze[y][x] == '.')
      {
        newPlayer = updateScore(newPlayer, 5);
      }
      else if(origMaze[y][x] == '*')
      {
        newPlayer = updateScore(newPlayer, 10);
      }
      else if(origMaze[y][x] == '!')
      {
        newPlayer = updateScore(newPlayer, 15);
      }
      else if(origMaze[y][x] == '$')
      {
        newPlayer = addMultipler(newPlayer);
      }
      else if(origMaze[y][x] == '+')
      {
        newPlayer.movesLeft += 10;
      }
      else if(origMaze[y][x] == '-')
      {
        newPlayer.movesLeft -= 10;
      }
    }     
  }
    return newPlayer;
}