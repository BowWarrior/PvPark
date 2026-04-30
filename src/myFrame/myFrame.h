#include <GLFW/glfw3.h>

#ifndef MYFRAME_H
#define MYFRAME_H

class MyFrame {
public:
    MyFrame();
    ~MyFrame();

    bool init();
    void pollEvents();
    bool shouldClose();
    void swapBuffers();

    GLFWwindow* getWindow();

private:
    GLFWwindow* window;
};

#endif