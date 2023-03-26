#include "../Includes/transverse_puissance4.h"
#include "../Includes/interface_puissance4.h"

int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window = SDL_CreateWindow("Ma fenêtre SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_LARGEUR, WIN_HAUTEUR, SDL_WINDOW_RESIZABLE);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface* imageSurface = IMG_Load("/Images/texte_puissance4.png");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    
    int coor_grilleX = 50;
    int coor_grilleY = 150;

    char **grille;
    int gagnant;
    
    grille = create_grille();
    if (!grille)
    {
        printf("Problème à la création de la grille.\n");
        return (0);
    }

    //afficher le plateau de jeu au debut
    aff_fond(grille, renderer, imageSurface, texture, coor_grilleX, coor_grilleY, 0);
    SDL_RenderPresent(renderer);

    gagnant = resolution(grille, renderer, imageSurface, texture, coor_grilleX, coor_grilleY);
    if (gagnant == 0)
        printf("Égalité entre les deux joueurs !\n"); //AFFICHER UNE EGALITÉ
    else if (gagnant == -1)
        printf("Fin de jeu\n");
    else
        printf("Le joueur %d a gagné !\n", gagnant); //AFFICHER UN MESSAGE POUR LE GAGNANT

    //afficher le plateau de jeu a la fin
    aff_fond(grille, renderer, imageSurface, texture, coor_grilleX, coor_grilleY, 0);
    SDL_RenderPresent(renderer);
    //AFFICHER UN MESSAGE DE FIN DE JEU

    int running = 1;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }
    }
    SDL_FreeSurface(imageSurface);
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
