#include "artisans.h"
#include "menu.h"
#include "menu.cpp"
#include "relation.h"
#include "relation.cpp"

int main()
{
    // welcome
    welcomeBanner();
    
    // main Menu
    mainMenu();
    int mainMenuOption;
    cin >> mainMenuOption;
    if (mainMenuOption == 1) {
        // add data
        addData();
        int addDataOption;
        cin >> addDataOption;
        if (addDataOption == 1) {
            // add data kerajinan

        } else if (addDataOption == 2) {
            // add data pasar

        } else if (addDataOption == 3) {
            // exit to main menu

        } else if (addDataOption < 1 || addDataOption > 3) {
            // invalid optiions
            // primitive, need a revamp
            printf("Option is invalid! Exiting...");
            return 1;
        }
    } else if (mainMenuOption == 2) {
        // config data
        configData();
        int configDataOption;
        cin >> configDataOption;
        if (configDataOption == 1) {
            // edit data

        } else if (configDataOption == 2) {
            // delete data

        } else if (configDataOption == 3) {
            // find data

        } else if (configDataOption == 4) {
            // data relation

        } else if (configDataOption == 5) {
            // exit to main menu

        } else if (configDataOption < 1 || configDataOption > 5) {
            // invalid optiions
            // primitive, need a revamp
            printf("Option is invalid! Exiting...");
            return 1;
        }
    } else if (mainMenuOption == 3) {
        // primitive, need to be revamped
        printf("Outputting data...");
        showAllPasar(L);
        showAllKerajinan(L);
        printAllRelasi(L, LP);
    } else if (mainMenuOption == 4) {
        printf("Exiting,,,");
        return 0;
    } else if (mainMenuOption < 1 || mainMenuOption > 4) {
        // invalid optiions
        // primitive, need a revamp
        printf("Option is invalid! Exiting...");
        return 1;
    }

    return 0;
}