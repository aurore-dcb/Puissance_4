#include "puissance_4.h"

char **create_grille(void)
{
    int i;
    int j;
    char **grille;

    i = 0;
    grille = malloc(sizeof(*grille) * (HAUTEUR + 1));
    if (!grille)
        return NULL;
    while (i < HAUTEUR)
    {
        grille[i] = malloc(sizeof(char) * (LARGEUR + 1));
        if (!grille[i])
        {
            free_tab(grille);
            return NULL;
        }
        j = 0;
        while (j < LARGEUR)
        {
            grille[i][j++] = '0';
        }
        grille[i++][j] = '\0';
    }
    grille[i] = 0;
    return (grille);
}

void placer_jeton(char **grille, int col, int joueur)
{
    int i;
    int jeton;

    i = HAUTEUR - 1;
    if (joueur == 1)
        jeton = 'O';
    else
        jeton = 'X';
    while (grille[i][col] != '0')
        i--;
    grille[i][col] = jeton;
}