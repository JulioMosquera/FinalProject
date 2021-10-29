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


//Print scoreboard with info of current game
void PrintScoreboard(int score, int multiplier, int moves, int locX, int locY, int timeSpent) {
  printf(" ------------------------------------------------------\n");
  printf("|                    SCOREBOARD                         |\n");
  printf("|-------------------------------------------------------|\n");
  printf("| Score      |  \t%i\t     |  Location X   |   \t%i\t|\n", score, locX);
  printf("|-------------------------------------------------------|\n");
  printf("| Multiplier |  \t%i\t     |  Location Y   |   \t%i\t|\n", multiplier, locY);
  printf("|-------------------------------------------------------|\n");
  printf("| Moves Left |  \t%i\t     |  Time(s)      |    \t%is\t|\n", moves,timeSpent);
  printf(" -------------------------------------------------------\n");
}
//Print the selected maze
void PrintMaze(char curMaze[27][52], char input)
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
        printf(KBLU"%c",curMaze[i][j]);
      }
      else if(curMaze[i][j] == ' ')
      {
        printf(KWHT"~");
      }
      else if(curMaze[i][j] == 'X')
      {
        printf(KGRN"%c",curMaze[i][j]);
      }
      else if(curMaze[i][j] == '.' || curMaze[i][j] == '*')
      {
        printf(KCYN"%c",curMaze[i][j]);
      }
      else if(curMaze[i][j] == '!')
      {
        printf(KYEL"%c",curMaze[i][j]);
      }
      else if(curMaze[i][j] == '+')
      {
        printf(KGRN"%c",curMaze[i][j]);
      }
      else if(curMaze[i][j] == '-')
      {
        printf(KRED"%c",curMaze[i][j]);
      }
      else if(curMaze[i][j] == '$')
      {
        printf(KMAG"%c",curMaze[i][j]);
      }
      else
      {
        printf(KWHT"%c",curMaze[i][j]);
      }
      }
    }
      printf("\nYou typed: %c\n", input);
      printf("Use W/A/S/D to move, Q to Quit\n");

}
//Print main title screen at the start of the game
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

//Print GAME OVER in ASCII art when player runs out of moves
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
//Print YOU WIN in ASCII art when player reaches end
void PrintWin()
{
  printf("  ___    ___ ________  ___  ___     \n");
  printf(" |\\  \\  /  /|\\   __  \\|\\  \\|\\  \\    \n");
  printf(" \\ \\  \\/  / | \\  \\|\\  \\ \\  \\\\\\  \\   \n");
  printf("  \\ \\    / / \\ \\  \\\\\\  \\ \\  \\\\\\  \\  \n");
  printf("   \\/  /  /   \\ \\  \\\\\\  \\ \\  \\\\\\  \\ \n");
  printf(" __/  / /      \\ \\_______\\ \\_______\\\n");
  printf("|\\___/ /        \\|_______|\\|_______|\n");
  printf("\\|___|/\n");
  printf("\n\n");
  printf(" ___       __   ___  ________       \n");
  printf("|\\  \\     |\\  \\|\\  \\|\\   ___  \\     \n");
  printf("\\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\    \n");
  printf(" \\ \\  \\  __\\ \\  \\ \\  \\ \\  \\\\ \\  \\   \n");
  printf("  \\ \\  \\|\\__\\_\\  \\ \\  \\ \\  \\\\ \\  \\  \n");
  printf("   \\ \\____________\\ \\__\\ \\__\\\\ \\__\\ \n");
  printf("    \\|____________|\\|__|\\|__| \\|__| \n");
  printf("\t Press 'E' to play a new maze!\n");
}
//Print info telling the player the rules of the game
void PrintInfoScreen()
{
  printf("\t\tWelcome to Minotaur\n");
  printf("This is a game where you(&) have to escape a labyrinth \n");
  printf("that has a Minotaur trapped inside.\n");
  printf("You only have 200 moves to escape the labyrinth.\n");
  printf("Use 'W/A/S/D' to move to the exit(X). \n");
  printf("Collect power ups './*/!/$/+/-' to get a  \nhigher score and adjust moves left.\n");
  printf("But be careful because once you pass over the traps the \n");
  printf("warnings will disappear, but the traps wont!\n");
  printf("\n\t\tPress 'E' to start\n");
}