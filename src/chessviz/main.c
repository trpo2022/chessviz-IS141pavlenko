#include <stdio.h>
#include <stdlib.h>
#include "chess.h"
#define n 9
#define str 18


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
 
    int *early_pos = malloc(sizeof(int)*str);
    int *last_pos = malloc(sizeof(int)*str);
 
    int fl=0;
    printf("------------------\n");
    while (fl != 1)
      {
        fl = move(early_pos, last_pos, fl ,board);     
 				if (fl != -1)
 				{
		      for(int i=0; i<n; i++)
		        {
				    for(int j=0;j<n; j++)
				      {
				        printf("%c ",board[i][j]);
				            
				      }
				    printf("\n");
		        }
		      printf("------------------\n");
        }
      }
      
    return 0;
}
