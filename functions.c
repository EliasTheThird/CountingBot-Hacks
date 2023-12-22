#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <Windows.h>
#include "functions.h" 

#define MAX_OUTPUT_SIZE 4001

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

int inputInt() {

    int integer; 
    char newLine;

    do {
        scanf("%d%c", &integer, &newLine);
        if (newLine != '\n') {
            printf("ERROR! Input a whole number\n");
            clearInputBuffer();
            printf("Selection: "); 
        }
    } while (newLine != '\n');  
    return integer;
}

int inputIntRange(int min, int max) {

    int input;
    do {
        input = inputInt();
        if (input < min || input > max) {
            printf("ERROR! Value must be between %d and %d inclusive\n", min, max);
            printf("Selection: ");
        }
    } while (input < min || input > max);

    return input;
} 

//////////////////////////////////////
// MENU & MODE FUNCTIONS
//////////////////////////////////////

void clearInputBuffer()
{

    while (getchar() != '\n')
    {
        ;
    }
}

void mainMenu() {

    int mode;

    do {
        printf("+ --------------------------------------------------------------------------------- +\n"
            "|                                    MODE SELECT                                    |\n"
            "+ --------------------------------------------------------------------------------- +\n"
            "|               [1] = Normal              ||              [2] = Troll               |\n"
            "+ --------------------------------------------------------------------------------- +\n"
            "|                                     [0] = Exit                                    |\n"
            "+ --------------------------------------------------------------------------------- +\n"
            "Selection: ");
        mode = inputIntRange(0, 2);
        putchar('\n');
        switch (mode) {
        case 1:
            modeNormal();
            break;
        case 2:
            modeTroll();
            break;
        }
    } while (mode);
}

void modeNormal() {

    int num;
    char output[MAX_OUTPUT_SIZE] = "";

    do { 
        printf("+ --------------------------------------------------------------------------------- +\n"
            "|                                    Normal Mode                                    |\n"
            "+ --------------------------------------------------------------------------------- +\n"
            "|                      Enter a positive integer --- [0] to Exit                     |\n"
            "+ --------------------------------------------------------------------------------- +\n");


        printf("Number: ");
        num = inputIntRange(0, 983);

        output[0] = '\0';

        int i = 1;
        while (i < num) {
            printf("1+");
            strcat(output, "1+");
            i++;
        }
        printf("1\n\n");
        strcat(output, "1");  

        clipboardCopy(output);

    } while (num != 0);
    system("cls");

}

void modeTroll() {

    int num, index = 0;
    char output[MAX_OUTPUT_SIZE] = "";
    const char* strings[] = { "69^0", "420^0" };

    do {
        printf("+ =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= +\n"
            "|                69^420               Troll Mode               69^420               |\n"
            "+ =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= +\n"
            "|                      Enter a positive integer --- [0] to Exit                     |\n"
            "+ =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= +\n");


        printf("Number: ");
        num = inputIntRange(0, 727);

        output[0] = '\0';

        for (int i = 0; i < num; i++) {  
            printf("%s", strings[index]);  
            strcat(output, strings[index]); 
            if (i != num - 1) {
                printf("+");
                strcat(output, "+");
            }
            index = (index + 1) % 2; 
        }

        printf("\n\n");     

        clipboardCopy(output);

    } while (num != 0);
    system("cls");

}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

void clipboardCopy(const char* output) {
    if (OpenClipboard(NULL)) {
        HGLOBAL clipboardData = GlobalAlloc(GMEM_MOVEABLE, strlen(output) + 1);
        if (clipboardData != NULL) {
            char* clipboardText = (char*)GlobalLock(clipboardData);
            strcpy(clipboardText, output);
            GlobalUnlock(clipboardData);
            EmptyClipboard();
            SetClipboardData(CF_TEXT, clipboardData);
            CloseClipboard();
        }
        else {
            printf("Error: Failed to allocate memory for clipboard data.\n");
        }
    }
    else {
        printf("Error: Failed to open the clipboard.\n");
    }
}

//////////////////////////////////////
// ASCII ART FUNCTIONS
//////////////////////////////////////

void printHeader() {

    printf(" _____ _     _____  ___   _____   _____ _   _  _____   _____ _   _ _________________\n"
        "|  ___| |   |_   _|/ _ \\ /  ___| |_   _| | | ||  ___| |_   _| | | |_   _| ___ \\  _  \\\n"
        "| |__ | |     | | / /_\\ \\\\ `--.    | | | |_| || |__     | | | |_| | | | | |_/ / | | |\n"
        "|  __|| |     | | |  _  | `--. \\   | | |  _  ||  __|    | | |  _  | | | |    /| | | |\n"
        "| |___| |_____| |_| | | |/\\__/ /   | | | | | || |___    | | | | | |_| |_| |\\ \\| |/ / \n"
        "\\____/\\_____/\\___/\\_| |_/\\____/    \\_/ \\_| |_/\\____/    \\_/ \\_| |_/\\___/\\_| \\_|___/ \n\n");

}

void printFooter() {

    system("cls");
    printf("                                                                     ***./***,*,\n"
    "                                  .#%%&&%%%%%%&%%%%%%%%%#/            ,.*,*/(...\n"
    "                                 &@@@@@@&&&&&%%%%%%##%########((/(,(*/((/,//,,..\n"
    "                                @@@@@@@@@@@@&&&&&%%%&(*/#%%#*(%##*/,,*/.,,..**,*\n"
    "                               &@@@@@@@@@@@@@&&&%.*/#&%%#%%&&%%%#%*,*(.,  ,*./((\n"
    "                             (%&&@@@@@@@@@@@@@&* (#/(/((*((/&%,##%#&(/       /((\n"
    "                            @@@@@@@@@@@@@@@@@@(*##(/////(//*//*(**/*#&(##    *//\n"
    "                           &@@@@@@@@@@@@@@@@@@#/*#//**/*////.**,(((*(#////***.,.\n"
    "            .&&&&&&&&&&@@&@@@@@@@@@@@@@@@@@@@@@(,/(/***,/*///*/*//*/#*/(((((### \n"
    "        &&&&&@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@@&*/#(/(///*/*//*,*/(//*/((/((#%  \n"
    "     #&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@,*%#####*/,/*(,*((*(*#((##%/   \n"
    "   %&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@(#%%%#(*#(,,(*((((###%%%%#     \n"
    " *&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&%%%%%%%%#####%%%&&&%&&&%   \n"
    " #&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&@&&%&&&&&&&&@@@&&/      \n"
    "  %&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@%/(*  \n"
    "    #&%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@@@@&%&*(((/*  \n"
    "      .#&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&@&@@@@/@.*(###((/*   \n"
    "          (%%%%&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&%%#%(**,,((##((((#(/   \n"
    "                %&&&&&&&@@@@@@&&&@@@@@&&&%%&&&%%%%((///////(/((((//,    \n"
    "                         /&&@@@@&&&&&%#(*..%&&%(((...,*//#(#####(/    \n"
    "                           (%&&&%%&&%##(*/,. .@*.    ..,*/#(/%#(*     \n"
    "                      (,%#(((&&&&%&&&#####/*,.&*..  ,,,*/#((//,    \n"
    "                 *(%#&@@@&@&&@@@&&&&&&&&%%%%%%%%&&&##%%&%#((,   \n"
    "              ,/#%&&&&&@@@@@@@@@@@@@@@&&&&&%#%/**(&&%#(//((#%#//*,  \n"
    "             /#%&&&&&&&&&@@@@@@@@@@@@@@@@@@@&##&%%%%#((/(%%%(((////,   \n"
    "           ,(%&&&&&&&&&&&&&@@@@@@@@@@@@@@@@&&&%%%%#%/##%&(((/(//////,    \n"
    "           /#%&&&&&&&&&&&&&&&&&&&@@@@@@@&&*#(/ &%%%%(%/(##(#(/////////   \n"
    "          /(#%&&&&&&&&&&&&&&@&&&&&&&&&%&%&(%&@,&%&&(((((((((((/////((/,  \n"
    "        ,(#%&&&&&&&&&&&&&&&&&&&%%#(**,,,,*@%&%#%,*//((((//((((///////**    \n"
    "+ --------------------------------------------------------------------------------- +\n"
    "|       <3 Thank you for using my counting bot program!  Hope you enjoyed! <3       |\n"
    "+ --------------------------------------------------------------------------------- +\n"
    "Press [ENTER] to close...");
    clearInputBuffer();
}
