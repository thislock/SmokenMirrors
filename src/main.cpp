

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_video.h>

#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

#include <assert.h>

#include "constants.h"
#include <iostream>

#include <bgfx/embedded_shader.h>

// #include <glsl/vs_color.sc.bin.h>
// const bgfx::EmbeddedShader k_vs = BGFX_EMBEDDED_SHADER(vs_color);

void log(char * str) {
    std::cout << "LOG: " << str << ".\n";
}

void initBgfx(bgfx::PlatformData & pd) {

    pd.context = NULL;
	pd.backBuffer = NULL;
	pd.backBufferDS = NULL;

    bgfx::Init init;

    init.platformData = pd;
    init.vendorId = BGFX_PCI_ID_NONE;
    
    init.type = bgfx::RendererType::Count; // auto
    
    init.resolution.width = DEFAULT_RESOLUTION_WIDTH;
    init.resolution.height = DEFAULT_RESOLUTION_HEIGHT;
    
    //init.resolution.reset = BGFX_RESET_VSYNC;
    bgfx::init(init);

    bgfx::setDebug(BGFX_DEBUG_TEXT);

    bgfx::setViewClear(0,
        BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH,
        0x443355FF,  // RGBA clear color
        1.0f,       // depth clear value
        0         // stencil clear value
    );
}

#include "engine.h"

void update_loop(SDL_Window * window) {

    EngineMain engine = EngineMain(
        window
    );

    engine.run_engine();

    // quit
}

#include "platform_dependent.h"
int main(void) {

    if (!SDL_Init(0)) {
        char msg[] = "error; SDL failed to initialise.";
        log(msg);
        return 1;
    }

    SDL_Window * window = SDL_CreateWindow("SmokenMirrors", DEFAULT_RESOLUTION, SDL_WINDOW_RESIZABLE);
    assert(window != nullptr);
    SDL_PumpEvents();
    SDL_SyncWindow(window);
    
    bgfx::PlatformData pd = getPlatformData(window);
    
    // force it to render a frame out, to make sure the buffer is set up
    bgfx::renderFrame(); 

    initBgfx(pd);

    update_loop(window);

    bgfx::shutdown();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
