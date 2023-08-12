#ifndef GAME_HPP
#define GAME_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "Shader.hpp"
#include "VAO.hpp"
#include "VBO.hpp"
#include "EBO.hpp"

namespace kdr
{
  class Game
  {
    public:
      Game(){};
      ~Game();

      bool initialize();
      void run();
      void terminate();

    private:
      GLFWwindow* window;
      Shader* defaultShader;
      VAO* VAO1;
      VBO* VBO1;
      EBO* EBO1;

      bool initializeGlfw();
      bool initializeGlew();
      bool initializeWindow();
      bool initializeComponents();

      void update();
      void render();
  };
}

#endif // GAME_HPP
