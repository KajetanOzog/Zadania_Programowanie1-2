//Kajetan Ozog
#include "bitwise_operations.h"

void Union(int x, int y, int* z)
{
    *z = x | y;
}

void Intersection(int x, int y, int* z)
{
    *z = x & y;
}

void Symmetric(int x, int y, int* z)
{
    *z = x ^ y;
}

void Difference(int x, int y, int* z)
{
    int p = ~y;
    *z = x & p;
}

void Complement(int x, int* z)
{
    *z = ~x;
}