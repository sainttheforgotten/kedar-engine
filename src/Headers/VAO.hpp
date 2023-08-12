#ifndef VAO_HPP
#define VAO_HPP

#include <GL/glew.h>

#include "VBO.hpp"

namespace kdr
{
  class VAO
  {
    public:
      VAO();

      const GLuint getID() const;

      void LinkAttrib(VBO& VBO, GLuint layout, GLuint size, GLenum type, GLsizei stride, const void* offset);
      void Bind();
      void Unbind();
      void Delete();

    private:
      GLuint ID;
  };
}

#endif // VAO_HPP
