#include "../Includes/transverse_puissance4.h"
#include "../Includes/interface_puissance4.h"

void display_confetti(SDL_Renderer *renderer, int num_confetti)
{
    // Remplir la fenêtre avec la couleur de fond
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //blanc
    SDL_RenderClear(renderer); //appliquer la couleur blanche sur le fond
    SDL_RenderPresent(renderer);

    // Définir les propriétés des confettis
    int confetti_size = 5;
    int confetti_speed = 20;
    float confetti_lifetime = 1.0;

    // Créer un générateur de nombres aléatoires
    srand(time(NULL));

    // Créer une texture pour chaque confetti
    SDL_Texture *confetti_textures[num_confetti];
    for (int i = 0; i < num_confetti; i++)
    {
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        SDL_Surface *confetti_surface = SDL_CreateRGBSurface(0, confetti_size, confetti_size, 32, 0, 0, 0, 0);
        SDL_FillRect(confetti_surface, NULL, SDL_MapRGB(confetti_surface->format, r, g, b));
        confetti_textures[i] = SDL_CreateTextureFromSurface(renderer, confetti_surface);
        SDL_FreeSurface(confetti_surface);
    }

    // Initialiser les positions et les durées de vie des confettis
    SDL_Rect confetti_pos[num_confetti];
    float confetti_lifetime_remaining[num_confetti];
    for (int i = 0; i < num_confetti; i++)
    {
        confetti_pos[i].x = rand() % WIN_LARGEUR;
        confetti_pos[i].y = rand() % WIN_HAUTEUR;
        confetti_lifetime_remaining[i] = ((float) rand() / RAND_MAX) * confetti_lifetime;
    }

    // Boucle principale pour afficher les confettis
    int running = 1;
    Uint32 last_time = SDL_GetTicks();
    while (running < 2000) {
        // Calculer le temps écoulé depuis la dernière frame
        Uint32 current_time = SDL_GetTicks();
        float elapsed_time = (current_time - last_time) / 1000.0f;
        last_time = current_time;

        // Mettre à jour les positions et les durées de vie des confettis
        for (int i = 0; i < num_confetti; i++) {
            confetti_lifetime_remaining[i] -= elapsed_time;
            if (confetti_lifetime_remaining[i] <= 0) {
                confetti_pos[i].x = rand() % WIN_LARGEUR;
                confetti_pos[i].y = rand() % WIN_HAUTEUR;
                confetti_lifetime_remaining[i] = ((float) rand() / RAND_MAX) * confetti_lifetime;
            }

            confetti_pos[i].y += confetti_speed * elapsed_time;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //blanc
        SDL_RenderClear(renderer); //appliquer la couleur blanche sur le fond
        // Dessiner les confettis sur le renderer
        for (int i = 0; i < num_confetti; i++) {
            SDL_Rect dest_rect = { confetti_pos[i].x, confetti_pos[i].y, confetti_size, confetti_size };
            SDL_RenderCopy(renderer, confetti_textures[i], NULL, &dest_rect);
        }

        // Mettre à jour l'affichage
        SDL_RenderPresent(renderer);
        running++;
    }
    // Libérer la mémoire utilisée par les textures des confettis
    for (int i = 0; i < num_confetti; i++) {
        SDL_DestroyTexture(confetti_textures[i]);
    }
}