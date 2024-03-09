//Kajetan Ozog
#include "bitwise_operations.h"

int counter(int n, int num, int p)
{
    if(n == -1)
    {
        return p;
    }
    else
    {
        int x = ((num) & (1 << n));
        if(x != 0)
        {
            p++;
        }
        n--;
        counter(n,num,p);
    }
}

int Cardinality(int number)
{
    return counter(31, number, 0);
}