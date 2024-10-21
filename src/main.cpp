#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <iostream>

// --------------------------------------------------------------------------------------------------------------------
// Settings
// --------------------------------------------------------------------------------------------------------------------
constexpr unsigned int WIDTH = 800;
constexpr unsigned int HEIGHT = 600;
// --------------------------------------------------------------------------------------------------------------------

// --------------------------------------------------------------------------------------------------------------------
// Function Declarations
// --------------------------------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
// --------------------------------------------------------------------------------------------------------------------

int main()
{
    // ----------------------------------------------------------------------------------------------------------------
    // Initialization
    // ----------------------------------------------------------------------------------------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    // ----------------------------------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------------------------------
    // Create Window
    // ----------------------------------------------------------------------------------------------------------------
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "ERROR::GLFW::WINDOW::FAILED_CREATE" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // ----------------------------------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------------------------------
    // Register callbacks
    // ----------------------------------------------------------------------------------------------------------------
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    // ----------------------------------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------------------------------
    // Initialize GLAD
    // ----------------------------------------------------------------------------------------------------------------
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cout << "ERROR::GLAD::GLAD_LOAD_FAILED" << std::endl;
        return -1;
    }
    // ----------------------------------------------------------------------------------------------------------------

    // ----------------------------------------------------------------------------------------------------------------
    // Render loop
    // ----------------------------------------------------------------------------------------------------------------
    while (!glfwWindowShouldClose(window)) {
        // Process input
        processInput(window);

        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers
        glfwSwapBuffers(window);
        // Poll events
        glfwPollEvents();
    }
    // ----------------------------------------------------------------------------------------------------------------

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, const int width, const int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
