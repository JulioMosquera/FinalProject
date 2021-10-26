#ifdef FINALPROJECT_PLAYER_STRUCT
#define FINALPROJECT_PLAYER_STRUCT

typedef struct Player_Struct
{
  int location[2];
  int movesLeft;
  int score;
  int scoreMultipler;
}Player;

Player initPlayer(int l[2], int ml, int s, int sm);
Player moverplayer(Player p, int l[2]);
Player updateScore(Player p, int s);
Player addMultipler(Player p);
