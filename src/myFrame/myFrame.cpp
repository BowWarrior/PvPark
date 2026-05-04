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
}


bool MyFrame::init(){
    glfwInit();

    //sets size of the window to monitor size
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    width = mode->width;
    height = mode->height;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if(window == NULL){
        cout << "failed to create GLFW window" << endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        cout << "failed to initialize GLAD" << endl;
        return false;
    }
    return true;
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