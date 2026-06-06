#include "RuteTol.h"

bool RuteTol::cekRute(string tolMasuk, string tolKeluar)
{
    vector<vector<string>> jalur = {
        {
            "gttangerang",
            "cawang",
            "cibitung",
            "gtbuahbatu"
        },
        {
            "gtpondokaren",
            "depok",
            "gtsentul",
            "gtbogor"
        },
        {
            "gtciawi",
            "cikarang",
            "gtjatiluhur",
            "gtpadalarang"
        }
    };

    for (auto line : jalur)
    {
        bool adaMasuk = false;
        bool adaKeluar = false;

        for (auto gerbang : line)
        {
            if (gerbang == tolMasuk)
            {
                adaMasuk = true;
            }

            if (gerbang == tolKeluar)
            {
                adaKeluar = true;
            }
        }

        if (adaMasuk && adaKeluar)
        {
            return true;
        }
    }

    return false;
}


bool RuteTol::validTolMasuk(string gerbang)
{
    vector<string> gerbangMasuk = {
        "gttangerang",
        "gtbuahbatu",
        "gtpondokaren",
        "gtsentul",
        "gtbogor",
        "gtciawi",
        "gtjatiluhur",
        "gtpadalarang"
    };

    for (auto gt : gerbangMasuk)
    {
        if (gt == gerbang)
        {
            return true;
        }
    }

    return false;
}

bool RuteTol::validTolKeluar(string gerbang)
{
    vector<string> semuaGerbang = {
        "gttangerang",
        "cawang",
        "cibitung",
        "gtbuahbatu",

        "gtpondokaren",
        "depok",
        "gtsentul",
        "gtbogor",

        "gtciawi",
        "cikarang",
        "gtjatiluhur",
        "gtpadalarang"
    };

    for (auto gt : semuaGerbang)
    {
        if (gt == gerbang)
        {
            return true;
        }
    }

    return false;
}

vector<string> RuteTol::getPilihanKeluar(string tolMasuk)
{
    vector<vector<string>> jalur = {
        {
            "gttangerang",
            "cawang",
            "cibitung",
            "gtbuahbatu"
        },
        {
            "gtpondokaren",
            "depok",
            "gtsentul",
            "gtbogor"
        },
        {
            "gtciawi",
            "cikarang",
            "gtjatiluhur",
            "gtpadalarang"
        }
    };

    for (auto line : jalur)
    {
        bool ditemukan = false;

        for (auto gerbang : line)
        {
            if (gerbang == tolMasuk)
            {
                ditemukan = true;
                break;
            }
        }

        if (ditemukan)
        {
            vector<string> hasil;

            for (auto gerbang : line)
            {
                if (gerbang != tolMasuk)
                {
                    hasil.push_back(gerbang);
                }
            }

            return hasil;
        }
    }

    return {};
}