#pragma once
#define n 9
#define str 18

int *find_pos(char *tmp, int *pos);
int check_mate(char *tmp);
int move(int *early_pos, int *last_pos,int fl , char board[n][n]);
