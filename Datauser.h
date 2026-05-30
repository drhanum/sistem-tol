#ifndef DATAUSER_H
#define DATAUSER_H

#include <iostream>
using namespace std;

class DataUser {
    protected:
        string nomorKartu;
        string tolMasuk;
        int golongan;
        int saldo;

    public:
        DataUser();
        DataUser(string nomorKartu, string tolMasuk, int golongan, int saldo);

        string getNomorKartu();
        string getTolMasuk();
        int getGolongan();
        int getSaldo();

        void setSaldo(int saldo);
};

#endif