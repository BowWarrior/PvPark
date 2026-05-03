#ifndef RENDER_SYSTEM_H
#define RENDER_SYSTEM_H

#include <GLFW/glfw3.h>

class ECS;

class RenderSystem{
public:
    void render(ECS& ecs, GLFWwindow* window);
};

#endif