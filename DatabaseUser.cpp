#include "DatabaseUser.h"
#include <fstream>

json DatabaseUser::bacaData()
{
    ifstream file("user.json");

    if (!file.is_open())
    {
        return json::array();
    }

    json data;
    file >> data;

    file.close();

    return data;
}

void DatabaseUser::simpanData(json data)
{
    ofstream file("user.json");

    file << data.dump(4);

    file.close();
}

void DatabaseUser::tambahData(DataUser user)
{
    json data = bacaData();

    data.push_back({
        {"nomorKartu", user.getNomorKartu()},
        {"tolMasuk", user.getTolMasuk()},
        {"golongan", user.getGolongan()},
        {"saldo", user.getSaldo()}
    });

    simpanData(data);
}

bool DatabaseUser::kartuAda(string nomorKartu)
{
    json data = bacaData();

    for (auto &user : data)
    {
        if (user["nomorKartu"] == nomorKartu)
        {
            return true;
        }
    }

    return false;
}

bool DatabaseUser::ambilDataKartu(
    string nomorKartu,
    string &tolMasuk,
    int &golongan,
    int &saldo)
{
    json data = bacaData();

    for (auto &user : data)
    {
        if (user["nomorKartu"] == nomorKartu)
        {
            tolMasuk = user["tolMasuk"];
            golongan = user["golongan"];
            saldo = user["saldo"];

            return true;
        }
    }

    return false;
}

bool DatabaseUser::updateSaldo(string nomorKartu, int saldoBaru)
{
    json data = bacaData();

    for (auto& user : data)
    {
        if (user["nomorKartu"] == nomorKartu)
        {
            user["saldo"] = saldoBaru;
            user["tolMasuk"] = "none";

            simpanData(data);
            return true;
        }
    }

    return false;
}

void DatabaseUser::updateDataSetelahTransaksi(
    string nomorKartu,
    int saldoBaru,
    string tolMasukBaru
)
{
    json data = bacaData();

    for (auto &user : data)
    {
        if (user["nomorKartu"] == nomorKartu)
        {
            user["saldo"] = saldoBaru;
            user["tolMasuk"] = tolMasukBaru;
            break;
        }
    }

    simpanData(data);
}
