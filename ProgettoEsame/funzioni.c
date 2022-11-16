/**
 *  @file funzioni.c
 *  @brief Questo modulo contiene tutte le funzioni utilizzate dal modulo "menu".
 *
 *  @version 1.0
 *  @date 15/11/2022
 *  @authors Balde Omar, Cutrignelli Vanessa, De Santis Samantha
 */

#include "funzioni.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  @file funzioni.c
 *  @brief La funzione "acquisizionedafile" permette di inizializzare delle matrici con i valori contenuti nei file.
 *
 *  Abbiamo due file precedentemente creati dal progettista con all'interno due matrici 4x4, contenenti 16 valori seperati da un carattere speciale "#"
 *  che vengono eliminati durante l'assegnazione dei valori alla nuova matrice.
 *
 *  @param[in] p:char* puntatore a file
 *  @return matrice di ritorno
 *
 */
int **acquisizionedafile(char * p)
{
    int* values = calloc(4*4, sizeof(int));
    int** matrice = malloc(4* sizeof(int*));

    char * tokenString;
    FILE *fileptr;
    for (int i=0; i<4; ++i)
    {
        matrice[i] = values + i*4;
    }
    if( ( fileptr = fopen(p, "r") ) == NULL )
    {
        printf("Non e' stato possibile aprire il file\n");
    }
        else
        {
            printf("Il file e' stato aperto correttamente!\n");
            char StringaLetta[20];
            fscanf(fileptr, "%19s", StringaLetta);
            short temp = 0, i = 0, j = 0;
            int t;

            while(!feof(fileptr))
            {
                tokenString = strtok(StringaLetta, "#");

                while(tokenString != NULL)
                {
                    switch (temp)
                    {
                    case 0:
                        t=atoi(tokenString);
                        matrice[i][j] = t;
                        j++;
                        if ( j==4 ) { temp ++; i++;}

                    break;
                    case 1:
                        t=atoi(tokenString);
                        matrice[i][j] = t;
                        j++;
                        if ( j==4 ) { temp ++; i++;}
                    break;
                    case 2:
                        t=atoi(tokenString);
                        matrice[i][j] = t;
                        j++;
                        if ( j==4 ) { temp ++; i++; }
                    break;
                    case 3:
                        t=atoi(tokenString);
                        matrice[i][j] = t;
                        j++;
                        if ( j==4 ) { temp ++; }
                    break;
                    case 4:
                    break;
                    }
                    tokenString = strtok(NULL, "#");
                }
                j = 0;
                fscanf(fileptr, "%19s", StringaLetta);
            }
        }

        fclose( fileptr);
        return matrice;
}

/**
 *  @file funzioni.c
 *  @brief La funzione "trasposta" permette di eseguire il calcolo della trasposta su una matrice.
 *
 *  L'utente sceglie su quale matrice applicare il calcolo della trasporta, in seguito il programma mantiene la diagonale
 *  e inverte le matrici triangolari superiori e inferiori.
 *
 *  @param[in] matrice:int** puntatore a puntatore
 *  @return matrice di ritorno
 */

int ** trasposta(int ** matrice)
{

    int k, y;
    int* values = calloc(4*4, sizeof(int));
    int** matrice3 = malloc(4* sizeof(int*));
    for (int i=0; i<4; ++i)
    {
        matrice3[i] = values + i*4;
    }
    for ( k = 0; k < righe; k++)
    {
        for ( y = 0 ; y < colonne; y++)
        {
            matrice3[k][y]=matrice[y][k];

        }
    }
    return matrice3;

}

/**
 *  @file funzioni.c
 *  @brief La funzione "uguaglianza" permette di confrontare due righe tra due matrici.
 *
 *  L'utente sceglie l'indice della riga delle due matrici da confrontare. Verrà stampata una nuova matrice sul file "Uguaglianza.txt" dove:
 *  1)Se le due righe sono uguali (i valori sono sia uguali che nello stesso ordine), la nuova matrice avrà tutti gli elementi inizalizzati a zero tranne per la riga uguale
 *  2)Se non ci sono uguaglianze la matrice stampata sarà inizializzata a zero su tutti gli elementi di essa.
 *
 *  @param[in] matrice1:int** puntatore a puntatore
 *  @param[in] matrice2:int** puntatore a puntatore
 *  @param[in] indice:int indice fornito dall'utente, il quale seleziona la riga delle matrici
 *  @return matrice di ritorno
 */
int ** uguaglianzamatrici(int **matrice1, int **matrice2,  int indice  )
{
    int count = 0;
    //FILE *Uguaglianzeptr;
    int j;
    int* values = calloc(4*4, sizeof(int));
    int** matrice3 = malloc(4* sizeof(int*));

    for (int i=0; i<4; ++i)
    {
        matrice3[i] = values + i*4;
    }

    for( j = 0; j < colonne; j++ )
    {
        if( matrice1[indice][j] == matrice2[indice][j] )
        {
            count++;

        }
    }
    if (count == colonne)
    {
        for( j = 0; j < colonne; j++ )
        {
            matrice3[indice][j] = matrice1[indice][j];
        }

    }
    return matrice3;
}

/**
 *  @file funzioni.c
 *  @brief La funzione "stampamatrice" permette di stampare a schermo la/e matrice/i selezionate dall'utente (come controllo).
 *
 *  @param[in] matrice:int** puntatore a puntatore
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

/**
 *  @file funzioni.c
 *  @brief La funzione "stampamatricefile" permette di stampare su un file la matrice passata alla funzione.
 *
 *  @param[in] matrice:int** puntatore a puntatore
 *  @param[in] nomefile[]:char array di caratteri
 */
void stampamatricefile (int ** matrice, char nomefile[])
{
        FILE *fileptr;
        if( ( fileptr = fopen(nomefile, "w") ) == NULL )
        {
            printf("Non e' stato possibile aprire il file!");
            return;
        }
        else
        {
        for (int i = 0; i<righe; i++)
        {
            fprintf(fileptr, "%d#%d#%d#%d\n", matrice[i][0], matrice[i][1], matrice[i][2], matrice[i][3]);
        }
        fclose(fileptr);
        }

}

