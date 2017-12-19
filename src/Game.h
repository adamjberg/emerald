#ifndef EMERALD_GAME_H
#define EMERALD_GAME_H

class State;

struct SDL_Renderer;
struct SDL_Window;

class Game {
public:
    Game(const char *title, int width, int height, State *state);

    ~Game();

    void Start();

    void Loop();
    void Update();
    void Render();
    void HandleEvents();

    const char *title;
    unsigned int width;
    unsigned int height;
    State *state;
    bool running;
    SDL_Renderer *renderer;
    SDL_Window *window;
    unsigned int lastTick;
    unsigned int frameCount;
    unsigned int msPassed;
};


#endif //EMERALD_GAME_H
