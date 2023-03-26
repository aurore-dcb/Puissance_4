#include "../Includes/transverse_puissance4.h"
#include "../Includes/interface_puissance4.h"

int resolution(char **grille, SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY)
{
    int j;
    int joueur;
    int fin_de_jeu;
    int num_c;
    int valid;
    
    fin_de_jeu = 0;
    num_c = 0;
    j = 0;
    while (fin_de_jeu == 0)
    {
        joueur = j % 2 + 1;
        valid = 0;
        while (valid == 0)
        {
            num_c = move_curseur(grille, renderer, imageSurface, texture, coor_grilleX, coor_grilleY, joueur);
            if (num_c == -1)
                return (-1);
            valid = valid_col(grille, num_c);
        }
        placer_jeton(grille, num_c, joueur);
        if (gagnant(grille, joueur))
            return (joueur);
        j++;
        if (is_full(grille))
            return (0);
    }
    return (j);
}