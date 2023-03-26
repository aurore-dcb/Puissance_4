#ifndef INTERFACE_PUISSANCE4_H
# define INTERFACE_PUISSANCE4_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include </usr/local/Cellar/sdl_gfx/2.0.26_1/include/SDL/SDL_gfxPrimitives.h>
// #include <SDL2/SDL_gfxPrimitives.h>
#include "stdbool.h"

#define WIN_HAUTEUR 480
#define WIN_LARGEUR 640


#define COLOR_1
#define COLOR_2

/* Dessine l'arriere plan */
void aff_fond(char **grille, SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY, int joueur);

/* Dessine la grille de jeu */
void dessiner_grille(SDL_Renderer* renderer, int x, int y, int nb_colonnes, int nb_lignes, int largeur_cellule, int hauteur_cellule);

/*Permet de bouger le curseur et de recupérer sa position quand elle est validée par le joueur */
int move_curseur(char **grille, SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY, int joueur);
/* dessine un curseur */
void dessiner_curseur(SDL_Renderer* renderer, int x, int y, int w);

int resolution(char **grille, SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY);

/* affiche tous les jetons déjà placés sur la grille */
void dessiner_jetons(char **grille, SDL_Renderer* renderer, int coor_grilleY, int coor_grilleX);

/* dessine un rond sur le renderer */
void dessine_rond(SDL_Renderer* renderer, int x, int y, int h, int w, int r, int g, int b);

#endif