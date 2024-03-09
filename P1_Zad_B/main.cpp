//Kajetan Ozog
#include <iostream>
using namespace std;
int main()
{
    int indeks = 0;
    int fragment = 0;
    int dlugosc = 0;
    int wartosc = 0;
    int d = 0;
    int ilosc_petli = 0;
    cin >> ilosc_petli;
    while (ilosc_petli-->0)
    {
        int rozm_tab = 0;
        cin >> rozm_tab;
        if (rozm_tab > 0)
        {
            int tab[rozm_tab];
            int i = 0;
            while(i<rozm_tab)
            {
                cin >> tab[i];
                i++;
            }
            i = 0;
            while(i< rozm_tab)
            {
                cout << tab[i] << " ";
                i++;
            }
            cout << endl;
            bool kontynuacja = true;
            while (kontynuacja)
            {
                char znak;
                cin >> znak;
                if (znak == 'F')
                {
                    kontynuacja = false;
                    i = 0;
                    while(i<rozm_tab)
                    {
                        cout << tab[i] << " ";
                        i++;
                    }
                    cout << endl;
                }
                else if (znak == 'R')
                {
                    cin >> indeks;
                    cin >> fragment;
                    if ((fragment > 0) && (fragment <= rozm_tab))
                    {
                        indeks = indeks % rozm_tab;
                        if (indeks < 0)
                        {
                            indeks = indeks + rozm_tab;
                        }
                        int ilosc_odwrocen = rozm_tab /  fragment;
                        int x;
                        d = 0;
                        while (ilosc_odwrocen-- > 0)
                        {
                            x = fragment / 2;
                            d = 0;
                            while (x-- >0)
                            {
                                int pom = tab[(indeks + d) % rozm_tab];
                                tab[(indeks + d) % rozm_tab] = tab[(indeks - d - 1 + fragment) % rozm_tab];
                                tab[(indeks - d - 1 + fragment) % rozm_tab] = pom;
                                d++;
                            }
                            indeks = (indeks + fragment) % rozm_tab;
                        }
                    }
                }
                else if (znak == 'M')
                {
                    cin >> indeks;
                    cin >> fragment;
                    cin >> wartosc;
                    if((fragment <= rozm_tab) && (fragment>0) && (wartosc != 0))
                    {
                        indeks = indeks % rozm_tab;
                        if (indeks < 0)
                        {
                            indeks = indeks + rozm_tab;
                        }
                        int ilosc_rund = rozm_tab / fragment;
                        int x = wartosc;
                        x = x % fragment;
                        if(x < 0)
                        {
                            x = x + fragment;
                        }
                        while(ilosc_rund > 0)
                        {

                            int rundka = fragment / 2;
                            d = 0;
                            while(rundka > 0)
                            {
                                int pom = tab[(indeks +d) % rozm_tab];
                                tab[(indeks +d) % rozm_tab] = tab[(indeks - d - 1 + fragment) % rozm_tab];
                                tab[(indeks - d - 1 + fragment) % rozm_tab] = pom;
                                d++;
                                rundka--;
                            }
                            rundka = x / 2;
                            d = 0;
                            while(rundka > 0)
                            {
                                int pom = tab[(indeks +d)%rozm_tab];
                                tab[(indeks +d)%rozm_tab] = tab[(indeks + x - 1 - d)%rozm_tab];
                                tab[(indeks + x - 1 -d)%rozm_tab] = pom;
                                d++;
                                rundka--;
                            }
                            rundka = (fragment - x) /2;
                            d = 0;
                            while(rundka > 0)
                            {
                                int pom = tab[(indeks + x + d)% rozm_tab];
                                tab[(indeks + x + d)% rozm_tab] = tab[(indeks + fragment - d -1)%rozm_tab];
                                tab[(indeks + fragment - d -1)%rozm_tab] = pom;
                                d++;
                                rundka--;
                            }
                            indeks = (indeks + fragment) % rozm_tab;
                            ilosc_rund--;
                        }
                        int reszta = rozm_tab - ((rozm_tab/ fragment)* fragment);
                        if (reszta != 0)
                        {

                            d = 0;
                            int x = wartosc;
                            x = x % reszta;
                            int rundka = reszta / 2;
                            if(x < 0)
                            {
                                x = x + reszta;
                            }
                            while(rundka > 0)
                            {
                                int pom = tab[(indeks + d)% rozm_tab];
                                tab[(indeks + d)% rozm_tab] = tab[(indeks - 1 - d + reszta)% rozm_tab];
                                tab[(indeks - 1 - d + reszta)% rozm_tab] = pom;
                                d++;
                                rundka--;
                            }
                            d = 0;
                            rundka = x / 2;
                            while(rundka > 0)
                            {
                                int pom = tab[(indeks + d)% rozm_tab];
                                tab[(indeks + d)% rozm_tab] = tab[(indeks -1 -d + x)%rozm_tab];
                                tab[(indeks -1 -d + x)%rozm_tab] = pom;
                                d++;
                                rundka--;
                            }
                            d = 0;
                            rundka = (reszta - x)/2;
                            while(rundka > 0)
                            {
                                int pom = tab[(indeks + d + x) % rozm_tab];
                                tab[(indeks + d + x) % rozm_tab] = tab[(indeks - d -1 + reszta) % rozm_tab];
                                tab[(indeks - d -1 + reszta) % rozm_tab] = pom;
                                d++;
                                rundka--;
                            }

                        }
                    }
                    if((fragment == 0) && (wartosc != 0))
                    {
                        indeks = indeks % rozm_tab;
                        if (indeks < 0)
                        {
                            indeks = indeks + rozm_tab;
                        }
                        int x = wartosc;
                        x = x % rozm_tab;
                        if(x < 0)
                        {
                            x = x + rozm_tab;
                        }
                        int rundka = rozm_tab / 2;
                        d = 0;
                        while(rundka > 0)
                        {
                            int pom = tab[(indeks + d)% rozm_tab];
                            tab[(indeks + d)% rozm_tab] = tab[(indeks - 1 - d + rozm_tab)% rozm_tab];
                            tab[(indeks - 1 - d + rozm_tab)% rozm_tab] = pom;
                            d++;
                            rundka--;
                        }
                        d = 0;
                        rundka = x / 2;
                        while(rundka > 0)
                        {
                            int pom = tab[(indeks + d)% rozm_tab];
                            tab[(indeks + d)% rozm_tab] = tab[(indeks -1 -d + x)%rozm_tab];
                            tab[(indeks -1 -d + x)%rozm_tab] = pom;
                            d++;
                            rundka--;
                        }
                        d = 0;
                        rundka = (rozm_tab - x)/2;
                        while(rundka > 0)
                        {
                            int pom = tab[(indeks + d + x) % rozm_tab];
                            tab[(indeks + d + x) % rozm_tab] = tab[(indeks - d -1 + rozm_tab) % rozm_tab];
                            tab[(indeks - d -1 + rozm_tab) % rozm_tab] = pom;
                            d++;
                            rundka--;
                        }

                    }
                }
                else if (znak == 'C')
                {
                    cin >> indeks;
                    cin >> fragment;
                    if ((fragment > 0) && (fragment <= rozm_tab))
                    {
                        indeks = indeks % rozm_tab;
                        if (indeks < 0)
                        {
                            indeks = indeks + rozm_tab;
                        }
                        int ilosc_zamian = (rozm_tab / fragment) / 2;
                        while(ilosc_zamian-- >0)
                        {
                            int x = fragment;
                            d = 0;
                            while(x-- > 0)
                            {
                                int pom = tab[(indeks + d) % rozm_tab];
                                tab[(indeks + d) % rozm_tab] = tab[(indeks + fragment + d) % rozm_tab];
                                tab[(indeks + fragment + d) % rozm_tab] = pom;
                                d++;
                            }
                            indeks = (indeks + fragment + fragment) % rozm_tab;
                        }
                    }
                }
                else if (znak == 'S')
                {
                    cin >> indeks;
                    cin >> dlugosc;
                    if (dlugosc > rozm_tab)
                    {
                        dlugosc = rozm_tab;
                    }
                    if(dlugosc < -rozm_tab)
                    {
                        dlugosc = -rozm_tab;
                    }
                    if (dlugosc != 0)
                    {
                        indeks = indeks % rozm_tab;
                        if (indeks < 0)
                        {
                            indeks = indeks + rozm_tab;
                        }
                        indeks = indeks % rozm_tab;
                        int napozniej = indeks;
                        if (dlugosc < 0)
                        {
                            int x = dlugosc;
                            x = -1 * x;
                            int ilosc_pelnych_rund = rozm_tab / x;
                            while(ilosc_pelnych_rund-- >0)
                            {
                                int y = 0;
                                while(y < x -1)
                                {
                                    int z = 0;
                                    while(z < x - y -1)
                                    {
                                        if (tab[(indeks + z) % rozm_tab] < tab[(indeks + z + 1) % rozm_tab])
                                        {
                                            int pom = tab[(indeks + z) % rozm_tab];
                                            tab[(indeks + z) % rozm_tab] = tab[(indeks + z + 1) % rozm_tab];
                                            tab[(indeks + z + 1) % rozm_tab] = pom;
                                        }
                                        z++;
                                    }
                                    y++;
                                }
                                indeks = (indeks + x) % rozm_tab;
                            }
                            indeks = indeks % rozm_tab;
                            int r = rozm_tab - ((rozm_tab/dlugosc)* dlugosc);
                            if (r != 0)
                            {
                                if (r < 0)
                                {
                                    r = -1 * r;
                                }
                                int y = 0;
                                while (y < r - 1)
                                {
                                    int z = 0;
                                    while (z < r - y -1)
                                    {
                                        if(tab[(indeks + z) % rozm_tab] < tab[(indeks + 1 + z) % rozm_tab])
                                        {
                                            int pom = tab[(indeks + z) % rozm_tab];
                                            tab[(indeks + z) % rozm_tab] =  tab[(indeks + 1 + z) % rozm_tab];
                                            tab[(indeks + 1 + z) % rozm_tab] = pom;
                                        }
                                        z++;
                                    }
                                    y++;
                                }
                            }
                        }
                        else
                        {
                            int x = dlugosc;
                            int ilosc_pelnych_rund = rozm_tab / x;
                            while(ilosc_pelnych_rund-- >0)
                            {
                                int y = 0;
                                while(y < x -1)
                                {
                                    int z = 0;
                                    while(z < x - y -1)
                                    {
                                        if (tab[(indeks + z) % rozm_tab] > tab[(indeks + z + 1) % rozm_tab])
                                        {
                                            int pom = tab[(indeks + z) % rozm_tab];
                                            tab[(indeks + z) % rozm_tab] = tab[(indeks + z + 1) % rozm_tab];
                                            tab[(indeks + z + 1) % rozm_tab] = pom;
                                        }
                                        z++;
                                    }
                                    y++;
                                }
                                indeks = (indeks + x) % rozm_tab;
                            }
                            indeks = indeks % rozm_tab;
                            int r = napozniej - indeks;
                            if (r != 0)
                            {
                                if (r < 0)
                                {
                                    r = -1 * r;
                                }
                                int y = 0;
                                while (y < r - 1)
                                {
                                    int z = 0;
                                    while (z < r - y -1)
                                    {
                                        if(tab[(indeks + z) % rozm_tab] > tab[(indeks + 1 + z) % rozm_tab])
                                        {
                                            int pom = tab[(indeks + z) % rozm_tab];
                                            tab[(indeks + z) % rozm_tab] =  tab[(indeks + 1 + z) % rozm_tab];
                                            tab[(indeks + 1 + z) % rozm_tab] = pom;
                                        }
                                        z++;
                                    }
                                    y++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}