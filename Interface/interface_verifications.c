#include "../Includes/transverse_puissance4.h"
#include "../Includes/interface_puissance4.h"

int valid_col(char **grille, int col)
{
    if (!(col >= 0 && col < LARGEUR))
        return (0);
    if (grille[0][col] != '0')
        return (0);
    return (1);
}

/* regarde si y'a un puissance 4 sur une ligne */
int puissance_ligne(char **grille, char c, struct sol *s)
{
    int compteur;
    int i;
    int j;

    compteur = 0;
    i = 0;
    while (grille[i])
    {
        j = 0;
        while (grille[i][j])
        {
            compteur = 0;
            if (grille[i][j] == c)
            {
                s->x_debut = j;
                s->y_debut = i;
                compteur++;
                j++;
                while (grille[i][j] && grille[i][j++] == c)
                    compteur++;
                if (compteur >= NB_JETONS)
                {
                    s->x_fin = s->x_debut + (compteur);
                    s->y_fin = i;
                    s->type = 'L';
                    return (1);
                }
                s->x_debut = -1;
                s->y_debut = -1;
            }
            else
                j++;
        }
        i++;
    }
    return (0);
}

/* regarde si y'a un puissance 4 sur une colonne */
int puissance_colonne(char **grille, char c, struct sol *s)
{
    int compteur;
    int i;
    int j;

    compteur = 0;
    j = 0;
    while (j < LARGEUR)
    {
        i = 0;
        while (i < HAUTEUR)
        {
            compteur = 0;
            if (grille[i][j] == c)
            {
                s->x_debut = j;
                s->y_debut = i;
                compteur++;
                i++;
                while (i < HAUTEUR && grille[i++][j] == c)
                    compteur++;
                if (compteur >= NB_JETONS)
                {
                    s->x_fin = j;
                    s->y_fin = s->y_debut + compteur;
                    s->type = 'C';
                    return (1);
                }
                s->x_debut = -1;
                s->y_debut = -1;
            }
            else
                i++;
        }
        j++;
    }
    return (0);
}

/* regarde si y'a un puissance 4 sur une diagonale vers la droite (en partant du haut) */
int puissance_diag_droite(char **grille, char c, struct sol *s)
{
    int i;
    int j;
    int tmp_i;
    int tmp_j;
    int compteur;

    i = 0;
    while (i < HAUTEUR)
    {
        j = 0;
        while (j < LARGEUR)
        {
            compteur = 0;
            if (grille[i][j] == c)
            {
                s->x_debut = j;
                s->y_debut = i;
                tmp_i = i;
                tmp_j = j;
                compteur++;
                i++;
                j++;
                while (i < HAUTEUR && j < LARGEUR && grille[i++][j++] == c)
                    compteur++;
                if (compteur >= NB_JETONS)
                {
                    s->x_fin = s->x_debut + compteur;
                    s->y_fin = s->y_debut + compteur;
                    s->type = 'D';
                    return (1);
                }
                s->x_debut = -1;
                s->y_debut = -1;
                i = tmp_i;
                j = tmp_j + 1;
            }
            else
                j++;
        }
        i++;
    }
    return (0);
}

/* regarde si y'a un puissance 4 sur une diagonale vers la gauche (en partant du haut) */
int puissance_diag_gauche(char **grille, char c, struct sol *s)
{
    int i;
    int j;
    int tmp_i;
    int tmp_j;
    int compteur;

    i = 0;
    while (i < HAUTEUR)
    {
        j = LARGEUR - 1;
        while (j >= 0)
        {
            compteur = 0;
            if (grille[i][j] == c)
            {
                s->x_debut = j;
                s->y_debut = i;
                tmp_i = i;
                tmp_j = j;
                compteur++;
                i++;
                j--;
                while (i < HAUTEUR && j < LARGEUR && grille[i++][j--] == c)
                    compteur++;
                if (compteur >= NB_JETONS)
                {
                    s->x_fin = s->x_debut - compteur ;
                    s->y_fin = s->y_debut + compteur;
                    s->type = 'G';
                    return (1);
                }
                s->x_debut = -1;
                s->y_debut = -1;
                i = tmp_i;
                j = tmp_j - 1;
            }
            else
                j--;
        }
        i++;
    }
    return (0);
}

/* Determine grace au verificiation si il a un puissance 4 et qui est le joueur gagnant */
int gagnant(char **grille, int joueur, struct sol *s)
{
    char jeton;

    if (joueur == 1)
        jeton = 'O';
    else
        jeton = 'X';
    if (puissance_ligne(grille, jeton, s))
        return (1);
    if (puissance_colonne(grille, jeton, s))
        return (1);
    if (puissance_diag_droite(grille, jeton, s))
        return (1);
    if (puissance_diag_gauche(grille, jeton, s))
        return (1);
    return (0);
}

/* renvoie 1 si la grille est completement remplie, 0 sinon */
int is_full(char **grille)
{
    int i;
    int j;

    i = 0;
    while (i < HAUTEUR)
    {
        j = 0;
        while (j < LARGEUR)
        {
            if (grille[i][j] == '0')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}