#pragma once
#include <vector>
#include "Mesh.hpp"

// e = EBO used

// Vert 0 & 1 are a line, Vert 2 & 3 are a line... If non-even, extra vertex is ignored. Every pair of verts forms a line
void DrawLine(const std::vector<DrawDetails>& details) {
    if (details.empty()) return;

    for (const auto& d : details) {
        glBindVertexArray(d.vao);
        glDrawArrays(GL_LINES, 0, d.numElems);
    }
    glBindVertexArray(0);
}

void e_DrawLine(const std::vector<DrawDetails>& details) {
    if (details.empty()) return;

    for (const auto& d : details) {
        glBindVertexArray(d.vao);
        glDrawElements(GL_LINES, d.numElems, GL_UNSIGNED_INT, nullptr);
    }
    glBindVertexArray(0);
}

// Adjacent Verts are considered as lines. N verts = N - 1 Lines
void DrawLineStrip(const std::vector<DrawDetails>& details) {
    if (details.empty()) return;

    for (const auto& d : details) {
        glBindVertexArray(d.vao);
        glDrawArrays(GL_LINE_STRIP, 0, d.numElems);
    }
    glBindVertexArray(0);
}

void e_DrawLineStrip(const std::vector<DrawDetails>& details) {
    if (details.empty()) return;

    for (const auto& d : details) {
        glBindVertexArray(d.vao);
        glDrawElements(GL_LINE_STRIP, d.numElems, GL_UNSIGNED_INT, nullptr);
    }
    glBindVertexArray(0);
}

// Line Strip except that first & last vert area also used as a line. N verts = N lines
void DrawLineLoop(const std::vector<DrawDetails>& details) {
    if (details.empty()) return;

    for (const auto& d : details) {
        glBindVertexArray(d.vao);
        glDrawArrays(GL_LINE_LOOP, 0, d.numElems);
    }
    glBindVertexArray(0);
}

void e_DrawLineLoop(const std::vector<DrawDetails>& details) {
    if (details.empty()) return;

    for (const auto& d : details) {
        glBindVertexArray(d.vao);
        glDrawElements(GL_LINE_LOOP, d.numElems, GL_UNSIGNED_INT, nullptr);
    }
    glBindVertexArray(0);
}

// Vert 0, 1, 2 Form a Triangle, Vert 3, 4, 5 From a triangle, ....
void DrawTriangle(const std::vector<DrawDetails>& details) {
    if (details.empty()) return;

    for (const auto& d : details) {
        glBindVertexArray(d.vao);
        glDrawArrays(GL_TRIANGLES, 0, d.numElems);
    }
    glBindVertexArray(0);
}

void e_DrawTriangle(const std::vector<DrawDetails>& details) {
    if (details.empty()) return;

    for (const auto& d : details) {
        glBindVertexArray(d.vao);
        glDrawElements(GL_TRIANGLES, d.numElems, GL_UNSIGNED_INT, nullptr);
    }
    glBindVertexArray(0);
}

// Every group of 3 adjacent verts form a triangle. Face direction determined by winding of first triangle. Each successive triangle has face order reversed. N Verts = N - 2 Tris
void DrawTriangleStrip(const std::vector<DrawDetails>& details) {
    if (details.empty()) return;

    for (const auto& d : details) {
        glBindVertexArray(d.vao);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, d.numElems);
    }
    glBindVertexArray(0);
}

void e_DrawTriangleStrip(const std::vector<DrawDetails>& details) {
    if (details.empty()) return;
    for (const auto& d : details) {
        glBindVertexArray(d.vao);
        glDrawElements(GL_TRIANGLE_STRIP, d.numElems, GL_UNSIGNED_INT, nullptr);
    }
    glBindVertexArray(0);
}

// First vertex is always held fixed, from there on every group of 2 adj verts form triangle w/ first: (0, 1, 2), (0, 2, 3), (0, 3, 4) ....
void DrawTriangleFan(const std::vector<DrawDetails>& details) {
    if (details.empty()) return;

    for (const auto& d : details) {
        glBindVertexArray(d.vao);
        glDrawArrays(GL_TRIANGLE_FAN, 0, d.numElems);
    }
    glBindVertexArray(0);
}

void e_DrawTriangleFan(const std::vector<DrawDetails>& details) {
    if (details.empty()) return;

    for (const auto& d : details) {
        glBindVertexArray(d.vao);
        glDrawElements(GL_TRIANGLE_FAN, d.numElems, GL_UNSIGNED_INT, nullptr);
    }
    glBindVertexArray(0);
}