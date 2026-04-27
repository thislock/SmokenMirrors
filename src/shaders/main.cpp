// main.cpp
#include <glsl/vs_color.sc.bin.h>
#include <essl/vs_color.sc.bin.h>
#include <spirv/vs_color.sc.bin.h>
#include <glsl/fs_color.sc.bin.h>
#include <essl/fs_color.sc.bin.h>
#include <spirv/fs.sc.bin.h>
#if defined(_WIN32)
#include <dx11/vs.sc.bin.h>
#include <dx11/fs.sc.bin.h>
#endif //  defined(_WIN32)
#if __APPLE__
#include <metal/vs.sc.bin.h>
#include <metal/fs.sc.bin.h>
#endif // __APPLE__
