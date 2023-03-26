#include "../Includes/transverse_puissance4.h"
#include "../Includes/interface_puissance4.h"

int resolution(char **grille, SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY)
{
    int j;
    int joueur;
    int fin_de_jeu;
    int num_c;

    fin_de_jeu = 0;
    num_c = 0;
    j = 0;
    while (fin_de_jeu == 0)
    {
        joueur = j % 2 + 1;
        printf("\n----- Tour du joueur %d -----\n", joueur); // AFFICHER LE JOUEUR QUI DOIT JOUER
        num_c = move_curseur(renderer, imageSurface, texture, coor_grilleX, coor_grilleY);
        if (num_c == -1)
            return (-1);
        placer_jeton(grille, num_c, joueur);
        // aff_grille(grille);
        if (gagnant(grille, joueur))
            return (joueur);
        j++;
        if (is_full(grille))
            return (0);
    }
    return (j);
}