#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "funzioni.h"

#define righe 4
#define colonne 4
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
