#include <iostream>
#include <SDL2/SDL.h>
#include "Game.hpp"

using namespace std;

Game *game = nullptr;

int main() {

    const int FPS = 60;
    const int frameDelay = 1000 / FPS; // max time between frames
    Uint32 frameStart;
    int frameTime;


    game = new Game();
    game->init("OneWheel Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    while(game->running()) {

        frameStart = SDL_GetTicks(); // how many ms it has been since SDL was initialized

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart; // how many ms doing the above functions

        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();

    return 0;
}