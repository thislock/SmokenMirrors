
#include "bgfx/defines.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_video.h>
#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

#include <assert.h>

#include "constants.h"
#include <iostream>

void log(char * str) {
    std::cout << "LOG: " << str << ".\n";
}

bgfx::PlatformData getPlatformData(SDL_Window* window) { 
    bgfx::PlatformData pd{}; 
    #if defined(SDL_PLATFORM_WIN32) 
    pd.nwh = SDL_GetProperty(SDL_GetWindowProperties(window), SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr); 
    #elif defined(SDL_PLATFORM_MACOS) 
    pd.nwh = SDL_GetProperty(SDL_GetWindowProperties(window), SDL_PROP_WINDOW_COCOA_WINDOW_POINTER, nullptr); 
    #elif defined(SDL_PLATFORM_LINUX) 
    if (SDL_strcmp(SDL_GetCurrentVideoDriver(), "wayland") == 0) 
    { 
        pd.ndt = SDL_GetPointerProperty( SDL_GetWindowProperties( window ), SDL_PROP_WINDOW_WAYLAND_DISPLAY_POINTER, 0 );
        pd.nwh = SDL_GetPointerProperty( SDL_GetWindowProperties( window ), SDL_PROP_WINDOW_WAYLAND_SURFACE_POINTER, 0 );
        pd.type = bgfx::NativeWindowHandleType::Wayland;
    } else if (SDL_strcmp(SDL_GetCurrentVideoDriver(), "x11") == 0) 
    { 
        pd.ndt = SDL_GetPointerProperty(SDL_GetWindowProperties(window), SDL_PROP_WINDOW_X11_DISPLAY_POINTER, 0); 
        pd.nwh = (void*)SDL_GetNumberProperty(SDL_GetWindowProperties(window), SDL_PROP_WINDOW_X11_WINDOW_NUMBER, 0); 
    }
    #endif 
    bgfx::setPlatformData(pd);
    return pd;
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

    EngineMain engine = EngineMain();

    engine.run_engine();

    // quit
}

int main(void) {

    if (!SDL_Init(0)) {
        log("error; SDL failed to initialise.");
        return 1;
    }

    SDL_Window * window = SDL_CreateWindow("SmokenMirrors", DEFAULT_RESOLUTION, 0);
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
