#include "../Includes/transverse_puissance4.h"
#include "../Includes/interface_puissance4.h"

void dessiner_grille(SDL_Renderer* renderer, int x, int y, int nb_colonnes, int nb_lignes, int largeur_cellule, int hauteur_cellule)
{
    // Dessiner les lignes verticales
    for (int i = 0; i <= nb_colonnes; i++) {
        SDL_RenderDrawLine(renderer, x + i * largeur_cellule, y, x + i * largeur_cellule, y + nb_lignes * hauteur_cellule);
    }
    SDL_RenderDrawLine(renderer, x, y + nb_lignes * hauteur_cellule, x + nb_colonnes * largeur_cellule, y + nb_lignes * hauteur_cellule);
    // Dessiner les lignes horizontales
    // for (int i = 0; i <= nb_lignes; i++) {
    //     SDL_RenderDrawLine(renderer, x, y + i * (hauteur_cellule), x + nb_colonnes * (largeur_cellule), y + i * (hauteur_cellule));
    // }
}

void dessine_rond(SDL_Renderer* renderer, int x, int y, int h, int w, int r, int g, int b)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    int rayonX = h / 2;
    int rayonY = w / 2;
    int centreX = x + w / 2;
    int centreY = y + h / 2;
    for (int i = 0; i < rayonX * 2; i++)
    {
        for (int j = 0; j < rayonY * 2; j++)
        {
            int deltaX = centreX - (x + j);
            int deltaY = centreY - (y + i);
            if ((deltaX * deltaX + deltaY * deltaY) <= (rayonX * rayonX))
            {
                SDL_RenderDrawPoint(renderer, x + j, y + i);
            }
        }
    }
}

void dessiner_jetons(char **grille, SDL_Renderer* renderer, int coor_grilleY, int coor_grilleX)
{
    int i = 0;
    int j;
    Uint8 r1 = 255;
    Uint8 g1 = 255;
    Uint8 b1 = 0;

    Uint8 r2 = 255;
    Uint8 g2 = 0;
    Uint8 b2 = 0;

    int x = 0;
    int y = 0;
    int w = (WIN_LARGEUR - (2*50))/LARGEUR;
    int h = (WIN_HAUTEUR - coor_grilleY - 15)/HAUTEUR;

    SDL_Rect curseur_rect = { x, y, w, h };   

    curseur_rect.w = w - 10;
    curseur_rect.h = h - 10;
    while (i < HAUTEUR)
    {
        j = 0;
        while (j < LARGEUR)
        {
            y = coor_grilleY + (i * h);
            curseur_rect.y = y + 5;
            if (grille[i][j] == 'O')
            {
                x = coor_grilleX + (j * w);
                curseur_rect.x = x + 5;
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &curseur_rect);
                dessine_rond(renderer, x, y, h, w, r1, g1, b1);
            }
            else if (grille[i][j] == 'X')
            {
                x = coor_grilleX + (j * w);
                curseur_rect.x = x + 5;
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &curseur_rect);
                dessine_rond(renderer, x, y, h, w, r2, g2, b2);
            }
            j++;
        }
        i++;
        
    }
}

void dessiner_curseur(SDL_Renderer* renderer, int x, int y, int w)
{
    SDL_RenderDrawLine(renderer, x + (w/2), y, x + (w/2), y + w);
    SDL_RenderDrawLine(renderer, x , y + (w/2), x + (w/2), y + w);
    SDL_RenderDrawLine(renderer, x + w , y + (w/2), x + (w/2), y + w);
}

int move_curseur(char **grille, SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY, int joueur)
{
    int pos = 0;
    int running = 1;
    int x = 50; // position du curseur au depart
    int y = 70; 
    bool redraw = false;
    int w = (WIN_LARGEUR - (2*50))/LARGEUR;
    SDL_Rect curseur_rect = { x, y, w, w };
    
    aff_fond(grille, renderer, imageSurface, texture, coor_grilleX, coor_grilleY, joueur);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    dessiner_curseur(renderer, x, y, w);
    SDL_RenderPresent(renderer);

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        SDL_RenderClear(renderer);
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                        SDL_RenderFillRect(renderer, &curseur_rect);
                        if (pos > 0)
                        {
                            x -= (WIN_LARGEUR - (2*50))/LARGEUR;
                            pos--;
                            redraw = true;
                        }
                        break;
                    case SDLK_RIGHT:
                        SDL_RenderClear(renderer);
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                        SDL_RenderFillRect(renderer, &curseur_rect);
                        if (pos < LARGEUR - 1)
                        {
                            x += (WIN_LARGEUR - (2*50))/LARGEUR;
                            pos++;
                            redraw = true;
                        }
                        break;
                    case SDLK_RETURN:
                        SDL_RenderClear(renderer);
                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                        SDL_RenderFillRect(renderer, &curseur_rect);
                        aff_fond(grille, renderer, imageSurface, texture, coor_grilleX, coor_grilleY, joueur);
                        SDL_RenderPresent(renderer);
                        return(pos);
                }
                break;
            }
        }
        if (redraw)
        {   
            aff_fond(grille, renderer, imageSurface, texture, coor_grilleX, coor_grilleY, joueur);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
            dessiner_curseur(renderer, x, y, w);
            SDL_RenderPresent(renderer);
            redraw = false;
        }
    }
    return (-1);
}

/* Dessine l'arriere plan */
void aff_fond(char **grille, SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY, int joueur)
{
    (void)grille;
    // Remplir la fenêtre avec la couleur de fond
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //blanc
    SDL_RenderClear(renderer); //appliquer la couleur blanche sur le fond
    
    // Afficher le texte "Puissance 4"
    int x = WIN_LARGEUR / 2 - (imageSurface->w) / 4;
    int y = 0;
    SDL_Rect dstrect = {x, y, (imageSurface->w) / 2, (imageSurface->h) / 2};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    //AFFICHER JETONS
    dessiner_jetons(grille, renderer, coor_grilleY, coor_grilleX);

    //GRILLE
    SDL_SetRenderDrawColor(renderer, 0, 0, 155, 255);
    dessiner_grille(renderer, coor_grilleX, coor_grilleY, LARGEUR, HAUTEUR, (WIN_LARGEUR - (2*50))/LARGEUR, (WIN_HAUTEUR - coor_grilleY - 15)/HAUTEUR);

    //AFFICHER LE JOUEUR
    if (joueur != 0)
    {
        SDL_Surface* imgJoueur = NULL;
        if (joueur == 1)
            imgJoueur = IMG_Load("/Images/joueur1.png");
        else if (joueur == 2)
            imgJoueur = IMG_Load("/Images/joueur2.png");
        SDL_Texture* textureJoueur = SDL_CreateTextureFromSurface(renderer, imgJoueur);
        x = 0;
        y = 0;
        SDL_Rect dstrect = {x, y, (imgJoueur->w) / 4, (imgJoueur->h) / 4};
        SDL_RenderCopy(renderer, textureJoueur, NULL, &dstrect);
    }
   
}