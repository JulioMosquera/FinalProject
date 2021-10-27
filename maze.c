#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <time.h>

#include "repeatedFunctions.h"
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


static struct termios old, current;
void initTermios(int echo)
{
 tcgetattr(0, &old);
 current = old;
 current.c_lflag &= ~ICANON;
 if (echo) {
     current.c_lflag |= ECHO;
 } else {
     current.c_lflag &= ~ECHO;
 }
 tcsetattr(0, TCSANOW, &current);
}
void resetTermios(void)
{
 tcsetattr(0, TCSANOW, &old);
}
char getch_(int echo)
{
 char ch;
 initTermios(echo);
 ch = getchar();
 resetTermios();
 return ch;
}
char getch(void)
{
 return getch_(0);
}

char getche(void)
{
 return getch_(1);
}


int main(void)
{
  char input = ' ';
  char start = ' ';
  int currLoc[2] = {1,1};
  int x,y, xNext, yNext;
  x = currLoc[0];
  y = currLoc[1];
  Player curPlayer;
  curPlayer = initPlayer( currLoc, 200, 0, 1);
  srand(1);
  int randMaze = rand() %5;
  char currMaze[27][52];
  for(int i = 0; i< 27; i++)
  {
    for(int j = 0; j < 52; j++)
    {
      currMaze[i][j] = mazes[randMaze][i][j];
    }
  }

  PrintMainScreen();
  while(start != 'e')
  {
    start = getche();
  }
  
  


  while(1)
  {    
    printf("\033[H\033[J");
    PrintScoreboard(curPlayer.score, curPlayer.scoreMultipler, curPlayer.movesLeft, curPlayer.location[0], curPlayer.location[1]);
    for(int i = 0; i < 27; i++)
    {
      for(int j = 0; j < 52; j++)
      {
      if(currMaze[i][j] == '#')
      {
        printf(KRED"#");
      }
      else if(currMaze[i][j] == '&') 
      {
        printf(KGRN"%c",currMaze[i][j]);
      }
      else if(currMaze[i][j] == ' ')
      {
        printf(KBLU"~");
      }
      else if(currMaze[i][j] == 'X')
      {
        printf(KGRN"%c",currMaze[i][j]);
      }
      else
      {
        printf(KWHT"%c",currMaze[i][j]);
      }
      }
    }
      printf("\nYou typed: %c\n", input);
      printf("Use W/A/S/D to move, Q to Quit\n");

      input = getche();
      
  if(input =='w')
  {
    yNext = 0;
    curPlayer = CheckNextCharY(currMaze, mazes[randMaze], yNext, curPlayer);
    printf("move up\n");
  }
  if(input =='a')
  {
    xNext = 0;
    curPlayer = CheckNextCharX(currMaze, mazes[randMaze], xNext, curPlayer);

    printf("move left\n");
  }
  if(input =='s')
  {
    yNext = 1;
    curPlayer = CheckNextCharY(currMaze, mazes[randMaze], yNext, curPlayer);
    printf("move down\n");
  }
  if(input =='d')
  {
    xNext = 1;
    curPlayer = CheckNextCharX(currMaze, mazes[randMaze], xNext, curPlayer);
    printf("move right\n");
  }
    
    if(gameOver(curPlayer) == 0)
    {
      printf("\033[H\033[J");  
      PrintGameOver();
      while(input != 'r')
      {
        input = getche();
      }
      curPlayer = initPlayer( currLoc, 200, 0, 1);
    }
    if(youWon(curPlayer) == 0)
    {
      printf("\033[H\033[J");  
      PrintWin();
      while( input != 'e')
      {
        input = getche();
      }
        if(input == 'e')
      {
        randMaze = rand() %5;
        for(int i = 0; i< 27; i++)
        {
          for(int j = 0; j < 52; j++)
          {
            currMaze[i][j] = mazes[randMaze][i][j];
          }
        }
      }
      curPlayer = initPlayer( currLoc, 200, 0, 1);
    
    }
    if(input == 'r' || input == 'q')
    {
      currMaze[1][1] = '&';
      currMaze[y][x] = ' ';
      x = 1;
      y = 1;
      curPlayer.location[0] = x;
      curPlayer.location[1] = y;
      curPlayer.movesLeft = 200;
      printf("\033[H\033[J");  
      PrintMainScreen();
      while(input != 'e')
      {
        input = getche();
      }
      PrintScoreboard(curPlayer.score, curPlayer.scoreMultipler, curPlayer.movesLeft, curPlayer.location[0], curPlayer.location[1]);
    
    }

  }
  return 0;
}

