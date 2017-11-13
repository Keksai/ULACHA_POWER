#ifndef WAV_H
#define WAV_H


#pragma once
#include <iostream>
//#include <Windows.h>
#include <fstream>
#include <cstring>
#include <curses.h>


using namespace std;
typedef unsigned long DWORD;

struct h_wav
{
    char  id[4];
    DWORD rozmiar;

};

class CWav
{
private:
    FILE *plik = NULL;
    float rozmiar;
    char *nazwa;
    short **tablica;
    float energia_sL = 0;
    float energia_sR = 0;
    float entropia_L = 0;
    float entropia_R = 0;

public:
    h_wav naglowek;
    void pokaz_probki(int od,int ile);

    void energia();
    void entropia();
    void zapis();
    void init(char *name);
    CWav();
    ~CWav();
};
#endif
