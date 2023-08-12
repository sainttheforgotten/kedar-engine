#include "../Headers/VBO.hpp"

kdr::VBO::VBO(GLfloat vertices[], GLsizeiptr size)
{
  glGenBuffers(1, &this->ID);
  glBindBuffer(GL_ARRAY_BUFFER, this->ID);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

const GLuint kdr::VBO::getID() const
{
  return this->ID;
}

void kdr::VBO::Bind()
{
  glBindBuffer(GL_ARRAY_BUFFER, this->ID);
}

void kdr::VBO::Unbind()
{
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void kdr::VBO::Delete()
{
  glDeleteBuffers(1, &this->ID);
}
