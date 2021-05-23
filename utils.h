
#ifndef INC_11_TIC_TAC_TOE_UTILS_H
#define INC_11_TIC_TAC_TOE_UTILS_H

#ifdef __unix__
#define clrscr() printf("\x1B[2J")
#elif __BORLANDC__ && __MSDOS__
#include <conio.h>
#elif __WIN32__ || _MSC_VER
#define clrscr() system("cls")
#else
define clrscr() printf("clrscr() - FEHLER!! \n")
#endif

void reset(char fieldParam[][3], int *moveCounter);
void printField(char fieldParam[][3]);
void determineRules(int *mode, int *winCounter);
void showFinalResults(int results[3], int mode, int winCounter);

#endif //INC_11_TIC_TAC_TOE_UTILS_H
