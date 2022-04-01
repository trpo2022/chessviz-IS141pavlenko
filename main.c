#include <stdio.h>
#include <stdlib.h>
#define n 9
#define str 2

int find_pos(int *pos)
{
  char tmp[str];
  scanf("%s", tmp);
  int stolb = tmp[0]-'0'-48;
  int stroka = tmp[1]-'0';
  stroka = 8 - stroka;
  //printf("stolb:%d str:%d\n", stolb, stroka);
  pos[0] = stroka;
  pos[1] = stolb;

  return pos;
}

int move(early_pos, last_pos)
{
  
}

int main()
{
	char board[n][n]={{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
	                  {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
	                  {'6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	                  {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	                  {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	                  {'3', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	                  {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
	                  {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
	                  {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};
	
	for(int i=0; i<n; i++)
	{
		for(int j=0;j<n; j++)
		{
			printf("%c ",board[i][j]);
		        
		}
		printf("\n");
	}
        int *pos = malloc(sizeof(int)*str);
	find_pos(pos);
	printf("%c\n", board[pos[0]][pos[1]]);

	return 0;
}
