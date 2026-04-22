
#include "constants.h"
#include "engine.h"

#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <bgfx/defines.h>


EngineMain::EngineMain(SDL_Window * window) {
    this->window = window;
}

EngineMain::~EngineMain() {

}

void EngineMain::run_engine() {
    
    bool running = true;
    while (running) {

        while ( SDL_PollEvent(&this->current_event) ) 
        {
            switch(this->current_event.type) 
            {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
                    running = false;
                    break;
            }
        }
        
        bgfx::setViewRect(0, 0, 0, DEFAULT_RESOLUTION);


        bgfx::touch(0);
        bgfx::frame();

    }
}