#ifndef ARTISANS_H_INCLUDED
#define ARTISANS_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define info(P) P->info
#define next(P) P->next

// linux mad with these
// naa, it doesn't
using namespace std;

typedef struct elmKerajinan *adrKerajinan;
typedef struct elmPasar *adrPasar;
typedef struct elmRelasi *adrRelasi;

struct ListPasar
{
    adrPasar FirstPasar;
};

struct ListKerajinan
{
    adrKerajinan Firstkerajinan;
    adrKerajinan Lastkerajinan;
};

struct ListRelasi
{
    adrRelasi FirstRelasi;
    adrRelasi LastRelasi;
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
    kerajinan info;
    adrKerajinan nextkerajinan;
};

struct elmPasar
{
    pasar info;
    adrPasar nextPasar;
};

struct elmRelasi
{
    adrPasar nextPasar;
    adrKerajinan nextKerajinan;
    adrRelasi nextRelasi;
};

#endif // ARTISANS_H_INCLUDED