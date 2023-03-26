#ifndef INTERFACE_PUISSANCE4_H
# define INTERFACE_PUISSANCE4_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "stdbool.h"

#define WIN_HAUTEUR 480
#define WIN_LARGEUR 640

/* Dessine l'arriere plan */
void aff_fond(SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY);

/* Dessine la grille de jeu */
void dessiner_grille(SDL_Renderer* renderer, int x, int y, int nb_colonnes, int nb_lignes, int largeur_cellule, int hauteur_cellule);

/* dessine un curseur */
int move_curseur(SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY);
void dessiner_curseur(SDL_Renderer* renderer, int x, int y, int w);

int resolution(char **grille, SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY);

#endif