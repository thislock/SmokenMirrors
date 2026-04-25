
$input v_texcoord0

#include <bgfx_shader.h>

SAMPLE2D(s_texColor, 0);

void main() {
    gl_FragColor = texture2D(s_texColor, v_texcoord0);
}
