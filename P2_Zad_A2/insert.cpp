//Kajetan Ozog
#include "bitwise_operations.h"

void Insert(char* chain, int* number)
{
    int x = 0;
    Emplace(chain, &x);
    *number |= x;
}
