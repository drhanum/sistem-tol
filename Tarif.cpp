#include "Tarif.h"
#include "RuteTol.h"
#include <map>
#include <cmath>

int Tarif::hitungTarif( string masuk, string keluar, int golongan)
{
    map<string, int> line1 = {
        {"gttangerang", 0},
        {"cawang", 1},
        {"cibitung", 2},
        {"gtbuahbatu", 3}
    };

    map<string, int> line2 = {
        {"gtpondokaren", 0},
        {"depok", 1},
        {"gtsentul", 2},
        {"gtbogor", 3}
    };

    map<string, int> line3 = {
        {"gtciawi", 0},
        {"cikarang", 1},
        {"gtjatiluhur", 2},
        {"gtpadalarang", 3}
    };

    int jarak = -1;

    if (line1.count(masuk) && line1.count(keluar))
    {
        jarak = abs(
            line1[masuk] -
            line1[keluar]
        );
    }
    else if (line2.count(masuk) && line2.count(keluar))
    {
        jarak = abs(
            line2[masuk] -
            line2[keluar]
        );
    }
    else if (line3.count(masuk) && line3.count(keluar))
    {
        jarak = abs(
            line3[masuk] -
            line3[keluar]
        );
    }

    if (jarak <= 0)
    {
        return -1;
    }

    int tarifDasar = 20000 * jarak;

    switch (golongan)
    {
        case 1:
            return tarifDasar;

        case 2:
        case 3:
            return tarifDasar * 1.5;

        case 4:
        case 5:
            return tarifDasar * 2;

        default:
            return -1;
    }
}

void Tarif::prosesTarif(string nomorKartu, string tolKeluar)
{
    DatabaseUser db;

    string tolMasuk;
    int golongan;
    int saldo;

    if (!db.ambilDataKartu(
            nomorKartu,
            tolMasuk,
            golongan,
            saldo))
    {
        cout << "Kartu Tidak Ditemukan" << endl;
        return;
    }

    RuteTol rute;

    if (!rute.cekRute(tolMasuk, tolKeluar))
    {
        cout << "Rute Tidak Valid" << endl;
        return;
    }

    int tarif = hitungTarif(
        tolMasuk,
        tolKeluar,
        golongan
    );

    if (tarif == -1)
    {
        cout << "Rute Tidak Valid" << endl;
        return;
    }

    cout << "\n===== INFORMASI TARIF =====" << endl;
    cout << "Tol Masuk : " << tolMasuk << endl;
    cout << "Tol Keluar : " << tolKeluar << endl;
    cout << "Golongan : " << golongan << endl;
    cout << "Tarif : " << tarif << endl;

    while (saldo < tarif)
    {
        cout << "\nSaldo Tidak Cukup" << endl;
        cout << "Saldo Saat Ini : " << saldo << endl;

        int topup;

        cout << "Input Top-up Saldo : ";
        cin >> topup;

        if (topup > 0)
        {
            saldo += topup;
            cout << "Top-up Berhasil" << endl;
        }
        else
        {
            cout << "Nominal Top-up Tidak Valid" << endl;
        }
    }

    saldo -= tarif;

    db.updateDataSetelahTransaksi(
        nomorKartu,
        saldo,
        "none"
    );

    cout << "\n===== PEMBAYARAN BERHASIL =====" << endl;
    cout << "Tarif : " << tarif << endl;
    cout << "Sisa Saldo : " << saldo << endl;
}

