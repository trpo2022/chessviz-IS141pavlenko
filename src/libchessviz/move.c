#include <libchessviz/chess.h>
#include <stdio.h>

int check_motion(const int *early_pos, char board[n][n])
{
    if (board[early_pos[0]][earpy_pos[1]] == 'K') {
      if ((board[early_pos[0]-1][earpy_pos[1]-1) == ' ' || (board[early_pos[0]-1][earpy_pos[1]-1) == 'p' || (board[early_pos[0]-1][earpy_pos[1]-1) == 'r' || (board[early_pos[0]-1][earpy_pos[1]-1) == 'n' || (board[early_pos[0]-1][earpy_pos[1]-1) == 'b' || (board[early_pos[0]-1][earpy_pos[1]-1) == 'q') {
		    return 1;
      }
    }
}

int move(int* early_pos, int* last_pos, int fl, char board[n][n])
{
    char figure;
    char tmp[str];
    scanf("%s", tmp);

    if (tmp[0] == '1' || tmp[0] == '2' || tmp[0] == '3' || tmp[0] == '4'
        || tmp[0] == '5' || tmp[0] == '6' || tmp[0] == '7' || tmp[0] == '8'
        || tmp[0] == '9') {
        return -1;
    }
    for (int i = 0; i < str; i += 2) {
        char tmp_early[2];
        char tmp_last[2];

        if (tmp[i] == 'K' || tmp[i] == 'Q' || tmp[i] == 'B' || tmp[i] == 'R'
            || tmp[i] == 'N') {
            i++;
            if (tmp[i] != '-') {
                tmp_early[0] = tmp[i];
                tmp_early[1] = tmp[i + 1];
                find_pos(tmp_early, early_pos);

            } else if (tmp[i] == '-') {
                tmp_last[0] = tmp[i + 1];
                tmp_last[1] = tmp[i + 2];
                find_pos(tmp_last, last_pos);
                fl = check_mate(tmp);
                break;
            }
        } else {
            if (tmp[i] != '-') {
                tmp_early[0] = tmp[i];
                tmp_early[1] = tmp[i + 1];
                find_pos(tmp_early, early_pos);

            } else if (tmp[i] == '-') {
                tmp_last[0] = tmp[i + 1];
                tmp_last[1] = tmp[i + 2];
                find_pos(tmp_last, last_pos);
                fl = check_mate(tmp);
                break;
            }
        }
    }
    check_motion(early_pos, board);
    if (last_pos[0] != 8 && early_pos[0] != 8 && last_pos[1] != 0
        && early_pos[1] != 0) {
        board[last_pos[0]][last_pos[1]] = board[early_pos[0]][early_pos[1]];
        board[early_pos[0]][early_pos[1]] = ' ';
    } else {
        printf("Не корректный ход!\n");
        return -1;
    }
    return fl;
}

