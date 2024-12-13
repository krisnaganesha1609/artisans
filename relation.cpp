#include "relation.h"

void createListRelasi(ListRelasi &L)
{
    firstRelasi(L) = NULL;
    lastRelasi(L) = NULL;
}

adrRelasi createNewElmRelasi(adrPasar p, adrKerajinan k)
{
    adrRelasi P = new elmRelasi;
    nextRelasiPasar(P) = p;
    nextRelasiKerajinan(P) = k;
    nextRelasi(P) = NULL;
    prevRelasi(P) = NULL;
    return P;
}

void insertLastRelasi(ListRelasi &L, adrRelasi P)
{
    if (firstRelasi(L) == NULL && lastRelasi(L) == NULL)
    {
        firstRelasi(L) = P;
        lastRelasi(L) = P;
        return;
    }
    adrRelasi Q = lastRelasi(L);
    nextRelasi(Q) = P;
    prevRelasi(P) = Q;
    lastRelasi(L) = P;
}

void deleteFoundRelasi(ListRelasi &L, adrRelasi &P, adrRelasi del)
{
    if (del == firstRelasi(L))
    {
        firstRelasi(L) = nextRelasi(firstKerajinan(L));
        nextRelasi(del) = NULL;
    }
    else if (del == lastRelasi(L))
    {
        lastKerajinan(L) = prevRelasi(lastRelasi(L));
        prevRelasi(del) = NULL;
    }
    else if (del == NULL)
    {
        cout << "Desired data not found!" << endl;
    }
    else
    {
        adrRelasi prec = prevRelasi(del);
        nextRelasi(prec) = nextRelasi(del);
        prevRelasi(nextRelasi(del)) = prec;
        prevRelasi(del) = NULL;
        nextRelasi(del) = NULL;
    }
    P = del;
}

adrRelasi findRelasi(ListRelasi L, adrKerajinan K, adrPasar P)
{
    adrRelasi R = firstRelasi(L);
    if (R != NULL)
    {
        while (R != NULL)
        {
            if (nextPasar(R) == P && nextKerajinan(R) == K)
            {
                return R;
            }
            R = next(R);
        }
    }
    return NULL;
}

adrRelasi findRelasiByInfo(ListRelasi L, string lokasiPasar, string namaKerajinan)
{
    adrRelasi P = firstRelasi(L);
    if (P != NULL)
    {
        while (P != NULL)
        {
            if (infoPasar(nextRelasiPasar(P)).lokasi == lokasiPasar && infoKerajinan(nextRelasiKerajinan(P)).namaKerajinan == namaKerajinan)
            {
                return P;
            }
            P = nextRelasi(P);
        }
    }
    return NULL;
}

void connectRelasi(ListRelasi &L, ListPasar LP, ListKerajinan LK, string lokasiPasar, string namaKerajinan)
{
    adrPasar ps = findPasarByLokasi(LP, lokasiPasar);
    adrKerajinan kr = findKerajinanByNamaKerajinan(LK, namaKerajinan);
    if (ps != NULL && kr != NULL)
    {
        adrRelasi R = createNewElmRelasi(ps, kr);
        insertLastRelasi(L, R);
    }
}

void printAllRelasi(ListRelasi L, ListPasar LP)
{
    adrPasar P = firstPasar(LP);
    cout << "LIST OF ALL RELATIONS - ARTISANS" << endl;
    while (R != NULL)
    {
        cout << "# " << infoPasar(P).namaPasar << " - " << infoPasar(P).lokasi << endl;
        adrRelasi R = firstRelasi(L);
        if (R != NULL)
        {
            do
            {
                if (nextRelasiPasar(R) == P)
                {
                    cout << "|---> " << infoKerajinan(nextRelasiKerajinan(R)).namaKerajinan << " - By: " << infoKerajinan(nextRelasiKerajinan(R)).namaPengrajin << endl;
                }
                R = nextRelasi(R);
            } while (R != firstRelasi(L));
        }
        cout << endl;
        P = nextPasar(P);
    }
    cout << endl;
}
