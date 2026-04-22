
#include "platform_dependent.h"
#include <bgfx/platform.h>

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