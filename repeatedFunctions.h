#include "player.h"


void ChooseNewMap(char * newMaze);
void PrintCurMap(char curMaze[27][52]);
void PrintScoreboard(int score, int multiplier, int moves, int locX, int locY, int timeSpent); //Print scoreboard with info of current game
void PrintMainScreen(); //Print main title screen at the start of the game
void PrintMaze(char curMaze[27][52], char input);
void PrintGameOver(); //Print GAME OVER in ASCII art when player runs out of moves
void PrintWin(); //Print YOU WIN in ASCII art when player reaches end
void PrintInfoScreen();