
#pragma once
#include <SDL3/SDL.h>

class EngineMain {

public:

    EngineMain();
    ~EngineMain();

    void run_engine();
    
private:

    SDL_Event current_event;
    

};