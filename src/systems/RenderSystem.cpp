#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "RenderSystem.h"
#include "../ecs/ECS.h"


void RenderSystem::render(ECS& ecs, GLFWwindow* window){
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear depth for 3D

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    float aspectRatio = (float)width / (float)height;

    // Perspective projection — fixed FOV, aspect ratio adjusts with window size
    glm::mat4 projection = glm::perspective(
        glm::radians(45.0f), // fixed vertical FOV — widening window reveals more horizontally
        aspectRatio,         // derives horizontal FOV from window shape, no distortion
        0.1f,                // near clip
        1000.0f              // far clip — increase for large open worlds
    );

    // Placeholder view — replace this with your camera entity later
    glm::mat4 view = glm::lookAt(
        glm::vec3(0.0f, 2.0f, 5.0f),  // camera position
        glm::vec3(0.0f, 0.0f, 0.0f),  // looking at origin
        glm::vec3(0.0f, 1.0f, 0.0f)   // up direction
    );

    for(auto& [entity, render] : ecs.getRenders()){
        glUseProgram(render.shaderProgram);

        glm::mat4 model = glm::mat4(1.0f);

        glUniformMatrix4fv(glGetUniformLocation(render.shaderProgram, "model"),
            1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(glGetUniformLocation(render.shaderProgram, "view"),
            1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(render.shaderProgram, "projection"),
            1, GL_FALSE, glm::value_ptr(projection));

        glBindVertexArray(render.VAO);
        glDrawArrays(render.drawMode, 0, render.vertexCount);
    }

    glfwSwapBuffers(window);
}