//Kajetan Ozog
#include <string>
#include <cstdarg>

using namespace std;

void mNumZeros(string* a, int *number)
{
    if((*a)[*number] == '0')
    {
        (*number)++;
        mNumZeros(a, number);
    }
    else
    {
        return;
    }
}

void mReverse(string* a, int start, int end)
{
    if (start >= end) {
        return;
    }
    char temp = (*a)[start];
    (*a)[start] = (*a)[end];
    (*a)[end] = temp;
    mReverse(a, start + 1, end - 1);
}

void mDodajJaja(string *a, int ile)
{
    if(ile != 0)
    {
        (*a) += '0';
        ile--;
        mDodajJaja(a, ile);
    }
    return;
}

void mAdd(string*a, string* b, string* result, int carry, int nr)
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
    mAdd(a, b, result, carry, nr);
}

void mOneMult(int liczba, string* a, string* result, int nrA, int curry)
{
    if(nrA == (*a).length())
    {
        if(curry > 0)
        {
            char ccurry = curry + 48;
            (*result) += ccurry;
        }
        return;
    }
    int ile = (*a)[nrA] - 48;
    int iloraz = (ile * liczba) + curry;
    curry = iloraz / 10;
    int wpis = iloraz % 10;
    char wwpis = wpis + 48;
    (*result) += wwpis;
    nrA++;
    mOneMult(liczba,a,result,nrA,curry);
}


void mMult(string* a, string* b, string* result, int nrB)
{
    if(nrB == (*b).length())
    {
        return;
    }
    string pom;
    int liczba = (*b)[nrB] - 48;
    mOneMult(liczba, a, &pom, 0, 0);
    mDodajJaja(&pom, (*a).length() + (*b).length() - pom.length() - nrB);
    mReverse(&pom, 0 , pom.length()- 1);
    mDodajJaja(&pom, nrB);
    nrB++;
    string pom2;
    mReverse(&pom, 0 , pom.length()- 1);
    mReverse(result,0,(*result).length() -1);
    int ile = pom.length() - (*result).length();
    if(ile < 0)
    {
        ile = ile * -1;
        mDodajJaja(&pom, ile);
    }
    else
    {
        mDodajJaja(result, ile);
    }
    mAdd(&pom, result, &pom2, 0, 0);
    (*result) = pom2;
    mReverse(result,0,(*result).length() -1);
    mMult(a,b,result,nrB);
}

string mMnozenie(string x, string y)
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

    mNumZeros(&a, &num1);
    mNumZeros(&b, &num2);

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

    mReverse(&a, 0, a.length() - 1);
    mReverse(&b,0,b.length() - 1);

    string result;
    mMult(&a,&b,&result,0);

    int nn = 0;
    mNumZeros(&result, &nn);
    result.erase(0,nn);

    if(result.empty())
    {
        result = "0";
        return result;
    }

    if(signB != signA)
    {
        mReverse(&result,0,result.length() - 1);
        result += '-';
        mReverse(&result,0,result.length() - 1);
    }
    return result;
}

string Mult1(const string* napis, string wynik, int ile)
{
    if(ile < 0)
    {
        return wynik;
    }
    else
    {
        wynik = mMnozenie(wynik, *(napis + ile));
        ile--;
        return Mult1(napis, wynik, ile);
    }
}

string Mult2(va_list ap, string wynik, int ile)
{
    if(ile < 0)
    {
        return wynik;
    }
    else
    {
        wynik = mMnozenie(wynik, va_arg(ap, char*));
        ile--;
        return Mult2(ap, wynik, ile);
    }
}

string Mult(int ile, const string* napis) //1
{
    string wynik = "1";
    ile--;
    return Mult1(napis, wynik, ile);
}

string Mult(int ile, ...) //2
{
    va_list ap;
    va_start(ap, ile);
    ile--;
    string pom = "1";
    string wynik = Mult2(ap,pom, ile);
    va_end(ap);
    return wynik;
}

void Mult(string* wynik, int ile, const string* napis) //3
{
    string pom = "1";
    ile--;
    *wynik = Mult1(napis, pom, ile);
}

void Mult(string* wynik, int ile, ...) //4
{
    va_list ap;
    va_start(ap, ile);
    string pom = "1";
    ile--;
    *wynik = Mult2(ap,pom,ile);
    va_end(ap);
}
void Mult(string& wynik, int ile, const string* napis) //5
{
    string pom = "1";
    ile--;
    wynik = Mult1(napis,pom,ile);
}

void Mult(string& wynik, int ile, ...) //6
{
    va_list ap;
    va_start(ap, ile);
    string pom = "1";
    ile--;
    wynik = Mult2(ap,pom,ile);
    va_end(ap);
}
