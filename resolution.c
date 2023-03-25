#include "puissance_4.h"

int resolution(char **grille)
{
    int j;
    int joueur;
    int fin_de_jeu;
    int num_c;
    int valid;

    fin_de_jeu = 0;
    num_c = 0;
    j = 0;
    printf("Le joueur 1 commence et joue avec les 'O'.\n");
    while (fin_de_jeu == 0)
    {
        valid = 0;
        joueur = j % 2 + 1;
        while (valid == 0)
        {
            printf("Numéro de colonne : ");
            scanf ("%d", &num_c);
            valid = valid_col(grille, num_c);
        }
        placer_jeton(grille, num_c, joueur);
        aff_grille(grille);
        if (gagnant(grille, joueur))
            return (joueur);
        j++;
        if (is_full(grille))
            return (0);
    }
    return (j);
}