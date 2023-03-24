#include "puissance_4.h"

int resolution(char **grille)
{
    int j;
    int fin_de_jeu;
    int num_c;

    (void)grille;
    fin_de_jeu = 0;
    num_c = 0;
    srand(time(NULL));
    j = rand()%2+1;
    printf("Le joueur %d commence et joue avec les 'O'.\n", j);
    while (fin_de_jeu == 0)
    {
        do {
            printf("Numéro de colonne : ");
            scanf ("%d", &num_c);
        } while (!(num_c >= 0 && num_c < LARGEUR));
        // if (all_verif == 1)
        //     return (j);
        // if (grille_full(grille))
        //     return (0);
    }
    return (j);
}