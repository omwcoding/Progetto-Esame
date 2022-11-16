/**
 *  @file funzioni.h
 *  @brief Questa libreria contiene tutte le funzioni utilizzate dal modulo "menu".
 *
 *  @version 1.0
 *  @date 15/11/2022
 *  @authors Balde Omar, Cutrignelli Vanessa, De Santis Samantha
 */

#include <stdio.h>
#define righe 4
#define colonne 4

/**
 *  @file funzioni.h
 *  @brief Prototipi delle funzioni utilizzate in "menu".
 */

/// Prototipi di funzione
int ** acquisizionedafile(char * p, int *controllo );
int ** trasposta(int ** matrice);
int ** uguaglianzamatrici(int **matrice1, int **matrice2,  int indice  );
void stampamatricefile (int ** matrice, char nomefile[]);
