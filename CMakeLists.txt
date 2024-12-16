cmake_minimum_required(VERSION 3.11)

project(audioViz)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_DIR "${CMAKE_SOURCE_DIR}/libs/glfw")

set(LIBSNDFILE_DIR "${CMAKE_SOURCE_DIR}/libs/libsndfile")

set(FFTW3_DIR "${CMAKE_SOURCE_DIR}/libs/fftw3")

set(OPENAL_DIR "${CMAKE_SOURCE_DIR}/libs/openal")

include_directories(${GLFW_DIR}/include)

include_directories(${LIBSNDFILE_DIR}/include)

include_directories(${FFTW3_DIR}/include)

include_directories(${GLFW_DIR}/include/glad)
include_directories(${GLFW_DIR}/include/KHVR)

include_directories(${OPENAL_DIR}/include)

link_directories(${GLFW_DIR}/lib)

link_directories(${LIBSNDFILE_DIR}/lib)

link_directories(${FFTW3_DIR}/lib)

link_directories(${OPENAL_DIR}/lib)

add_executable(audioViz 
    src/main.cpp include/glad.c 
    src/util.hpp
    src/audioAnalyzer/audioAnalyzer.cpp 
    src/audioLoader/audioLoader.cpp
    src/rendering/GL/Mesh.hpp
    src/rendering/GL/OpenGLCallbacks.hpp
    src/rendering/GL/OpenGLDrawer.hpp
    src/rendering/GL/OpenGLInput.hpp
    src/rendering/GL/OpenGLLoader.hpp
    src/rendering/GLSL/GLSLShader.hpp
    src/rendering/GLSL/QueryShader.hpp
    src/rendering/GLSL/ShaderLoader.hpp
)

include(FetchContent)

FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)

FetchContent_MakeAvailable(glm)

target_link_libraries(audioViz glfw3 sndfile fftw3 OpenAL32 kernel32 user32 gdi32 winspool shell32 ole32 oleaut32 uuid comdlg32 advapi32 glm::glm)

# Post-build: copy dynamic libraries if needed
if(EXISTS ${GLFW_DIR}/lib/glfw3.dll)
    add_custom_command(TARGET audioViz POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${GLFW_DIR}/lib/glfw3.dll $<TARGET_FILE_DIR:audioViz>)
endif()

if(EXISTS ${LIBSNDFILE_DIR}/lib/libsndfile.dll)
    add_custom_command(TARGET audioViz POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${LIBSNDFILE_DIR}/lib/libsndfile.dll $<TARGET_FILE_DIR:audioViz>)
endif()

if(EXISTS ${FFTW3_DIR}/lib/libfftw3-3.dll)
    add_custom_command(TARGET audioViz POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${FFTW3_DIR}/lib/libfftw3-3.dll $<TARGET_FILE_DIR:audioViz>)
endif()

