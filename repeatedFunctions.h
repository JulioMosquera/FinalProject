#include "player.h"

void PrintScoreboard(int score, int multiplier, int moves, int locX, int locY, int timeSpent); //Print scoreboard with info of current game
void PrintMainScreen(); //Print main title screen at the start of the game
void PrintMaze(char curMaze[27][52], char input);//Print the selected maze
void PrintGameOver(); //Print GAME OVER in ASCII art when player runs out of moves
void PrintWin(); //Print YOU WIN in ASCII art when player reaches end
void PrintInfoScreen(); //Print info telling the player the rules of the game