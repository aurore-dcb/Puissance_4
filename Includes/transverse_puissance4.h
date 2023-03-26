#ifndef TRANSVERSE_PUISSANCE4_H
# define TRANSVERSE_PUISSANCE4_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef HAUTEUR
# define HAUTEUR 6
#endif 

#ifndef LARGEUR
# define LARGEUR 7
#endif

#ifndef NB_JETONS
# define NB_JETONS 4
#endif

/* alloue et crée la grille de jeu */
char **create_grille(void);

/* ajoute sur la grille le nouveau jeton dans la colonne demandée */
void placer_jeton(char **grille, int col, int joueur);

/* Libère tout l'espace alloué de la grille principale */
void free_tab(char **grille);

/* regarde si y'a un puissance 4 sur une ligne */
int puissance_ligne(char **grille, char c);
/* regarde si y'a un puissance 4 sur une colonne */
int puissance_colonne(char **grille, char c);
/* regarde si y'a un puissance 4 sur une diagonale vers la droite (en partant du haut) */
int puissance_diag_droite(char **grille, char c);
/* regarde si y'a un puissance 4 sur une diagonale vers la gauche (en partant du haut) */
int puissance_diag_gauche(char **grille, char c);

/* Determine grace au verificiation si il a un puissance 4 et qui est le joueur gagnant */
int gagnant(char **grille, int joueur);

/* renvoie 1 si la grille est completement remplie, 0 sinon */
int is_full(char **grille);



#endif