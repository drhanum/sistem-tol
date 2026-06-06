#ifndef RUTETOL_H
#define RUTETOL_H

#include <iostream>
#include <vector>

using namespace std;

class RuteTol
{
    public:
        bool cekRute(string tolMasuk, string tolKeluar);
        bool validTolMasuk(string gerbang);
        bool validTolKeluar(string gerbang);
        vector<string> getPilihanKeluar(string tolMasuk);
};

#endif