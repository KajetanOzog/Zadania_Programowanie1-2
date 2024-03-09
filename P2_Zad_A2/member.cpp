//Kajetan Ozog
#include "bitwise_operations.h"

bool Member(char* chain, int number)
{
    int num = 0;
    Emplace(chain, &num);
    int x = num & number;
    return x != 0;
}
