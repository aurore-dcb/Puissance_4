#include "../Includes/transverse_puissance4.h"
#include "../Includes/puissance_4.h"

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
            printf("\n----- Tour du joueur %d -----\n", joueur);
            printf("Numéro de colonne : ");
            if (scanf ("%d", &num_c) == 0)
                fflush(stdin);
            else
            {
                if (valid_col(grille, num_c) == 0)
                    valid = 0;
                else
                    valid = 1;
            }
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