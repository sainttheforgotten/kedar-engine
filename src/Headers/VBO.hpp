#ifndef VBO_HPP
#define VBO_HPP

#include <GL/glew.h>

namespace kdr
{
  class VBO
  {
    public:
      VBO(GLfloat vertices[], GLsizeiptr size);

      const GLuint getID() const;

      void Bind();
      void Unbind();
      void Delete();

    private:
      GLuint ID;
  };
}

#endif // VBO_HPP
