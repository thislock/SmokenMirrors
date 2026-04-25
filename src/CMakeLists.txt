
project(SourceNMirrors VERSION 0.1.0 LANGUAGES C CXX)

add_executable(SourceNMirrors 
    main.cpp
    engine.cpp
    platform_dependent.cpp
    shaders.cpp
)

target_link_libraries(SourceNMirrors PRIVATE bgfx bimg bx SDL3)