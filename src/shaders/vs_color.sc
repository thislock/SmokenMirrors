$input a_position, a_normal
$output v_normal

// just pass everything along
#include <bgfx_shader.h>
void main () {
    gl_Position = mul(u_modelViewProj, vec4(a_position,1.0));
    v_normal = a_normal;
}