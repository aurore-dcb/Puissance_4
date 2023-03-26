#ifndef PUISSANCE_4_H
# define PUISSANCE_4_H


/* affiche la grille de jeu */
void aff_grille(char **grille);
/* fonction principale, boucle de jeu */
int resolution(char **grille);
/* Renvoie 1 si on peut placer le jeton dans la colonne demandées, 0 sinon */
int valid_col(char **grille, int col);


#endif