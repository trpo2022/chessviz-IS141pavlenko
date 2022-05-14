#include <libchessviz/chess.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctest.h>

CTEST(chess_suite, test_check_mate)
{
	char tmp[] = {'#'};

	int res; 
	res = check_mate(tmp);		
    const int exp = 1;

    ASSERT_EQUAL(exp, res);
}
