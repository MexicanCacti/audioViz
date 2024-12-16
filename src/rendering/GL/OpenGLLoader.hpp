#pragma once
#include "Mesh.hpp"
// s = Static, d = Dynamic, f = float, 2 = 2D, 3 = 3D

// 2D Pos
DrawDetails sf2_UploadMeshP(const GLfloat* pos, const int posCount){
    GLuint vboHandle;
    glGenBuffers(1, &vboHandle);
    GLuint posHandle = vboHandle;
    glBindBuffer(GL_ARRAY_BUFFER, posHandle);
    
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_STATIC_DRAW);

    GLuint vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);

    glEnableVertexAttribArray(0);
    glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 2);
    glVertexAttribFormat(0, 2, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);

    return DrawDetails(vaoHandle, posCount);
}

DrawDetails sf2_UploadMeshPE(const GLfloat* pos, const int posCount, const GLuint* elem, const int elemCount){
    GLuint vboHandle;
    glGenBuffers(1, &vboHandle);
    GLuint posHandle = vboHandle;
    glBindBuffer(GL_ARRAY_BUFFER, posHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_STATIC_DRAW);

    GLuint vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);

    glEnableVertexAttribArray(0);  // enable position
    glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 2);
    glVertexAttribFormat(0, 2, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);  // map to shader

    GLuint elemHandle;
    glGenBuffers(1, &elemHandle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elemHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elemCount * sizeof(GLuint), elem, GL_STATIC_DRAW);

    return DrawDetails(vaoHandle, static_cast<GLuint>(elemCount));
}

DrawDetails sf2_UploadMeshPC(const GLfloat* pos, const int posCount, const GLfloat* colors) {
  GLuint vboHandles[2];
  glGenBuffers(2, vboHandles);
  GLuint posHandle = vboHandles[0];
  GLuint colorHandle = vboHandles[1];
  // Populate the position buffer
  glBindBuffer(GL_ARRAY_BUFFER, posHandle);
  glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_STATIC_DRAW);
  // Populate the color buffer
  glBindBuffer(GL_ARRAY_BUFFER, colorHandle);
  glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), colors, GL_STATIC_DRAW);


  GLuint vaoHandle;
  glGenVertexArrays(1, &vaoHandle);
  glBindVertexArray(vaoHandle);

  // Enable the vertex attribute arrays
  glEnableVertexAttribArray(0); // Vertex position
  glEnableVertexAttribArray(1); // Vertex color

  glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 2);
  glBindVertexBuffer(1, colorHandle, 0, sizeof(GLfloat) * 3);

  glVertexAttribFormat(0, 2, GL_FLOAT, GL_FALSE, 0);
  glVertexAttribBinding(0, 0);  //map to shader

  glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
  glVertexAttribBinding(1, 1);  //map to shader

  //glDeleteBuffers(2, vboHandles);
  //glDeleteBuffers(1, &elemHandle);

  return DrawDetails(vaoHandle, posCount);
}

DrawDetails sf2_UploadMeshPCE(const GLfloat* pos, const int posCount, const GLfloat* colors, const GLuint* elem, const int elemCount) {
    GLuint vboHandles[2];
    glGenBuffers(2, vboHandles);
    GLuint posHandle = vboHandles[0];
    GLuint colorHandle = vboHandles[1];
    // Populate the position buffer
    glBindBuffer(GL_ARRAY_BUFFER, posHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_STATIC_DRAW);
    // Populate the color buffer
    glBindBuffer(GL_ARRAY_BUFFER, colorHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), colors, GL_STATIC_DRAW);

    // Create and set-up the vertex array object
    GLuint vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);
    // Enable the vertex attribute arrays
    glEnableVertexAttribArray(0); // Vertex position
    glEnableVertexAttribArray(1); // Vertex color

    glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 2);
    glBindVertexBuffer(1, colorHandle, 0, sizeof(GLfloat) * 3);

    glVertexAttribFormat(0, 2, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);  //map to shader

    glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(1, 1);  //map to shader

    GLuint elemHandle;
    glGenBuffers(1, &elemHandle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elemHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elemCount * sizeof(GLuint), elem, GL_STATIC_DRAW);

    //glDeleteBuffers(2, vboHandles);
    //glDeleteBuffers(1, &elemHandle);

    return DrawDetails(vaoHandle, static_cast<GLuint>(elemCount));
}

DrawDetails df2_UploadMeshP(const GLfloat* pos, const int posCount){
    GLuint vboHandle;
    glGenBuffers(1, &vboHandle);
    GLuint posHandle = vboHandle;
    glBindBuffer(GL_ARRAY_BUFFER, posHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_DYNAMIC_DRAW);

    GLuint vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);

    glEnableVertexAttribArray(0);
    glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 2);
    glVertexAttribFormat(0, 2, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);

    return DrawDetails(vaoHandle, posCount);
}

DrawDetails df2_UploadMeshPE(const GLfloat* pos, const int posCount, const GLuint* elem, const int elemCount){
    GLuint vboHandle;
    glGenBuffers(1, &vboHandle);
    GLuint positionBufferHandle = vboHandle;
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_DYNAMIC_DRAW);

    GLuint vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);

    glEnableVertexAttribArray(0);  // enable position
    glBindVertexBuffer(0, positionBufferHandle, 0, sizeof(GLfloat) * 2);
    glVertexAttribFormat(0, 2, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);  // map to shader

    GLuint elemHandle;
    glGenBuffers(1, &elemHandle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elemHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elemCount * sizeof(GLuint), elem, GL_DYNAMIC_DRAW);

    return DrawDetails(vaoHandle, static_cast<GLuint>(elemCount));
}

DrawDetails df2_UploadMeshPC(const GLfloat* pos, const int posCount, const GLfloat* colors) {
  GLuint vboHandles[2];
  glGenBuffers(2, vboHandles);
  GLuint posHandle = vboHandles[0];
  GLuint colorHandle = vboHandles[1];
  // Populate the position buffer
  glBindBuffer(GL_ARRAY_BUFFER, posHandle);
  glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_DYNAMIC_DRAW);
  // Populate the color buffer
  glBindBuffer(GL_ARRAY_BUFFER, colorHandle);
  glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), colors, GL_DYNAMIC_DRAW);


  GLuint vaoHandle;
  glGenVertexArrays(1, &vaoHandle);
  glBindVertexArray(vaoHandle);

  // Enable the vertex attribute arrays
  glEnableVertexAttribArray(0); // Vertex position
  glEnableVertexAttribArray(1); // Vertex color

  glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 2);
  glBindVertexBuffer(1, colorHandle, 0, sizeof(GLfloat) * 3);

  glVertexAttribFormat(0, 2, GL_FLOAT, GL_FALSE, 0);
  glVertexAttribBinding(0, 0);  //map to shader

  glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
  glVertexAttribBinding(1, 1);  //map to shader

  //glDeleteBuffers(2, vboHandles);
  //glDeleteBuffers(1, &elemHandle);

  return DrawDetails(vaoHandle, posCount);
}

DrawDetails df2_UploadMeshPCE(const GLfloat* pos, const int posCount, const GLfloat* colors, const GLuint* elem, const int elemCount) {
    GLuint vboHandles[2];
    glGenBuffers(2, vboHandles);
    GLuint posHandle = vboHandles[0];
    GLuint colorHandle = vboHandles[1];
    // Populate the position buffer
    glBindBuffer(GL_ARRAY_BUFFER, posHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_DYNAMIC_DRAW);
    // Populate the color buffer
    glBindBuffer(GL_ARRAY_BUFFER, colorHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), colors, GL_DYNAMIC_DRAW);

    // Create and set-up the vertex array object
    GLuint vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);
    // Enable the vertex attribute arrays
    glEnableVertexAttribArray(0); // Vertex position
    glEnableVertexAttribArray(1); // Vertex color

    glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 2);
    glBindVertexBuffer(1, colorHandle, 0, sizeof(GLfloat) * 3);

    glVertexAttribFormat(0, 2, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);  //map to shader

    glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(1, 1);  //map to shader

    GLuint elemHandle;
    glGenBuffers(1, &elemHandle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elemHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elemCount * sizeof(GLuint), elem, GL_DYNAMIC_DRAW);

    //glDeleteBuffers(2, vboHandles);
    //glDeleteBuffers(1, &elemHandle);

    return DrawDetails(vaoHandle, static_cast<GLuint>(elemCount));
}

//3D POS

DrawDetails sf3_UploadMeshP(const GLfloat* pos, const int posCount){
    GLuint vboHandle;
    glGenBuffers(1, &vboHandle);
    GLuint posHandle = vboHandle;
    glBindBuffer(GL_ARRAY_BUFFER, posHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_STATIC_DRAW);

    GLuint vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);

    glEnableVertexAttribArray(0);
    glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 3);
    glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);

    return DrawDetails(vaoHandle, posCount);
}

DrawDetails sf3_UploadMeshPE(const GLfloat* pos, const int posCount, const GLuint* elem, const int elemCount){
    GLuint vboHandle;
    glGenBuffers(1, &vboHandle);
    GLuint positionBufferHandle = vboHandle;
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_STATIC_DRAW);

    GLuint vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);

    glEnableVertexAttribArray(0);  // enable position
    glBindVertexBuffer(0, positionBufferHandle, 0, sizeof(GLfloat) * 3);
    glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);  // map to shader

    GLuint elemHandle;
    glGenBuffers(1, &elemHandle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elemHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elemCount * sizeof(GLuint), elem, GL_STATIC_DRAW);

    return DrawDetails(vaoHandle, static_cast<GLuint>(elemCount));
}

DrawDetails sf3_UploadMeshPC(const GLfloat* pos, const int posCount, const GLfloat* colors) {
  GLuint vboHandles[2];
  glGenBuffers(2, vboHandles);
  GLuint posHandle = vboHandles[0];
  GLuint colorHandle = vboHandles[1];
  // Populate the position buffer
  glBindBuffer(GL_ARRAY_BUFFER, posHandle);
  glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_STATIC_DRAW);
  // Populate the color buffer
  glBindBuffer(GL_ARRAY_BUFFER, colorHandle);
  glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), colors, GL_STATIC_DRAW);


  GLuint vaoHandle;
  glGenVertexArrays(1, &vaoHandle);
  glBindVertexArray(vaoHandle);

  // Enable the vertex attribute arrays
  glEnableVertexAttribArray(0); // Vertex position
  glEnableVertexAttribArray(1); // Vertex color

  glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 3);
  glBindVertexBuffer(1, colorHandle, 0, sizeof(GLfloat) * 3);

  glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
  glVertexAttribBinding(0, 0);  //map to shader

  glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
  glVertexAttribBinding(1, 1);  //map to shader

  //glDeleteBuffers(2, vboHandles);
  //glDeleteBuffers(1, &elemHandle);

  return DrawDetails(vaoHandle, posCount);
}

DrawDetails sf3_UploadMeshPCE(const GLfloat* pos, const int posCount, const GLfloat* colors, const GLuint* elem, const int elemCount) {
    GLuint vboHandles[2];
    glGenBuffers(2, vboHandles);
    GLuint posHandle = vboHandles[0];
    GLuint colorHandle = vboHandles[1];
    // Populate the position buffer
    glBindBuffer(GL_ARRAY_BUFFER, posHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_STATIC_DRAW);
    // Populate the color buffer
    glBindBuffer(GL_ARRAY_BUFFER, colorHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), colors, GL_STATIC_DRAW);

    // Create and set-up the vertex array object
    GLuint vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);
    // Enable the vertex attribute arrays
    glEnableVertexAttribArray(0); // Vertex position
    glEnableVertexAttribArray(1); // Vertex color

    glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 3);
    glBindVertexBuffer(1, colorHandle, 0, sizeof(GLfloat) * 3);

    glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);  //map to shader

    glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(1, 1);  //map to shader

    GLuint elemHandle;
    glGenBuffers(1, &elemHandle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elemHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elemCount * sizeof(GLuint), elem, GL_STATIC_DRAW);

    //glDeleteBuffers(2, vboHandles);
    //glDeleteBuffers(1, &elemHandle);

    return DrawDetails(vaoHandle, static_cast<GLuint>(elemCount));
}

DrawDetails df3_UploadMeshP(const GLfloat* pos, const int posCount){
    GLuint vboHandle;
    glGenBuffers(1, &vboHandle);
    GLuint posHandle = vboHandle;
    glBindBuffer(GL_ARRAY_BUFFER, posHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_DYNAMIC_DRAW);

    GLuint vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);

    glEnableVertexAttribArray(0);
    glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 3);
    glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);

    return DrawDetails(vaoHandle, posCount);
}

DrawDetails df3_UploadMeshPE(const GLfloat* pos, const int posCount, const GLuint* elem, const int elemCount){
    GLuint vboHandle;
    glGenBuffers(1, &vboHandle);
    GLuint positionBufferHandle = vboHandle;
    glBindBuffer(GL_ARRAY_BUFFER, positionBufferHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_DYNAMIC_DRAW);

    GLuint vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);

    glEnableVertexAttribArray(0);  // enable position
    glBindVertexBuffer(0, positionBufferHandle, 0, sizeof(GLfloat) * 3);
    glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);  // map to shader

    GLuint elemHandle;
    glGenBuffers(1, &elemHandle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elemHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elemCount * sizeof(GLuint), elem, GL_DYNAMIC_DRAW);

    return DrawDetails(vaoHandle, static_cast<GLuint>(elemCount));
}

DrawDetails df3_UploadMeshPC(const GLfloat* pos, const int posCount, const GLfloat* colors) {
  GLuint vboHandles[2];
  glGenBuffers(2, vboHandles);
  GLuint posHandle = vboHandles[0];
  GLuint colorHandle = vboHandles[1];
  // Populate the position buffer
  glBindBuffer(GL_ARRAY_BUFFER, posHandle);
  glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_DYNAMIC_DRAW);
  // Populate the color buffer
  glBindBuffer(GL_ARRAY_BUFFER, colorHandle);
  glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), colors, GL_DYNAMIC_DRAW);


  GLuint vaoHandle;
  glGenVertexArrays(1, &vaoHandle);
  glBindVertexArray(vaoHandle);

  // Enable the vertex attribute arrays
  glEnableVertexAttribArray(0); // Vertex position
  glEnableVertexAttribArray(1); // Vertex color

  glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 3);
  glBindVertexBuffer(1, colorHandle, 0, sizeof(GLfloat) * 3);

  glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
  glVertexAttribBinding(0, 0);  //map to shader

  glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
  glVertexAttribBinding(1, 1);  //map to shader

  //glDeleteBuffers(2, vboHandles);
  //glDeleteBuffers(1, &elemHandle);

  return DrawDetails(vaoHandle, posCount);
}

DrawDetails df3_UploadMeshPCE(const GLfloat* pos, const int posCount, const GLfloat* colors, const GLuint* elem, const int elemCount) {
    GLuint vboHandles[2];
    glGenBuffers(2, vboHandles);
    GLuint posHandle = vboHandles[0];
    GLuint colorHandle = vboHandles[1];
    // Populate the position buffer
    glBindBuffer(GL_ARRAY_BUFFER, posHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), pos, GL_DYNAMIC_DRAW);
    // Populate the color buffer
    glBindBuffer(GL_ARRAY_BUFFER, colorHandle);
    glBufferData(GL_ARRAY_BUFFER, posCount * sizeof(GLfloat), colors, GL_DYNAMIC_DRAW);

    // Create and set-up the vertex array object
    GLuint vaoHandle;
    glGenVertexArrays(1, &vaoHandle);
    glBindVertexArray(vaoHandle);
    // Enable the vertex attribute arrays
    glEnableVertexAttribArray(0); // Vertex position
    glEnableVertexAttribArray(1); // Vertex color

    glBindVertexBuffer(0, posHandle, 0, sizeof(GLfloat) * 3);
    glBindVertexBuffer(1, colorHandle, 0, sizeof(GLfloat) * 3);

    glVertexAttribFormat(0, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(0, 0);  //map to shader

    glVertexAttribFormat(1, 3, GL_FLOAT, GL_FALSE, 0);
    glVertexAttribBinding(1, 1);  //map to shader

    GLuint elemHandle;
    glGenBuffers(1, &elemHandle);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elemHandle);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elemCount * sizeof(GLuint), elem, GL_DYNAMIC_DRAW);

    //glDeleteBuffers(2, vboHandles);
    //glDeleteBuffers(1, &elemHandle);

    return DrawDetails(vaoHandle, static_cast<GLuint>(elemCount));
}

void UnloadMesh(std::vector<DrawDetails>& details){
    for(auto& d : details){
        glDeleteBuffers(1, &d.vao);
    }

    details.clear();
}