#include <stdio.h>
#include "player.h"
#include "utils.h"
#include "score.h"

bool playerMove(char fieldParam[][3], int *moveCounter, char playerCharacter, char name[]) {
    if (*moveCounter >= 9) {
        return false;
    }

    int line = 0;
    int column = 0;
    do {
        printField(fieldParam);

        printf("%s ist an der Reihe.\n\n", name);

        printf("Bitte geben Sie die Zeile an [1 - 3]: ");
        scanf("%d", &line);
        fflush(stdin);
        printf("Bitte geben Sie die Spalte an [1 - 3]: ");
        scanf("%d", &column);
        fflush(stdin);
    } while (line < 1 || line > 3 || column < 1 || column > 3 || fieldParam[line - 1][column - 1] != ' ');

    fieldParam[line - 1][column - 1] = playerCharacter;
    (*moveCounter)++;

    return playerWon(fieldParam, line - 1, column - 1);
}
