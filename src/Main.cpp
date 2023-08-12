#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Headers/Shader.hpp"
#include "Headers/VBO.hpp"
#include "Headers/EBO.hpp"
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
  kdr::VBO VBO1(vertices, sizeof(vertices));
  kdr::EBO EBO1(indices, sizeof(indices));

  glGenVertexArrays(1, &VAO);

  glBindVertexArray(VAO);
  VBO1.Bind();
  EBO1.Bind();

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindVertexArray(0);
  VBO1.Unbind();
  EBO1.Unbind();

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
  VBO1.Delete();
  EBO1.Delete();
  defaultShader.Delete();
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
