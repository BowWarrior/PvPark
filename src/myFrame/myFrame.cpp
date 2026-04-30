#include "glad/glad.h"
#include "myFrame.h"
#include <iostream>

MyFrame::MyFrame() : window(nullptr) {}

MyFrame::~MyFrame() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

bool MyFrame::init() {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW\n";
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); 

    window = glfwCreateWindow(800, 800, "PvPark", NULL, NULL);
    if (!window) {
        const char* description;
        int code = glfwGetError(&description);
        std::cout << "GLFW Window Creation Failed: " << description << " (Code: " << code << ")\n";
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD\n";
        return false;
    }

    return true;
}

void MyFrame::pollEvents() {
    glfwPollEvents();
}

bool MyFrame::shouldClose() {
    return glfwWindowShouldClose(window);
}

void MyFrame::swapBuffers() {
    glfwSwapBuffers(window);
}

GLFWwindow* MyFrame::getWindow() {
    return window;
}