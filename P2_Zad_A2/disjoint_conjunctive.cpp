//Kajetan Ozog
#include "bitwise_operations.h"

bool Disjoint(int num1, int num2)
{
    int x = num1 && num2;
    return x == 0;
}

bool Conjunctive(int num1, int num2)
{

    int x = num1 && num2;
    return x != 0;
}