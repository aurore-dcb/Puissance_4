#include "puissance_4.h"

void free_tab(char **grille)
{
    int i;

    i = 0;
    while (grille[i])
        free(grille[i++]);
    free(grille);
}



int main(void)
{
    printf("\n\n      ----- JEU DU PUISSANCE 4 -----\n\n");
    printf("Le jeu se joue à deux joueurs : déterminez qui est le joueur 1 et qui est le joueur 2 avant de commencer la partie.\nLe joueur qui commence est déterminé aléatoirement.\n\n");
    
    char **grille;
    int gagnant;

    grille = create_grille();
    if (grille == NULL)
    {
        printf("Problème à la création de la grille.\n");
        return (0);
    }
    aff_grille(grille);
    gagnant = resolution(grille);
    if (gagnant == 0)
        printf("Égalité entre les deux joueurs !\n");
    else
        printf("Le joueur %d a gagné !\n", gagnant);
    return (0);
}