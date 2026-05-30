#ifndef DATABASEUSER_H
#define DATABASEUSER_H

#include <iostream>
#include <fstream>
#include "json.hpp"
#include "DataUser.h"

using namespace std;
using json = nlohmann::json;

class DatabaseUser {
    public:
        bool kartuAda(string nomorKartu);
        bool ambilDataKartu(string nomorKartu, string &tolMasuk, int &golongan, int &saldo);

        void tambahData(DataUser user);
        bool updateSaldo(string nomorKartu, int saldo);

    private:
        json bacaData();
        void simpanData(json data);
};

#endif