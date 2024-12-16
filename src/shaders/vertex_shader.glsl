#version 430 core

uniform float u_time;

layout(location = 0) in vec3 pos; 
layout(location = 1) in vec3 color;

layout(location = 0) out vec3 passColor;

void main() {
    float angle = u_time;

    mat2 rotationMatrix = mat2(
        cos(angle), -sin(angle),
        sin(angle), cos(angle)
    );

    vec2 rotatePos = rotationMatrix * pos.xy;

    
    float r = 0.5 + 0.5 * sin(u_time + pos.x); 
    float g = 0.5 + 0.5 * sin(u_time + pos.y); 
    float b = 0.5 + 0.5 * cos(u_time + pos.z);         
    passColor = vec3(r, g, b);

    vec4 final_pos = vec4(rotatePos, 0.0, 1.0);
    gl_Position = final_pos;
};