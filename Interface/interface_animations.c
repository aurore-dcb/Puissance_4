#include "../Includes/transverse_puissance4.h"
#include "../Includes/interface_puissance4.h"

void dessiner_rectangle_blanc(SDL_Renderer* renderer, int x, int y, int largeur, int hauteur)
{
    // Changer la couleur de rendu en blanc
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Dessiner le rectangle blanc
    SDL_Rect rect = {x, y, largeur, hauteur};
    SDL_RenderFillRect(renderer, &rect);
}

void animation_gagnant(SDL_Renderer* renderer, int gagnant)
{
    int running = 1;
    int show_image = 1; // afficher l'image par défaut
    Uint32 last_time = SDL_GetTicks(); // temps écoulé depuis le démarrage de l'application (en millisecondes)

    SDL_Texture* textureGagnant = NULL;
    SDL_Rect dstrect = {0, 0, 0, 0};

    SDL_Surface* imgGagnant = NULL;
    if (gagnant == 1)
        imgGagnant = IMG_Load("/Images/joueur1.png");
    else if (gagnant == 2)
        imgGagnant = IMG_Load("/Images/joueur2.png");
    else
        return ;//peut etre afficher l'egalité

    if (imgGagnant == NULL)
        return ;

    // AFFICHER LES CONFETTIS
    display_confetti(renderer, 100);

    // Remplir la fenêtre avec la couleur de fond
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //blanc
    SDL_RenderClear(renderer); //appliquer la couleur blanche sur le fond
    SDL_RenderPresent(renderer);

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    return ;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_RETURN:
                            running = 0;
                            return ;
                    }
            }
        }

        // Remplir la fenêtre avec la couleur de fond
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //blanc
        SDL_RenderClear(renderer); //appliquer la couleur blanche sur le fond

        // //AFFICHER JETONS
        // dessiner_jetons(grille, renderer, coor_grilleY, coor_grilleX);

        // //GRILLE
        // SDL_SetRenderDrawColor(renderer, 0, 0, 155, 255);
        // dessiner_grille(renderer, coor_grilleX, coor_grilleY, LARGEUR, HAUTEUR, (WIN_LARGEUR - (2*50))/LARGEUR, (WIN_HAUTEUR - coor_grilleY - 15)/HAUTEUR);

        int x = (WIN_LARGEUR / 2) - ((imgGagnant->w) / 4);
        int y = (WIN_HAUTEUR / 2) - ((imgGagnant->h) / 4);
        dstrect.x = x;
        dstrect.y = y;
        dstrect.w = (imgGagnant->w) / 2;
        dstrect.h = (imgGagnant->h) / 2;
        if (show_image) // afficher l'image si la variable show_image est vraie
        {
            //AFFICHER LE GAGNANT
            textureGagnant = SDL_CreateTextureFromSurface(renderer, imgGagnant);
            SDL_RenderCopy(renderer, textureGagnant, NULL, &dstrect);
            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(textureGagnant);
        }
        else
        {
            dessiner_rectangle_blanc(renderer, dstrect.x, dstrect.y, dstrect.w, dstrect.h);
            SDL_RenderPresent(renderer);
        }
        Uint32 current_time = SDL_GetTicks();
        if (current_time - last_time >= 750) // changer l'état de la variable show_image toutes les 500 millisecondes
        { 
            show_image = !show_image;
            last_time = current_time;
        }
    }
    SDL_FreeSurface(imgGagnant);
}