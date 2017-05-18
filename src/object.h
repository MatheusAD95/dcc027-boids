#ifndef _BOIDS_OBJECT_H_
#define _BOIDS_OBJECT_H_
#include "shader.h"
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
class Object {
  public:
    Object(glm::mat4 VP, glm::vec3);
    ~Object();
    void move(glm::vec3);
    void draw();
    void setVP(glm::mat4 VP);
    glm::vec3 getPos() { return pos; }
  private:
    Shader shader;
    GLuint vao, colorbuffer, vertexbuffer;
    glm::mat4 VP;
    glm::mat4 MVP, model;
    glm::vec3 pos;
};
#endif
