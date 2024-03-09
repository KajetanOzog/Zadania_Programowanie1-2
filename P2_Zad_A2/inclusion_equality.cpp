//Kajetan Ozog
#include "bitwise_operations.h"

bool Inclusion(int x, int y)
{
    int n = x | y;
    return n == y;
}

bool Equality(int x, int y)
{
    return x == y;
}