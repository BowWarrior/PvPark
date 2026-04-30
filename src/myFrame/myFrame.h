#ifndef MYFRAME_H
#define MYFRAME_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>

class MyFrame{
public:
    MyFrame();
    MyFrame(int width, int height, const char* title);
    bool init();
    bool shouldClose();
    void pollEvents();
    void destroy();


private:
    int width;
    int height;
    const char* title;
    GLFWwindow* window;
};

#endif