//Kajetan Ozog
#include <iostream>
using namespace std;
int main()
{
    int ilosc_powtorzen = 0;
    double wygrane_a = 0;
    double wygrane_b = 0;
    double wygrane_c = 0;
    double wygrane_d = 0;
    double przegrane_a = 0;
    double przegrane_b = 0;
    double przegrane_c = 0;
    double przegrane_d = 0;
    double remisy_a = 0;
    double remisy_b = 0;
    double remisy_c = 0;
    double remisy_d = 0;
    cin >> ilosc_powtorzen;
    while (ilosc_powtorzen > 0) {
        ilosc_powtorzen--;
        char pierwszy;
        char wybor_1;
        char drugi;
        char wybor_2;
        int sila_1=0;
        int sila_2 = 0;
        cin >> pierwszy;
        cin >> wybor_1;
        cin >> sila_1;
        cin >> drugi;
        cin >> wybor_2;
        cin >> sila_2;
        int wynik = 0;
        if (wybor_1 == 'J' && wybor_2 == 'P') {         //Wygrane A
            wynik = 1;
        }
        if (wybor_1 == 'J' && wybor_2 == 'S') {
            wynik = 1;
        }
        if (wybor_1 == 'K' && wybor_2 == 'J') {
            wynik = 1;
        }
        if (wybor_1 == 'K' && wybor_2 == 'N') {
            wynik = 1;
        }
        if (wybor_1 == 'N' && wybor_2 == 'J') {
            wynik = 1;
        }
        if (wybor_1 == 'N' && wybor_2 == 'P') {
            wynik = 1;
        }
        if (wybor_1 == 'P' && wybor_2 == 'K') {
            wynik = 1;
        }
        if (wybor_1 == 'P' && wybor_2 == 'S') {
            wynik = 1;
        }
        if (wybor_1 == 'S' && wybor_2 == 'K') {
            wynik = 1;
        }
        if (wybor_1 == 'S' && wybor_2 == 'N') {
            wynik = 1;
        }
        if (wybor_2 == 'J' && wybor_1 == 'P') {         //Wygrane B
            wynik = 2;
        }
        if (wybor_2 == 'J' && wybor_1 == 'S') {
            wynik = 2;
        }
        if (wybor_2 == 'K' && wybor_1 == 'J') {
            wynik = 2;
        }
        if (wybor_2 == 'K' && wybor_1 == 'N') {
            wynik = 2;
        }
        if (wybor_2 == 'N' && wybor_1 == 'J') {
            wynik = 2;
        }
        if (wybor_2 == 'N' && wybor_1 == 'P') {
            wynik = 2;
        }
        if (wybor_2 == 'P' && wybor_1 == 'K') {
            wynik = 2;
        }
        if (wybor_2 == 'P' && wybor_1 == 'S') {
            wynik = 2;
        }
        if (wybor_2 == 'S' && wybor_1 == 'K') {
            wynik = 2;
        }
        if (wybor_2 == 'S' && wybor_1 == 'N') {
            wynik = 2;
        }
        if (wybor_1 == wybor_2) {               //Remis?
            if (sila_1 > sila_2) {
                wynik = 1;
            }
            if (sila_1 < sila_2) {
                wynik = 2;
            }
            if (sila_1 == sila_2) {
                wynik = 0;
            }
        }
        if (wynik == 0) {
            if (pierwszy == 'a') {
                remisy_a++;
            }
            if (pierwszy == 'b') {
                remisy_b++;
            }
            if (pierwszy == 'c') {
                remisy_c++;
            }
            if (pierwszy == 'd') {
                remisy_d++;
            }
            if (drugi == 'a') {
                remisy_a++;
            }
            if (drugi == 'b') {
                remisy_b++;
            }
            if (drugi == 'c') {
                remisy_c++;
            }
            if (drugi == 'd') {
                remisy_d++;
            }
        }
        if (wynik == 1) {
            if (pierwszy == 'a') {
                wygrane_a++;
            }
            if (pierwszy == 'b') {
                wygrane_b++;
            }
            if (pierwszy == 'c') {
                wygrane_c++;
            }
            if (pierwszy == 'd') {
                wygrane_d++;
            }
            if (drugi == 'a') {
                przegrane_a++;
            }
            if (drugi == 'b') {
                przegrane_b++;
            }
            if (drugi == 'c') {
                przegrane_c++;
            }
            if (drugi == 'd') {
                przegrane_d++;
            }
        }
        if (wynik == 2) {
            if (drugi == 'a') {
                wygrane_a++;
            }
            if (drugi == 'b') {
                wygrane_b++;
            }
            if (drugi == 'c') {
                wygrane_c++;
            }
            if (drugi == 'd') {
                wygrane_d++;
            }
            if (pierwszy == 'a') {
                przegrane_a++;
            }
            if (pierwszy == 'b') {
                przegrane_b++;
            }
            if (pierwszy == 'c') {
                przegrane_c++;
            }
            if (pierwszy == 'd') {
                przegrane_d++;
            }
        }
    }
    //Koniec petli
    if ((wygrane_a + remisy_a + przegrane_a) > 0) { //Dla a
        cout << "gracz a" << endl;
        if (wygrane_a > 0) {
            double wyg = (wygrane_a) / (wygrane_a + remisy_a + przegrane_a) * 100;
            cout << "    wygrane: " << wyg << "%" << endl;
        }
        if (remisy_a > 0) {
            double rem = (remisy_a) / (wygrane_a + remisy_a + przegrane_a) * 100;
            cout << "    remisy: " << rem << "%" << endl;
        }
        if (przegrane_a > 0) {
            double prz = (przegrane_a) / (wygrane_a + remisy_a + przegrane_a) * 100;
            cout << "    przegrane: " << prz << "%" << endl;
        }
        cout << endl;
    }
    if ((wygrane_b + remisy_b + przegrane_b) > 0) { //Dla b
        cout << "gracz b" << endl;
        if (wygrane_b > 0) {
            double wyg = (wygrane_b) / (wygrane_b + remisy_b + przegrane_b) * 100;
            cout << "    wygrane: " << wyg << "%" << endl;
        }
        if (remisy_b > 0) {
            double rem = (remisy_b) / (wygrane_b + remisy_b + przegrane_b) * 100;
            cout << "    remisy: " << rem << "%" << endl;
        }
        if (przegrane_b > 0) {
            double prz = (przegrane_b) / (wygrane_b + remisy_b + przegrane_b) * 100;
            cout << "    przegrane: " << prz << "%" << endl;
        }
        cout << endl;
    }
    if ((wygrane_c + remisy_c + przegrane_c) > 0) { //Dla c
        cout << "gracz c" << endl;
        if (wygrane_c > 0) {
            double wyg = (wygrane_c) / (wygrane_c + remisy_c + przegrane_c) * 100;
            cout << "    wygrane: " << wyg << "%" << endl;
        }
        if (remisy_c > 0) {
            double rem = (remisy_c) / (wygrane_c + remisy_c + przegrane_c) * 100;
            cout << "    remisy: " << rem << "%" << endl;
        }
        if (przegrane_c > 0) {
            double prz = (przegrane_c) / (wygrane_c + remisy_c + przegrane_c) * 100;
            cout << "    przegrane: " << prz << "%" << endl;
        }
        cout << endl;
    }
    if ((wygrane_d + remisy_d + przegrane_d) > 0) { //Dla d
        cout << "gracz d" << endl;
        if (wygrane_d > 0) {
            double wyg = (wygrane_d) / (wygrane_d + remisy_d + przegrane_d) * 100;
            cout << "    wygrane: " << wyg << "%" << endl;
        }
        if (remisy_d > 0) {
            double rem = (remisy_d) / (wygrane_d + remisy_d + przegrane_d) * 100;
            cout << "    remisy: " << rem << "%" << endl;
        }
        if (przegrane_d > 0) {
            double prz = (przegrane_d) / (wygrane_d + remisy_d + przegrane_d) * 100;
            cout << "    przegrane: " << prz << "%" << endl;
        }
        cout << endl;
    }
}
