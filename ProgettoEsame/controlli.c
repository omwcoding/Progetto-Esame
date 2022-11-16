/**
 *  @file controlli.c
 *  @brief Questa libreria contiene la funzione di controllo da file.
 *
 *
 *
 *  @version 1.0
 *  @date 15/11/2022
 *  @authors Balde Omar, Cutrignelli Vanessa, De Santis Samantha
 */

#include <stdio.h>
#include <stdlib.h>
#include "controlli.h"
#include "funzioni.h"
#include "menu.h"

/**
 *  @file controlli.c
 *  @brief La funzione "controllodafile" permette di verificare l'apertura dei file contenenti le matrici.
 *
 *  La funzione "controllodafile" legge il valore della variabile "controllo", presente nella funzione "acquisizionefile",
 *  e ne assume lo stesso valore. La funzione viene usata dai vari case del "menu" nei casi in cui l'utente scelga di operare
 *  sulle matrici prima della loro acquisizione.
 *
 *  @param[in] controllo:int* puntatore a variabile intera
 *  @return valore di controllo
 *  INTERVENTO DI TESTING: Cosa succede se l'utente vuole operare sulle matrici prima di averle acquisite?
 *  DIFENSIVA: supporta programmazione difensiva per la mancata acquisizione da file.
 */

int controllodafile( int * controllo)
{
 return *controllo;
}

/**
 *  @file funzioni.c
 *  @brief La funzione "stampamatrice" permette di stampare a schermo la/e matrice/i selezionate dall'utente (come controllo).
 *
 *  @param[in] matrice:int** puntatore a puntatore
 *
 *  DIFENSIVA: supporta programmazione difensiva per la corretta acquisizione della matrice da file.
 */
void stampamatrice (int ** matrice)
{
        printf("La matrice selezionata e' : \n");
        for (int i = 0; i<righe; i++)
        {
            printf("%d %d %d %d\n", matrice[i][0], matrice[i][1], matrice[i][2], matrice[i][3]);
        }
        printf("\n");
}

