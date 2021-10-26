#include <stdio.h>
#include <string.h>
#include <termios.h>
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

int main(void){
  char input;
  int startingLoc[2] = {0,0};
  Player curPlayer;
  curPlayer = initPlayer( startingLoc, 100, 0, 1);
while(1){
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
  printf("\nYou typed: %c\n", input);
  printf("Use W/A/S/D to move, Q to Quit\n");

  input = getche();
  system("clear");
  if(input =='w'){
    printf("move up");
  }
  if(input =='a'){
    printf("move left");
  }
  if(input =='s'){
    printf("move down");
  }
  if(input =='d'){
    printf("move right");
  }

}

  return 0;
}

