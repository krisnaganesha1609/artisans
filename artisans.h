#ifndef ARTISANS_H_INCLUDED
#define ARTISANS_H_INCLUDED
#include <iostream>
#define firstKerajinan(L) L.Firstkerajinan
#define lastKerajinan(L) L.Lastkerajinan
#define firstPasar(G) G.FirstPasar
#define infoKerajinan(P) P->infoKerajinan
#define nextKerajinan(P) P->nextKerajinan
#define prevKerajinan(P) P->prevKerajinan
#define infoPasar(Q) Q->infoPasar
#define nextPasar(Q) Q->nextPasar

using namespace std;

typedef struct elmKerajinan *adrKerajinan;
typedef struct elmPasar *adrPasar;

struct ListPasar
{
    adrPasar FirstPasar;
};

struct ListKerajinan
{
    adrKerajinan Firstkerajinan;
    adrKerajinan Lastkerajinan;
};

struct kerajinan
{
    std::string namaKerajinan;
    std::string namaPengrajin;
    int stok;
};

struct pasar
{
    std::string namaPasar;
    std::string lokasi;
};

struct elmKerajinan
{
    kerajinan infoKerajinan;
    adrKerajinan prevKerajinan;
    adrKerajinan nextKerajinan;
};

struct elmPasar
{
    pasar infoPasar;
    adrPasar nextPasar;
};

void createListPasar(ListPasar &L);
void createListKerajinan(ListKerajinan &L);

adrPasar createNewElmPasar(pasar x);
adrKerajinan createNewElmKerajinan(kerajinan x);

void insertLastPasar(ListPasar &L, adrPasar P);
void insertLastKerajinan(ListKerajinan &L, adrKerajinan P);
void deleteFoundKerajinan(ListKerajinan &L, adrKerajinan &P, adrKerajinan del);
void deleteFoundPasar(ListPasar &L, adrPasar &P, adrPasar del);
adrPasar findPasarByLokasi(ListPasar L, string lokasi);
adrKerajinan findKerajinanByNamaKerajinan(ListKerajinan L, string namaKerajinan);
adrKerajinan findKerajinanByNamaPengrajin(ListKerajinan L, string namaPengrajin);

void showAllPasar(ListPasar L);
void showAllKerajinan(ListKerajinan L);

#endif // ARTISANS_H_INCLUDED