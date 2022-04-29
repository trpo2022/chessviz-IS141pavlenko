#include <libchessviz/chess.h>
#include <stdio.h>

int* find_pos(char* tmp, int* pos)
{
    int stolb = tmp[0] - '0' - 48;
    int stroka = tmp[1] - '0';
    stroka = 8 - stroka;

    pos[0] = stroka;
    pos[1] = stolb;

    return pos;
}
