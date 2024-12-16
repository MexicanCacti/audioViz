#include <glad.h>
#include <glfw3.h>
#include <sndfile.h>
#include <fftw3.h>
#include <al.h>
#include <alc.h>
#include <filesystem>

#include "audioLoader/audioLoader.hpp"
#include "audioAnalyzer/audioAnalyzer.hpp"

#include "rendering/GL/Mesh.hpp"
#include "rendering/GL/OpenGLCallbacks.hpp"
#include "rendering/GL/OpenGLDrawer.hpp"
#include "rendering/GL/OpenGLInput.hpp"
#include "rendering/GL/OpenGLLoader.hpp"

#include "rendering/GLSL/GLSLShader.hpp"
#include "rendering/GLSL/QueryShader.hpp"
#include "rendering/GLSL/ShaderLoader.hpp"

#include "util.hpp"

int main(int argc, char** argv){
    int windowWidth = 800;
    int windowHeight = 600;

    // Init GLFW and GLAD
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // No depreciated stuff

    GLFWwindow* initWindow = glfwCreateWindow(windowWidth, windowHeight, extractName(argv[0]).c_str(), NULL, NULL);
    if (!initWindow) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(initWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, windowWidth, windowHeight);

    printGLInfo();

    // Callbacks
    glfwSetErrorCallback(glfwErrorCallback);
    glfwSetWindowCloseCallback(initWindow, glfwCloseWindow);
    glfwSetFramebufferSizeCallback(initWindow, glfwResizeWindow);

    glClearColor(.2f, .2f, .6f, 0.f);

    // Set up Points & Shaders
    std::vector<DrawDetails> drawDetails;
    std::vector<DrawDetails> backgroundDetails;

    const GLfloat backgroundCover[]{
        -1.0f, -1.0f,  // Bottom-left corner
        1.0f, -1.0f,   // Bottom-right corner
        -1.0f,  1.0f,  // Top-left corner
        -1.0f,  1.0f,  // Top-left corner
        1.0f, -1.0f,   // Bottom-right corner
        1.0f,  1.0f    // Top-right corner
    };

    // Pts between 1 -> -1 due to OpenGL graphing (Normalized)
    const GLfloat posData[] = {
    // Vertices of the pentagram (calculated using unit circle, radius = 1.0)
    1.0f, 0.0f,           // P0 (right)
    0.3090f, 0.9511f,     // P1 (top-right)
    -0.8090f, 0.5878f,    // P2 (top-left)
    -0.8090f, -0.5878f,   // P3 (bottom-left)
    0.3090f, -0.9511f     // P4 (bottom-right)
    };

    const GLfloat colorData[] = {
        1.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f,
        1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f
    };

    const GLuint elems[] = {
    0, 2,  // Line from P0 to P2
    2, 4,  // Line from P2 to P4
    4, 1,  // Line from P4 to P1
    1, 3,  // Line from P1 to P3
    3, 0   // Line from P3 to P0
    };

    drawDetails.push_back(sf2_UploadMeshPCE(posData, sizeof(posData) / sizeof(posData[0]), colorData, elems, sizeof(elems) / sizeof(elems[0])));
    
    //drawDetails.push_back(sf3_UploadMeshP(posData, sizeof(posData) / sizeof(posData[0])));

    backgroundDetails.push_back(sf2_UploadMeshP(backgroundCover, sizeof(backgroundCover) / sizeof(backgroundCover[0])));

    std::filesystem::path path = std::filesystem::current_path();
    std::string directoryPath = path.parent_path().string();

    GLSLShader *testShader;
    testShader = new GLSLShader (directoryPath + "\\src\\shaders\\vertex_shader.glsl", directoryPath + "\\src\\shaders\\fragment_shader.glsl");

    queryInputAttribs(testShader->getID());
    queryUniforms(testShader->getID());

    GLSLShader *backgroundShader;
    backgroundShader = new GLSLShader(directoryPath + "\\src\\shaders\\background_vertex_shader.glsl", directoryPath + "\\src\\shaders\\background_fragment_shader.glsl");

    queryInputAttribs(backgroundShader->getID());
    queryUniforms(backgroundShader->getID());
    std::string u = "u_time";
    std::string r = "u_resolution";

    GLfloat lineWidthRange[2];
    glGetFloatv(GL_LINE_WIDTH_RANGE, lineWidthRange);
    std::cout << "Line width range: " << lineWidthRange[0] << " to " << lineWidthRange[1] << std::endl;


    // NOTE: PROBABLY MAKE A TIME CLASS TO HOLD ALL TIME-RELATED OPERATIONS
    float prevTime = glfwGetTime();
    while(!glfwWindowShouldClose(initWindow)){
        float currentTime = glfwGetTime();
        float dt = currentTime - prevTime;
        prevTime = currentTime;
        //std::cout << dt << std::endl;

        ProcessInput(initWindow);

        glClear(GL_COLOR_BUFFER_BIT);
        // WHEN YOU RESIZE THE WINDOW, YOU SOMEHOW NEED TO CHANGE THE RESOLUTION UNIFORM FOR EVERY SHADER!
        backgroundShader->use();
        backgroundShader->setFloatUniform(u.c_str(), currentTime);
        backgroundShader->setVec2Uniform(r.c_str(), glm::vec2(windowWidth, windowHeight));
        DrawTriangle(backgroundDetails);

        testShader->use();
        testShader->setFloatUniform(u.c_str(), currentTime);
        //testShader->setVec2Uniform(r.c_str(), glm::vec2(windowWidth, windowHeight));
        e_DrawLine(drawDetails);

        glfwSwapBuffers(initWindow);
        
        glfwPollEvents();
    }

    UnloadMesh(drawDetails);
    UnloadMesh(backgroundDetails);

    glfwDestroyWindow(initWindow);  
    glfwTerminate();
    return 0;
}