#ifndef TARIF_H
#define TARIF_H

#include "DatabaseUser.h"
#include <iostream>

using namespace std;

class Tarif {
    private:
        int hitungTarif(string masuk, string keluar, int golongan);

    public:
        void prosesTarif(string nomorKartu, string tolKeluar);
};

#endif