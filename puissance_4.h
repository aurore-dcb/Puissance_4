#ifndef PUISSANCE_4_H
# define PUISSANCE_4_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef HAUTEUR
# define HAUTEUR 6
#endif 

#ifndef LARGEUR
# define LARGEUR 7
#endif

/* alloue et crée la grille de jeu */
char **create_grille(void);
/* Libère tout l'espace alloué de la grille principale */
void free_tab(char **grille);
/* affiche la grille de jeu */
void aff_grille(char **grille);
/* fonction principale, boucle de jeu */
int resolution(char **grille);

#endif