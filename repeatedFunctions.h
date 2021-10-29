#include "player.h"


void ChooseNewMap(char * newMaze);
void PrintCurMap(char curMaze[27][52]);
void PrintScoreboard(int score, int multiplier, int moves, int locX, int locY, int timeSpent); //Print scoreboard with current game info
void PrintMainScreen(); //Print main screen at the start of the game
void PrintMaze(char curMaze[27][52], char input);
void PrintGameOver(); //Print GAME OVER screen when player runs out of moves
void PrintWin(); //Print YOU WIN screen when player reaches the end
void PrintInfoScreen();