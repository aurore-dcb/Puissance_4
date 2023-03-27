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

/* regarde si la colonne où le joueur veut mettre le jeton existe et qu'elle n'est pas déjà pleine */
int valid_col(char **grille, int col);

/* renvoie 1 si la grille est completement remplie, 0 sinon */
int is_full(char **grille);



#endif