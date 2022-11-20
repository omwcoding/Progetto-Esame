#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "funzioni.h"

#define righe 4
#define colonne 4

/**
*   @author Balde Omar, Cutrignelli Vanessa, De Santis Samantha
*   @file main.c
*   @brief Questo file utilizza il modulo "menu".
*   Chiamando questa funzione vediamo a schermo il menu di scelta contenente le varie opzioni.
*
*   @return 0 se il programma è stato eseguito correttamente
*/

int main()
{
    printf("Benvenuto, faccia la sua scelta tra le seguenti : \n");
    menu();
    return 0;
}
