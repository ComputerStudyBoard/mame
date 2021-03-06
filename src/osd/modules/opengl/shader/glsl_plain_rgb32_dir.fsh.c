// license:BSD-3-Clause
// copyright-holders:Sven Gothel
const char glsl_plain_rgb32_dir_fsh_src[] =
"\n"
"#pragma optimize (on)\n"
"#pragma debug (off)\n"
"\n"
"uniform sampler2D color_texture;\n"
"uniform vec4      vid_attributes;     // gamma, contrast, brightness\n"
"\n"
"// #define DO_GAMMA  1 // 'pow' is very slow on old hardware, i.e. pre R600 and 'slow' in general\n"
"\n"
"void main()\n"
"{\n"
"#ifdef DO_GAMMA\n"
"   vec4 gamma = vec4( 1.0 / vid_attributes.r, 1.0 / vid_attributes.r, 1.0 / vid_attributes.r, 0.0);\n"
"\n"
"   // gamma, contrast, brightness equation from: rendutil.h / apply_brightness_contrast_gamma_fp\n"
"   vec4 color = pow( texture2D(color_texture, gl_TexCoord[0].st) , gamma);\n"
"#else\n"
"   vec4 color = texture2D(color_texture, gl_TexCoord[0].st);\n"
"#endif\n"
"\n"
"   // contrast/brightness\n"
"   gl_FragColor =  (color * vid_attributes.g) + vid_attributes.b - 1.0;\n"
"}\n"
"\n"
;
