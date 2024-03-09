//Kajetan Ozog
#include "bitwise_operations.h"

bool LessThen(int x, int y)
{
    int a = Cardinality(x);
    int b = Cardinality(y);
    if(a < b)
    {
        return true;
    }
    else if (a == b)
    {
        if( x < y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool LessEqual(int x, int y)
{
    int a = Cardinality(x);
    int b = Cardinality(y);
    if(a < b)
    {
        return true;
    }
    else if (a == b)
    {
        if(x <= y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool GreatEqual(int x, int y)
{
    int a = Cardinality(x);
    int b = Cardinality(y);
    if(a > b)
    {
        return true;
    }
    else if (a == b)
    {
        if(x >= y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool GreatThen(int x, int y)
{
    int a = Cardinality(x);
    int b = Cardinality(y);
    if(a > b)
    {
        return true;
    }
    else if (a == b)
    {
        if(x > y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
