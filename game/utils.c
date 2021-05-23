#include <stdio.h>
#include "utils.h"

void reset(char fieldParam[][3], int *moveCounter) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fieldParam[i][j] = ' ';
        }
    }

    *moveCounter = 0;
}

void printField(char fieldParam[][3]) {
    clrscr();

    printf("+-+-+-+\n");
    printf("|%c|%c|%c|\n", fieldParam[0][0], fieldParam[0][1], fieldParam[0][2]);
    printf("+-+-+-+\n");
    printf("|%c|%c|%c|\n", fieldParam[1][0], fieldParam[1][1], fieldParam[1][2]);
    printf("+-+-+-+\n");
    printf("|%c|%c|%c|\n", fieldParam[2][0], fieldParam[2][1], fieldParam[2][2]);
    printf("+-+-+-+\n\n");
}

void determineRules(int *mode, int *winCounter) {
    char modeChar = 'f';
    printf("Bitte Modus eingeben\n");
    printf("\tSpieler vs Spieler: (1 / default bei anderen Werten)\n");
    printf("\tSpieler vs Computer: (2)\n");
    printf("\tComputer vs Spieler: (3)\n");
    printf("\tComputer vs Computer: (4)\n");
    printf("Spielmodus: ");
    scanf("%c", &modeChar);
    fflush(stdin);

    printf("\n");
    printf("Bis wie vielen Siegen soll gespielt werden?\n");
    printf("Anzahl Siege zum Gesamtsieg: ");
    scanf("%d", winCounter);
    fflush(stdin);

    if (modeChar - '1' > 0 && modeChar - '1' < 4) {
        *mode += modeChar - '1';
    }
}

void showFinalResults(int results[3], int mode, int winCounter) {
    clrscr();

    printf("Finale Ergebnisse:\n\t%s 1:\t%d\n\tUnentschieden:\t%d\n\t%s 2:\t%d\n\n",
           mode < 3 ? "Spieler" : "Computer",
           results[1], results[0], mode % 2 == 1 ? "Spieler" : "Computer", results[2]);

    printf("Gratulation an den Gewinner, ");

    if (results[1] >= winCounter) {
        printf("%s 1!\n\n", mode < 3 ? "Spieler" : "Computer");
    } else {
        printf("%s 2!\n\n", mode % 2 == 1 ? "Spieler" : "Computer");
    }

    printf("Beenden mit Enter...");
    char whatever = 'f';
    scanf("%c", &whatever);
    fflush(stdin);
}