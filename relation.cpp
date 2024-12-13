#include "relation.h"

void createListRelasi(ListRelasi &L)
{
}

adrRelasi createNewElmRelasi(adrPasar p, adrKerajinan k)
{
    return adrRelasi();
}

void insertLastRelasi(ListRelasi &L, adrRelasi P)
{
}

void deleteFoundRelasi(ListRelasi &L, adrRelasi &P, adrRelasi prec)
{
}

adrRelasi findRelasi(ListRelasi L, adrKerajinan K, adrPasar P)
{
    adrRelasi R = firstRelasi(L);
    if(R != NULL){
        while(R != NULL){
            if(nextPasar(R) == P && nextKerajinan(R) == K){
                return R;
            }
            R = next(R);
        }
    }
    return adrRelasi();
}
