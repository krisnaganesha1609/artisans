#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED
#include "artisans.h"
#include <iostream>
using namespace std;

#define firstRelasi(L) L.FirstRelasi
#define lastRelasi(L) L.LastRelasi
#define nextRelasi(Q) Q->nextRelasi
#define prevRelasi(Q) Q->prevRelasi
#define nextRelasiPasar(Q) Q->nextRelasiPasar
#define nextRelasiKerajinan(Q) Q->nextRelasiKerajinan

typedef struct elmRelasi *adrRelasi;

struct ListRelasi
{
    adrRelasi FirstRelasi;
    adrRelasi LastRelasi;
};

struct elmRelasi
{
    adrPasar nextRelasiPasar;
    adrKerajinan nextRelasiKerajinan;
    adrRelasi nextRelasi;
    adrRelasi prevRelasi;
};

void createListRelasi(ListRelasi &L);
adrRelasi createNewElmRelasi(adrPasar p, adrKerajinan k);
void insertLastRelasi(ListRelasi &L, adrRelasi P);
void deleteFoundRelasi(ListRelasi &L, adrRelasi &P, adrRelasi del);
adrRelasi findRelasi(ListRelasi L, adrKerajinan K, adrPasar P);
adrRelasi findRelasiByInfo(ListRelasi L, string lokasiPasar, string namaKerajinan);

void connectRelasi(ListRelasi &L, ListPasar LP, ListKerajinan LK, string lokasiPasar, string namaKerajinan);

void printAllRelasi(ListRelasi L, ListPasar LP);

void transaction(ListRelasi &L, string lokasiPasar, string namaKerajinan, int qty);

int countChildRelasi(ListRelasi L, adrPasar P);

#endif // RELATION_H_INCLUDED