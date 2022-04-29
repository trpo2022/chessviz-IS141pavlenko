#include <libchessviz/chess.h>
#include <stdio.h>

int check_mate(char* tmp)
{
    for (int i = 0; i < str; i++) {
        if (tmp[i] == '#')
            return 1;
    }
    return 0;
}
