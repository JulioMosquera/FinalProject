#include <stdio.h>
#include "player.h"

Player initPlayer(int loc[2], int ml, int s, int sm)
{
    Player newPlayer;
    newPlayer.location[0] = loc[0]; // Initializes player to the given location x = 1
    newPlayer.location[1] = loc[1]; // y = 1
    newPlayer.movesLeft = ml; // Moves left set to 200
    newPlayer.score = 0; //Score set to 0 along with the rest given default values
    newPlayer.scoreMultipler = 1;
    newPlayer.timeSpent = 0;
    return newPlayer;
}

Player moverplayer(Player p, int loc[2]) // moves player to new location
{
  p.location[0] = loc[0];  // Player X set to new X value
  p.location[1] = loc[1]; //  Player Yset to new Y value
  return p;
}

Player updateScore(Player p, int s)
{
  int tempscore = s * p.scoreMultipler; // Multiplies the new score recieved by the multipliers
  p.score = p.score + tempscore;        // obtained in game and adds it to the previous sum
  return p;
}

Player addMultipler(Player p)
{
  p.scoreMultipler += 1; // Increases the score multiplier by 1
  return p;
}

int gameOver(Player p)  
{
  if(p.movesLeft < 0)   // When the remaining moves becomes less than 0
  {
    int restart[2] = {1,1};
    initPlayer(restart ,200, 0, 1);  // Resets player location and moves and sets it up for the next map
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
  if(newPlayer.location[1] == 25 && newPlayer.location[0] == 49) // When the player's location reaches the end of the map
  {
    return 0;  //return false
  }
  else
  {
    return 1; //return true
  }
  
}

Player CheckNextCharX(char curMaze[27][52], char origMaze[27][52], int i, Player p)
{
  Player newPlayer = p;
  int x = newPlayer.location[0];
  int y = newPlayer.location[1];
  if( i == 1)  // If the input is in the positive X direction (True)
  {
    if(curMaze[y][x + 1] != '#') // // Checks what the next character on the board is, in this case a wall
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
        newPlayer = updateScore(newPlayer, 10); // Do the following to influence the game
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

  if( i == 0)  // If the input is in the negative X direction (False)
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
  if( i == 1)   // If input is in the positive Y direction
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
  if( i == 0)   // If input is in the negative Y direction
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