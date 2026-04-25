
#pragma once

#include <bx/math.h>
#include <array>
#include "bgfx/bgfx.h"
#include "constants.h"

// iterates over a constant array
template <typename Enum, std::size_t N, typename Func>
constexpr void for_each_enum(const std::array<Enum, N>& values, Func f) {
    for (auto v : values) {
        f(v);
    }
}

enum VertexSetting {
    Normal3D,
    Pos3D,
    Texcoord,
    ColorRGB,
    Transparency,
};

struct Vertex {
    bx::Vec3 pos3D = {0.0, 0.0, 0.0};
    bx::Vec3 Normal3D = {0.0, 0.0, 0.0};
    
    f32 texcoord[2] = {0.0, 0.0};
    
    f32 color[3] = {0.0, 0.0, 0.0};
    f32 transparency = 0.0;
};

constexpr std::array<VertexSetting, 2> Vertex3D_Normal = {
    VertexSetting::Pos3D,
    VertexSetting::Normal3D,
};

struct VertexCompiler {
    VertexCompiler(VertexSetting settings[]);
    bgfx::VertexBufferHandle compile_verticies(Vertex verticies[]);
};

class Model {

    

};