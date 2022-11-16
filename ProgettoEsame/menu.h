/**
 *  @file funzioni.c
 *  @brief Questo modulo contiene tutte le funzioni utilizzate dal modulo "menu".
 *
 *  @version 1.0
 *  @date 15/11/2022
 *  @authors Balde Omar, Cutrignelli Vanessa, De Santis Samantha
 */

#include <stdbool.h>
#define righe 4
#define colonne 4


/// @var NomeFile1, NomeFile2, scelta, indice, matrice1, matrice2, matrice3
    char NomeFile1[15], NomeFile2[15];
    int scelta, indice;
    int ** matrice1;
    int ** matrice2;
    int ** matrice3;

///Prototipo di funzione
void menu (void);
