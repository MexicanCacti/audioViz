#pragma once
#include <glad.h>
#include <glm/glm.hpp>
#include <iostream>
#include "ShaderLoader.hpp"

// Handles all Shader-Related info
class GLSLShader{
    private:
        GLuint programID;
        GLint location;

        GLint getUniformLocation(const char* name){
            location = glGetUniformLocation(programID, name);
            if(location >= 0){
                return location;
            }
            else throw("Unknown Uniform: " + std::string(name));
            
            return location;
        };

    public:
        GLSLShader(){
            location = -1;
            programID = -1;
        }

        GLSLShader(const std::string vertexShaderPath, const std::string fragmentShaderPath){
            location = -1;
            programID = 0;
            programID = loadShader(vertexShaderPath, fragmentShaderPath);
            if(programID != 0) std::cout << "Shader Loaded!" << std::endl;
        }

        void use(){
            glUseProgram(programID);
        }

        void setIntUniform(const char* name, const GLint& value){
            location = getUniformLocation(name);
            glUniform1iv(location, 1, &value);
        }

        void setUIntUniform(const char* name, const GLuint& value){
            location = getUniformLocation(name);
            glUniform1uiv(location, 1, &value);
        }

        void setFloatUniform(const char* name, const GLfloat& value){
            location = getUniformLocation(name);
            glUniform1fv(location, 1, &value);
        }

        // All Vecs use floats
        void setVec2Uniform(const char* name, const glm::vec2& value){
            location = getUniformLocation(name);
            glUniform2fv(location, 1, &value[0]);
        }

        void setVec3Uniform(const char* name, const glm::vec3& value){
            location = getUniformLocation(name);
            glUniform3fv(location, 1, &value[0]);
        }

        void setVec4Uniform(const char* name, const glm::vec4& value){
            location = getUniformLocation(name);
            glUniform4fv(location, 1, &value[0]);
        }

        // GL_FALSE: Means matrix provided in column-major order.
        // Note all exist 2 x 3, 2x4, 3x2, 3x4... define if needed
        void setMatrix2Uniform(const char* name, const glm::mat2& value){
            location = getUniformLocation(name);
            glUniformMatrix2fv(location, 1, GL_FALSE, &value[0][0]);
        }

        void setMatrix3Uniform(const char* name, const glm::mat3& value){
            location = getUniformLocation(name);
            glUniformMatrix3fv(location, 1, GL_FALSE, &value[0][0]);
        }

        void setMatrix4Uniform(const char* name, const glm::mat4& value){
            location = getUniformLocation(name);
            glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
        }

        GLuint getID() { return programID; }

        GLuint deleteShader(){
            glDeleteProgram(programID);
            programID = 0;

            return programID;
        }

        GLuint createShader(const std::string vertexShaderPath, const std::string fragmentShaderPath){
            if(programID != 0){
                throw ("Delete current shader before creating a new one.");
            }
            programID = loadShader(vertexShaderPath, fragmentShaderPath);
        }
};