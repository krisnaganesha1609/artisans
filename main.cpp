#include "artisans.h"
#include "artisans.cpp"
#include "menu.h"
#include "menu.cpp"
#include "relation.h"
#include "relation.cpp"

using namespace std;

int main()
{
    // welcome
    welcomeBanner();

    // values
    ListPasar LP;
    ListKerajinan LK;
    ListRelasi LR;
    adrPasar AP;
    adrKerajinan AK;
    adrRelasi AR;
    pasar pas;
    kerajinan ker;

    // init list
    createListPasar(LP);
    createListKerajinan(LK);
    createListRelasi(LR);
    createNewElmPasar(pas);
    createNewElmKerajinan(ker);
    createNewElmRelasi(AP, AK);

    // main Menu
    while (true)
    {
        mainMenu();
        int mainMenuOption;
        cin >> mainMenuOption;
        if (mainMenuOption == 1)
        {
            // add data
            printf("\033[2J\033[1;1H");
            while (true)
            {
                
                addData();
                int addDataOption;
                cin >> addDataOption;
                if (addDataOption == 1)
                {
                    // add data kerajinan
                    printf("\033[2J\033[1;1H");
                    int loopKerajinanDataAdd;
                    cout << "Jumlah data kerajinan yang ingin dimasukkan: ";
                    cin >> loopKerajinanDataAdd;
                    for (int i = 0; i < loopKerajinanDataAdd; i++)
                    {
                        adrKerajinan P = new elmKerajinan;
                        cout << "Nama Kerajinan: ";
                        cin >> infoKerajinan(P).namaKerajinan;
                        cout << "Nama Pengrajin: ";
                        cin >> infoKerajinan(P).namaPengrajin;
                        cout << "Stok: ";
                        cin >> infoKerajinan(P).stok;
                        nextKerajinan(P) = NULL;
                        insertLastKerajinan(LK, P);
                    }
                }
                else if (addDataOption == 2)
                {
                    // add data pasar
                    printf("\033[2J\033[1;1H");
                    int loopPasarDataAdd;
                    cout << "Jumlah data pasar yang ingin dimasukkan: ";
                    cin >> loopPasarDataAdd;
                    for (int i = 0; i < loopPasarDataAdd; i++)
                    {
                        adrPasar Q = new elmPasar;
                        cout << "Nama Pasar: ";
                        cin >> infoPasar(Q).namaPasar;
                        cout << "Lokasi: ";
                        cin >> infoPasar(Q).lokasi;
                        nextPasar(Q) = NULL;
                        insertLastPasar(LP, Q);
                    }
                }
                else if (addDataOption == 3)
                {
                    cout << "Kembali ke menu utama...\n";
                    printf("\033[2J\033[1;1H");
                    break;
                }
                else
                {
                    cout << "Opsi tidak valid, coba lagi...\n";
                    printf("\033[2J\033[1;1H");
                    addData();
                }
            }
        }
        else if (mainMenuOption == 2)
        {
            // config data
            printf("\033[2J\033[1;1H");
            configData();
            int configDataOption;
            cin >> configDataOption;
            if (configDataOption == 1)
            {
                // delete data
                printf("\033[2J\033[1;1H");
                while (true)
                {
                    deleteData();
                    int deleteDataOption;
                    cin >> deleteDataOption;
                    if (deleteDataOption == 1)
                    {
                        // delete data kerajinan
                        printf("\033[2J\033[1;1H");
                        showAllKerajinan(LK);
                        string namaKerajinan;
                        cout << "Nama Kerajinan yang ingin dihapus: ";
                        cin >> namaKerajinan;
                        adrKerajinan del = findKerajinanByNamaKerajinan(LK, namaKerajinan);
                        deleteFoundKerajinan(LK, del, del);
                        cout << "Alamat Kerajinan Yang dihapus: " << del << endl;
                    }
                    else if (deleteDataOption == 2)
                    {
                        // delete data pasar
                        printf("\033[2J\033[1;1H");
                        showAllPasar(LP);
                        string lokasiPasar;
                        cout << "Lokasi Pasar yang ingin dihapus: ";
                        cin >> lokasiPasar;
                        adrPasar del = findPasarByLokasi(LP, lokasiPasar);
                        deleteFoundPasar(LP, del, del);
                        cout << "Alamat Pasar Yang dihapus: " << del << endl;
                    }
                    else if (deleteDataOption == 3)
                    {
                        cout << "Kembali ke menu utama...\n";
                        printf("\033[2J\033[1;1H");
                        break;
                    }
                    else
                    {
                        cout << "Opsi tidak valid, coba lagi...\n";
                        printf("\033[2J\033[1;1H");
                        deleteData();
                    }
                }
            }
            else if (configDataOption == 2)
            {
                // find data
                printf("\033[2J\033[1;1H");
                while (true)
                {
                    findData();
                    int findDataOption;
                    cin >> findDataOption;
                    if (findDataOption == 1)
                    {
                        // find data kerajinan
                        printf("\033[2J\033[1;1H");
                        while (true)
                        {
                            findDataKerajinanOptions();
                            int findDataKerajinanOption;
                            cin >> findDataKerajinanOption;
                            if (findDataKerajinanOption == 1)
                            {
                                // find data kerajinan by nama kerajinan
                                printf("\033[2J\033[1;1H");
                                string namaKerajinan;
                                cout << "Nama Kerajinan yang ingin dicari: ";
                                cin >> namaKerajinan;
                                adrKerajinan found = findKerajinanByNamaKerajinan(LK, namaKerajinan);
                                if (found != NULL)
                                {
                                    cout << "Data ditemukan!\n";
                                    cout << "Nama Kerajinan: " << infoKerajinan(found).namaKerajinan << endl;
                                    cout << "Nama Pengrajin: " << infoKerajinan(found).namaPengrajin << endl;
                                    cout << "Stok: " << infoKerajinan(found).stok << endl;
                                }
                                else
                                {
                                    cout << "Data tidak ditemukan!\n";
                                }
                            }
                            else if (findDataKerajinanOption == 2)
                            {
                                // find data kerajinan by nama pengrajin
                                printf("\033[2J\033[1;1H");
                                string namaPengrajin;
                                cout << "Nama Pengrajin yang ingin dicari: ";
                                cin >> namaPengrajin;
                                adrKerajinan found = findKerajinanByNamaPengrajin(LK, namaPengrajin);
                                if (found != NULL)
                                {
                                    cout << "Data ditemukan!\n";
                                    cout << "Nama Kerajinan: " << infoKerajinan(found).namaKerajinan << endl;
                                    cout << "Nama Pengrajin: " << infoKerajinan(found).namaPengrajin << endl;
                                    cout << "Stok: " << infoKerajinan(found).stok << endl;
                                }
                                else
                                {
                                    cout << "Data tidak ditemukan!\n";
                                }
                            }
                            else if (findDataKerajinanOption == 3)
                            {
                                cout << "Kembali ke menu utama...\n";
                                printf("\033[2J\033[1;1H");
                                break;
                            }
                            else
                            {
                                cout << "Opsi tidak valid, coba lagi...\n";
                                printf("\033[2J\033[1;1H");
                                findDataKerajinanOptions();
                            }
                        }
                    }
                    else if (findDataOption == 2)
                    {
                        // find data pasar
                        printf("\033[2J\033[1;1H");
                        string lokasiPasar;
                        cout << "Lokasi Pasar yang ingin dicari: ";
                        cin >> lokasiPasar;
                        adrPasar found = findPasarByLokasi(LP, lokasiPasar);
                        if (found != NULL)
                        {
                            cout << "Data ditemukan!\n";
                            cout << "Nama Pasar: " << infoPasar(found).namaPasar << endl;
                            cout << "Lokasi: " << infoPasar(found).lokasi << endl;
                        }
                        else
                        {
                            cout << "Data tidak ditemukan!\n";
                        }
                    }
                    else if (findDataOption == 3)
                    {
                        cout << "Kembali ke menu utama...\n";
                        printf("\033[2J\033[1;1H");
                        break;
                    }
                    else
                    {
                        cout << "Opsi tidak valid, coba lagi...\n";
                        printf("\033[2J\033[1;1H");
                        findData();
                    }
                }
            }
            else if (configDataOption == 3)
            {
                // data relation
                printf("\033[2J\033[1;1H");
                while (true)
                {
                    printAllRelasi(LR, LP);
                    configDataRelation();
                    int configDataRelationOption;
                    cin >> configDataRelationOption;
                    if (configDataRelationOption == 1)
                    {
                        // add relation
                        printf("\033[2J\033[1;1H");
                        showAllPasar(LP);
                        showAllKerajinan(LK);
                        string lokasiPasar;
                        string namaKerajinan;
                        cout << "Lokasi Pasar: ";
                        cin >> lokasiPasar;
                        cout << "Nama Kerajinan: ";
                        cin >> namaKerajinan;
                        connectRelasi(LR, LP, LK, lokasiPasar, namaKerajinan);
                    }
                    else if (configDataRelationOption == 2)
                    {
                        // find relation
                        printf("\033[2J\033[1;1H");
                        string lokasiPasar;
                        string namaKerajinan;
                        cout << "Lokasi Pasar: ";
                        cin >> lokasiPasar;
                        cout << "Nama Kerajinan: ";
                        cin >> namaKerajinan;
                        adrRelasi found = findRelasiByInfo(LR, lokasiPasar, namaKerajinan);
                        if (found != NULL)
                        {
                            cout << "Data ditemukan!\n";
                            cout << "Nama Pasar: " << infoPasar(nextRelasiPasar(found)).namaPasar << endl;
                            cout << "Lokasi: " << infoPasar(nextRelasiPasar(found)).lokasi << endl;
                            cout << "Nama Kerajinan: " << infoKerajinan(nextRelasiKerajinan(found)).namaKerajinan << endl;
                            cout << "Nama Pengrajin: " << infoKerajinan(nextRelasiKerajinan(found)).namaPengrajin << endl;
                            cout << "Stok: " << infoKerajinan(nextRelasiKerajinan(found)).stok << endl;
                        }
                        else
                        {
                            cout << "Data tidak ditemukan!\n";
                        }
                    }
                    else if (configDataRelationOption == 3)
                    {
                        // delete relation
                        printf("\033[2J\033[1;1H");
                        printAllRelasi(LR, LP);
                        string lokasiPasar;
                        string namaKerajinan;
                        cout << "Lokasi Pasar: ";
                        cin >> lokasiPasar;
                        cout << "Nama Kerajinan: ";
                        cin >> namaKerajinan;
                        adrRelasi theDeletedOne;
                        adrRelasi del = findRelasiByInfo(LR, lokasiPasar, namaKerajinan);
                        deleteFoundRelasi(LR, theDeletedOne, del);
                        cout << "Alamat Relasi Yang dihapus: " << theDeletedOne << endl;
                    }
                    else if (configDataRelationOption == 4)
                    {
                        cout << "Kembali ke menu utama...\n";
                        printf("\033[2J\033[1;1H");
                        break;
                    }
                    else
                    {
                        cout << "Opsi tidak valid, coba lagi...\n";
                        printf("\033[2J\033[1;1H");
                        configDataRelation();
                    }
                }
            }
            else if (configDataOption == 4)
            {
                // exit to main menu
                cout << "Kembali ke menu utama...\n";
                printf("\033[2J\033[1;1H");
                break;
            }
            else
            {
                // invalid
                cout << "Opsi tidak valid, coba lagi...\n";
                printf("\033[2J\033[1;1H");
                configData();
            }
        }
        else if (mainMenuOption == 3)
        {
            // show all data
            printf("\033[2J\033[1;1H");
            while (true)
            {
                showAllDataMenu();
                int showAllDataOption;
                cin >> showAllDataOption;
                if (showAllDataOption == 1)
                {
                    // show all data pasar
                    printf("\033[2J\033[1;1H");
                    showAllPasar(LP);
                }
                else if (showAllDataOption == 2)
                {
                    // show all data kerajinan
                    printf("\033[2J\033[1;1H");
                    showAllKerajinan(LK);
                }
                else if (showAllDataOption == 3)
                {
                    // show all data relation
                    printf("\033[2J\033[1;1H");
                    printAllRelasi(LR, LP);
                }
                else if (showAllDataOption == 4)
                {
                    cout << "Kembali ke menu utama...\n";
                    printf("\033[2J\033[1;1H");
                    break;
                }
                else
                {
                    cout << "Opsi tidak valid, coba lagi...\n";
                    printf("\033[2J\033[1;1H");
                    showAllDataMenu();
                }
            }
        }
        else if (mainMenuOption == 4)
        {
            printf("Exiting,,,");
            printf("\033[2J\033[1;1H");
            break;
        }
        else
        {
            cout << "Opsi tidak valid, coba lagi...\n";
            printf("\033[2J\033[1;1H");
            mainMenu();
        }
    }
    // tempat return 0 original
    return 0;
}