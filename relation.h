#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED
#include "artisans.h"
#include <iostream>
using namespace std;

#define firstRelasi(L) L.FirstRelasi
#define lastRelasi(L) L.LastRelasi
#define nextRelasi(Q) Q->nextRelasi
#define prevRelasi(Q) Q->prevRelasi

typedef struct elmRelasi *adrRelasi;

struct ListRelasi
{
    adrRelasi FirstRelasi;
    adrRelasi LastRelasi;
};

struct elmRelasi
{
    adrPasar nextPasar;
    adrKerajinan nextKerajinan;
    adrRelasi nextRelasi;
    adrRelasi prevRelasi;
};

void createListRelasi(ListRelasi &L);
adrRelasi createNewElmRelasi(adrPasar p, adrKerajinan k);
void insertLastRelasi(ListRelasi &L, adrRelasi P);
void deleteFoundRelasi(ListRelasi &L, adrRelasi &P, adrRelasi prec);
adrRelasi findRelasi(ListRelasi L, adrKerajinan K, adrPasar P);

#endif // RELATION_H_INCLUDED