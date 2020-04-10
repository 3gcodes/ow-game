#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

class Game {
    public:
    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() {
        return isRunning;
    }

    private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;

};

#endif