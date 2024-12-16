#pragma once
#include <glad.h>
#include <glfw3.h>

// If want/need more attribs to hold... Add & create new constructor.
struct Mesh{
    float pos[3];
    float color[3];
    Mesh (float x, float y, float z) : pos{x,y,z}, color{0.0f,0.0f,0.0f} {}

    Mesh (float x, float y, float z, float r, float g, float b) : pos{x,y,z}, color{r,g,b} {}
};

struct DrawDetails {
    GLuint vao;
    GLuint numElems;

    DrawDetails(GLuint v, GLuint e) : vao(v), numElems(e) {}
};