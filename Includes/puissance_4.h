#ifndef PUISSANCE_4_H
# define PUISSANCE_4_H


/* affiche la grille de jeu */
void aff_grille(char **grille);
/* fonction principale, boucle de jeu */
int resolution(char **grille);
/* Renvoie 1 si on peut placer le jeton dans la colonne demandées, 0 sinon */
int valid_col(char **grille, int col);

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


#endif