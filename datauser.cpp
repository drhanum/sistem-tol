#include "DataUser.h"

DataUser::DataUser() {
    nomorKartu = "";
    tolMasuk = "";
    golongan = 0;
    saldo = 0;
}

DataUser::DataUser(string nomorKartu, string tolMasuk, int golongan, int saldo) {
    this->nomorKartu = nomorKartu;
    this->tolMasuk = tolMasuk;
    this->golongan = golongan;
    this->saldo = saldo;
}

string DataUser::getNomorKartu() {
    return nomorKartu;
}

string DataUser::getTolMasuk() {
    return tolMasuk;
}

int DataUser::getGolongan() {
    return golongan;
}

int DataUser::getSaldo() {
    return saldo;
}

void DataUser::setSaldo(int saldo) {
    this->saldo = saldo;
}