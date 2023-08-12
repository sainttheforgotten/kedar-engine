#ifndef EBO_HPP
#define EBO_HPP

#include <GL/glew.h>

namespace kdr
{
  class EBO
  {
    public:
      EBO(GLuint indices[], GLsizeiptr size);

      const GLuint getID() const;

      void Bind();
      void Unbind();
      void Delete();

    private:
      GLuint ID;
  };
}

#endif // EBO_HPP
