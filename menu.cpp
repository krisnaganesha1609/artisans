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
    printf("\033[H");
}

// Main Menu
void mainMenu() {
    printf("====================\n");
    printf("     Main  Menu     \n");
    printf("====================\n");
    printf("1. Tambah Data\n");
    printf("2. Konfigurasi Data\n");
    printf("3. Tampilkan Data\n");
    printf("\n");
    printf("Pilih menu (1-3): ");
    // printf("\033[H");
}

void configData() {
    printf("====================\n");
    printf("  Konfigurasi Data  \n");
    printf("====================\n");
    printf("1. Edit Data\n");
    printf("2. delete Data\n");
    printf("3. Cari Data\n");
    printf("\n");
    printf("Pilih menu (1-3): ");
    // printf("\033[H");
}

// add data
void addData() {
    printf("====================\n");
    printf("    Tambah  Data    \n");
    printf("====================\n");
    printf("1. Tambah Data Kerajinan\n");
    printf("2. Tambah Data Pasar\n");
    printf("\n");
    printf("Pilih menu (1-2): ");
}

// edit data
void editData() {
    printf("====================\n");
    printf("     Edit  Data     \n");
    printf("====================\n");
    printf("1. Edit Data Kerajinan\n");
    printf("2. Edit Data Pasar\n");
    printf("\n");
    printf("Pilih menu (1-2): ");
}

// delete data
void deleteData() {
    printf("====================\n");
    printf("     Hapus Data     \n");
    printf("====================\n");
    printf("1. Hapus Data Kerajinan\n");
    printf("2. Hapus Data Pasar\n");
    printf("\n");
    printf("Pilih menu (1-2): ");
}