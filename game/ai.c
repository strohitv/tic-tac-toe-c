#include <stdio.h>
#include <windows.h>
#include "ai.h"
#include "utils.h"
#include "score.h"

bool aiMove(char fieldParam[][3], int *moveCounter, char playerCharacter, char name[], char enemyCharacter) {
    if (*moveCounter >= 9) {
        return false;
    }

    int line = 0;
    int column = 0;
    bool canWinThisTurn = false;

    printField(fieldParam);
    printf("%s ist an der Reihe.\n\n", name);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (fieldParam[i][j] != ' ') {
                continue;
            }

            if (fieldScore(fieldParam, playerCharacter, i, j) == 2) {
                // setting this field would win the game
                line = i;
                column = j;
                canWinThisTurn = true;
                break;
            }
        }
    }

    bool hasToPreventDefeatThisTurn = false;
    if (!canWinThisTurn) {
        // try to prevent enemy player from winning
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (fieldParam[i][j] != ' ') {
                    continue;
                }

                if (fieldScore(fieldParam, enemyCharacter, i, j) == 2) {
                    // NOT setting this field would lose the game
                    line = i;
                    column = j;
                    hasToPreventDefeatThisTurn = true;
                    break;
                }
            }
        }
    }

    if (!canWinThisTurn && !hasToPreventDefeatThisTurn) {
        // random choice
        do {
            line = rand() % 3;
            column = rand() % 3;
        } while (fieldParam[line][column] != ' ');
    }

    fieldParam[line][column] = playerCharacter;
    (*moveCounter)++;

    Sleep(aiWaitTime);

    return playerWon(fieldParam, line, column);
}
