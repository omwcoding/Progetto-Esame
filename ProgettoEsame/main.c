#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define righe 4
#define colonne 4
void menu( void );
int **acquisizionedafile(char * p);
int ** uguaglianzamatrici(int **matrice1, int **matrice2,  int indice  );
int ** trasposta(int ** matrice);
void stampamatrice (int ** matrice);
void stampamatricefile (int ** matrice, char nomefile[]);


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

int ** uguaglianzamatrici(int **matrice1, int **matrice2,  int indice  )
{
    int count = 0;
    FILE *Uguaglianzeptr;
    int i, j;
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
void stampamatrice (int ** matrice)
{
        for (int i = 0; i<righe; i++)
        {
            printf("%d %d %d %d\n", matrice[i][0], matrice[i][1], matrice[i][2], matrice[i][3]);
        }
        printf("\n");
}

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
