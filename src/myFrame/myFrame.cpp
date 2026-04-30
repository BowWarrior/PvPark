#include <iostream>
#include "myFrame.h"
using namespace std;

MyFrame::MyFrame(){
    width = 800;
    height = 800;
    title = "PvPark";
    window = nullptr;
}

MyFrame::MyFrame(int width, int height, const char* title){
    this->width = width;
    this->height = height;
    this->title = title;
    window = nullptr;
}

bool MyFrame::init(){
    glfwInit();
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