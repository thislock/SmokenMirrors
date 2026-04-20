cmake_minimum_required(VERSION 3.10.0)
project(SmokenMirrors VERSION 0.1.0 LANGUAGES C CXX)


# rust like include system 
# (very nice, hats off to whoever made this)
include(FetchContent)

# bgfx graphics library
FetchContent_Declare(
    bgfx_cmake
    GIT_REPOSITORY https://github.com/bkaradzic/bgfx.cmake.git # a nice cmake build that follows bgfx (thanks bro)
    GIT_TAG v1.139.9155-513 # latest tag i found with "verified", so i hope that means stable.
)

# SDL3 windowing
FetchContent_Declare(
    sdl3_cmake
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.4 # latest stable at this time, i won't be changing this anytime soon.
)

FetchContent_MakeAvailable(bgfx_cmake)
FetchContent_MakeAvailable(sdl3_cmake)

add_subdirectory(src)
