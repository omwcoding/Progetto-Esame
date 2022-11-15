#include "menu.h"
//Includere le altre librerie di menu

void menu( void )
{
    char NomeFile1[15], NomeFile2[15];
    int scelta, indice;
    int ** matrice1;
    int ** matrice2;
    int ** matrice3;

    printf( "Scelga una delle seguenti opzioni : \n"
            "1. Acquisizione di matrici da file\n"
            "2. Confronto tra righe appartenenti alle due matrici\n"
            "3. Calcolo della trasposta di una delle due matrici\n"
            "4. Uscita dal programma\n"
            "Nota bene: per operare sulle matrici e' necessario prima acquisirle\n\n");
    scanf("%d", &scelta );

    while( scelta != 4 )
    {
        switch( scelta )
        {
            case 1 :
                printf("\nHa scelto di acquisire delle matrici da file:\n");
                printf("Scrivere il nome del primo file da cui acquisire la matrice\n"
                       "(Si rammenta che la scelta verte tra Matrici1.txt e Matrici2.txt):\n");
                scanf("%s", NomeFile1);

                if (!(strcmp(NomeFile1, "Matrici1.txt" )))
                {
                    matrice1=acquisizionedafile( NomeFile1 );
                    stampamatrice(matrice1);
                }
                    else
                {
                    printf("Il file da lei scelto non e' disponibile\n");
                }

                printf("Scrivere il nome del secondo file da cui acquisire la matrice: ");
                scanf("%s", NomeFile2);
                if (!(strcmp(NomeFile2, "Matrici2.txt")))
                {
                    matrice2=acquisizionedafile( NomeFile2);
                    stampamatrice(matrice2);
                }
                    else
                    {
                    printf("Il file da lei scelto non e' disponibile!\n");
                    }
            break;

            case 2 :
                printf("Ha scelto di verificare l'ugualianza fra due righe appartenenti alle due matrici selezionate\n");
                printf("Ora scelga l'indice della riga da confrontare: ");
                scanf("%d", &indice );

                matrice3 = uguaglianzamatrici( matrice1, matrice2, indice-1);

                stampamatrice(matrice3);
                stampamatricefile(matrice3, "Uguaglianza.txt");
            break;

            case 3 :
                printf("Scelga la matrice al quale applicare il calcolo della trasposta: \n"
                        "1. Per applicare il calcolo sulla prima matrice\n"
                        "2. Per applicare il calcolo sulla seconda matrice\n");
                int n; /*variabile per la scelta della matrice su cui applicare il calcolo della trasposta */
                scanf("%d", &n);
                if (n==1)
                {

                    matrice3 = trasposta(matrice1);
                    stampamatrice(matrice3);
                    stampamatricefile (matrice3, "Trasposta.txt");
                }
                else if (n==2)
                {
                    matrice3 = trasposta(matrice2);
                    stampamatrice(matrice3);
                    stampamatricefile (matrice3, "Trasposta.txt");
                }
                else
                {
                    printf("Scelta non valida!\n");
                }

            break;

            default :
                printf("Valore di input non valido!\n");
                break;
      }
      printf("Faccia la sua prossima scelta, tra quelle elencate prima\n");
      scanf("%d", &scelta );
    }
}