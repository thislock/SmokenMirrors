
#pragma once

#include <bx/bx.h>
#include <bgfx/bgfx.h>

#include <bgfx/platform.h>
#include <bgfx/defines.h>

#define DEFAULT_RESOLUTION_WIDTH 600
#define DEFAULT_RESOLUTION_HEIGHT 400
#define DEFAULT_RESOLUTION DEFAULT_RESOLUTION_WIDTH, DEFAULT_RESOLUTION_HEIGHT

#define f32 float

// from https://github.com/bkaradzic/bgfx/blob/master/examples/01-cubes/cubes.cpp
// struct PosColorVertex
// {
// 	float m_x;
// 	float m_y;
// 	float m_z;
// 	uint32_t m_abgr;

// 	static bgfx::VertexLayout ms_layout;

// 	static void init()
// 	{
// 		ms_layout
// 			.begin()
// 			.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
// 			.add(bgfx::Attrib::Color0,   4, bgfx::AttribType::Uint8, true)
// 			.end();
// 	};

// };

// static PosColorVertex s_cubeVertices[] =
// {
// 	{-1.0f,  1.0f,  1.0f, 0xff000000 },
// 	{ 1.0f,  1.0f,  1.0f, 0xff0000ff },
// 	{-1.0f, -1.0f,  1.0f, 0xff00ff00 },
// 	{ 1.0f, -1.0f,  1.0f, 0xff00ffff },
// 	{-1.0f,  1.0f, -1.0f, 0xffff0000 },
// 	{ 1.0f,  1.0f, -1.0f, 0xffff00ff },
// 	{-1.0f, -1.0f, -1.0f, 0xffffff00 },
// 	{ 1.0f, -1.0f, -1.0f, 0xffffffff },
// };

static const uint16_t s_cubeTriList[] =
{
	0, 1, 2, // 0
	1, 3, 2,
	4, 6, 5, // 2
	5, 6, 7,
	0, 2, 4, // 4
	4, 2, 6,
	1, 5, 3, // 6
	5, 7, 3,
	0, 4, 1, // 8
	4, 5, 1,
	2, 3, 6, // 10
	6, 3, 7,
};

static const uint16_t s_cubeTriStrip[] =
{
	0, 1, 2,
	3,
	7,
	1,
	5,
	0,
	4,
	2,
	6,
	7,
	4,
	5,
};

static const uint16_t s_cubeLineList[] =
{
	0, 1,
	0, 2,
	0, 4,
	1, 3,
	1, 5,
	2, 3,
	2, 6,
	3, 7,
	4, 5,
	4, 6,
	5, 7,
	6, 7,
};

static const uint16_t s_cubeLineStrip[] =
{
	0, 2, 3, 1, 5, 7, 6, 4,
	0, 2, 6, 4, 5, 7, 3, 1,
	0,
};

static const uint16_t s_cubePoints[] =
{
	0, 1, 2, 3, 4, 5, 6, 7
};

static const char* s_ptNames[]
{
	"Triangle List",
	"Triangle Strip",
	"Lines",
	"Line Strip",
	"Points",
};

static const uint64_t s_ptState[]
{
	UINT64_C(0),
	BGFX_STATE_PT_TRISTRIP,
	BGFX_STATE_PT_LINES,
	BGFX_STATE_PT_LINESTRIP,
	BGFX_STATE_PT_POINTS,
};
static_assert(BX_COUNTOF(s_ptState) == BX_COUNTOF(s_ptNames) );
