//Kajetan Ozog
#include <iostream>
using namespace std;

void Algorytm_Bareissa(long long macierz[][32], int size)
{
        int uf = 1;
        for(int k = 0; k < size - 1; k++)
        {
            int numer = k;
            while(numer < size && macierz[numer][k] == 0)
            {
                numer = numer + 1;
            }
            if(numer == size)
            {
                cout << 0 << endl;
                return;
            }
            if(k != numer)
            {
                for(int i = 0; i < size; i++)
                {
                    long long pom;
                    pom = macierz[numer][i];
                    macierz[numer][i] = macierz[k][i];
                    macierz[k][i] = pom;
                }
                uf = -1 * uf;
            }
            for(int i = k + 1; i < size; i++)
            {
                for(int j = k + 1; j < size; j++)
                {
                    if(k == 0)
                    {
                        macierz[i][j] = ((macierz[i][j] * macierz[k][k]) - (macierz[i][k] * macierz[k][j]));
                    }
                    else
                    {
                        macierz[i][j] = ((macierz[i][j] * macierz[k][k]) - (macierz[i][k] * macierz[k][j]))/macierz[k - 1][k - 1];
                    }
                }
            }
        }
        cout << macierz[size - 1][size - 1] * uf << endl;
}


int main()
{
    int size = 0;
    cin >> size;
    long long cube[size][size][size];
    for (int panel = 0; panel < size; panel++)
    {
        for (int pion = 0; pion < size; pion++)
        {
            for (int poziom = 0; poziom < size; poziom++)
            {
                cin >> cube[pion][poziom][panel];
            }
        }
    }
    bool kontynuacja = true;
    while (kontynuacja)
    {
        char znak;
        cin >> znak;
        if(znak == 'E')
        {
            kontynuacja = false;
        }
        if(znak == 'C')
        {
            long long suma = 0;
            int w_poziom; //l
            int w_pion; //v
            int w_panel; //p
            int d_poziom; //h
            int d_pion; //w
            int d_panel; //d
            cin >> w_poziom;
            cin >> w_pion;
            cin >> w_panel;
            cin >> d_poziom;
            cin >> d_pion;
            cin >> d_panel;
            int k_poziom = 1;
            int k_pion = 1;
            int k_panel = 1;
            d_panel++;
            d_pion++;
            d_poziom++;
            if(w_panel >= (size /2))
            {
                k_panel = -1;
            }
            if(w_pion >= (size /2))
            {
                k_pion = -1;
            }
            if(w_poziom >= (size /2))
            {
                k_poziom = -1;
            }
            for (int poziom = 0; poziom < d_poziom; poziom++)
            {
                for (int pion = 0; pion < d_pion; pion++)
                {
                    for (int panel = 0; panel < d_panel; panel++)
                    {
                        int wsp_Z = w_panel + (k_panel * panel);
                        int wsp_Y = w_pion + (k_pion * pion);
                        int wsp_X = w_poziom + (k_poziom * poziom);
                        if((wsp_Z >= 0) && (wsp_Z < size) && (wsp_X >= 0) && (wsp_X < size) && (wsp_Y >= 0) && (wsp_Y < size) )
                        {
                            suma = suma + cube[wsp_X][wsp_Y][wsp_Z];
                        }
                    }
                }
            }
            cout << suma << endl;
        }
        if(znak == 'T')
        {
            long long suma = 0;
            int w_poziom; //l
            int w_pion; //v
            int w_panel; //p
            int krawedz; //e
            cin >> w_poziom;
            cin >> w_pion;
            cin >> w_panel;
            cin >> krawedz;
            krawedz++;
            int k_poziom = 1;
            int k_pion = 1;
            int k_panel = 1;
            if(w_panel >= (size /2))
            {
                k_panel = -1;
            }
            if(w_pion >= (size /2))
            {
                k_pion = -1;
            }
            if(w_poziom >= (size /2))
            {
                k_poziom = -1;
            }
            for (int poziom = 0; poziom < krawedz; poziom++)
            {
                for (int pion = 0; pion < krawedz - poziom; pion++)
                {
                    for (int panel = 0; panel < (krawedz - (poziom + pion)); panel++)
                    {
                        int wsp_Z = w_panel + (k_panel * panel);
                        int wsp_Y = w_pion + (k_pion * pion);
                        int wsp_X = w_poziom + (k_poziom * poziom);
                        if((wsp_Z >= 0) && (wsp_Z < size) && (wsp_X >= 0) && (wsp_X < size) && (wsp_Y >= 0) && (wsp_Y < size) )
                        {
                            suma = suma + cube[wsp_X][wsp_Y][wsp_Z];
                        }
                    }
                }
            }
            cout << suma << endl;
        }
        if(znak == 'O')
        {
            long long suma = 0;
            int w_poziom; //l
            int w_pion; //v
            int w_panel; //p
            int promien; //e
            cin >> w_poziom;
            cin >> w_pion;
            cin >> w_panel;
            cin >> promien;
            promien++;
            int k_poziom = 1;
            int k_pion = 1;
            int k_panel = 1;
            if(w_panel >= (size /2))
            {
                k_panel = -1;
            }
            if(w_pion >= (size /2))
            {
                k_pion = -1;
            }
            if(w_poziom >= (size /2))
            {
                k_poziom = -1;
            }
            for (int poziom = 0; poziom < promien; poziom++)
            {
                for (int pion = 0; pion < promien; pion++)
                {
                    for (int panel = 0; panel < promien; panel++)
                    {
                        int wsp_Z = w_panel + (k_panel * panel);
                        int wsp_Y = w_pion + (k_pion * pion);
                        int wsp_X = w_poziom + (k_poziom * poziom);
                        if((wsp_Z >= 0) && (wsp_Z < size) && (wsp_X >= 0) && (wsp_X < size) && (wsp_Y >= 0) && (wsp_Y < size) )
                        {
                            long long dist = ((wsp_X - w_poziom) * (wsp_X - w_poziom)) + ((wsp_Z - w_panel) * (wsp_Z - w_panel)) + ((wsp_Y - w_pion) * (wsp_Y - w_pion));
                            long long r_kw = (promien - 1) * (promien - 1);
                            if(dist <= r_kw)
                            {
                                suma = suma + cube[wsp_X][wsp_Y][wsp_Z];
                            }
                        }
                    }
                }
            }
            cout << suma << endl;
        }
        if (znak == 'D')
        {
            char k;
            cin >> k;
            int numer;
            cin >> numer;
            long long macierz[32][32]={};
            if(k == 'l')
            {
                for(int dl = 0; dl< size; dl++)
                {
                    for(int szer = 0; szer < size; szer++)
                    {
                        macierz[dl][szer] = cube[numer][dl][szer];
                    }
                }
            }
            if(k == 'v')
            {
                for(int dl = 0; dl< size; dl++)
                {
                    for(int szer = 0; szer < size; szer++)
                    {
                        macierz[dl][szer] = cube[dl][numer][szer];
                    }
                }
            }
            if(k == 'p')
            {
                for(int dl = 0; dl< size; dl++) {
                    for (int szer = 0; szer < size; szer++) {
                        macierz[dl][szer] = cube[dl][szer][numer];
                    }
                }
            }
            Algorytm_Bareissa(macierz, size);
        }
    }
}