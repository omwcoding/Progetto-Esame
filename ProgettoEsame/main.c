#include <stdio.h>
#include <stdlib.h>

#define righe 4
#define colonne 4
void menu( void );
void acquisizionedafile( FILE *fileptr, int matrice[4][colonne] );
void uguaglianzamatrici( FILE *Uguaglianzeptr, int matrice1[4][4], int matrice2[4][colonne], int matrice3[4][colonne], int indice );
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
  int scelta, indice, i, j;
  int matrice1[righe][4], matrice2[righe][4], matrice3[righe][4];
  FILE *Matrici1ptr, *Matrici2ptr, *Uguaglianzeptr;

  printf("Scegli una delle seguenti opzioni : \n"
        "1. Acquisizione da file delle due matrici\n"
        "2. Confronto tra le righe delle due matrici\n"
        "3. Calcolo della trasposta su una delle due matrici\n"
        "4. Esci dal programma\n");
     scanf("%d", &scelta );
      while( scelta != 4 )
     {
      switch( scelta )
       {
        case 1 : printf("Acquisizione di file di due matrici:\n");
                 acquisizionedafile( Matrici1ptr, matrice1 );
                 acquisizionedafile( Matrici2ptr, matrice2 );
                 break;

        case 2 : printf("Uguaglianza tra due righe delle due matrici selezionate\n");
                 printf("Scegli l'indice della riga delle due matrici da confrontare : ");
                 scanf("%d", &indice );

                 acquisizionedafile( Matrici1ptr, matrice1 );
                 acquisizionedafile( Matrici2ptr, matrice2 );
                 uguaglianzamatrici( Uguaglianzeptr, matrice1[righe][4], matrice2[righe][4], matrice3[righe][4], indice );
                 break;

        case 3 : printf("Scegli la matrice al quale applicare il calcolo della traspost: \n"
                        "1 per applicare il calcolo sulla prima matrice\n"
                        "2 per applicare il calcolo sulla seconda matrice\n");
                int n; /*variabile per la scelta della matrice su cui applicare il calcolo della trasposta */
                scanf("%d", &n);
                if (n==1)
                {
                    acquisizionedafile( Matrici1ptr, matrice1 );
                    trasposta(matrice1);
                }
                if (n==2)
                {
                    acquisizionedafile( Matrici2ptr, matrice2 );
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
void acquisizionedafile( FILE *fileptr, int matrice[righe][4] )
{
 if( ( fileptr = fopen( fileptr, "r+") ) == NULL )
                    {
                      printf("Non e' stato possibile aprire i file 'Matrici1.txt' e 'Matrici2.txt'\n");
                    }
                 else
                    {

                     fclose( fileptr);
                    }

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

void uguaglianzamatrici( FILE *Uguaglianzeptr, int matrice1[4][4], int matrice2[4][colonne], int matrice3[4][colonne], int indice )
{
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
