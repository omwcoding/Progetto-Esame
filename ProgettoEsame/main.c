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

  printf("Scegli una delle seguenti opzioni : \n"
        "1. Acquisizione da file delle due matrici\n"
        "2. Confronto tra le righe delle due matrici\n"
        "3. Calcolo della trasposta su una delle due matrici\n"
        "4. Esci dal programma\n\n");
     scanf("%d", &scelta );
      while( scelta != 4 )
     {
      switch( scelta )
       {
        case 1 :printf("\nAcquisizione di file di due matrici:\n");
                printf("Scrivere il nome del primo file (compresa di estensione) : ");
                scanf("%s", NomeFile1);
                if (!(strcmp(NomeFile1, "Matrici1.txt" ))) {
                        acquisizionedafile( NomeFile1, matrice1 );
                    }
                else {
                        printf("Il file da lei scelto non e' disponibile\n");
                    }
                printf("Scrivere il nome del secondo file: ");
                scanf("%s", NomeFile2);
                if (!(strcmp(NomeFile2, "Matrici2.txt"))) {
                        acquisizionedafile( NomeFile2, matrice2 );
                            }
                else {
                        printf("Il file da lei scelto non e' disponibile\n");
                    }
                break;

        case 2 : printf("Uguaglianza tra due righe delle due matrici selezionate\n");
                 printf("Scegli l'indice della riga delle due matrici da confrontare : ");
                 scanf("%d", &indice );

                 acquisizionedafile( NomeFile1, matrice1 );
                 acquisizionedafile( NomeFile2, matrice2 );
                 uguaglianzamatrici( matrice1[righe][4], matrice2[righe][4], indice );
                 break;

        case 3 : printf("Scegli la matrice al quale applicare il calcolo della traspost: \n"
                        "1 per applicare il calcolo sulla prima matrice\n"
                        "2 per applicare il calcolo sulla seconda matrice\n");
                int n; /*variabile per la scelta della matrice su cui applicare il calcolo della trasposta */
                scanf("%d", &n);
                if (n==1)
                {
                    acquisizionedafile( NomeFile1, matrice1 );
                    trasposta(matrice1);
                }
                if (n==2)
                {
                    acquisizionedafile( NomeFile2, matrice2 );
                    trasposta(matrice2);
                }
                else
                    printf("Scelta non valida!");


                   break;

                default : printf("Scelta non valida\n");
                          menu();
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

            while(!feof(fileptr))
            {
                tokenString = strtok(StringaLetta, "#");
                short temp = 0, i = 0, j = 0;
                int t;

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
    }               for (int i = 0; i<righe; i++)
                    {
                        printf("%d %d %d %d", matrice[i][0], matrice[i][1], matrice[i][2], matrice[i][3]);
                    }
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
    for ( k = 0; k < righe; k++){
        for ( y = k + 1; y < colonne; y++){
            swap(&matrice[k][y],&matrice[y][k]);
        }
    }
}

void uguaglianzamatrici(int matrice1[4][4], int matrice2[4][colonne],  int indice )
{
 int matrice3[4][colonne];
 FILE *Uguaglianzeptr;
 int i, j;
  for( j = 0; j < colonne; j++ )
                        {
                         if( matrice1[indice][j] = matrice2[indice][j] )
                           {
                            matrice3[indice][j] = matrice1[indice][j];
                           }
                        }

                     if( ( Uguaglianzeptr = fopen("Uguaglianza.txt", "w") ) == NULL )
                       {
                        printf("Non e' stato possibile aprire il file 'Uguaglianza.txt'\n");
                       }
                    else
                      {
                       for( i = 0; i < righe; i++ )
                          {
                           for( j = 0; j < colonne; j++)
                              { fprintf( Uguaglianzeptr ,"%d ", matrice3[i][j]);
                                printf("%d ", matrice3[i][j]);
                              }
                            puts("");
                          }
                        fclose(Uguaglianzeptr);
                      }
}
