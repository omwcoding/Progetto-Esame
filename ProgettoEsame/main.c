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

                //stampamatrice(matrice1);
                if (!(strcmp(NomeFile1, "Matrici1.txt" )))
                {
                    matrice1=acquisizionedafile( NomeFile1 );
                    stampamatrice(matrice1);
                }
                    else
                {
                    printf("Il file da lei scelto non e' disponibile\n");
                }

                printf("Scrivere il nome del secondo file: ");
                scanf("%s", NomeFile2);
                if (!(strcmp(NomeFile2, "Matrici2.txt")))
                {
                    matrice2=acquisizionedafile( NomeFile2);
                    stampamatrice(matrice2);
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

                matrice3 = uguaglianzamatrici( matrice1, matrice2, indice-1);

                stampamatrice(matrice3);
                stampamatricefile(matrice3, "Uguaglianza.txt");
            break;

            case 3 :
                printf("Scegli la matrice al quale applicare il calcolo della traspost: \n"
                        "1 per applicare il calcolo sulla prima matrice\n"
                        "2 per applicare il calcolo sulla seconda matrice\n");
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
                //menu();
                break;
      }
      printf("Faccia la sua prossima scelta tra quelle elencate prima\n");
      scanf("%d", &scelta );
    }
}
int **acquisizionedafile(char * p)
{
    int* values = calloc(4*4, sizeof(int));
    int** matrice = malloc(4* sizeof(int*));

    //int matrice[righe][colonne];
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
        //stampamatrice (matrice);
        fclose( fileptr);
        return matrice;
}

/*void swap(int* a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
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
            //swap(&matrice[k][y],&matrice[y][k]);

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
