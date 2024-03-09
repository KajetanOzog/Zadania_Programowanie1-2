//Kajetan Ozog
#include <string>
#include <cstdarg>
using namespace std;

void naTab(int n, int ile, string tab[], va_list ap)
{
    if (n < ile)
    {
        tab[n] = va_arg(ap, char*);
        naTab(n+1, ile, tab, ap);
    }
    else
    {
        return;
    }
}

string Operation(string (*operation)(int, const string*), int ile, const string* napis) //1
{
    return operation(ile, napis);
}

string Operation(string (*operation)(int, const string*), int ile, ...) //2
{
    string* tab = new string[ile];
    va_list ap;
    va_start(ap, ile);
    naTab(0, ile, tab, ap);
    va_end(ap);
    string wynik = operation(ile, tab);
    delete [] tab;
    return wynik;
}

void Operation(string* wynik, string (*operation)(int, const string*), int ile, const string* napis) //4
{
    *wynik = operation(ile, napis);
}

void Operation(string* wynik, string (*operation)(int, const string*), int ile, ...) //3
{
    string* tab = new string[ile];
    va_list ap;
    va_start(ap, ile);
    naTab(0,ile,tab,ap);
    va_end(ap);
    *wynik = operation(ile, tab);
    delete [] tab;
}

void Operation(string& wynik, void (*operation)(string*, int, const string*), int ile, const string* napis) //5
{
    operation(&wynik, ile, napis);
}

void Operation(string& wynik, void (*operation)(string*, int, const string*), int ile, ...) //6
{
    string* tab = new string[ile];
    va_list ap;
    va_start(ap, ile);
    naTab(0,ile,tab,ap);
    va_end(ap);
    operation(&wynik, ile, tab);
    delete [] tab;
}



