#include "../Headers/Game.hpp"

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

kdr::Game::~Game()
{
  delete this->defaultShader;
  delete this->VAO1;
  delete this->VBO1;
  delete this->EBO1;
}

bool kdr::Game::initialize()
{
  bool success = true;

  success = this->initializeGlfw();
  success = this->initializeWindow();
  success = this->initializeGlew();
  success = this->initializeComponents();

  return success;
}

void kdr::Game::run()
{
  while (!glfwWindowShouldClose(this->window))
  {
    this->update();
    this->render();
  }
}

void kdr::Game::terminate()
{
  this->defaultShader->Delete();
  this->VAO1->Delete();
  this->VBO1->Delete();
  this->EBO1->Delete();
  glfwDestroyWindow(this->window);
  glfwTerminate();
}

bool kdr::Game::initializeGlfw()
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  return true;
}

bool kdr::Game::initializeComponents()
{
  this->defaultShader = new kdr::Shader("src/Shaders/default.vert", "src/Shaders/default.frag");
  this->VAO1 = new kdr::VAO();
  this->VBO1 = new kdr::VBO(vertices, sizeof(vertices));
  this->EBO1 = new kdr::EBO(indices, sizeof(indices));

  this->VAO1->Bind();
  this->VBO1->Bind();
  this->EBO1->Bind();

  this->VAO1->LinkAttrib(*this->VBO1, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
  this->VAO1->LinkAttrib(*this->VBO1, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

  this->VAO1->Unbind();
  this->VBO1->Unbind();
  this->EBO1->Unbind();

  return true;
}

bool kdr::Game::initializeWindow()
{
  this->window = glfwCreateWindow(
    800,
    600,
    "Kedar Engine",
    NULL,
    NULL
  );
  if (window == NULL)
  {
    std::cerr << "Failed to create a window!" << std::endl;
    glfwTerminate();
    return false;
  }
  glfwMakeContextCurrent(this->window);

  GLclampf red   = 0.0f;
  GLclampf green = 0.3f;
  GLclampf blue  = 0.3f;
  GLclampf alpha = 1.0f;
  glClearColor(red, green, blue, alpha);

  return true;
}

bool kdr::Game::initializeGlew()
{
  GLenum err = glewInit();
  if (GLEW_OK != err)
  {
    std::cerr << "Failed to initialize GLEW!" << std::endl;
    std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
    glfwTerminate();
    return false;
  }
  return true;
}

void kdr::Game::update()
{
  glfwPollEvents();
}

void kdr::Game::render()
{
  glClear(GL_COLOR_BUFFER_BIT);
  this->defaultShader->Use();
  this->VAO1->Bind();
  glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
  glfwSwapBuffers(this->window);
}
