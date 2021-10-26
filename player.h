#ifdef FINALPROJECT_PLAYER_STRUCT
#define FINALPROJECT_PLAYER_STRUCT

typedef struct Player
{
  int location[2];
  int movesLeft;
  int score;
  int scoreMultipler;
}player;

player initPlayer(int l[2], int ml, int s, int sm);
player moverplayer(int l[2]);
player updateScore(int s);
player addMultipler(int sm);
