#ifndef INTERFACE_PUISSANCE4_H
# define INTERFACE_PUISSANCE4_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include </usr/local/Cellar/sdl_gfx/2.0.26_1/include/SDL/SDL_gfxPrimitives.h>
//
#include "stdbool.h"

#define WIN_HAUTEUR 480
#define WIN_LARGEUR 640

typedef struct sol
{
    int x_debut;
    int y_debut;
    int x_fin;
    int y_fin;
    char type;
} solution;

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

int resolution(char **grille, SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY, struct sol *s);

/* regarde si y'a un puissance 4 sur une ligne */
int puissance_ligne(char **grille, char c, struct sol *s);
/* regarde si y'a un puissance 4 sur une colonne */
int puissance_colonne(char **grille, char c, struct sol *s);
/* regarde si y'a un puissance 4 sur une diagonale vers la droite (en partant du haut) */
int puissance_diag_droite(char **grille, char c, struct sol *s);
/* regarde si y'a un puissance 4 sur une diagonale vers la gauche (en partant du haut) */
int puissance_diag_gauche(char **grille, char c, struct sol *s);

/* Determine grace au verificiation si il a un puissance 4 et qui est le joueur gagnant */
int gagnant(char **grille, int joueur, struct sol *s);

/* affiche tous les jetons déjà placés sur la grille */
void dessiner_jetons(char **grille, SDL_Renderer* renderer, int coor_grilleY, int coor_grilleX);

/* dessine un rond sur le renderer */
void dessine_rond(SDL_Renderer* renderer, int x, int y, int h, int w, int r, int g, int b);

void animation_gagnant(char **grille, SDL_Renderer* renderer, int coor_grilleY, int coor_grilleX, int gagnant, struct sol *s);
void dessiner_ligne_epaisse(SDL_Renderer *renderer, int x1, int y1, int x2, int y2, int epaisseur);
void tracer_solution(SDL_Renderer* renderer, struct sol *s, int coor_grilleX, int coor_grilleY);
void display_confetti(SDL_Renderer *renderer, int num_confetti);

#endif