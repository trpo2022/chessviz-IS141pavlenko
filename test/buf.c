#include "ctest.h"
#define n 2
CTEST(suite1, test_find_position)
{
	char tmp[n];
	int pos[2];
	
	tmp[0] = 'e';
	tmp[1] = '2';
	
	int stolb = tmp[0] - '0' - 48;
    int stroka = tmp[1] - '0';
    stroka = 8 - stroka;

    pos[0] = stroka;
    pos[1] = stolb;

	const int result_stolb = pos[0];
	const int result_stroka = pos[1];
	
    const int expected_stolb = 5;
    const int expected_stroka = 6;
    
    ASSERT_EQUAL(expected_stolb, result_stolb);
    ASSERT_EQUAL(expected_stroka, result_stroka);
}
