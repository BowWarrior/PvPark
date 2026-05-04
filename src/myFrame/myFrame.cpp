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

    //start windowed, and subtract 75px from height to make space for minimize and exit btn
    width = mode->width;
    height = mode->height - 75;

    window = glfwCreateWindow(width, height, title, NULL, NULL);

    if(window == NULL){
        cout << "failed to create GLFW window" << endl;
        glfwTerminate();
        return false;
    }

    //centers window
    windowedX = (mode->width - width) / 2;
    windowedY = (mode->height - height) / 2;
    glfwSetWindowPos(window, windowedX, windowedY);

    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, keyCallback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        cout << "failed to initialize GLAD" << endl;
        return false;
    }

    isFullscreen = false;

    return true;
}

void MyFrame::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key == GLFW_KEY_F11 && action == GLFW_PRESS){
        MyFrame* frame = (MyFrame*)glfwGetWindowUserPointer(window);
        frame->toggleFullscreen();
    }
}

void MyFrame::toggleFullscreen() {
    isFullscreen = !isFullscreen;

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    if (isFullscreen) {
        //save windowed state
        glfwGetWindowPos(window, &windowedX, &windowedY);
        glfwGetWindowSize(window, &windowedWidth, &windowedHeight);

        //toggle to borderless fullscreen size
        glfwSetWindowAttrib(window, GLFW_DECORATED, GLFW_FALSE); //set to GLFW_FALSE to GLFW_TRUE for true fullscreen
        glfwSetWindowPos(window, 0, 0);
        glfwSetWindowSize(window, mode->width, mode->height);
    } else {
        //toggle to windowed size
        glfwSetWindowAttrib(window, GLFW_DECORATED, GLFW_TRUE);
        glfwSetWindowSize(window, windowedWidth, windowedHeight);
        glfwSetWindowPos(window, windowedX, windowedY);
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