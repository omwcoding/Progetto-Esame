#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define righe 4
#define colonne 4
void menu( void );
void acquisizionedafile( char *, int matrice[4][colonne] );
void uguaglianzamatrici( int matrice1[4][4], int matrice2[4][colonne],int indice );
void trasposta(int matrice[4][colonne]);
void swap(int* a, int *b);
void stampamatrice (int matrice[4][4]);


int main()
{


  printf("Benvenuto, faccia la sua scelta tra le seguenti : \n");

  menu();

    return 0;
}

void menu( void )
{
    char NomeFile1[15], NomeFile2[15];
    int scelta, indice;
    int matrice1[righe][4], matrice2[righe][4], matrice3[righe][4];

    printf( "Scegli una delle seguenti opzioni : \n"
            "1. Acquisizione da file delle due matrici\n"
            "2. Confronto tra le righe delle due matrici\n"
            "3. Calcolo della trasposta su una delle due matrici\n"
            "4. Esci dal programma\n\n");
    scanf("%d", &scelta );

    while( scelta != 4 )
    {
        switch( scelta )
        {
            case 1 :
                printf("\nAcquisizione di file di due matrici:\n");
                printf("Scrivere il nome del primo file (compresa di estensione) : ");
                scanf("%s", NomeFile1);

                if (!(strcmp(NomeFile1, "Matrici1.txt" )))
                {
                    acquisizionedafile( NomeFile1, matrice1 );
                }
                    else
                {
                    printf("Il file da lei scelto non e' disponibile\n");
                }
                printf("Scrivere il nome del secondo file: ");
                scanf("%s", NomeFile2);
                if (!(strcmp(NomeFile2, "Matrici2.txt")))
                {
                    acquisizionedafile( NomeFile2, matrice2 );
                }
                    else
                    {
                    printf("Il file da lei scelto non e' disponibile\n");
                    }
            break;

            case 2 :
                printf("Uguaglianza tra due righe delle due matrici selezionate\n");
                printf("Scegli l'indice della riga delle due matrici da confrontare : ");
                scanf("%d", &indice );


                acquisizionedafile( "Matrici1.txt", matrice1 );
                acquisizionedafile( "Matrici2.txt", matrice2 );
                uguaglianzamatrici( matrice1, matrice2, indice-1 );
            break;

            case 3 :
                printf("Scegli la matrice al quale applicare il calcolo della traspost: \n"
                        "1 per applicare il calcolo sulla prima matrice\n"
                        "2 per applicare il calcolo sulla seconda matrice\n");
                int n; /*variabile per la scelta della matrice su cui applicare il calcolo della trasposta */
                scanf("%d", &n);
                if (n==1)
                {
                    acquisizionedafile( "Matrici1.txt", matrice1 );
                    trasposta(matrice1);
                    stampamatrice(matrice1);
                    stampamatricefile (matrice1, "Trasposta.txt");
                }
                else if (n==2)
                {
                    acquisizionedafile( "Matrici2.txt", matrice2 );
                    trasposta(matrice2);
                    stampamatrice(matrice2);
                    stampamatricefile (matrice2, "Trasposta.txt");
                }
                else
                {
                    printf("Scelta non valida!\n");
                }

            break;

            default :
                printf("Valore di input non valido!\n");
                //menu();
                break;
      }
      printf("Faccia la sua prossima scelta tra quelle elencate prima\n");
      scanf("%d", &scelta );
    }
}
void acquisizionedafile(char * p, int matrice[righe][4] )
{
    char * tokenString;
    FILE *fileptr;
    if( ( fileptr = fopen(p, "r") ) == NULL )
    {
        printf("Non e' stato possibile aprire il file\n");
    }
        else
        {
            printf("Il file e' stato aperto correttamente\n");
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
        stampamatrice (matrice);
        fclose( fileptr);
}

void swap(int* a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

/* Converts A[][] to its transpose */
void trasposta(int matrice[righe][4])
{

    int k, y;
    for ( k = 0; k < righe; k++)
    {
        for ( y = k + 1; y < colonne; y++)
        {
            swap(&matrice[k][y],&matrice[y][k]);
        }
    }
}

void uguaglianzamatrici(int matrice1[righe][colonne], int matrice2[righe][colonne],  int indice )
{
    int count = 0;
    int matrice3[righe][colonne] = {0};
    FILE *Uguaglianzeptr;
    int i, j;
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
        stampamatrice(matrice3);
        stampamatricefile(matrice3, "Uguaglianza.txt");
}
void stampamatrice (int matrice[4][4])
{
        for (int i = 0; i<righe; i++)
        {
            printf("%d %d %d %d\n", matrice[i][0], matrice[i][1], matrice[i][2], matrice[i][3]);
        }
        printf("\n");
}

void stampamatricefile (int matrice[][4], char nomefile[])
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
