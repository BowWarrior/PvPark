#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

struct RenderComponent{
    unsigned int VAO;
    unsigned int VBO;
    unsigned int shaderProgram;
    int vertexCount;
    unsigned int drawMode;
};


#endif