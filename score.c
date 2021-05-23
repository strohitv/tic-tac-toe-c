#include "score.h"

int singleScore(char playerCharacter, char fieldCharacter) {
    return playerCharacter == fieldCharacter ? 1 : 0;
}

int fieldScore(char fieldParam[][3], char playerCharacter, int line, int column) {
    int scores[4] = {0};

    scores[0] = singleScore(playerCharacter, fieldParam[line][0])
                + singleScore(playerCharacter, fieldParam[line][1])
                + singleScore(playerCharacter, fieldParam[line][2]);
    scores[1] = singleScore(playerCharacter, fieldParam[0][column])
                + singleScore(playerCharacter, fieldParam[1][column])
                + singleScore(playerCharacter, fieldParam[2][column]);

    if (line + column == 2) {
        scores[2] = singleScore(playerCharacter, fieldParam[0][2])
                    + singleScore(playerCharacter, fieldParam[1][1])
                    + singleScore(playerCharacter, fieldParam[2][0]);
    }

    if (line == column) {
        scores[3] = singleScore(playerCharacter, fieldParam[0][0])
                    + singleScore(playerCharacter, fieldParam[1][1])
                    + singleScore(playerCharacter, fieldParam[2][2]);
    }

    int max = 0;
    for (int i = 0; i < 4; i++) {
        if (scores[i] > max) {
            max = scores[i];
        }
    }

    return max;
}

bool playerWon(char fieldParam[][3], int line, int column) {
    return fieldScore(fieldParam, fieldParam[line][column], line, column) == 3;
}
