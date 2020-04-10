#include <iostream>
#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

GameObject* player;

int cnt = 0;

using namespace std;

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        cout << "Subsystems initialized" << endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if (window) {
            cout << "Window created..." << endl;
            renderer = SDL_CreateRenderer(window, -1, 0);

            if (renderer) {
                cout << "Renderer created" << endl;
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                isRunning = true;
            } else {
                isRunning = false;
            }

            
        }

        
    }

    player = new GameObject("assets/onewheel.png", renderer, 0, 0);
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    };
}
void Game::update() {
   player->update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    // add stuff to render

    player->render();


    SDL_RenderPresent(renderer);

}
void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game cleaned" << endl;
}

