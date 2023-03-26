#include "../Includes/transverse_puissance4.h"
#include "../Includes/interface_puissance4.h"

void dessiner_grille(SDL_Renderer* renderer, int x, int y, int nb_colonnes, int nb_lignes, int largeur_cellule, int hauteur_cellule)
{
    // Dessiner les lignes verticales
    for (int i = 0; i <= nb_colonnes; i++) {
        SDL_RenderDrawLine(renderer, x + i * largeur_cellule, y, x + i * largeur_cellule, y + nb_lignes * hauteur_cellule);
    }

    // Dessiner les lignes horizontales
    for (int i = 0; i <= nb_lignes; i++) {
        SDL_RenderDrawLine(renderer, x, y + i * (hauteur_cellule), x + nb_colonnes * (largeur_cellule), y + i * (hauteur_cellule));
    }
}

void dessiner_curseur(SDL_Renderer* renderer, int x, int y, int w)
{
    SDL_RenderDrawLine(renderer, x + (w/2), y, x + (w/2), y + w);
    SDL_RenderDrawLine(renderer, x , y + (w/2), x + (w/2), y + w);
    SDL_RenderDrawLine(renderer, x + w , y + (w/2), x + (w/2), y + w);
}

int move_curseur(SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY)
{
    int pos = 0;
    int running = 1;
    int x = 50; // position du curseur au depart
    int y = 70; 
    bool redraw = false;
    int w = (WIN_LARGEUR - (2*50))/LARGEUR;
    SDL_Rect curseur_rect = { x, y, w, w };
    
    aff_fond(renderer, imageSurface, texture, coor_grilleX, coor_grilleY);
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
                        aff_fond(renderer, imageSurface, texture, coor_grilleX, coor_grilleY);
                        SDL_RenderPresent(renderer);
                        return(pos);
                }
                break;
            }
        }
        if (redraw)
        {   
            aff_fond(renderer, imageSurface, texture, coor_grilleX, coor_grilleY);
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
            dessiner_curseur(renderer, x, y, w);
            SDL_RenderPresent(renderer);
            redraw = false;
        }
    }
    return (-1);
}

/* Dessine l'arriere plan */
void aff_fond(SDL_Renderer* renderer, SDL_Surface* imageSurface, SDL_Texture* texture, int coor_grilleX, int coor_grilleY)
{
    // Remplir la fenêtre avec la couleur de fond
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //blanc
    SDL_RenderClear(renderer); //appliquer la couleur blanche sur le fond
    
    // Afficher le texte "Puissance 4"
    int x = WIN_LARGEUR / 2 - (imageSurface->w) / 4;
    int y = 0;
    SDL_Rect dstrect = {x, y, (imageSurface->w) / 2, (imageSurface->h) / 2};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    //GRILLE
    SDL_SetRenderDrawColor(renderer, 0, 0, 155, 255);
    dessiner_grille(renderer, coor_grilleX, coor_grilleY, LARGEUR, HAUTEUR, (WIN_LARGEUR - (2*50))/LARGEUR, (WIN_HAUTEUR - coor_grilleY - 15)/HAUTEUR);
}