#include <stdio.h>
#include <string.h>
#include "player.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

void CheckNextChar(char curMaze[27][52], char input, int l[2], Player curPlayer)
{
  int x = curPlayer.location[0];
  int y;
  y = curPlayer.location[0];

  if(input =='w')
    {
      if(curMaze[y - 1][x] != '#')
      {
        curMaze[y][x] = ' ';
        y--;
        curPlayer.location[1] = y;
        curMaze[y][x] = '&';
        curPlayer.movesLeft--;
  
      }
      printf("move up\n");
    }
    if(input =='a')
    {
      if(curMaze[y][x - 1] != '#')
      {
        curMaze[y][x] = ' ';
        x--;
        curPlayer.location[0] = x;
        curMaze[y][x] = '&';
        curPlayer.movesLeft--;
    
      }
      printf("move left\n");
    }
    if(input =='s')
    {
      if(curMaze[(y + 1)][x] != '#')
      {
        curMaze[y][x] = ' ';
        y++;
        curPlayer.location[1] = y;
        curMaze[y][x] = '&';
        curPlayer.movesLeft--;
      
      }
      printf("move down\n");
    }
    if(input =='d')
    {
      if(curMaze[y][x + 1] != '#')
      {
        curMaze[y][x] = ' ';
        x++;
        curPlayer.location[0] = x;
        curMaze[y][x] = '&';
        curPlayer.movesLeft--;
      
      }
      printf("move right\n");
    }
}
void ChooseNewMap(char * newMaze)
{
  
}
void PrintCurMap(char curMaze[27][52])
{
    for(int i = 0; i < 27; i++)
    {
      for(int j = 0; j < 52; j++)
      {
      if(curMaze[i][j] == '#')
      {
        printf(KRED"#");
      }
      else if(curMaze[i][j] == '&') 
      {
        printf(KGRN"%c",curMaze[i][j]);
      }
      else if(curMaze[i][j] == ' ')
      {
        printf(KBLU"~");
      }
      else if(curMaze[i][j] == 'X')
      {
        printf(KGRN"%c",curMaze[i][j]);
      }
      else
      {
        printf(KWHT"%c",curMaze[i][j]);
      }
      }
      }
}
void PrintScoreboard(int score, int multiplier, int moves, int locX, int locY) {
  printf(" ------------------------------------------------------\n");
  printf("|                    SCOREBOARD                         |\n");
  printf("|-------------------------------------------------------|\n");
  printf("| Score      |  \t%i\t     |  Location X   |   \t%i\t|\n", score, locX);
  printf("|-------------------------------------------------------|\n");
  printf("| Multiplier |  \t%i\t     |  Location Y   |   \t%i\t|\n", multiplier, locY);
  printf("|-------------------------------------------------------|\n");
  printf("| Moves Left |  \t%i\t     |                    \t    |\n", moves);
  printf(" -------------------------------------------------------\n");
}

void PrintMainScreen() {
  printf(" _____ ______   ___  ________   ________  _________  ________  ___  ___  ________     \n");
  printf("|\\   _ \\  _   \\|\\  \\|\\   ___  \\|\\   __  \\|\\___   ___\\\\   __  \\|\\  \\|\\  \\|\\   __  \\    \n");
  printf("\\ \\  \\\\\\__\\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\\\\\  \\ \\  \\|\\  \\   \n");
  printf(" \\ \\  \\\\|__| \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\\\\\  \\   \\ \\  \\ \\ \\   __  \\ \\  \\\\\\  \\ \\   _  _\\  \n");
  printf("  \\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\\\\\  \\   \\ \\  \\ \\ \\  \\ \\  \\ \\  \\\\\\  \\ \\  \\\\  \\| \n");
  printf("   \\ \\__\\    \\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\   \\ \\__\\ \\ \\__\\ \\__\\ \\_______\\ \\__\\\\ _\\ \n");
  printf("    \\|__|     \\|__|\\|__|\\|__| \\|__|\\|_______|    \\|__|  \\|__|\\|__|\\|_______|\\|__|\\|__|\n");
  printf("\t\t\t\t\t\t\t\t Press 'E' to begin!\n");
  printf("\t\t\t\t\t\t\t\t Press 'Q' at anytime to quit the game\n");

}


void PrintGameOver()
{
    printf(" ________  ________  _____ ______   _______ \n");
  printf("|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\\n");
  printf("\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/| \n");
  printf(" \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/_\n");
  printf("  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\\n");
  printf("   \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\\n");
  printf("    \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|\n");
  printf("\n");
  printf(" ________  ___      ___ _______   ________ \n");
  printf("|\\   __  \\|\\  \\    /  /|\\  ___ \\ |\\   __  \\\n");
  printf("\\ \\  \\|\\  \\ \\  \\  /  / | \\   __/|\\ \\  \\|\\  \\\n");
  printf(" \\ \\  \\\\  \\ \\  \\/  / / \\ \\  \\_|/_\\ \\   _  _\\ \n");
  printf("  \\ \\  \\\\  \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\  \\\n");
  printf("   \\ \\_______\\ \\__/ /     \\ \\_______\\ \\__\\\\ _\\\n");
  printf("    \\|_______|\\|__|/       \\|_______|\\|__|\\|__|\n");
  printf("\t\t\t\t\t Press 'R' to try again!\n");
}