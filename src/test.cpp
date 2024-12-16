/*
#include <iostream>
#include <glad.h>
#include <glfw3.h>
#include <sndfile.h>
#include <fftw3.h>
#include <al.h>
#include <alc.h>

#include <fstream>
#include <sstream>
#include <stdexcept>

#include "audioLoader/audioLoader.hpp"
#include "audioAnalyzer/audioAnalyzer.hpp"

// Resize viewport when window adjusted
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open shader file: " + filePath);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}    

GLuint compileShader(GLenum type, const std::string& source) {
    GLuint shader = glCreateShader(type);
    const char* sourceCStr = source.c_str();
    glShaderSource(shader, 1, &sourceCStr, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        throw std::runtime_error("Shader compilation failed:\n" + std::string(infoLog));
    }
    return shader;
}

GLuint createShaderProgram(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
    std::string vertexShaderCode = readFile(vertexShaderPath);
    std::string fragmentShaderCode = readFile(fragmentShaderPath);

    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexShaderCode);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentShaderCode);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    GLint success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        throw std::runtime_error("Shader program linking failed:\n" + std::string(infoLog));
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

GLuint createVAO(const std::vector<float>& data) {
    GLuint VAO, VBO;
    // Create and bind VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Create VBO and bind it
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Upload normalized audio data to GPU
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);

    // Define how to interpret vertex data
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);  // Unbind buffer
    glBindVertexArray(0);  // Unbind VAO

    return VAO;
}



int main(){
    std::cout << "Starting Program" << std::endl;

    int windowWidth = 800;
    int windowHeight = 600;

    std::string audioFile = "D:\\VSProjects\\audioViz\\musicSources\\Russian - Part_1.wav";

    audioLoader audioLoad(audioFile);
    audioAnalyzer audioAnalyze(audioLoad.getAudioData());

    if (audioLoad.getAudioData().empty()) {
    std::cerr << "Failed to load audio data." << std::endl;
    return -1;
}

    // Normalize the audio data and generate the waveform
    std::vector<float> normalizedSamples = audioAnalyze.getNormalizedAudioData();

    // Init GLFW and GLAD
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    std::cout << "GLFWINIT" << std::endl;

    GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Viz!", nullptr, nullptr);
    if (!window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    std::cout << "GLFWWindowINIT" << std::endl;
    
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, windowWidth, windowHeight);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    glfwSwapInterval(1); // vSynxc

    GLuint shaderProgram = createShaderProgram("D:\\VSProjects\\audioViz\\src\\shaders\\vertex_shader.glsl", "D:\\VSProjects\\audioViz\\src\\shaders\\fragment_shader.glsl");
    std::cout << "Shader program compiled and linked successfully!" << std::endl;

    GLuint VAO = createVAO(normalizedSamples);

    while(!glfwWindowShouldClose(window)) {

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Dark gray background
        glClear(GL_COLOR_BUFFER_BIT);

        // Use the shader program
        glUseProgram(shaderProgram);

        glClear(GL_COLOR_BUFFER_BIT);

        // Bind the VAO for the waveform
        glBindVertexArray(VAO);

        // Draw the waveform as a line strip
        glDrawArrays(GL_LINE_STRIP, 0, normalizedSamples.size() / 2); // Divide by 2 since it's 2D (x, y)

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}  
*/