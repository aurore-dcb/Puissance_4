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

    struct sol *s;
    s = (struct sol*) malloc(sizeof(struct sol));
    if (s == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        return (-1);
    }
    s->x_debut = -1;
    s->y_debut = -1;
    s->x_fin = -1;
    s->y_fin = -1;

    grille = create_grille();
    if (!grille)
    {
        printf("Problème à la création de la grille.\n");
        return (-1);
    }

    //afficher le plateau de jeu au debut
    aff_fond(grille, renderer, imageSurface, texture, coor_grilleX, coor_grilleY, 0);
    SDL_RenderPresent(renderer);

    gagnant = resolution(grille, renderer, imageSurface, texture, coor_grilleX, coor_grilleY, s);

    printf("Début : (%d,%d)\n", s->x_debut, s->y_debut);
    printf("Fin : (%d,%d)\n", s->x_fin, s->y_fin);

    animation_gagnant(grille, renderer, coor_grilleX, coor_grilleY, gagnant, s);

    SDL_Delay(500);

    // Fenetre de fin
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //blanc
    SDL_RenderClear(renderer); //appliquer la couleur blanche sur le fond
    
    // Afficher le texte "Puissance 4"
    int x = WIN_LARGEUR / 2 - (imageSurface->w) / 4;
    int y = 0;
    SDL_Rect dstrect = {x, y, (imageSurface->w) / 2, (imageSurface->h) / 2};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_RenderPresent(renderer);

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
