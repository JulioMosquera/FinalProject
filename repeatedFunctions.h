#include "player.h"

void CheckNextChar(char curMaze[27][52],char input, int l[2], Player p);
void ChooseNewMap(char * newMaze);
void PrintCurMap(char curMaze[27][52]);
void PrintScoreboard(int score, int multiplier, int moves, int locX, int locY);
void PrintMainScreen();
void PrintGameOver();