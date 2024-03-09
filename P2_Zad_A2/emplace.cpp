//Kajetan Ozog
#include "bitwise_operations.h"

void helper(char* chain, int n, int* number)
{
    if(*(chain + n) == '0' || *(chain + n) == '1')
    {
        int sum = 0;
        if(*(chain + n) == '1')
        {
            sum = sum + 16;
        }
        if(*(chain + n + 1) == '1')
        {
            sum = sum + 8;
        }
        if(*(chain + n + 2) == '1')
        {
            sum = sum + 4;
        }
        if(*(chain + n + 3) == '1')
        {
            sum = sum + 2;
        }
        if(*(chain + n + 4) == '1')
        {
            sum = sum + 1;
        }
        sum;
        *number |= (1 << sum);
        helper(chain, n + 5, number);
    }
    else if (*(chain + n) == '\0')
    {
        return;
    }
    else
    {
        helper(chain, n + 1, number);
    }
}
void Emplace(char* chain, int* number)
{
    *number = 0;
    helper(chain, 0, number);
}