#ifndef _BOIDS_OBJECT_TEXTURE_H_
#define _BOIDS_OBJECT_TEXTURE_H_
#include "shader.h"
#include "object.h"
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
typedef struct {
  GLuint vao, uvbuffer, vertexbuffer;
} Frame2;
class ObjectTx {
  public:
    ObjectTx(glm::mat4 VP, glm::vec3, const char *, int);
    ~ObjectTx();
    void move(glm::vec3);
    virtual void draw();
    void setVP(glm::mat4 VP);
    glm::vec3 getPos() { return pos; }
    GLuint addFrame(Frame2 *, const char *);
  protected:
    glm::mat4 VP, MVP, model;
    glm::vec3 pos;
  private:
    static const GLuint frame_delay = 5;
    GLuint number_of_vertices;
    Shader shader;
    GLuint vao, colorbuffer, vertexbuffer;
    GLuint cnt, cnt2, number_of_frames, direction;
    Frame2 *frames;
    std::vector<glm::vec3> g_vertex_buffer_data;
    std::vector<glm::vec3> color_buff;
    GLuint Texture;
};
#endif
