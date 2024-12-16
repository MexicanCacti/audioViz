#version 430 core

layout(location = 0) in vec3 pos; 

void main() {
    vec4 final_pos = vec4(pos, 1.0);
    gl_Position = final_pos;
};