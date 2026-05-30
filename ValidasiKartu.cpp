#include "ValidasiKartu.h"

bool ValidasiKartu::cekKartu(string nomorKartu)
{
    if (nomorKartu.length() != 16)
    {
        cout << "Nomor Kartu Invalid" << endl;
        return false;
    }

    string kodeBank = nomorKartu.substr(0, 4);

    if (kodeBank == "6032" ||
        kodeBank == "1231" ||
        kodeBank == "5326" ||
        kodeBank == "6019" ||
        kodeBank == "1020")
    {
        cout << "Bank Valid, Silahkan Lanjut" << endl;
        return true;
    }

    cout << "Bank Tidak Terdaftar" << endl;
    return false;
}