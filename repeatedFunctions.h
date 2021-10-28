#include "player.h"


void ChooseNewMap(char * newMaze);
void PrintCurMap(char curMaze[27][52]);
void PrintScoreboard(int score, int multiplier, int moves, int locX, int locY, int timeSpent);
void PrintMainScreen();
void PrintMaze(char curMaze[27][52], char input);
void PrintGameOver();
void PrintWin();