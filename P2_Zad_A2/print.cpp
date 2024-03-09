//Kajetan Ozog
#include "bitwise_operations.h"

void helper2(int* number, int n, int p, char* chain)
{
    if(n == -1)
    {
        *(chain + p) = '\0';
        return;
    }
    else
    {
        int x = ((*number) & (1 << n));
        if(x != 0)
        {
            if(p == 0)
            {
                int n2 = n;
                int x5 = n2 % 2;
                n2 /= 2;
                int x4 = n2 % 2;
                n2 /= 2;
                int x3 = n2 % 2;
                n2 /= 2;
                int x2 = n2 % 2;
                n2 /= 2;
                int x1 = n2 % 2;
                *(chain + p) = x1 + 48;
                *(chain + p + 1) = x2 + 48;
                *(chain + p + 2) = x3 + 48;
                *(chain + p + 3) = x4 + 48;
                *(chain + p + 4) = x5 + 48;
                p += 5;
            }
            else
            {
                int n2 = n;
                int x5 = n2 % 2;
                n2 /= 2;
                int x4 = n2 % 2;
                n2 /= 2;
                int x3 = n2 % 2;
                n2 /= 2;
                int x2 = n2 % 2;
                n2 /= 2;
                int x1 = n2 % 2;
                *(chain + p) = ' ';
                *(chain + p + 1) = x1 + 48;
                *(chain + p + 2) = x2 + 48;
                *(chain + p + 3) = x3 + 48;
                *(chain + p + 4) = x4 + 48;
                *(chain + p + 5) = x5 + 48;
                p += 6;
            }

        }
        helper2(number, n-1, p, chain);
    }
}

void Print(int number, char* chain)
{
    if (number == 0)
    {
        *(chain + 0) = 'e';
        *(chain + 1) = 'm';
        *(chain + 2) = 'p';
        *(chain + 3) = 't';
        *(chain + 4) = 'y';
        *(chain + 5) = '\0';
    }
    else
    {
        helper2(&number, 31, 0, chain);
    }
}
