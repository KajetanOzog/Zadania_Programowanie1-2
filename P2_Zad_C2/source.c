//Kajetan Ozog
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int** ZwolnijBlok(int** array, int* dlugosc, int** wielkosci, int r, int h, int c, int w)
{
    if(h == 0 || w == 0)
    {
        return array;
    }

    int i = 0;
    while (i < h)
    {
        int stary = *dlugosc;
        if(r + i < *dlugosc)
        {
            if(c < *(*(wielkosci) + r + i))
            {
                int x = c + w - 1;
                if(x >= *(*(wielkosci) + r + i))
                {
                    x = *(*(wielkosci) + r + i) - 1;
                }
                int t = x - c + 1;
                int j;
                for(j = 1 ; x + j < *(*(wielkosci) + r + i); j++)
                {
                    *(*(array + r + i) + c + j - 1) = *(*(array + r + i) + x + j);
                }
                *(*(wielkosci) + r + i) = *(*(wielkosci) + r + i) - t;
                if(*(*(wielkosci) + r + i) == 0)
                {
                    free(*(array + r + i));
                    *dlugosc = *dlugosc - 1;
                    for(j = r + i; j < *dlugosc; j++)
                    {
                        *(array + j) = *(array + j + 1);
                        *(*wielkosci + j) = *(*wielkosci + j + 1);
                    }
                    array = (int**)realloc(array, *dlugosc * sizeof(int*));
                    *wielkosci = (int*)realloc(*wielkosci, *dlugosc * sizeof(int));
                }
                else
                {
                    *(array + r + i) = (int*)realloc(*(array + r + i), *(*(wielkosci) + r + i) * sizeof(int));
                }
            }
        }
        if(stary == *dlugosc)
        {
            i = i + 1;
        }
        else
        {
            h = h - 1;
        }
    }
    return array;
}

int** DodajWiersz(int** array, int* wiersz, int wierszSize, int na_miejsce, int* wiersze, int** dlugosc)
{
    *wiersze = *wiersze + 1;
    *dlugosc = (int*)realloc(*dlugosc, *wiersze * sizeof(int));
    array = (int**)realloc(array, *wiersze * sizeof(int*));
    int i;
    for(i = *wiersze - 1; i > na_miejsce; i--)
    {
        *(array + i) = *(array + i - 1);
        *(*(dlugosc) + i) = *(*(dlugosc) + i - 1);
    }
    *(array + na_miejsce) = wiersz;
    *(*(dlugosc)+ na_miejsce) = wierszSize;
    return array;
}

int** DodajBlok(int** array, int* dlugosc, int** wielkosci, int r, int c, int h, int w, int** blok, int wymiar)
{

    int i;
    int org_c = c;
    for (i = 0; i < h; i++)
    {
        c = org_c;
        int curr = i + r;
        int* wiersz = *(blok + i);
        if(curr < *dlugosc)
        {
            int stary_rozmiar = *(*wielkosci + curr);
            if(c > *(*wielkosci + curr))
            {
                c = *(*wielkosci + curr);
            }
            int to = c + w;
            *(*wielkosci + curr) = *(*wielkosci + curr) + w;
            *(array + curr) = (int*)realloc(*(array + curr), *(*wielkosci + curr) * sizeof(int));
            int j;
            int from = -1;
            for(j = *(*wielkosci + curr) - 1 ; j >= to; j--)
            {
                *(*(array + curr) + j) = *(*(array + curr) + stary_rozmiar + from);
                from--;
            }
            for(j = 0; j < w; j++)
            {
                *(*(array + curr) + j + c) = *(wiersz + j);
            }
            free(wiersz);
        }
        else
        {
            *dlugosc = *dlugosc + 1;
            *wielkosci = (int*)realloc(*wielkosci, *dlugosc * sizeof(int));
            array = (int**)realloc(array, *dlugosc * sizeof(int*));
            *(array + *dlugosc - 1) = wiersz;
            *(*(wielkosci)+ *dlugosc - 1) = w;
        }
    }
    if(wymiar == 2)
    {
        free(blok);
    }
    return array;
}

int* naTab(int rozmiar)
{
    int* nowa = (int*)malloc(rozmiar * sizeof(int));
    int i;
    for(i = 0; i < rozmiar; i++)
    {
        scanf("%d", (nowa + i));
    }
    return nowa;
}


int main()
{
    int** array = (int**)malloc(1 * sizeof(int*));
    *(array + 0)  = (int*)malloc(1 * sizeof(int));
    int* wielkosci = (int*)malloc(1 * sizeof(int));
    int dlugosc = 0;
    int* wsk_dlugosc = &dlugosc;

    char* tekst  = malloc(4);
    scanf("%s", tekst);
    while (strcmp(tekst, "END") != 0)
    {
        if(strcmp(tekst, "PRT") == 0)
        {
            printf("%i\n", dlugosc);
            int i;
            for( i = 0; i < dlugosc; i++)
            {
                printf("%i", *(wielkosci + i));
                int j;
                for( j = 0; j < *(wielkosci + i); j++)
                {
                    printf(" %i", *(*(array + i) + j));
                }
                printf("\n");
            }
        }
        else if(strcmp(tekst, "AFR") == 0)
        {
            int Row;
            scanf("%d", &Row);
            if(Row >= 1 && Row <= 65535)
            {
                int* nowy_wiersz = naTab(Row);
                array = DodajWiersz(array, nowy_wiersz, Row, 0, wsk_dlugosc, &wielkosci);
            }
        }
        else if(strcmp(tekst, "ALR") == 0)
        {
            int Row;
            scanf("%d", &Row);
            if(Row >= 1 && Row <= 65535)
            {
                int* newRow = naTab(Row);
                array = DodajWiersz(array, newRow, Row, dlugosc, wsk_dlugosc, &wielkosci);
            }
        }
        else if(strcmp(tekst, "AFC") == 0)
        {
            int Col;
            scanf("%d", &Col);
            if(Col >= 1 && Col <= 65535)
            {
                int* newCol = naTab(Col);
                if(Col <= dlugosc)
                {
                    int i;
                    for(i = 0; i < Col; i++)
                    {
                        (*(wielkosci + i) )= (*(wielkosci + i)) + 1;
                        *(array + i) = (int*)realloc(*(array + i), *(wielkosci + i) * sizeof(int));
                    }
                    for(i = 0; i < Col; i++)
                    {
                        int j;
                        for(j = *(wielkosci + i) - 1; j > 0; j--)
                        {
                            *(*(array + i) + j) = *(*(array + i) + j - 1);
                        }
                    }
                    for(i = 0; i < Col; i++)
                    {
                        *(*(array + i) + 0) = *(newCol + i);
                    }
                }
                else
                {
                    int i;
                    for(i = 0; i < dlugosc; i++)
                    {
                        (*(wielkosci + i) )= (*(wielkosci + i)) + 1;
                        *(array + i) = (int*)realloc(*(array + i), *(wielkosci + i) * sizeof(int));
                    }
                    for(i = 0; i < dlugosc; i++)
                    {
                        int j;
                        for(j = *(wielkosci + i) - 1; j > 0; j--)
                        {
                            *(*(array + i) + j) = *(*(array + i) + j - 1);
                        }
                    }
                    for(i = 0; i < dlugosc; i++)
                    {
                        *(*(array + i) + 0) = *(newCol + i);
                    }

                    int roznica = Col - dlugosc;

                    for(i = 0; i < roznica; i++)
                    {
                        int* pom = (int*)malloc(sizeof(int));
                        *(pom + 0) = *(newCol + Col - roznica + i);
                        array = DodajWiersz(array, pom, 1, dlugosc, wsk_dlugosc, &wielkosci);
                    }
                }
                free(newCol);
            }
        }
        else if(strcmp(tekst, "ALC") == 0)
        {
            int Col;
            scanf("%d", &Col);
            if(Col >= 1 && Col <= 65535)
            {
                int* newCol = naTab(Col);
                if(Col <= dlugosc)
                {
                    int i;
                    for(i = 0; i < Col; i++)
                    {
                        (*(wielkosci + i) ) = (*(wielkosci + i)) + 1;
                        *(array + i) = (int*)realloc(*(array + i), *(wielkosci + i) * sizeof(int));
                    }
                    for(i = 0; i < Col; i++)
                    {
                        *(*(array + i) - 1 + *(wielkosci + i)) = *(newCol + i);
                    }
                }
                else
                {
                    int i;
                    for(i = 0; i < dlugosc; i++)
                    {
                        (*(wielkosci + i) )= (*(wielkosci + i)) + 1;
                        *(array + i) = (int*)realloc(*(array + i), *(wielkosci + i) * sizeof(int));
                    }
                    for(i = 0; i < dlugosc; i++)
                    {
                        *(*(array + i) - 1 + *(wielkosci + i)) = *(newCol + i);
                    }

                    int roznica = Col - dlugosc;

                    for(i = 0; i < roznica; i++)
                    {
                        int* pom = (int*)malloc(sizeof(int));
                        *(pom + 0) = *(newCol + Col - roznica + i);
                        array = DodajWiersz(array, pom, 1, dlugosc, wsk_dlugosc, &wielkosci);
                    }
                }
                free(newCol);
            }
        }
        else if(strcmp(tekst, "IBR") == 0)
        {
            int r;
            int Row;
            scanf("%d %d", &r, &Row);
            int* newRow = naTab(Row);
            if(r < dlugosc)
            {
                array = DodajWiersz(array, newRow, Row, r, wsk_dlugosc, &wielkosci);
            }
            else
            {
                free(newRow);
            }

        }
        else if(strcmp(tekst, "IAR") == 0)
        {
            int r;
            int Row;
            scanf("%d %d", &r, &Row);
            int* newRow = naTab(Row);
            if(r < dlugosc)
            {
                array = DodajWiersz(array, newRow, Row, r + 1, wsk_dlugosc, &wielkosci);
            }
            else
            {
                free(newRow);
            }
        }
        else if(strcmp(tekst, "IBC") == 0)
        {
            int c;
            int Cols;
            scanf("%d %d", &c, &Cols);
            //int* newCol = naTab(Cols);
            int** blok = (int**)malloc(Cols * sizeof(int*));
            int i;
            for(i = 0; i < Cols; i++)
            {
                *(blok + i)  = (int*)malloc(1 * sizeof(int));
                int kolumna;
                scanf("%d", &kolumna);
                *(*(blok + i) + 0) = kolumna;
            }
            array = DodajBlok(array, wsk_dlugosc, &wielkosci, 0, c, Cols, 1,  blok, 2);
        }
        else if(strcmp(tekst, "IAC") == 0)
        {
            int c;
            int Col;
            scanf("%d %d", &c, &Col);
            //int* newCol = naTab(Col);
            int** blok = (int**)malloc(Col * sizeof(int*));
            int i;
            for(i = 0; i < Col; i++)
            {
                *(blok + i)  = (int*)malloc(1 * sizeof(int));
                int kolumna;
                scanf("%d", &kolumna);
                *(*(blok + i) + 0) = kolumna;
            }
            array = DodajBlok(array, wsk_dlugosc, &wielkosci, 0, c + 1, Col, 1, blok, 2);
        }
        else if(strcmp(tekst, "SWR") == 0)
        {
            int r;
            int s;
            scanf("%d %d", &r, &s);
            if(r < dlugosc && s < dlugosc)
            {
                int * pom1 = *(array + r);
                *(array + r) = *(array + s);
                *(array + s) = pom1;
                int pom = *(wielkosci + r);
                *(wielkosci + r) = *(wielkosci + s);
                *(wielkosci + s) = pom;
            }
        }
        else if(strcmp(tekst, "SWC") == 0)
        {
            int c;
            int d;
            scanf("%d %d", &c, &d);
            int i;
            for(i = 0; i < dlugosc; i++)
            {
                if(c < *(wielkosci + i) && d < *(wielkosci + i))
                {
                    int pom1 = *(*(array + i) + c);
                    *(*(array + i) + c) = *(*(array + i) + d);
                    *(*(array + i) + d) = pom1;
                }
            }
        }
        else if(strcmp(tekst, "DFR") == 0)
        {
            if(dlugosc != 0)
            {
                array = ZwolnijBlok(array, wsk_dlugosc, &wielkosci, 0, 1, 0, *(wielkosci + 0));
            }
        }
        else if(strcmp(tekst, "DLR") == 0)
        {
            if(dlugosc != 0)
            {
                array = ZwolnijBlok(array, wsk_dlugosc, &wielkosci, dlugosc - 1, 1, 0, *(wielkosci + dlugosc - 1));
            }
        }
        else if(strcmp(tekst, "DFC") == 0)
        {
            if(dlugosc != 0)
            {
                array = ZwolnijBlok(array, wsk_dlugosc, &wielkosci, 0, dlugosc, 0, 1);
            }
        }
        else if(strcmp(tekst, "DLC") == 0)
        {
            if(dlugosc != 0)
            {
                int i = 0;
                while(i < dlugosc)
                {
                    int staraDlugosc = dlugosc;
                    array = ZwolnijBlok(array, wsk_dlugosc, &wielkosci, i, 1, *(wielkosci + i) - 1, 1);
                    if(staraDlugosc == dlugosc)
                    {
                        i++;
                    }
                }
            }
        }
        else if(strcmp(tekst, "RMR") == 0)
        {
            int r;
            scanf("%d", &r);
            if(r < dlugosc)
            {
                array = ZwolnijBlok(array, wsk_dlugosc, &wielkosci, r, 1, 0, *(wielkosci + r));
            }
        }
        else if(strcmp(tekst, "RMC") == 0)
        {
            if(dlugosc != 0)
            {
                int c;
                scanf("%d", &c);
                array = ZwolnijBlok(array, wsk_dlugosc, &wielkosci, 0, dlugosc, c, 1);
            }

        }
        else if(strcmp(tekst, "RMB") == 0)
        {
            if(dlugosc != 0)
            {
                int r, c, h, w;
                scanf("%d %d %d %d", &r, &h, &c, &w);
                array = ZwolnijBlok(array, wsk_dlugosc, &wielkosci, r, h, c, w);
            }
        }
        else if(strcmp(tekst, "ISB") == 0)
        {
            int r, c, h, w;
            scanf("%d %d %d %d", &r, &c, &h, &w);
            int** blok = (int**)malloc(h * sizeof(int*));
            int i;
            for(i = 0; i < h; i++)
            {
                *(blok + i)  = (int*)malloc(w * sizeof(int));
                int j;
                for(j = 0; j < w; j++)
                {
                    int Col;
                    scanf("%d", &Col);
                    *(*(blok + i) + j) = Col;
                }
            }
            array = DodajBlok(array, wsk_dlugosc, &wielkosci, r, c, h, w, blok, 2);
        }
        else if(strcmp(tekst, "WRF") == 0)
        {
            char *nazwaPliku = (char*) malloc(16 * sizeof(char));

            scanf("%s", nazwaPliku);

            FILE* fp = fopen(nazwaPliku, "wb");

            fprintf(fp, "%d\n", dlugosc);

            int i;
            for (i = 0; i < dlugosc; i++)
            {
                int Row = *(wielkosci + i);

                unsigned char *RowTab = (char*) malloc(2 * sizeof(unsigned char));

                *(RowTab + 1) = Row & 255;
                *(RowTab + 0) = (Row >> 8) & 255;

                fwrite(RowTab, sizeof(unsigned char), 2, fp);

                int j;
                for (j = 0; j < Row; j++)
                {
                    int Col =  *(*(array + i) + j);

                    unsigned char *ColTab = (char*) malloc(4 * sizeof(unsigned char));
                    *(ColTab + 3) = Col & 255;
                    *(ColTab + 2) = (Col >> 8) & 255;
                    *(ColTab + 1) = (Col >> 16) & 255;
                    *(ColTab + 0) = (Col >> 24) & 255;

                    fwrite(ColTab, sizeof(unsigned char), 4, fp);
                    free(ColTab);
                }
                free(RowTab);
            }
            fclose(fp);
            free(nazwaPliku);
        }
        else if(strcmp(tekst, "RDF") == 0)
        {
            char *nazwaPliku = (char*) malloc(16 * sizeof(char));
            scanf("%s", nazwaPliku);

            int i;
            for (i = 0; i < dlugosc; i++)
            {
                free(*(array + i));
            }
            dlugosc = 0;
            free(array);
            free(wielkosci);

            FILE* fp = fopen(nazwaPliku, "rb");
            unsigned short Row = 0;
            int kontynuacja = 1;
            while (kontynuacja)
            {
                unsigned char znak;
                fread(&znak, sizeof(unsigned char), 1, fp);
                if (znak != '\n')
                {
                    Row = Row * 10;
                    Row = Row + (znak - '0');
                }
                else
                {
                    kontynuacja = 0;
                }
            }
            dlugosc = Row;

            array = (int**) malloc (dlugosc * sizeof(int*));
            wielkosci = (int*)malloc(dlugosc * sizeof(int));

            for (i = 0; i < dlugosc; i++){
                unsigned char* Roww = (char*) malloc(2 * sizeof(char));

                fread(Roww, sizeof(unsigned char), 2, fp);

                int x = 0;
                int k;
                for (k = 0; k < 2; k++)
                {
                    x =( (x << 8) | *(Roww + k));
                }
                int kolumna = x;

                *(array + i) = (int*) malloc ((kolumna + 1) * sizeof(int));
                *(wielkosci + i) = kolumna;

                free(Roww);

                int j;
                for (j = 0; j < *(wielkosci + i); j++)
                {
                    unsigned char* Col = (char*) malloc(4 * sizeof(unsigned char));
                    fread(Col, sizeof(unsigned char), 4, fp);

                    int y = 0;
                    int l;
                    for (l = 0; l < 4; l++)
                    {
                        y = ((y << 8) | *(Col + l));
                    }

                    *(*(array + i) + j) = y;
                    free(Col);
                }
            }
            fclose(fp);
            free(nazwaPliku);
        }
        scanf("%s", tekst);
    }
    free(tekst);


    int i;
    for(i = 0; i < dlugosc; i++)
    {
        free(*(array + i));
    }
    free(wielkosci);
    free(array);
    return 0;
}