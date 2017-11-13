#include "wav.h"
#include <cmath>


void CWav::init(char *name)
{
    plik = fopen(name, "rb");
    nazwa = name;
    fread(&naglowek, sizeof(h_wav), 1, plik);

    rozmiar = ((naglowek.rozmiar + 8) - 46)/4;
    fseek(plik, 46, SEEK_SET);
    tablica = new short *[(unsigned int)rozmiar];
    for (int i = 0; i < rozmiar; i++)
    {
        tablica[i] = new short[2];
        fread(&tablica[i][0], sizeof(short), 1, plik);
        fread(&tablica[i][1], sizeof(short), 1, plik);
    }
    fclose(plik);
}
CWav::~CWav()
{
}

CWav::CWav()
{
}
void CWav::pokaz_probki(int od,int ile)
{
    for (int i = od; i < (od+ile); i++)
    {
        cout <<"Probka nr. "<<i<<": "<< tablica[i][0] << "   " << tablica[i][1] << endl;
    }
}
void CWav::energia()
{
    energia_sL = tablica[0][0] * tablica[0][0];
    energia_sR = tablica[0][1] * tablica[0][1];
    for (int i = 1; i < rozmiar; i++)
    {
        energia_sL += ((tablica[i][0] - tablica[i - 1][0])*(tablica[i][0] - tablica[i - 1][0]));
        energia_sR += ((tablica[i][1] - tablica[i - 1][1])*(tablica[i][1] - tablica[i - 1][1]));
    }
}

void CWav::entropia()
{
    int *buff_Lp = new int[65537];
    int *buff_Lm = new int[65537];
    int *buff_Rp = new int[65537];
    int *buff_Rm = new int[65537];
    for (int i = 0; i < 65537; i++)
    {
        buff_Lp[i] = 0.0;
        buff_Lm[i] = 0.0;
        buff_Rp[i] = 0.0;
        buff_Rm[i] = 0.0;
    }
    int index;
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablica[i][0] >= 0)
        {
            index = tablica[i][0];
            buff_Lp[index] += 1.0;
        }
        else
        {
            index = tablica[i][0] * -1;
            buff_Lm[index] += 1.0;
        }

        if (tablica[i][1] >= 0)
        {
            index = tablica[i][1];
            buff_Rp[index] += 1.0;
        }
        else
        {
            index = tablica[i][1] * -1;
            buff_Rm[index] += 1.0;
        }
    }
    float xx;
    float bx;
    for (int i = 0; i < 65537; i++)
    {
        if (buff_Lp[i] != 0)
        {
            xx = buff_Lp[i] / rozmiar;
            bx = log2(xx);
            xx *= bx;
            entropia_L += xx;
        }
        if (buff_Lm[i] != 0)
        {
            xx = buff_Lm[i] / rozmiar;

            bx = log2(xx);
            xx *= bx;

            entropia_L += xx;
        }
        if (buff_Rp[i] != 0)
        {
            xx = buff_Rp[i] / rozmiar;
            bx = log2(xx);
            xx *= bx;
            entropia_R += xx;
        }
        if (buff_Rm[i] != 0)
        {
            xx = buff_Rm[i] / rozmiar;
            bx = log2(xx);
            xx *= bx;
            entropia_R += xx;
        }
    }

}

void CWav::zapis()
{
    cout << "****************************************************************" << endl;
    cout << "Nazwa pliku: " << nazwa << endl;
    cout << "Energia kanalu lewego: ";  printf("%f\n", energia_sL/rozmiar);
    cout << "Energia kanalu prawego: "; printf("%f\n", energia_sR /rozmiar);
    cout << "Entropia L: ";
    printf("%.10fl\n", -1 * entropia_L);
    cout << "Entropia R: ";
    printf("%.10fl\n", -1 * entropia_R);
    cout << "****************************************************************" << endl;
}
