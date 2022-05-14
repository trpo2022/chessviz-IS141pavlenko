#include <libchessviz/chess.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctest.h>
#define N 2

CTEST(chess_suite, test_check_mate) 
{
    char tmp[] = {'#'};
    int res; 
    res = check_mate(tmp);		
    const int exp = 1;
    ASSERT_EQUAL(exp, res);
}

CTEST(chess_suite, test_check_mate2) 
{
    char tmp[] = {'e'};
    int res; 
    res = check_mate(tmp);		
    const int exp = 0;
    ASSERT_EQUAL(exp, res);
}

CTEST(chess_suite, test_move) 
{
    char tmp[] = {'e', '2', '-', 'e', '4'};
    int pos[N];
    find_pos(tmp, pos);
    int res = pos[0];
    int exp = 6;
    ASSERT_EQUAL(exp, res);
    exp = 5;
    res = pos[1];
    ASSERT_EQUAL(exp, res);
}
