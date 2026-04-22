
#pragma once
#include <SDL3/SDL.h>

class EngineMain {

public:

    EngineMain(SDL_Window * window);
    ~EngineMain();

    void run_engine();
    
private:

    SDL_Window * window;

    SDL_Event current_event;    

};