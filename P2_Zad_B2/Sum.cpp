//Kajetan Ozog
#include <string>
#include <cstdarg>

using namespace std;

void sNumZeros(string* a, int *number)
{
    if((*a)[*number] == '0')
    {
        (*number)++;
        sNumZeros(a, number);
    }
    else
    {
        return;
    }
}

int sSame(string* a, string*b, int* n)
{
    if(*n == (*a).length())
    {
        return 0;
    }
    if((*a)[*n] > (*b)[*n])
    {
        return 1;
    }
    if((*a)[*n] < (*b)[*n])
    {
        return -1;
    }
    (*n)++;
    return sSame(a, b, n);
}

int sCompare(string* a, string* b)
{
    if((*a).length() >  (*b).length())
    {
        return 1;
    }
    else if( (*a).length() <  (*b).length())
    {
        return -1;
    }
    else
    {
        int c;
        int n = 0;
        c = sSame(a, b, &n);
        return c;
    }
}

void sReverse(string* a, int start, int end)
{
    if (start >= end) {
        return;
    }
    char temp = (*a)[start];
    (*a)[start] = (*a)[end];
    (*a)[end] = temp;
    sReverse(a, start + 1, end - 1);
}

void sAdd(string*a, string* b, string* result, int carry, int nr)
{
    if(nr == (*a).length())
    {
        if(carry == 0)
        {
            return;
        }
        else
        {
            (*result) += '1';
            return;
        }
    }
    int sum;
    int one = (int)(*a)[nr] - 48;
    int two = (int)(*b)[nr] - 48;
    sum = one + two + carry;
    carry = sum / 10;
    char added = (sum % 10) + 48;
    (*result) += added;
    nr++;
    sAdd(a, b, result, carry, nr);
}

void sSub(string*a, string* b, string* result, int nr)
{
    int one = (int)(*a)[nr] - 48;
    int two = (int)(*b)[nr] - 48;
    int sum;
    if(nr == (*a).length())
    {
        return;
    }
    if(one < two)
    {
        sum = 10 + one - two + 48;
        char added = sum;
        (*result) += added;
        int prev = (int)(*a)[nr + 1] - 48;
        prev--;
        char pprev = prev + 48;
        (*a)[nr+1] = pprev;
    }
    else
    {
        sum = one - two + 48;
        char added = sum;
        (*result) += added;
    }
    nr++;
    sSub(a, b, result, nr);
}

void sDodajJaja(string *a, int ile)
{
    if(ile != 0)
    {
        (*a) += '0';
        ile--;
        sDodajJaja(a, ile);
    }
    return;
}
string sDodanie(string x, string y)
{
    string a = x;
    string b = y;
    int signA = 1;
    int signB = 1;

    if(a[0] == '-')
    {
        signA = -1;
        a.erase(0,1);
    }
    else if(a[0] == '+')
    {
        a.erase(0,1);
    }
    if(b[0] == '-')
    {
        signB = -1;
        b.erase(0,1);
    }
    else if(b[0] == '+')
    {
        b.erase(0,1);
    }

    int num1 = 0;
    int num2 = 0;

    sNumZeros(&a, &num1);
    sNumZeros(&b, &num2);
    a.erase(0,num1);
    b.erase(0,num2);
    if(a.empty())
    {
        a = "0";
        signA = 1;
    }
    if(b.empty())
    {
        b = "0";
        signB = 1;
    }
    string result;
    if(signA == signB)
    {
        if(a.length() == b.length())
        {
            sReverse(&a, 0, a.length() - 1);
            sReverse(&b, 0, b.length() - 1);
            sAdd(&a, &b, &result, 0, 0);
            sReverse(&result, 0, result.length() - 1);
        }
        else if (a.length() > b.length())
        {
            sReverse(&a, 0, a.length() - 1);
            sReverse(&b, 0, b.length() - 1);
            int ile = a.length() - b.length();
            sDodajJaja(&b, ile);
            sAdd(&a, &b, &result, 0, 0);
            sReverse(&result, 0, result.length() - 1);
        }
        else
        {
            sReverse(&a, 0, a.length() - 1);
            sReverse(&b, 0, b.length() - 1);
            int ile = b.length() - a.length();
            sDodajJaja(&a, ile);
            sAdd(&a, &b, &result, 0, 0);
            sReverse(&result, 0, result.length() - 1);
        }
        if(signA == -1)
        {
            sReverse(&result, 0, result.length() - 1);
            result += '-';
            sReverse(&result, 0, result.length() - 1);
        }
    }
    else
    {
        int cmp = sCompare(&a, &b);
        if(cmp == 0)
        {
            result = "0";
        }
        else if(cmp == 1)
        {
            if(a.length() == b.length())
            {
                sReverse(&a, 0, a.length() - 1);
                sReverse(&b, 0, b.length() - 1);
                sSub(&a, &b, &result, 0);
                sReverse(&result, 0, result.length() - 1);
                int nn = 0;
                sNumZeros(&result, &nn);
                result.erase(0,nn);
            }
            else if (a.length() > b.length())
            {
                sReverse(&a, 0, a.length() - 1);
                sReverse(&b, 0, b.length() - 1);
                int ile = a.length() - b.length();
                sDodajJaja(&b, ile);
                sSub(&a, &b, &result, 0);
                sReverse(&result, 0, result.length() - 1);
                int nn = 0;
                sNumZeros(&result, &nn);
                result.erase(0,nn);
            }
            else
            {
                sReverse(&a, 0, a.length() - 1);
                sReverse(&b, 0, b.length() - 1);
                int ile = b.length() - a.length();
                sDodajJaja(&a, ile);
                sSub(&a, &b, &result, 0);
                sReverse(&result, 0, result.length() - 1);
            }
            if(signA == -1)
            {
                int nn = 0;
                sNumZeros(&result, &nn);
                result.erase(0,nn);
                sReverse(&result, 0, result.length() - 1);
                result += '-';
                sReverse(&result, 0, result.length() - 1);
            }
        }
        else
        {
            if(a.length() == b.length())
            {
                sReverse(&a, 0, a.length() - 1);
                sReverse(&b, 0, b.length() - 1);
                sSub(&b, &a, &result, 0);
                sReverse(&result, 0, result.length() - 1);
            }
            else if (a.length() > b.length())
            {
                sReverse(&a, 0, a.length() - 1);
                sReverse(&b, 0, b.length() - 1);
                int ile = a.length() - b.length();
                sDodajJaja(&b, ile);
                sSub(&b, &a, &result, 0);
                sReverse(&result, 0, result.length() - 1);
            }
            else
            {
                sReverse(&a, 0, a.length() - 1);
                sReverse(&b, 0, b.length() - 1);
                int ile = b.length() - a.length();
                sDodajJaja(&a, ile);
                sSub(&b, &a, &result, 0);
                sReverse(&result, 0, result.length() - 1);
            }
            int nn = 0;
            sNumZeros(&result, &nn);
            result.erase(0,nn);
            if(signB == -1)
            {
                sReverse(&result, 0, result.length() - 1);
                result += '-';
                sReverse(&result, 0, result.length() - 1);
            }
        }
    }
    return result;
}

string Sum1(string wynik, const string* napis, int ile)
{
    if(ile < 0)
    {
        return wynik;
    }
    wynik = sDodanie(wynik, *(napis + ile));
    ile--;
    return Sum1(wynik, napis, ile);
}

string Sum2(va_list ap,  string wynik, int ile)
{
    if(ile < 0)
    {
        return wynik;
    }
    else
    {
        wynik = sDodanie(wynik, va_arg(ap, char*));
        return Sum2(ap, wynik, ile - 1);
    }
}

string Summer(const string* napis, int n, int N)
{
    if (n < N) {
        return sDodanie(*(napis + n), Summer(napis, n+1, N));
    }
    else {
        return "0";
    }
}

string Sum(int ile, const string* napis) //1
{
    return Summer(napis, 0, ile);
}

string Sum(int ile, ...) //2
{
    va_list ap;
    va_start(ap, ile);
    ile--;
    string pom = "0";
    string wynik = Sum2(ap, pom, ile);
    va_end(ap);
    return wynik;
}

void Sum(string* wynik, int ile, const string* napis) //3
{
    string pom = "0";
    ile--;
    (*wynik) = Sum1(pom, napis, ile);
}

void Sum(string* wynik, int ile, ...) //4
{
    va_list ap;
    va_start(ap, ile);
    string pom = "0";
    ile--;
    *wynik = Sum2(ap, pom, ile);
    va_end(ap);
}

void Sum(string& wynik, int ile, const string* napis) //5
{
    ile--;
    string pom = "0";
    wynik = Sum1(pom, napis, ile);
}

void Sum(string& wynik, int ile, ...) //6
{
    va_list ap;
    va_start(ap, ile);
    ile--;
    string pom = "0";
    wynik = Sum2(ap, pom, ile);
    va_end(ap);
}

