#ifndef _BOIDS_SHADER_H_
#define _BOIDS_SHADER_H_
#include <GL/glew.h>
class Shader {
  public:
    GLuint ID;
    Shader() {};
    void compile(const GLchar *vertexSource,
        const GLchar *fragmentSource,
        const GLchar *geometrySource = NULL);
    void compileFromPath(const GLchar *vertexSourceCode,
        const GLchar *fragmentSourceCode);
    GLuint &getID();
  private:
    void checkShaderCompileErrors(GLuint object);
    void checkProgramCompileErrors(GLuint object);
};
#endif
