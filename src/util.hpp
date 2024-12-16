#pragma once
#include <string>
#include <fstream>
#include "rendering/GLSL/GLSLShader.hpp"

void printGLInfo(){
    const GLubyte* vendor = glGetString(GL_VENDOR);
    printf("GL Vendor : %s\n", vendor);

    const GLubyte* renderer = glGetString(GL_RENDERER);
    printf("GL Renderer : %s\n", renderer);

    const GLubyte* version = glGetString(GL_VERSION);
    printf("GL Version (string) : %s\n", version);

    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    printf("GL Version (integer) : %d.%d\n", major, minor);

    const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
    printf("GLSL Version : %s\n", glslVersion);
}

std::string extractName(const char* exePath){
    std::string fullPath(exePath);

    size_t lastSlash = fullPath.find_last_of("/\\");

    std::string extracted;

    if(lastSlash != std::string::npos){
        extracted = fullPath.substr(lastSlash + 1);
    }

    size_t lastDot = extracted.find_last_of('.');

    if(lastDot != std::string::npos){
        extracted = extracted.substr(0, lastDot);
    }
    
    return extracted;
}

/*
// Only works for float arrays created at compile time!
std::vector<Mesh> s_createMeshes(const float posData[], const float colorData[], const int posGroupSize, const int posSize){
    std::vector<Mesh> meshes;
    

    //3D, (Vertex is in group of 3)
    if(posGroupSize == 3){
        for(int i = 0 ; i < posSize; i += posGroupSize){
            Mesh mesh(posData[i], posData[i + 1], posData[i + 2], colorData[i], colorData[i + 1], colorData[i + 2]);
            meshes.push_back(mesh);
        }
    }
    else{
        for(int i = 0 ; i < posSize; i += posGroupSize){
            Mesh mesh(posData[i], posData[i + 1], 0.0f, colorData[i], colorData[i + 1], colorData[i + 2]);
            meshes.push_back(mesh);
        }
    }

    return meshes;
}
*/

// NOTE: Maybe write logging capabilites?