#include <chrono>
#include <thread>
#include "menu.h"

// needed for time delay
using namespace std::this_thread;
using namespace std::chrono_literals;
using std::chrono::system_clock;

// startup
void welcomeBanner() {
    printf("                                          \n");
    printf("     _        _   _                      \n"); 
    printf("    / \\  _ __| |_(_)___  __ _ _ __  ___  \n");
    printf("   / _ \\| '__| __| / __|/ _` | '_\\\\/ __| \n");
    printf("  / ___ \\ |  | |_| \\\\_\\\\ (_| | | | \\\\_\\\\ \n");
    printf(" ///   \\\\\\|  \\___|_|___/\\\\_,_|_| |_|___/ \n");
    printf("                                          \n");
    printf("==========================================\n");
    printf(" Artisans                   Business Tool \n");
    printf(" Made by:      Gede Krisna & Putu Justine \n");
    printf(" Available on:            Windows & Linux \n");
    printf("==========================================\n");
    sleep_for(3s);
    printf("\033[2J\033[1;1H");
}

// Main Menu
void mainMenu() {
    printf("====================\n");
    printf("     Main  Menu     \n");
    printf("====================\n");
    printf("1. Tambah Data\n");
    printf("2. Konfigurasi Data\n");
    printf("3. Tampilkan Data\n");
    printf("4. Keluar dari program\n");
    printf("\n");
    printf("Pilih menu (1-3): ");
    // printf("\033[2J\033[1;1H");
}

// config data
void configData() {
    printf("====================\n");
    printf("  Konfigurasi Data  \n");
    printf("====================\n");
    printf("1. delete Data\n");
    printf("2. Cari Data\n");
    printf("3. Relasi Data\n");
    printf("4. Kembali ke menu sebelumnya\n");
    printf("\n");
    printf("Pilih menu (1-4): ");
    // printf("\033[2J\033[1;1H");
}

// add data
void addData() {
    printf("====================\n");
    printf("    Tambah  Data    \n");
    printf("====================\n");
    printf("1. Tambah Data Kerajinan\n");
    printf("2. Tambah Data Pasar\n");
    printf("3. Kembali ke menu sebelumnya\n");
    printf("\n");
    printf("Pilih menu (1-3): ");
}

// delete data
void deleteData() {
    printf("====================\n");
    printf("     Hapus Data     \n");
    printf("====================\n");
    printf("1. Hapus Data Kerajinan\n");
    printf("2. Hapus Data Pasar\n");
    printf("3. Kembali ke menu sebelumnya\n");
    printf("\n");
    printf("Pilih menu (1-2): ");
}

// find data
void findData() {
    printf("====================\n");
    printf("     Cari  Data     \n");
    printf("====================\n");
    printf("1. Cari Data Kerajinan\n");
    printf("2. Cari Data Pasar\n");
    printf("3. Kembali ke menu sebelumnya\n");
    printf("\n");
    printf("Pilih menu (1-3): ");
}

// config data relation
void configDataRelation() {
    printf("======================\n");
    printf("  Konfigurasi Relasi  \n");
    printf("======================\n");
    printf("1. Tambah Relasi\n");
    printf("2. Cari Relasi\n");
    printf("3. Hapus Relasi\n");
    printf("4. Kembali ke menu sebelumnya\n");
    printf("\n");
    printf("Pilih menu (1-4): ");
    // printf("\033[2J\033[1;1H");
}

// config data relation
void showAllDataMenu() {
    printf("==================\n");
    printf("  Tampilkan Data  \n");
    printf("==================\n");
    printf("1. Tampilkan Data Pasar\n");
    printf("2. Tampilkan Data Kerajinan\n");
    printf("3. Tampilkan Data Relasi\n");
    printf("4. Kembali ke menu sebelumnya\n");
    printf("\n");
    printf("Pilih menu (1-4): ");
    // printf("\033[2J\033[1;1H");
}

// find data kerajinan options
void findDataKerajinanOptions() {
    printf("====================\n");
    printf("     Cari  Data     \n");
    printf("====================\n");
    printf("1. Cari Data Kerajinan\n");
    printf("2. Cari Data Pengrajin\n");
    printf("3. Kembali ke menu sebelumnya\n");
    printf("\n");
    printf("Pilih menu (1-3): ");
}