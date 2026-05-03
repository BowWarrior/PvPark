#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "RenderSystem.h"
#include "../ecs/ECS.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void RenderSystem::render(ECS& ecs, GLFWwindow* window){
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // get window size
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    float aspectRatio = (float)width / (float)height;

    // view matrix - camera looking at origin from z=3
    glm::mat4 view = glm::lookAt(
        glm::vec3(0.0f, 0.0f, 3.0f),  // camera position
        glm::vec3(0.0f, 0.0f, 0.0f),  // looking at origin
        glm::vec3(0.0f, 1.0f, 0.0f)   // up direction
    );

    // projection matrix - handles aspect ratio and perspective
    glm::mat4 projection = glm::perspective(
        glm::radians(45.0f),  // field of view
        aspectRatio,          // aspect ratio
        0.1f,                 // near clip
        100.0f                // far clip
    );

    for(auto& [entity, render] : ecs.getRenders()){
        glUseProgram(render.shaderProgram);

        // model matrix - identity for now (no transform)
        glm::mat4 model = glm::mat4(1.0f);

        // pass matrices to shader
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