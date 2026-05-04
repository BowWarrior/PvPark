#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "RenderSystem.h"
#include "../ecs/ECS.h"


void RenderSystem::render(ECS& ecs, GLFWwindow* window){
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    float aspectRatio = (float)width / (float)height;

    // Fixed world half-height — world always spans -1 to 1 vertically.
    // Width expands/shrinks with the window, cropping peripheral vision.
    const float halfHeight = 1.0f;
    float halfWidth = halfHeight * aspectRatio;

    glm::mat4 view = glm::mat4(1.0f); // no camera movement needed for 2D

    glm::mat4 projection = glm::ortho(
        -halfWidth,  halfWidth,   // left, right — scales with window width
        -halfHeight, halfHeight,  // bottom, top — always fixed
        -1.0f, 1.0f              // near, far
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