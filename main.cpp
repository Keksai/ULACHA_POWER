//#include <Windows.h>
#include "wav.h";


int main()
{

    string dane[16];
    dane[0] = "ATrain.wav";
    dane[1] = "BeautySlept.wav";
    dane[2] = "chanchan.wav";
    dane[3] = "death2.wav";
    dane[4] = "experiencia.wav";
    dane[5] = "female_speech.wav";
    dane[6] = "FloorEssence.wav";
    dane[7] = "ItCouldBeSweet.wav";
    dane[8] = "Layla.wav";
    dane[9] = "LifeShatters.wav";
    dane[10] = "macabre.wav";
    dane[11] = "male_speech.wav";
    dane[12] = "SinceAlways.wav";
    dane[13] = "thear1.wav";
    dane[14] = "TomsDiner.wav";
    dane[15] = "velvet.wav";

    char *buff;
    CWav sample[16];

    fstream plik("log.txt", ios::out);

    for (int i = 0; i < 16; i++)
    {
        buff = new char[dane[i].length() + 1];
        strcpy(buff, dane[i].c_str());
        sample[i].init(buff);
        sample[i].energia();
        sample[i].entropia();
        sample[i].zapis();
    }

    //delete buff[];

    system("pause");
    return 0;
}
