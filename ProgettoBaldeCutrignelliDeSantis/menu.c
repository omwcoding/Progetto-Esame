/**
 *  @file menu.c
 *  @brief Questo modulo gestisce le varie funzionalità a cui l'utente può avere accesso.
 *
 *  @version 1.0
 *  @date 15/11/2022
 *  @authors Balde Omar, Cutrignelli Vanessa, De Santis Samantha
 */

#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include <string.h>
#include "menu.h"
#include "funzioni.h"
#include "controlli.h"

/**
 *  @file menu.c
 *  @brief La funzione "menu" ci fa vedere a schermo le opzioni disponibili all'utente.
 *
 *  Sono stampate a schermo le opzioni disponibili all'utente. Le possibili scelte sono identificate attraverso un elenco e un numero a loro assegnato.
 *  L'utente ha la possibilità di inserire un numero da 1 a 4, a seconda del suo obiettivo. Se il numero inserito dall'utente è minore di 1 o maggiore di 4
 *  ci sarà un errore.
 *
 *  INTERVENTO DI TESTING: Cosa succede se l'utente inserisce un input diverso da un numero?
 *  BUG: L'inserimento della scelta deve essere per forza di tipo intero (un numero). In caso contrario il programma entrarà in loop.
 *       A questo punto è consigliato chiudere il terminale, riaprire il programma e inserire un valore valido.
 *
 *  INTERVENTO DI TESTING: Cosa succede se l'utente inserisce un indice maggiore o minore al numero delle righe della matrice?
 *  DIFENSIVA: supporta programmazione difensiva per la corretta acquisizione dell'indice della matrice da tastiera.
 */

void menu( void )
{
    int controllo = 0;
    printf( "Scelga una delle seguenti opzioni : \n"
            "1. Acquisizione di matrici da file\n"
            "2. Confronto tra righe appartenenti alle due matrici\n"
            "3. Calcolo della trasposta di una delle due matrici\n"
            "4. Uscita dal programma\n"
            "Nota bene: per operare sulle matrici e' necessario prima acquisirle\n\n");
    scanf("%d", &scelta );          //L'utente inserisce il numero che richiama l'opzione da lui desiderata

    while( scelta != 4 )
    {
        switch( scelta )
        {
            case 1 :
                printf("\nHa scelto di acquisire delle matrici da file:\n");
                printf("Scrivere il nome del primo file da cui acquisire la matrice\n"
                       "(Si rammenta che la scelta verte tra Matrici1.txt e Matrici2.txt): ");
                scanf("%14s", NomeFile1);

                if (!(strcmp(NomeFile1, "Matrici1.txt" )))      //Controllo sul nome del primo file inserito
                {
                    matrice1=acquisizionedafile( NomeFile1, &controllo );   //Assegnagnamo il ritorno della funzione "acquisizionedafile" alla matrice1
                    stampamatrice(matrice1);                    //Richiamiamo la funzione "stampamatrice" con parametro "matrice1"
                }
                    else
                    {
                        printf("Il file da lei scelto non e' disponibile! Sara' riportato al menu' iniziale\n\n");
                        break;
                    }

                printf("Scrivere il nome del secondo file da cui acquisire la matrice: ");
                scanf("%14s", NomeFile2);
                if (!(strcmp(NomeFile2, "Matrici2.txt")))       //Controllo sul nome del secondo file inserito
                {
                    matrice2=acquisizionedafile( NomeFile2, &controllo );    //Assegnagnamo il ritorno della funzione "acquisizionedafile" alla matrice2
                    stampamatrice(matrice2);                    //Richiamiamo la funzione "stampamatrice" con parametro "matrice2"
                }
                    else
                    {
                        printf("Il file da lei scelto non e' disponibile! Sara' riportato al menu' iniziale\n\n");
                    }
            break;

            case 2 :

                if( controllodafile(&controllo) == 1 )
                   {
                    printf("Ha scelto di verificare l'ugualianza fra due righe appartenenti alle due matrici selezionate\n");
                    printf("Ora scelga l'indice della riga da confrontare: ");
                    scanf("%d", &indice );      //L'utente inserisce l'indice della riga delle due matrici da confrontare

                    if (indice>0 && indice<5)
                    {
                        matrice3 = uguaglianzamatrici( matrice1, matrice2, indice-1);   //Assegnamo il ritorno della funzione "uguaglianzamatrici" alla matrice3
                        stampamatrice(matrice3);                                //Richiamiamo la funzione "stampamatrice" con parametro "matrice3"
                        stampamatricefile(matrice3, "Uguaglianza.txt");         //Richiamiamo la funzione "stampamatricefile" con parametri "matrice3" e "Uguaglianza.txt"
                    }
                        else
                        {
                            printf("L'indice inserito non e' valido! La matrice e' composta da 4 righe!\n");
                        }
                    }
                    else
                    {
                        printf("Non e' stato possibile fare il confronto poiche' non ha acqusistito prima le matrici dai file\n");
                    }

            break;

            case 3 :

                if( controllodafile(&controllo) == 1 )
                   {
                        printf("Scelga la matrice al quale applicare il calcolo della trasposta: \n"
                                "1. Per applicare il calcolo sulla prima matrice\n"
                                "2. Per applicare il calcolo sulla seconda matrice\n");
                        int n;                  //Variabile per la scelta della matrice su cui applicare il calcolo della trasposta
                        scanf("%d", &n);        //L'utente sceglie su quale delle due matrici applicare il calcolo della trasposta: 1 per "Matrici1.txt", 2 per "Matrici2.txt"
                        if (n==1)
                        {
                            matrice3 = trasposta(matrice1);     //Assegnamo il ritorno della funzione "trasposta" con parametro "matrice1" alla variabile matrice 3
                            stampamatrice(matrice3);            //Richiamiamo la funzione "stampamatrice" con parametro "matrice3"
                            stampamatricefile (matrice3, "Trasposta.txt");  //Richiamiamo la funzione "stampamatricefile" con parametro "matrice3" e "Trasposta.txt"
                        }
                            else if (n==2)
                            {
                                matrice3 = trasposta(matrice2);     //Assegnamo il ritorno della funzione "trasposta" con parametro "matrice2" alla variabile matrice 3
                                stampamatrice(matrice3);            //Richiamiamo la funzione "stampamatrice" con parametro "matrice3"
                                stampamatricefile (matrice3, "Trasposta.txt");  //Richiamiamo la funzione "stampamatricefile" con parametro "matrice3" e "Trasposta.txt"
                            }
                   }
                else
                    {
                     printf("Non e' stato possibile fare il calcolo della trasposta poiche' non ha acqusistito prima le matrici dai file\n");     //L'inserimento dell'utente non è valido
                    }

            break;

            default :
                printf("Valore di input non valido!\n");    ///CASO LIMITE: L'utente inserisce un input non valido (n<1 o n>4)

            break;
      }
      printf("Faccia la sua prossima scelta, tra quelle elencate prima : ");
      scanf("%d", &scelta );
    }
}
