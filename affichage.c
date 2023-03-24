#include "puissance_4.h"

void aff_num_colonne(void)
{
    int i = 0;
    while (i < LARGEUR)
    {
        if (i < 10)
            printf(" %d ", i);
        else if (i >= 10 && i < 100)
            printf(" %d", i);
        else
            printf("%d", i);
        if (i < LARGEUR - 1)
            printf(" ");
        i++;
    }
    printf("\n");
}

void aff_grille(char **grille)
{
    int i;
    int j;
    int k;

    i = 0;
    aff_num_colonne();
    while (grille[i])
    {
        j = 0;
        printf(" ");
        while (grille[i][j])
        {
            if (grille[i][j] == '0')
                printf("%c", ' ');
            else
                printf("%c", grille[i][j]);
            if (j < LARGEUR - 1)
                printf(" | ");
            j++;
        }
        if (i < HAUTEUR - 1)
        {
            printf("\n---");
            k = 0;
            while (++k < LARGEUR)
            {
                printf("----");
            }
        }
        i++;
        printf("\n");
    }
}
