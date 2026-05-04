#ifndef MYFRAME_H
#define MYFRAME_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>

class MyFrame{
public:
    MyFrame();
    MyFrame(const char* title);
    bool init();
    bool shouldClose();
    void pollEvents();
    void destroy();
    GLFWwindow* getWindow();
    void toggleFullscreen();

private:
    int width;
    int height;
    const char* title;
    GLFWwindow* window;
    int windowedX, windowedY; //stores windowed mode's position
    int windowedWidth, windowedHeight; //stores windowed mode's size
    bool isFullscreen;
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif