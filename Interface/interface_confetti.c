#include "../Includes/transverse_puissance4.h"
#include "../Includes/interface_puissance4.h"

void display_confetti(SDL_Window *window, SDL_Renderer *renderer) {
    // Définir les propriétés des confettis
    int confetti_size = 10;
    int confetti_speed = 200;
    float confetti_lifetime = 5.0;
    int num_confetti = 100;

    // Créer un générateur de nombres aléatoires
    srand(time(NULL));

    // Créer une surface pour chaque confetti
    SDL_Surface *confetti_surfaces[num_confetti];
    for (int i = 0; i < num_confetti; i++) {
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        SDL_Surface *confetti_surface = SDL_CreateRGBSurface(0, confetti_size, confetti_size, 32, 0, 0, 0, 0);
        SDL_FillRect(confetti_surface, NULL, SDL_MapRGB(confetti_surface->format, r, g, b));
        confetti_surfaces[i] = confetti_surface;
    }

    // Initialiser les positions et les durées de vie des confettis
    SDL_Rect confetti_pos[num_confetti];
    float confetti_lifetime_remaining[num_confetti];
    for (int i = 0; i < num_confetti; i++) {
        confetti_pos[i].x = rand() % (SDL_GetWindowSurface(window)->w - confetti_size);
        confetti_pos[i].y = rand() % (SDL_GetWindowSurface(window)->h - confetti_size);
        confetti_lifetime_remaining[i] = ((float) rand() / RAND_MAX) * confetti_lifetime;
    }

    // Boucle principale pour afficher les confettis
    int running = 1;
    Uint32 last_time = SDL_GetTicks();
    while (running) {
        // Calculer le temps écoulé depuis la dernière frame
        Uint32 current_time = SDL_GetTicks();
        float elapsed_time = (current_time - last_time) / 1000.0f;
        last_time = current_time;

        // Gérer les événements SDL (cliquer sur la croix pour fermer la fenêtre)
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
            }
        }

        // Mettre à jour les positions et les durées de vie des confettis
        for (int i = 0; i < num_confetti; i++) {
            confetti_lifetime_remaining[i] -= elapsed_time;
            if (confetti_lifetime_remaining[i] <= 0) {
                confetti_pos[i].x = rand() % (SDL_GetWindowSurface(window)->w - confetti_size);
                confetti_pos[i].y = rand() % (SDL_GetWindowSurface(window)->h - confetti_size);
                confetti_lifetime_remaining[i] = ((float) rand() / RAND_MAX) * confetti_lifetime;
            }

            confetti_pos[i].y += confetti_speed * elapsed_time;
        }

        // Dessiner les confettis sur la fenêtre
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < num_confetti; i++) {
            SDL_Texture *confetti_texture = SDL_CreateTextureFromSurface(renderer, confetti_surfaces[i]);
            SDL_RenderCopy(renderer, confetti_texture, NULL, &confetti_pos[i]);
            SDL_DestroyTexture(confetti_texture);
        }
        SDL_RenderPresent(renderer);

        // Attendre un petit moment avant de passer à la prochaine frame
        SDL_Delay(10);
    }

    // Libérer la mémoire utilisée par les surfaces des confettis
    for (int i = 0; i < num_confetti; i++) {
        SDL_FreeSurface(confetti_surfaces[i]);
    }
}
