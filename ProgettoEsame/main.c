#include <stdio.h>
#include <stdlib.h>

void menu( void );
void acquisizionedafile( FILE *fileptr, int matrice[4][4] );
void uguaglianzamatrici( int matrice1[4][4], int matrice2[4][4], int matrice3[4][4], int indice );
void trasposta(int matrice[4][4]);
void swap(int* a, int *b);


int main()
{


  printf("Benvenuto, faccia la sua scelta tra le seguenti : \n");

  menu();

    return 0;
}

void menu( void )
{
  int scelta, indice, j;
  int matrice1[4][4], matrice2[4][4], matrice3[4][4];
  FILE *Matrici1ptr, *Matrici2ptr, *Uguaglianzaptr;

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
        case 1 : printf("Acquisizione di file di due matrici:\n);
                  if( ( Matrici1ptr = fopen("Matrici1.txt", "r") ) == NULL && ( Matrici2ptr = fopen("Matrici2.txt", "r") ) == NULL )
                    {
                      printf("Non e' stato possibile aprire i file 'Matrici1.txt' e 'Matrici2.txt'\n");
                    }
                 else
                    {
                     acquisizionedafile( Matrici1ptr, matrice1 );
                     acquisizionedafile( Matrice2ptr, matrice2 );
                     fclose( Matrici1ptr);
                     fclose( Matrici2ptr);
                    }
                 break;

        case 2 : printf("Uguaglianza tra due righe delle due matrici selezionate\n");
                 printf("Scegli l'indice della riga delle due matrici da confrontare : ");
                 scanf("%d", &indice );

                 acquisizionedafile( Matrici1ptr, matrice1 );
                 acquisizionedafile( Matrice2ptr, matrice2 );
                 uguaglianzamatrici(  matrice1[4][4], matrice2[4][4], matrice3[4][4], indice );

                     for( j = 0; j < 4; j++ )
                        {
                         if( matrice1[indice][j] = matrice2[indice][j] )
                           {
                            matrice3[indice][j] = matrice1[indice][j];
                           }
                        }

                     if( ( Uguaglianzaptr = fopen("Uguaglianza.txt", "w") ) == NULL )
                       {
                        printf("Non e' stato possibile aprire il file 'Uguaglianza.txt'\n");
                       }
                    else
                      {
                       for( i = 0; i < 4; i++ )
                          {
                           for( j = 0; j < 4; j++)
                              { fprintf( Uguaglianzaptr ,"%d ", matrice3[i][j]);
                                printf("%d ", matrice[i][j]);
                              }
                            puts("");
                          }
                        fclose(Uguaglianzaptr);
                      }
        case 3 : printf("Scegli la matrice al quale applicare il calcolo della traspost: \n"
                        "1 per applicare il calcolo sulla prima matrice\n"
                        "2 per applicare il calcolo sulla seconda matrice\n");
                int n; //variabile per la scelta della matrice su cui applicare il calcolo della trasposta
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
void acquisizionedafile( FILE *fileptr, int matrice[4][4] );
{

}
void swap(int* a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
// Converts A[][] to its transpose
void trasposta(int matrice[4][4])
{

    int i, j;
    for (int i = 0; i < 4; i++){
        for (int j = i + 1; j < 4; j++){
            swap(&A[i][j],&A[j][i]);
        }
    }
}
