#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define turnWaitTime 3000
#define player1Char 'O'
#define player2Char 'X'

#include "utils.h"
#include "score.h"
#include "player.h"
#include "ai.h"

int main() {
    srand(time(NULL));

    char field[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};

    int moveCounter = 0;
    int results[3] = {0};

    int winCounter = 0;
    int mode = 1;

    determineRules(&mode, &winCounter);

    do {
        bool win = false;

        while (true) {
            win = mode < 3 ? playerMove(field, &moveCounter, player1Char, "Spieler 1") : aiMove(field, &moveCounter, player1Char,
                                                                                        "Computer 1", player2Char);

            if (!win && moveCounter >= 9) {
                results[0]++;
                printField(field);
                printf("Unentschieden...\n\n");
                break;
            }

            if (!win) {
                win = mode % 2 == 1 ? playerMove(field, &moveCounter, player2Char, "Spieler 2") : aiMove(field, &moveCounter,
                                                                                                 player2Char, "Computer 2",
                                                                                                 player1Char);

                if (win) {
                    results[2]++;
                    printField(field);
                    printf("%s 2 hat gewonnen!\n\n", mode % 2 == 1 ? "Spieler" : "Computer");
                    break;
                }
            } else {
                results[1]++;
                printField(field);
                printf("%s 1 hat gewonnen!\n\n", mode < 3 ? "Spieler" : "Computer");
                break;
            }
        }

        printf("Bisherige Ergebnisse:\n\t%s 1:\t%d\n\tUnentschieden:\t%d\n\t%s 2:\t%d\n\n",
               mode < 3 ? "Spieler" : "Computer",
               results[1], results[0], mode % 2 == 1 ? "Spieler" : "Computer", results[2]);

        Sleep(turnWaitTime);

        reset(field, &moveCounter);
    } while (results[1] < winCounter && results[2] < winCounter);

    showFinalResults(results, mode, winCounter);

    return 0;
}
