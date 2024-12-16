#pragma once
#include <iostream>
#include <glad.h>
#include <glfw3.h>

static void glfwErrorCallback(int error, const char* description){
    std::cerr << "GLFW ERROR: " << "[" << error << "] " << std::string(description) << std::endl; 
    throw ("glfw Error: " + error);
}

static void glfwCloseWindow(GLFWwindow* window){
    std::cout << "Closed Window: " << glfwGetWindowTitle(window) << std::endl;
}

static void glfwResizeWindow(GLFWwindow* window, int w, int h){
    glViewport(0, 0, w, h);
}