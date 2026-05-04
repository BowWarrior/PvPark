#include <iostream>
using namespace std;

#include "myFrame.h"




MyFrame::MyFrame(){
    title = "PvPark";
    window = nullptr;
}

MyFrame::MyFrame(const char* title){
    this->title = title;
    window = nullptr;
    isFullscreen = true;
}


bool MyFrame::init(){
    glfwInit();

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    windowedWidth = mode->width;
    windowedHeight = mode->height;
    windowedX = 0;
    windowedY = 0;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Start windowed, almost fullscreen
    width = mode->width;
    height = mode->height - 75;

    window = glfwCreateWindow(width, height, title, NULL, NULL);

    if(window == NULL){
        cout << "failed to create GLFW window" << endl;
        glfwTerminate();
        return false;
    }

    // Center window
    windowedX = (mode->width - width) / 2;
    windowedY = (mode->height - height) / 2;
    glfwSetWindowPos(window, windowedX, windowedY);

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        cout << "failed to initialize GLAD" << endl;
        return false;
    }

    isFullscreen = false;

    return true;
}

void MyFrame::toggleFullscreen() {
    isFullscreen = !isFullscreen;

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    if (isFullscreen) {
        // Save current windowed position + size
        glfwGetWindowPos(window, &windowedX, &windowedY);
        glfwGetWindowSize(window, &windowedWidth, &windowedHeight);

        // Switch to fullscreen
        glfwSetWindowMonitor(window, monitor, 0, 0,
                             mode->width, mode->height,
                             mode->refreshRate);
    } else {
    glfwSetWindowMonitor(window, NULL,
                         windowedX, windowedY,
                         windowedWidth, windowedHeight,
                         0);

    glfwSetWindowAttrib(window, GLFW_DECORATED, GLFW_TRUE);

    glfwSetWindowPos(window, windowedX, windowedY);

    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
}

    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
}


bool MyFrame::shouldClose(){
    return glfwWindowShouldClose(window);
}

void MyFrame::pollEvents(){
    glfwPollEvents();
}

void MyFrame::destroy(){
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLFWwindow* MyFrame::getWindow(){
    return window;
}