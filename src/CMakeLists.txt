
project(SourceNMirrors VERSION 0.1.0 LANGUAGES C CXX)

bgfx_compile_shaders(
    TYPE VERTEX
    SHADERS vs.sc
    VARYING_DEF varying.def.sc
    OUTPUT_DIR ${CMAKE_BINARY_DIR}/include/generated/shaders
    AS_HEADERS
)

bgfx_compile_shaders(
    TYPE FRAGMENT
    SHADERS fs.sc
    VARYING_DEF ${CMAKE_SOURCE_DIR}/varying.def.sc
    OUTPUT_DIR ${CMAKE_BINARY_DIR}/include/generated/shaders
    AS_HEADERS
)

add_executable(SourceNMirrors 
    main.cpp
    engine.cpp
    platform_dependent.cpp
    shaders.cpp

    shaders/fs_color.sc shaders/vs_color.sc
)

target_include_directories(SourceNMirrors PRIVATE ${CMAKE_BINARY_DIR}/include/generated/shaders)
target_link_libraries(SourceNMirrors PRIVATE bgfx bimg bx SDL3)
