
project(SourceNMirrors VERSION 0.1.0 LANGUAGES C CXX)

add_executable(SourceNMirrors 
    main.cpp
    engine.cpp
    platform_dependent.cpp
    shaders.cpp
)

add_subdirectory(shaders)
target_link_libraries(SourceNMirrors PUBLIC Shaders)

target_link_libraries(SourceNMirrors PRIVATE bgfx bimg bx SDL3)
target_include_directories(SourceNMirrors PRIVATE ${CMAKE_BINARY_DIR}/include/generated/shaders)
