#include "../Headers/VAO.hpp"

kdr::VAO::VAO()
{
  glGenVertexArrays(1, &this->ID);
}

const GLuint kdr::VAO::getID() const
{
  return this->ID;
}

void kdr::VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint size, GLenum type, GLsizei stride, const void* offset)
{
  VBO.Bind();
  glVertexAttribPointer(layout, size, type, GL_FALSE, stride, offset);
  glEnableVertexAttribArray(layout);
  VBO.Unbind();
}

void kdr::VAO::Bind()
{
  glBindVertexArray(this->ID);
}

void kdr::VAO::Unbind()
{
  glBindVertexArray(0);
}

void kdr::VAO::Delete()
{
  glDeleteVertexArrays(1, &this->ID);
}
