
#include "bgfx/bgfx.h"
#include "constants.h"
#include "engine.h"


EngineMain::EngineMain(SDL_Window * window) {
    this->window = window;
}

EngineMain::~EngineMain() {

}

void EngineMain::run_engine() {

    PosColorVertex::init();

    bgfx::VertexBufferHandle vertex_buffer_handle = bgfx::createVertexBuffer(
        bgfx::makeRef(s_cubeVertices, sizeof(s_cubeVertices)), 
        PosColorVertex::ms_layout
    );
    
    bgfx::IndexBufferHandle index_buffer_handle = bgfx::createIndexBuffer(bgfx::makeRef(s_cubeTriList, sizeof(s_cubeTriList)));

    bgfx::ShaderHandle shader_h = bgfx::createShader();

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