#ifndef EMERALD_STATE_H
#define EMERALD_STATE_H


#include <SDL2/SDL_system.h>

class State {
public:

    void Render(SDL_Renderer *renderer);

    void Update(float d);
};


#endif //EMERALD_STATE_H
