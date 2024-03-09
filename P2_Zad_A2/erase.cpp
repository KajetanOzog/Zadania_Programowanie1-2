//Kajetan Ozog
#include "bitwise_operations.h"

void Erase(char* chain, int* number)
{
    int x = 0;
    Emplace(chain, &x);
    *number = (*number & ~x);
}
