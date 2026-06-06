#include <iostream>
#include <algorithm>

#include "DataUser.h"
#include "DatabaseUser.h"
#include "ValidasiKartu.h"
#include "Tarif.h"

using namespace std;

string toLower(string text)
{
    transform(
        text.begin(),
        text.end(),
        text.begin(),
        ::tolower
    );

    return text;
}

int main()
{
    DatabaseUser db;
    ValidasiKartu validasi;
    Tarif transaksi;

    bool running = true;

    while (running)
    {
        cout << "\n===== SISTEM TOL =====" << endl;

        string nomorKartu;

        while (true)
        {
            cout << "\nInput Nomor Kartu (0 untuk keluar): ";
            getline(cin >> ws, nomorKartu);

            if (nomorKartu == "0")
            {
                running = false;
                break;
            }

            nomorKartu.erase(
                remove(
                    nomorKartu.begin(),
                    nomorKartu.end(),
                    ' '
                ),
                nomorKartu.end()
            );

            if (validasi.cekKartu(nomorKartu))
            {
                break;
            }
        }

        if (!running)
        {
            cout << "\nTerima Kasih" << endl;
            break;
        }

        // ==========================
        // KARTU BELUM TERDAFTAR
        // ==========================

        if (!db.kartuAda(nomorKartu))
        {
            cout << "\nStatus Kartu : Belum Terdaftar" << endl;

            string tolMasuk;

            cout << "\n===== TOL MASUK =====" << endl;
            cout << "Pilihan : Tangerang | Depok | Bogor" << endl;

            while (true)
            {
                cout << "Input Tol Masuk : ";
                cin >> tolMasuk;

                tolMasuk = toLower(tolMasuk);

                if (tolMasuk == "tangerang" ||
                    tolMasuk == "depok" ||
                    tolMasuk == "bogor")
                {
                    break;
                }

                cout << "Tol Tidak Tersedia" << endl;
            }

            int golongan;

            while (true)
            {
                cout << "Input Golongan Kendaraan (1-5) : ";
                cin >> golongan;

                if (golongan >= 1 && golongan <= 5)
                {
                    break;
                }

                cout << "Golongan Invalid" << endl;
            }

            int saldo;

            while (true)
            {
                cout << "Input Saldo Awal : ";
                cin >> saldo;

                if (saldo >= 0)
                {
                    break;
                }

                cout << "Saldo Invalid" << endl;
            }

            DataUser user(
                nomorKartu,
                tolMasuk,
                golongan,
                saldo
            );

            db.tambahData(user);

            cout << "\nKartu Berhasil Didaftarkan" << endl;
        }

        // ==========================
        // KARTU SUDAH TERDAFTAR
        // ==========================

        else 
        {
            string tolMasuk;
            int golongan;
            int saldo;

            db.ambilDataKartu(
                nomorKartu,
                tolMasuk,
                golongan,
                saldo
            );

            // cout << "\nDEBUG" << endl;
            // cout << "Nomor Kartu : " << nomorKartu << endl;
            // cout << "Tol Masuk   : [" << tolMasuk << "]" << endl;
            // cout << "Golongan    : " << golongan << endl;
            // cout << "Saldo       : " << saldo << endl;

            // Jika belum masuk tol
            if (tolMasuk == "none")
            {
                cout << "\nStatus Kartu : Sudah Terdaftar" << endl;
                cout << "Silakan Input Tol Masuk" << endl;

                string tolMasukBaru;

                cout << "\n===== TOL MASUK =====" << endl;
                cout << "Pilihan : Tangerang | Depok | Bogor" << endl;

                while (true)
                {
                    cout << "Input Tol Masuk : ";
                    cin >> tolMasukBaru;

                    tolMasukBaru = toLower(tolMasukBaru);

                    if (tolMasukBaru == "tangerang" ||
                        tolMasukBaru == "depok" ||
                        tolMasukBaru == "bogor")
                    {
                        break;
                    }

                    cout << "Tol Tidak Tersedia" << endl;
                }

                db.updateDataSetelahTransaksi(
                    nomorKartu,
                    saldo,
                    tolMasukBaru
                );

                cout << "\nBerhasil Masuk Tol" << endl;
            }

            // Jika sudah masuk tol
            else
            {
                cout << "\nStatus Kartu : Sudah Terdaftar" << endl;

                string tolKeluar;

                cout << "\n===== TOL KELUAR =====" << endl;
                cout << "Pilihan : Jakarta | Bandung | Bekasi" << endl;

                while (true)
                {
                    cout << "Input Tol Keluar : ";
                    cin >> tolKeluar;

                    tolKeluar = toLower(tolKeluar);

                    if (tolKeluar == "jakarta" ||
                        tolKeluar == "bandung" ||
                        tolKeluar == "bekasi")
                    {
                        break;
                    }

                    cout << "Tol Tidak Tersedia" << endl;
                }

                transaksi.prosesTarif(
                    nomorKartu,
                    tolKeluar
                );
            }
        }
    }
    return 0;
}