#include "Tarif.h"

int Tarif::hitungTarif(string masuk, string keluar, int golongan)
{
    if (masuk == "tangerang" && keluar == "jakarta")
    {
        if (golongan == 1)
            return 26000;
        else if (golongan == 2 || golongan == 3)
            return 39000;
        else
            return 51000;
    }

    else if (masuk == "tangerang" && keluar == "bandung")
    {
        if (golongan == 1)
            return 109500;
        else if (golongan == 2 || golongan == 3)
            return 168000;
        else
            return 225500;
    }

    else if (masuk == "tangerang" && keluar == "bekasi")
    {
        if (golongan == 1)
            return 54000;
        else if (golongan == 2 || golongan == 3)
            return 81000;
        else
            return 106500;
    }

    else if (masuk == "depok" && keluar == "jakarta")
    {
        if (golongan == 1)
            return 32000;
        else if (golongan == 2 || golongan == 3)
            return 48000;
        else
            return 63500;
    }

    else if (masuk == "depok" && keluar == "bandung")
    {
        if (golongan == 1)
            return 136500;
        else if (golongan == 2 || golongan == 3)
            return 205000;
        else
            return 273000;
    }

    else if (masuk == "depok" && keluar == "bekasi")
    {
        if (golongan == 1)
            return 54000;
        else if (golongan == 2 || golongan == 3)
            return 81000;
        else
            return 106500;
    }

    else if (masuk == "depok" && keluar == "jakarta")
    {
        if (golongan == 1)
            return 32000;
        else if (golongan == 2 || golongan == 3)
            return 48000;
        else
            return 63500;
    }

    else if (masuk == "depok" && keluar == "bandung")
    {
        if (golongan == 1)
            return 136500;
        else if (golongan == 2 || golongan == 3)
            return 205000;
        else
            return 273000;
    }

    else if (masuk == "depok" && keluar == "bekasi")
    {
        if (golongan == 1)
            return 136500;
        else if (golongan == 2 || golongan == 3)
            return 205000;
        else
            return 273000;
    }

    else if (masuk == "depok" && keluar == "bekasi")
    {
        if (golongan == 1)
            return 70500;
        else if (golongan == 2 || golongan == 3)
            return 106000;
        else
            return 141500;
    }

    else if (masuk == "bogor" && keluar == "jakarta")
    {
        if (golongan == 1)
            return 20500;
        else if (golongan == 2 || golongan == 3)
            return 31000;
        else
            return 41500;
    }

    else if (masuk == "bogor" && keluar == "tangerang")
    {
        if (golongan == 1)
            return 20500;
        else if (golongan == 2 || golongan == 3)
            return 31000;
        else
            return 41500;
    }

    else if (masuk == "bogor" && keluar == "bandung")
    {
        if (golongan == 1)
            return 118000;
        else if (golongan == 2 || golongan == 3)
            return 177500;
        else
            return 237500;
    }

    else if (masuk == "bogor" && keluar == "bekasi")
    {
        if (golongan == 1)
            return 62000;
        else if (golongan == 2 || golongan == 3)
            return 93500;
        else
            return 125000;
    }

    return -1;
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

