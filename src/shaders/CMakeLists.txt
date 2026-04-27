
project(Shaders VERSION 0.1.0 LANGUAGES C CXX)

set(BGFX_BUILD_TOOLS ON)

bgfx_compile_shaders(
    TYPE VERTEX
    # VERTEX SHADERS
    SHADERS vs_color.sc
    VARYING_DEF varying.def.sc
    OUTPUT_DIR ${CMAKE_BINARY_DIR}/include/generated/shaders
    AS_HEADERS
)

bgfx_compile_shaders(
    TYPE FRAGMENT
    # FRAGMENT SHADERS
    SHADERS fs_color.sc
    VARYING_DEF ${CMAKE_SOURCE_DIR}/varying.def.sc
    OUTPUT_DIR ${CMAKE_BINARY_DIR}/include/generated/shaders
    AS_HEADERS
)

add_library(Shaders 
    main.cpp
    fs_color.sc vs_color.sc
)

target_link_libraries(SourceNMirrors PUBLIC bgfx)
target_include_directories(Shaders PRIVATE ${CMAKE_BINARY_DIR}/include/generated/shaders)
