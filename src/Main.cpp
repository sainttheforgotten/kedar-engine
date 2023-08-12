#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Headers/Shader.hpp"
#include "Utils/File.hpp"

const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const char* WINDOW_TITLE         = "Kedar Engine";

GLfloat vertices[] = {
  -0.5f,  -0.5f, 0.0f, 1.f, 0.f, 0.f,
   0.0f,  -0.5f, 0.0f, 0.f, 1.f, 0.f,
   0.5f,  -0.5f, 0.0f, 0.f, 0.f, 1.f,
  -0.25f,  0.0f, 0.0f, 1.f, 1.f, 0.f,
   0.25f,  0.0f, 0.0f, 0.f, 1.f, 1.f,
   0.0f,   0.5f, 0.0f, 1.f, 0.f, 1.f,
};
GLuint indices[] = {
  0, 1, 3,
  1, 2, 4,
  3, 4, 5,
};

int main()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE,
    NULL,
    NULL
  );
  if (window == NULL)
  {
    std::cerr << "Failed to create a window!" << std::endl;
    glfwTerminate();
    return 1;
  }
  glfwMakeContextCurrent(window);

  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    std::cerr << "Failed to initialize GLEW!" << std::endl;
    std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
    glfwTerminate();
    return 1;
  }

  GLclampf red   = 0.0f;
  GLclampf green = 0.3f;
  GLclampf blue  = 0.3f;
  GLclampf alpha = 1.0f;
  glClearColor(red, green, blue, alpha);

  kdr::Shader defaultShader("src/Shaders/default.vert", "src/Shaders/default.frag");

  GLuint VAO;
  GLuint VBO;
  GLuint EBO;

  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindVertexArray(VAO);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glBindVertexArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    defaultShader.Use();
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
    glfwSwapBuffers(window);
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
  defaultShader.Delete();
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
