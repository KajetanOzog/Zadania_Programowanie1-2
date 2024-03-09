//Kajetan Ozog
#include <iostream>
using namespace std;


struct Place
{
    unsigned short int quantity;
    char label;
};


struct Shelf
{
    Place place[128];
    short number_of_places;
};


struct Rack
{
    Shelf shelf[128];
    short number_of_shelfs;
};


struct Warehouse
{
    Rack rack[128];
    short number_of_racks;
    Shelf W_handy_shelf;
};


struct All
{
    Warehouse warehouse[128];
    short number_of_warehouses;
    Rack A_handy_rack;
    Shelf A_handy_shelf;
};
All magazine;
long long ilosc;


//DONE
void SET_AP(int w, int r, int s, int p)
{
    if ((w>=0) && (w<128) && (r>=0) && (r<128) && (s>=0) && (s<128) && (p>=0) && (p<=128))
    {
        if ((w < magazine.number_of_warehouses) && (r < magazine.warehouse[w].number_of_racks) && (s < magazine.warehouse[w].rack[r].number_of_shelfs))
        {
            int used_places = magazine.warehouse[w].rack[r].shelf[s].number_of_places;
            magazine.warehouse[w].rack[r].shelf[s].number_of_places = p;
            for(int i = used_places; i < p; i++)
            {
                magazine.warehouse[w].rack[r].shelf[s].place[i].quantity = 0;
                magazine.warehouse[w].rack[r].shelf[s].place[i].label = 111;
            }
            for(int i = p; i < 128; i++)
            {
                ilosc -=  magazine.warehouse[w].rack[r].shelf[s].place[i].quantity;
                magazine.warehouse[w].rack[r].shelf[s].place[i].quantity = 0;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void SET_AS(int w, int r, int s, int p)
{
    if ((w>=0) && (w<128) && (r>=0) && (r<128) && (s>=0) && (s<=128) && (p>=0) && (p<=128))
    {
        if ((w < magazine.number_of_warehouses) && (r < magazine.warehouse[w].number_of_racks))
        {
            int used_shelfs = magazine.warehouse[w].rack[r].number_of_shelfs;
            magazine.warehouse[w].rack[r].number_of_shelfs = s;
            for (int i = 0; i < s; i++)
            {
                SET_AP(w,r,i,p);
            }
/*            for(int i = s; i < used_shelfs; i++)
            {
                SET_AP(w,r,i,0);
            }*/
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void SET_AR(int w, int r, int s, int p)
{
    if ((w>=0) && (w<128) && (r>=0) && (r<=128) && (s>=0) && (s<=128) && (p>=0) && (p<=128))
    {
        if ( w < magazine.number_of_warehouses)
        {
            int used_racks = magazine.warehouse[w].number_of_racks;
            magazine.warehouse[w].number_of_racks = r;
            for (int i = 0; i < r; i++)
            {
                SET_AS(w,i,s,p);
            }
/*            for (int i =r; i < used_racks; i++)
            {
                SET_AS(w,i,0,0);
            }*/
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void SET_AW(int w, int r, int s, int p)
{
    if ((w>=0) && (w<=128) && (r>=0) && (r<=128) && (s>=0) && (s<=128) && (p>=0) && (p<=128))
    {
        int used_magazines = magazine.number_of_warehouses;
        magazine.number_of_warehouses = w;
        for (int i = 0; i < w; i++)
        {
            SET_AR(i,r,s,p);
        }
/*        for (int i =w; i < used_magazines; i++)
        {
            SET_AR(i,0,0,0);
        }*/
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void SET_HW(int w, int p)
{
    if ((w>=0) && (w<128) && (p>=0) && (p<128))
    {
        if ( w < magazine.number_of_warehouses)
        {
            int used_shelfs = magazine.warehouse[w].W_handy_shelf.number_of_places;
            magazine.warehouse[w].W_handy_shelf.number_of_places = p;
            for (int i = used_shelfs; i < p; i++)
            {
                ilosc -= magazine.warehouse[w].W_handy_shelf.place[i].quantity;
                magazine.warehouse[w].W_handy_shelf.place[i].quantity = 0;
                magazine.warehouse[w].W_handy_shelf.place[i].label = 111;
            }
            for (int i = p; i < 128; i++)
            {
                ilosc -= magazine.warehouse[w].W_handy_shelf.place[i].quantity;
                magazine.warehouse[w].W_handy_shelf.place[i].quantity = 0;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void SET_HR(int s, int p)
{
    if ((s>=0) && (s<128) && (p>=0) && (p<128))
    {
        int used_shelfs = magazine.A_handy_rack.number_of_shelfs;
        magazine.A_handy_rack.number_of_shelfs = s;
        for(int ss = s; ss < used_shelfs; ss++)
        {
            for(int pp = 0; pp < magazine.A_handy_rack.shelf[ss].number_of_places; pp++)
            {
                ilosc -= magazine.A_handy_rack.shelf[ss].place[pp].quantity;
                magazine.A_handy_rack.shelf[ss].place[pp].quantity = 0;
                magazine.A_handy_rack.shelf[ss].place[pp].label = 111;
            }
            magazine.A_handy_rack.shelf[ss].number_of_places = 0;
        }
        for(int ss = 0; ss < s; ss++)
        {
            for (int pp = p; pp < magazine.A_handy_rack.shelf[ss].number_of_places; pp++)
            {
                ilosc -= magazine.A_handy_rack.shelf[ss].place[pp].quantity;
                magazine.A_handy_rack.shelf[ss].place[pp].quantity = 0;
                magazine.A_handy_rack.shelf[ss].place[pp].label = 111;
            }
            magazine.A_handy_rack.shelf[ss].number_of_places = p;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void SET_HS(int p)
{
    if ((p>=0) && (p<=128))
    {
        int used_places = magazine.A_handy_shelf.number_of_places;
        magazine.A_handy_shelf.number_of_places = p;
        for(int i = used_places; i < p; i++)
        {
            ilosc -= magazine.A_handy_shelf.place[i].quantity;
            magazine.A_handy_shelf.place[i].quantity = 0;
            magazine.A_handy_shelf.place[i].label = 111;
        }
        for(int i = p; i < 128; i++)
        {
            ilosc -= magazine.A_handy_shelf.place[i].quantity;
            magazine.A_handy_shelf.place[i].quantity = 0;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }

}

//DONE
void PUT_W(int w, int r, int s, int p, int A)
{
    if ((w>=0) && (w<128) && (r>=0) && (r<128) && (s>=0) && (s<128) && (p>=0) && (p<128))
    {
        if (w < magazine.number_of_warehouses)
        {
            if (r < magazine.warehouse[w].number_of_racks)
            {
                if(s < magazine.warehouse[w].rack[r].number_of_shelfs)
                {
                    if(p < magazine.warehouse[w].rack[r].shelf[s].number_of_places)
                    {
                        int amount = magazine.warehouse[w].rack[r].shelf[s].place[p].quantity;
                        if((amount + A) > 65535)
                        {
                            ilosc += 65535 - amount;
                            magazine.warehouse[w].rack[r].shelf[s].place[p].quantity = 65535;
                        }
                        else
                        {
                            ilosc += A;
                            magazine.warehouse[w].rack[r].shelf[s].place[p].quantity = (amount + A);
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                        return;
                    }
                }
                else
                {
                    cout << "error" << endl;
                    return;
                }
            }
            else
            {
                cout << "error" << endl;
                return;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void PUT_H(int w, int p, int A)
{
    if ((w>=0) && (w<128) && (p>=0) && (p<128))
    {
        if(w < magazine.number_of_warehouses)
        {
            if(p < magazine.warehouse[w].W_handy_shelf.number_of_places)
            {
                int amount = magazine.warehouse[w].W_handy_shelf.place[p].quantity;
                if((amount + A) > 65535)
                {
                    ilosc += 65535 - amount;
                    magazine.warehouse[w].W_handy_shelf.place[p].quantity = 65535;
                }
                else
                {
                    ilosc += A;
                    magazine.warehouse[w].W_handy_shelf.place[p].quantity = (amount + A);
                }
            }
            else
            {
                cout << "error" << endl;
                return;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void PUT_R(int s, int p, int A)
{
    if ((s>=0) && (s<128) && (p>=0) && (p<128))
    {
        if(s < magazine.A_handy_rack.number_of_shelfs)
        {
            if(p < magazine.A_handy_rack.shelf[s].number_of_places)
            {
                int amount = magazine.A_handy_rack.shelf[s].place[p].quantity;
                if((amount + A) > 65535)
                {
                    ilosc += 65535 - amount;
                    magazine.A_handy_rack.shelf[s].place[p].quantity = 65535;
                }
                else
                {
                    ilosc += A;
                    magazine.A_handy_rack.shelf[s].place[p].quantity = (amount + A);
                }
            }
            else
            {
                cout << "error" << endl;
                return;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void PUT_S (int p, int A)
{
    if ((p>=0) && (p<128))
    {
        if(p < magazine.A_handy_shelf.number_of_places)
        {
            int amount = magazine.A_handy_shelf.place[p].quantity;
            if((amount + A) > 65535)
            {
                ilosc += 65535 - amount;
                magazine.A_handy_shelf.place[p].quantity = 65535;
            }
            else
            {
                ilosc += A;
                magazine.A_handy_shelf.place[p].quantity = (amount + A);
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void Fill (int w, int r, int s, int p, int A)
{
    if ((w>=0) && (w<=128) && (r>=0) && (r<=128) && (s>=0) && (s<=128) && (p>=0) && (p<=128) && (A>=0) && (A <= 65535))
    {
        ilosc = 0;
        magazine.number_of_warehouses = w;
        for(int ww = 0; ww < w; ww++)
        {
            magazine.warehouse[ww].number_of_racks = r;
            magazine.warehouse[ww].W_handy_shelf.number_of_places = p;
            for (int pp = 0; pp < p; pp++)
            {
                ilosc += A;
                magazine.warehouse[ww].W_handy_shelf.place[pp].quantity = A;
                magazine.warehouse[ww].W_handy_shelf.place[pp].label = 111;
            }
            for(int rr = 0; rr < r; rr++)
            {
                magazine.warehouse[ww].rack[rr].number_of_shelfs = s;
                for(int ss = 0; ss < s; ss++)
                {
                    magazine.warehouse[ww].rack[rr].shelf[ss].number_of_places = p;
                    for (int pp = 0; pp < p; pp++)
                    {
                        ilosc += A;
                        magazine.warehouse[ww].rack[rr].shelf[ss].place[pp].quantity = A;
                        magazine.warehouse[ww].rack[rr].shelf[ss].place[pp].label = 111;
                    }
                }
            }
        }
        magazine.A_handy_shelf.number_of_places = p;
        for (int pp = 0; pp < p; pp++)
        {
            ilosc += A;
            magazine.A_handy_shelf.place[pp].quantity = A;
            magazine.A_handy_shelf.place[pp].label = 111;
        }
        magazine.A_handy_rack.number_of_shelfs = s;
        for (int ss = 0; ss < s; ss++)
        {
            magazine.A_handy_rack.shelf[ss].number_of_places = p;
            for (int pp = 0; pp < p; pp++)
            {
                ilosc += A;
                magazine.A_handy_rack.shelf[ss].place[pp].quantity = A;
                magazine.A_handy_rack.shelf[ss].place[pp].label = 111;
            }
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void POP_W(int w, int r, int s, int p, int A)
{
    if ((w>=0) && (w<128) && (r>=0) && (r<128) && (s>=0) && (s<128) && (p>=0) && (p<128))
    {
        if (w < magazine.number_of_warehouses)
        {
            if (r < magazine.warehouse[w].number_of_racks)
            {
                if(s < magazine.warehouse[w].rack[r].number_of_shelfs)
                {
                    if(p < magazine.warehouse[w].rack[r].shelf[s].number_of_places)
                    {
                        int amount = magazine.warehouse[w].rack[r].shelf[s].place[p].quantity;
                        if((amount - A) < 0)
                        {
                            ilosc -= magazine.warehouse[w].rack[r].shelf[s].place[p].quantity;
                            magazine.warehouse[w].rack[r].shelf[s].place[p].quantity = 0;
                        }
                        else
                        {
                            ilosc -= A;
                            magazine.warehouse[w].rack[r].shelf[s].place[p].quantity = (amount - A);
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                        return;
                    }
                }
                else
                {
                    cout << "error" << endl;
                    return;
                }
            }
            else
            {
                cout << "error" << endl;
                return;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void POP_H(int w, int p, int A) {
    if ((w>=0) && (w<128) && (p>=0) && (p<128))
    {
        if(w < magazine.number_of_warehouses)
        {
            if(p < magazine.warehouse[w].W_handy_shelf.number_of_places)
            {
                int amount = magazine.warehouse[w].W_handy_shelf.place[p].quantity;
                if((amount - A) < 0)
                {
                    ilosc -= magazine.warehouse[w].W_handy_shelf.place[p].quantity;
                    magazine.warehouse[w].W_handy_shelf.place[p].quantity = 0;
                }
                else
                {
                    ilosc -= A;
                    magazine.warehouse[w].W_handy_shelf.place[p].quantity = (amount - A);
                }
            }
            else
            {
                cout << "error" << endl;
                return;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void POP_R(int s, int p, int A)
{
    if ((s>=0) && (s<128) && (p>=0) && (p<128))
    {
        if(s < magazine.A_handy_rack.number_of_shelfs)
        {
            if(p < magazine.A_handy_rack.shelf[s].number_of_places)
            {
                int amount = magazine.A_handy_rack.shelf[s].place[p].quantity;
                if((amount - A) < 0)
                {
                    ilosc -= magazine.A_handy_rack.shelf[s].place[p].quantity;
                    magazine.A_handy_rack.shelf[s].place[p].quantity = 0;
                }
                else
                {
                    ilosc -= A;
                    magazine.A_handy_rack.shelf[s].place[p].quantity = (amount - A);
                }
            }
            else
            {
                cout << "error" << endl;
                return;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void POP_S (int p, int A)
{
    if ((p>=0) && (p<128))
    {
        if(p < magazine.A_handy_shelf.number_of_places)
        {
            int amount = magazine.A_handy_shelf.place[p].quantity;
            if((amount - A) < 0)
            {
                ilosc -= magazine.A_handy_shelf.place[p].quantity;
                magazine.A_handy_shelf.place[p].quantity = 0;
            }
            else
            {
                ilosc -= A;
                magazine.A_handy_shelf.place[p].quantity = (amount - A);
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void MOV_W(int w1, int r1, int s1, int w2, int r2, int s2, int p, int A)
{
    if ((w1 >= 0) && (w1 < 128) && (r1 >= 0) && (r1 < 128) && (s1 >= 0) && (s1 < 128) && (w2 >= 0) && (w2 < 128) &&
        (r2 >= 0) && (r2 < 128) && (s2 >= 0) && (s2 < 128) && (p >= 0) && (p < 128))
    {
        if ((w1 < magazine.number_of_warehouses) && (w2 < magazine.number_of_warehouses) )
        {
            if ((r1 < magazine.warehouse[w1].number_of_racks) && (r2 < magazine.warehouse[w2].number_of_racks))
            {
                if ((s1 < magazine.warehouse[w1].rack[r1].number_of_shelfs) && (s2 < magazine.warehouse[w2].rack[r2].number_of_shelfs))
                {
                    if ((p < magazine.warehouse[w1].rack[r1].shelf[s1].number_of_places) && (p < magazine.warehouse[w2].rack[r2].shelf[s2].number_of_places))
                    {
                        int q1 = magazine.warehouse[w1].rack[r1].shelf[s1].place[p].quantity;
                        int q2 = magazine.warehouse[w2].rack[r2].shelf[s2].place[p].quantity;
                        if ((A + q2) > 65535)
                        {
                            A = 65535 - q2;
                        }
                        if (A > q1)
                        {
                            A = q1;
                        }
                        magazine.warehouse[w1].rack[r1].shelf[s1].place[p].quantity -= A;
                        magazine.warehouse[w2].rack[r2].shelf[s2].place[p].quantity += A;
                    }
                    else
                    {
                        cout << "error" << endl;
                        return;
                    }
                }
                else
                {
                    cout << "error" << endl;
                    return;
                }
            }
            else
            {
                cout << "error" << endl;
                return;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void MOV_H(int w, int r, int s, int p, int A)
{
    if ((w>=0) && (w<128) && (r>=0) && (r<128) && (s>=0) && (s<128) && (p>=0) && (p<128))
    {
        if (w < magazine.number_of_warehouses)
        {
            if (r < magazine.warehouse[w].number_of_racks)
            {
                if (s < magazine.warehouse[w].rack[r].number_of_shelfs)
                {
                    if((p < magazine.warehouse[w].rack[r].shelf[s].number_of_places) && (p < magazine.warehouse[w].W_handy_shelf.number_of_places))
                    {
                        int q1 = magazine.warehouse[w].rack[r].shelf[s].place[p].quantity;
                        int q2 = magazine.warehouse[w].W_handy_shelf.place[p].quantity;
                        if ((A + q2) > 65535)
                        {
                            A = 65535 - q2;
                        }
                        if (A > q1)
                        {
                            A = q1;
                        }
                        magazine.warehouse[w].rack[r].shelf[s].place[p].quantity -= A;
                        magazine.warehouse[w].W_handy_shelf.place[p].quantity += A;
                    }
                    else
                    {
                        cout << "error" << endl;
                        return;
                    }
                }
                else
                {
                    cout << "error" << endl;
                    return;
                }
            }
            else
            {
                cout << "error" << endl;
                return;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void MOV_R(int w, int r, int s1, int s2, int p, int A)
{
    if ((w>=0) && (w<128) && (r>=0) && (r<128) && (s1>=0) && (s1<128) && (s2>=0) && (s2<128) && (p>=0) && (p<128))
    {
        if (w < magazine.number_of_warehouses)
        {
            if (r < magazine.warehouse[w].number_of_racks)
            {
                if ((s1 < magazine.warehouse[w].rack[r].number_of_shelfs) && (s2 < magazine.A_handy_rack.number_of_shelfs))
                {
                    if((p < magazine.warehouse[w].rack[r].shelf[s1].number_of_places) && (p < magazine.A_handy_rack.shelf[s2].number_of_places))
                    {
                        int q1 = magazine.warehouse[w].rack[r].shelf[s1].place[p].quantity;
                        int q2 = magazine.A_handy_rack.shelf[s2].place[p].quantity;
                        if ((A + q2) > 65535)
                        {
                            A = 65535 - q2;
                        }
                        if (A > q1)
                        {
                            A = q1;
                        }
                        magazine.warehouse[w].rack[r].shelf[s1].place[p].quantity -= A;
                        magazine.A_handy_rack.shelf[s2].place[p].quantity += A;
                    }
                    else
                    {
                        cout << "error" << endl;
                        return;
                    }
                }
                else
                {
                    cout << "error" << endl;
                    return;
                }
            }
            else
            {
                cout << "error" << endl;
                return;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void MOV_S(int s, int p, int A)
{
    if ((s>=0) && (s<128) && (p>=0) && (p<128))
    {
        if((s < magazine.A_handy_rack.number_of_shelfs))
        {
            if((p < magazine.A_handy_rack.shelf[s].number_of_places) && (p < magazine.A_handy_shelf.number_of_places))
            {
                int q1 = magazine.A_handy_rack.shelf[s].place[p].quantity;
                int q2 = magazine.A_handy_shelf.place[p].quantity;
                if ((A + q2) > 65535)
                {
                    A = 65535 - q2;
                }
                if (A > q1)
                {
                    A = q1;
                }
                magazine.A_handy_rack.shelf[s].place[p].quantity -= A;
                magazine.A_handy_shelf.place[p].quantity += A;
            }
            else
            {
                cout << "error" << endl;
                return;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
}

//DONE
void GET_E()
{
    cout << ilosc << endl;
    /*long long amount = 0;
    for (int w = 0; w < magazine.number_of_warehouses; w++)
    {
        for(int hs = 0; hs < magazine.warehouse[w].W_handy_shelf.number_of_places; hs++) //W_HANDY_SHELF
        {
            amount += magazine.warehouse[w].W_handy_shelf.place[hs].quantity;
        }
        for(int r = 0; r < magazine.warehouse[w].number_of_racks; r++)      //NORMAL
        {
            for(int s = 0; s < magazine.warehouse[w].rack[r].number_of_shelfs; s++)
            {
                for(int p = 0; p < magazine.warehouse[w].rack[r].shelf[s].number_of_places; p++)
                {
                    amount += magazine.warehouse[w].rack[r].shelf[s].place[p].quantity;
                }
            }
        }
    }
    for (int s = 0; s < magazine.A_handy_rack.number_of_shelfs; s++) //A_HANDY_RACK
    {
        for(int p = 0; p < magazine.A_handy_rack.shelf[s].number_of_places; p++)
        {
            amount += magazine.A_handy_rack.shelf[s].place[p].quantity;
        }
    }
    for (int p=0; p < magazine.A_handy_shelf.number_of_places; p++) //W_HANDY_SHELF
    {
        amount += magazine.A_handy_shelf.place[p].quantity;
    }
    cout << amount << endl;*/
}




//DONE
void GET_W(int w)
{
    long long amount = 0;
    if((w>=0) && (w<128))
    {
        if (w < magazine.number_of_warehouses)
        {
            for(int hs = 0; hs < magazine.warehouse[w].W_handy_shelf.number_of_places; hs++) //W_HANDY_SHELF
            {
                amount += magazine.warehouse[w].W_handy_shelf.place[hs].quantity;
            }
            for(int r = 0; r < magazine.warehouse[w].number_of_racks; r++)      //NORMAL
            {
                for(int s = 0; s < magazine.warehouse[w].rack[r].number_of_shelfs; s++)
                {
                    for(int p = 0; p < magazine.warehouse[w].rack[r].shelf[s].number_of_places; p++)
                    {
                        amount += magazine.warehouse[w].rack[r].shelf[s].place[p].quantity;
                    }
                }
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
    cout << amount << endl;
}

//DONE
void GET_RW(int w, int r)
{
    long long amount = 0;
    if((w>=0) && (w<128) && (r>=0) && (r<128))
    {
        if (w < magazine.number_of_warehouses)
        {
            if ( r < magazine.warehouse[w].number_of_racks)
            {
                for(int s = 0; s < magazine.warehouse[w].rack[r].number_of_shelfs; s++)
                {
                    for(int p = 0; p < magazine.warehouse[w].rack[r].shelf[s].number_of_places; p++)
                    {
                        amount += magazine.warehouse[w].rack[r].shelf[s].place[p].quantity;
                    }
                }
            }
            else
            {
                cout << "error" << endl;
                return;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
    cout << amount << endl;
}

//DONE
void GET_RH()
{
    long long amount = 0;
    for (int s = 0; s < magazine.A_handy_rack.number_of_shelfs; s++) //A_HANDY_RACK
    {
        for(int p = 0; p < magazine.A_handy_rack.shelf[s].number_of_places; p++)
        {
            amount += magazine.A_handy_rack.shelf[s].place[p].quantity;
        }
    }
    cout << amount << endl;
}

//DONE
void GET_SW(int w, int r, int s)
{
    long long amount = 0;
    if((w>=0) && (w<128) && (r>=0) && (r<128) && (s>=0) && (s<128))
    {
        if ((w < magazine.number_of_warehouses) && ( r < magazine.warehouse[w].number_of_racks) && (s < magazine.warehouse[w].rack[r].number_of_shelfs))
        {
            for (int p = 0; p < magazine.warehouse[w].rack[r].shelf[s].number_of_places; p++)
            {
                amount += magazine.warehouse[w].rack[r].shelf[s].place[p].quantity;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
    cout << amount << endl;
}

//DONE
void GET_SH(int w)
{
    long long amount = 0;
    if ((w>=0) && (w<128))
    {
        if (w < magazine.number_of_warehouses)
        {
            for(int hs = 0; hs < magazine.warehouse[w].W_handy_shelf.number_of_places; hs++) //W_HANDY_SHELF
            {
                amount += magazine.warehouse[w].W_handy_shelf.place[hs].quantity;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
    cout << amount << endl;
}


//DONE
void GET_SR (int s)
{
    long long amount = 0;
    if ((s>=0) && (s<128))
    {
        if (s < magazine.A_handy_rack.number_of_shelfs)
        {
            for (int p = 0; p < magazine.A_handy_rack.shelf[s].number_of_places; p++)
            {
                amount += magazine.A_handy_rack.shelf[s].place[p].quantity;
            }
        }
        else
        {
            cout << "error" << endl;
            return;
        }
    }
    else
    {
        cout << "error" << endl;
        return;
    }
    cout << amount << endl;
}

//DONE
void GET_S()
{
    long long amount = 0;
    for (int p=0; p < magazine.A_handy_shelf.number_of_places; p++) //W_HANDY_SHELF
    {
        amount += magazine.A_handy_shelf.place[p].quantity;
    }
    cout << amount << endl;
}

//DONE
void SET_LW(int w, int r, int s, int p, int d)
{
    if ((w>=0) && (w<128) && (r>=0) && (r<128) && (s>=0) && (s<128) && (p>=0) && (p<128) && (d>-1))
    {
        if(w < magazine.number_of_warehouses)
        {
            if(r < magazine.warehouse[w].number_of_racks)
            {
                if(s < magazine.warehouse[w].rack[r].number_of_shelfs)
                {
                    if(p < magazine.warehouse[w].rack[r].shelf[s].number_of_places)
                    {
                        magazine.warehouse[w].rack[r].shelf[s].place[p].label = d;
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
                else
                {
                    cout << "error" << endl;
                }
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else
        {
            cout << "error" << endl;
        }
    }
    else
    {
        cout << "error" << endl;
    }
}

//DONE
void SET_LH(int w, int p, int d)
{
    if ((w>=0) && (w<128) && (p>=0) && (p<128) && (d>-1))
    {
        if(w < magazine.number_of_warehouses)
        {
            if( p < magazine.warehouse[w].W_handy_shelf.number_of_places)
            {
                magazine.warehouse[w].W_handy_shelf.place[p].label= d;
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else
        {
            cout << "error" << endl;
        }
    }
    else
    {
        cout << "error" << endl;
    }
}

//DONE
void SET_LR(int s, int p, int d)
{
    if ((s>=0) && (s<128) && (p>=0) && (p<128) && (d>-1))
    {
        if (s < magazine.A_handy_rack.number_of_shelfs)
        {
            if (p < magazine.A_handy_rack.shelf[s].number_of_places)
            {
                magazine.A_handy_rack.shelf[s].place[p].label = d;
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else
        {
            cout << "error" << endl;
        }
    }
    else
    {
        cout << "error" << endl;
    }
}

//DONE
void SET_LS(int p, int d)
{
    if ((p>=0) && (p<128) && (d > -1))
    {
        if(p < magazine.A_handy_shelf.number_of_places)
        {
            magazine.A_handy_shelf.place[p].label = d;
        }
        else
        {
            cout << "error" << endl;
        }
    }
    else
    {
        cout << "error" << endl;
    }
}

//DONE
void GET_LW(int w, int r, int s, int p)
{
    if ((w>=0) && (w<128) && (r>=0) && (r<128) && (s>=0) && (s<128) && (p>=0) && (p<128))
    {
        if(w < magazine.number_of_warehouses)
        {
            if(r < magazine.warehouse[w].number_of_racks)
            {
                if(s < magazine.warehouse[w].rack[r].number_of_shelfs)
                {
                    if(p < magazine.warehouse[w].rack[r].shelf[s].number_of_places)
                    {
                        int x = magazine.warehouse[w].rack[r].shelf[s].place[p].label;
                        if(x == 111)
                        {
                            cout << "--" << endl;
                        }
                        else
                        {
                            if (x < 10)
                            {
                                cout << 0 << x << endl;
                            }
                            else
                            {
                                cout << x << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
                else
                {
                    cout << "error" << endl;
                }
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else
        {
            cout << "error" << endl;
        }
    }
    else
    {
        cout << "error" << endl;
    }
}

//DONE
void GET_LH(int w, int p)
{
    if ((w>=0) && (w<128) && (p>=0) && (p<128))
    {
        if(w < magazine.number_of_warehouses)
        {
            if( p < magazine.warehouse[w].W_handy_shelf.number_of_places)
            {
                int x = magazine.warehouse[w].W_handy_shelf.place[p].label;
                if(x == 111)
                {
                    cout << "--" << endl;
                }
                else
                {
                    if (x < 10)
                    {
                        cout << 0 << x << endl;
                    }
                    else
                    {
                        cout << x << endl;
                    }
                }
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else
        {
            cout << "error" << endl;
        }
    }
    else
    {
        cout << "error" << endl;
    }
}

//DONE
void GET_LR(int s, int p)
{
    if ((s>=0) && (s<128) && (p>=0) && (p<128))
    {
        if (s < magazine.A_handy_rack.number_of_shelfs)
        {
            if (p < magazine.A_handy_rack.shelf[s].number_of_places)
            {
                int x = magazine.A_handy_rack.shelf[s].place[p].label;
                if(x == 111)
                {
                    cout << "--" << endl;
                }
                else
                {
                    if (x < 10)
                    {
                        cout << 0 << x << endl;
                    }
                    else
                    {
                        cout << x << endl;
                    }
                }
            }
            else
            {
                cout << "error" << endl;
            }
        }
        else
        {
            cout << "error" << endl;
        }
    }
    else
    {
        cout << "error" << endl;
    }
}

//DONE
void GET_LS(int p)
{
    if ((p>=0) && (p<128))
    {
        if(p < magazine.A_handy_shelf.number_of_places)
        {
            int x = magazine.A_handy_shelf.place[p].label;
            if(x == 111)
            {
                cout << "--" << endl;
            }
            else
            {
                if (x < 10)
                {
                    cout << 0 << x << endl;
                }
                else
                {
                    cout << x << endl;
                }
            }
        }
        else
        {
            cout << "error" << endl;
        }
    }
    else
    {
        cout << "error" << endl;
    }
}


int main(){
    char operation[6] = {};
    operation[0] = '0';
    operation[1] = '0';
    operation[2] = '0';
    operation[3] = '0';
    operation[4] = '0';
    operation[5] = '0';
    while(operation[0]!='E')
    {
        operation[0] = '0';
        operation[1] = '0';
        operation[2] = '0';
        operation[3] = '0';
        operation[4] = '0';
        operation[5] = '0';
        int w;
        int r;
        int s;
        int p;
        int A;
        int w2;
        int r2;
        int s2;
        int dd;
        cin >> operation;
        if(operation[0]=='S')
        {
            if((operation[4]=='A') && (operation[5]=='P')) //SET_AP
            {
                cin >> w >> r >> s >> p;
                SET_AP(w,r,s,p);
            }
            else if((operation[4]=='A') && (operation[5]=='S')) //SET_AS
            {
                cin >> w >> r >> s >> p;
                SET_AS(w,r,s,p);
            }
            else if((operation[4] =='A') && (operation[5] =='R')) //SET_AR
            {
                cin >> w >> r >> s >> p;
                SET_AR(w,r,s,p);
            }
            else if((operation[4] =='A') && (operation[5] =='W')) //SET_AW
            {
                cin >> w >> r >> s >> p;
                SET_AW(w,r,s,p);
            }
            else if((operation[4] =='H') && (operation[5] =='W')) //SET_HW
            {
                cin >> w >> p;
                SET_HW(w,p);
            }
            else if((operation[4] =='H') && (operation[5] =='R')) //SET_HR
            {
                cin >> s >> p;
                SET_HR(s,p);
            }
            else if((operation[4] =='H') && (operation[5] =='S')) //SET_HS
            {
                cin >> p;
                SET_HS(p);
            }

                //ETYKIETY
            else if((operation[4] =='L') && (operation[5] =='W')) //SET_LW
            {
                cin >> w >> r >> s >> p;
                cin >> dd;
                SET_LW(w,r,s,p,dd);
            }
            else if((operation[4] =='L') && (operation[5] =='H')) //SET_LH
            {
                cin >> w >> p;
                cin >> dd;
                SET_LH(w, p,dd);
            }
            else if((operation[4] =='L') && (operation[5] =='R')) //SET_LR
            {
                cin >> s >> p;
                cin >> dd;
                SET_LR(s, p,dd);
            }
            else if((operation[4] =='L') && (operation[5] =='S')) //SET_LS
            {
                cin >> p;
                cin >> dd;
                SET_LS(p,dd);
            }
        }
        else if((operation[0] == 'P') && (operation[1] == 'U'))
        {
            if ((operation[4] == 'W')&& (operation[5] == '\0')) //PUT_W
            {
                cin >> w >> r >> s >> p >> A;
                PUT_W(w,r,s,p,A);
            }
            else if ((operation[4] == 'H')&& (operation[5] == '\0')) //PUT_H
            {
                cin >> w >> p >> A;
                PUT_H(w,p,A);
            }
            else if ((operation[4] == 'R') && (operation[5] == '\0')) //PUT_R
            {
                cin >> s >> p >> A;
                PUT_R(s,p,A);
            }
            else if ((operation[4] == 'S') && (operation[5] == '\0')) //PUT_S
            {
                cin >> p >> A;
                PUT_S(p,A);
            }
        }
        else if ((operation[0] =='F') && (operation[1] == 'I')) //FILL
        {
            cin >> w >> r >> s >> p >> A;
            Fill(w,r,s,p,A);
        }
        else if ((operation[0] == 'P') && (operation[1] == 'O'))
        {
            if ((operation[4] == 'W') && (operation[5] == '\0')) //POP_W
            {
                cin >> w >> r >> s >> p >> A;
                POP_W(w,r,s,p,A);
            }
            else if ((operation[4] == 'H') && (operation[5] == '\0')) //POP_H
            {
                cin >> w >> p >> A;
                POP_H(w,p,A);
            }
            else if ((operation[4] == 'R') && (operation[5] == '\0')) //POP_R
            {
                cin >> s >> p >> A;
                POP_R(s,p,A);
            }
            else if ((operation[4] == 'S') && (operation[5] == '\0')) //POP_S
            {
                cin >> p >> A;
                POP_S(p,A);
            }
        }
        else if (operation[0] == 'M')
        {
            if ((operation[4] == 'W' && (operation[5] == '\0'))) //MOV_W
            {
                cin >> w >> r >> s;
                cin >>w2 >> r2 >> s2;
                cin >> p >> A;
                MOV_W(w,r,s,w2,r2,s2,p,A);
            }
            else if ((operation[4] == 'H') && (operation[5] == '\0')) //MOV_H
            {
                cin >> w >> r >> s >> p >> A;
                MOV_H(w,r,s,p,A);
            }
            else if ((operation[4] == 'R') && (operation[5] == '\0')) //MOV_R
            {
                cin >> w >> r >> s;
                cin >> s2 >> p >> A;
                MOV_R(w,r,s,s2,p,A);
            }
            else if ((operation[4] == 'S') && (operation[5] == '\0')) //MOV_S
            {
                cin >> s >> p >> A;
                MOV_S(s,p,A);
            }

        }
        else if (operation[0] == 'G')
        {
            if((operation[4] == 'E') && (operation[5] == '\0')) //GET_E
            {
                GET_E();
            }
            else if((operation[4] == 'W') && (operation[5] == '\0')) //GET_W
            {
                cin >> w;
                GET_W(w);
            }
            else if((operation[4] == 'R') && (operation[5] == 'W') ) //GET_RW
            {
                cin >> w >> r;
                GET_RW(w, r);
            }
            else if((operation[4] == 'R') && (operation[5] == 'H') ) //GET_RH
            {
                GET_RH();
            }
            else if((operation[4] == 'S') && (operation[5] == 'W') ) //GET_SW
            {
                cin >> w >> r >> s;
                GET_SW(w, r, s);
            }
            else if((operation[4] == 'S') && (operation[5] == 'H') ) //GET_SH
            {
                cin >> w;
                GET_SH(w);
            }
            else if((operation[4] == 'S') && (operation[5] == 'R') ) //GET_SR
            {
                cin >> s;
                GET_SR(s);
            }
            else if((operation[4] == 'S') && (operation[5] == '\0')) //GET_S
            {
                GET_S();
            }
                //ETYKIETY
            else if((operation[4] == 'L') && (operation[5] == 'W')) //GET_LW
            {
                cin >> w >> r >> s >> p;
                GET_LW(w,r,s,p);
            }
            else if((operation[4] == 'L') && (operation[5] == 'H')) //GET_LH
            {
                cin >> w >> p;
                GET_LH(w, p);
            }
            else if((operation[4] == 'L') && (operation[5] == 'R')) //GET_LR
            {
                cin >> s >> p;
                GET_LR(s, p);
            }
            else if((operation[4] == 'L') && (operation[5] == 'S')) //GET_LS
            {
                cin >> p;
                GET_LS(p);
            }
        }
    }
    return 0;
}