#include "artisans.h"

void createListPasar(ListPasar &L)
{
    firstPasar(L) = NULL;
}

void createListKerajinan(ListKerajinan &L)
{
    firstKerajinan(L) = NULL;
    lastKerajinan(L) = NULL;
}

adrPasar createNewElmPasar(pasar x)
{
    adrPasar P = new elmPasar;
    infoPasar(P) = x;
    nextPasar(P) = NULL;
    return P;
}

adrKerajinan createNewElmKerajinan(kerajinan x)
{
    adrKerajinan P = new elmKerajinan;
    infoKerajinan(P) = x;
    nextKerajinan(P) = NULL;
    prevKerajinan(P) = NULL;
    return P;
}

void insertLastPasar(ListPasar &L, adrPasar P)
{
    if (firstPasar(L) == NULL)
    {
        firstPasar(L) = P;
        return;
    }
    adrPasar finder = firstPasar(L);
    while (nextPasar(finder) != NULL)
    {
        finder = nextPasar(finder);
    }
    nextPasar(finder) = P;
}

void insertLastKerajinan(ListKerajinan &L, adrKerajinan P)
{
    if (firstKerajinan(L) == NULL && lastKerajinan(L) == NULL)
    {
        firstKerajinan(L) = P;
        lastKerajinan(L) = P;
        return;
    }
    adrKerajinan finder = lastKerajinan(L);
    nextKerajinan(lastKerajinan(L)) = P;
    prevKerajinan(P) = lastKerajinan(L);
    lastKerajinan(L) = P;
}

void deleteFoundKerajinan(ListKerajinan &L, adrKerajinan &P, adrKerajinan del)
{
    if (del == firstKerajinan(L))
    {
        firstKerajinan(L) = nextKerajinan(firstKerajinan(L));
        nextKerajinan(del) = NULL;
    }
    else if (del == lastKerajinan(L))
    {
        lastKerajinan(L) = prevKerajinan(lastKerajinan(L));
        prevKerajinan(del) = NULL;
    }
    else if (del == NULL)
    {
        cout << "Desired data does not found!" << endl;
    }
    else
    {
        adrKerajinan prec = prevKerajinan(del);
        nextKerajinan(prec) = nextKerajinan(del);
        prevKerajinan(nextKerajinan(del)) = prec;
        prevKerajinan(del) = NULL;
        nextKerajinan(del) = NULL;
    }
    P = del;
}

void deleteFoundPasar(ListPasar &L, adrPasar &P, adrPasar del)
{
    if (del == firstPasar(L))
    {
        firstPasar(L) = nextPasar(firstPasar(L));
        nextPasar(del) = NULL;
    }
    else if (nextPasar(del) == NULL)
    {
        adrPasar finder = firstPasar(L);
        while (nextPasar(finder) != del)
        {
            finder = nextPasar(finder);
        }
        nextPasar(finder) = NULL;
    }
    else if (del == NULL)
    {
        cout << "Desired data does not found!" << endl;
    }
    else
    {
        adrPasar finder = firstPasar(L);
        while (nextPasar(finder) != del)
        {
            finder = nextPasar(finder);
        }
        nextPasar(finder) = nextPasar(del);
        nextPasar(del) = NULL;
    }
}

adrPasar findPasarByLokasi(ListPasar L, string lokasi)
{
    adrPasar Q = firstPasar(L);
    while (Q != NULL)
    {
        if (infoPasar(Q).lokasi == lokasi)
        {
            return Q;
        }
        Q = nextPasar(Q);
    }
    return NULL;
}

adrKerajinan findKerajinanByNamaKerajinan(ListKerajinan L, string namaKerajinan)
{
    adrKerajinan Q = firstKerajinan(L);
    while (Q != NULL)
    {
        if (infoKerajinan(Q).namaKerajinan == namaKerajinan)
        {
            return Q;
        }
        Q = nextKerajinan(Q);
    }
    return NULL;
}

adrKerajinan findKerajinanByNamaPengrajin(ListKerajinan L, string namaPengrajin)
{
    adrKerajinan Q = firstKerajinan(L);
    while (Q != NULL)
    {
        if (infoKerajinan(Q).namaPengrajin == namaPengrajin)
        {
            return Q;
        }
        Q = nextKerajinan(Q);
    }
    return NULL;
}

void showAllPasar(ListPasar L)
{
    adrPasar pas = firstPasar(L);
    int i = 1;
    cout << "LIST OF REGISTERED MARKET - ARTISANS" << endl;
    while (pas != NULL)
    {
        cout << i << ". " << infoPasar(pas).namaPasar << " - " << infoPasar(pas).lokasi << endl;
        pas = nextPasar(pas);
        i++;
    }
    cout << endl;
}

void showAllKerajinan(ListKerajinan L)
{
    adrKerajinan ker = firstKerajinan(L);
    int i = 1;
    cout << "LIST OF REGISTERED CRAFTS - ARTISANS" << endl;
    while (ker != NULL)
    {
        int stk = infoKerajinan(ker).stok;
        if (stk <= 0)
        {
            stk = 0;
        }
        cout << i << ". " << infoKerajinan(ker).namaPengrajin << " - " << infoKerajinan(ker).namaKerajinan << " - Stok: " << stk << endl;
        ker = nextKerajinan(ker);
        i++;
    }
    cout << endl;
}
