#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>

namespace kdr
{
  class Shader
  {
    public:
      Shader(const char* vertexPath, const char* fragmentPath);

      const GLuint getID() const;

      void Use();
      void Delete();

    private:
      GLuint ID;
  };
}

#endif // SHADER_HPP
