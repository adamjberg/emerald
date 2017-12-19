//
// Created by Adam Berg on 2017-12-11.
//

#include <iostream>
#include "SDL2/SDL.h"
#include "Game.h"
#include "State.h"

Game::Game(const char *title, int width, int height, State *state) : title(title), width(width), height(height),
                                                                     state(state), running(true) {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height,
                              SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
}

Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}


void Game::Start() {
    while (running) {
        Loop();
    }
}

void Game::Loop() {
    HandleEvents();
    Update();
    Render();
}

void Game::HandleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
                running = false;
                break;
            default:
                break;
        }
    }
}


void Game::Update() {
    float dt = (SDL_GetTicks() - lastTick) / 1000.0f;
    lastTick = SDL_GetTicks();
    state->Update(dt);
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    state->Render(renderer);

    SDL_RenderPresent(renderer);
}


