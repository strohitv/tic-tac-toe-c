#include <stdbool.h>

#ifndef INC_11_TIC_TAC_TOE_SCORE_H
#define INC_11_TIC_TAC_TOE_SCORE_H

int fieldScore(char fieldParam[][3], char playerCharacter, int line, int column);
bool playerWon(char fieldParam[][3], int line, int column);

#endif //INC_11_TIC_TAC_TOE_SCORE_H
