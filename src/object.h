#ifndef _BOIDS_OBJECT_H_
#define _BOIDS_OBJECT_H_
#include "shader.h"
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
typedef struct {
  GLuint vao, colorbuffer, vertexbuffer, uvbuffer;
} Frame;
class Object {
  public:
    Object(glm::mat4 VP, glm::vec3, const char *, int);
    Object(glm::mat4 VP, glm::vec3, const char *, int, const char *);
    ~Object();
    void move(glm::vec3);
    virtual void draw();
    void drawTxt();
    void drawColor();
    void setVP(glm::mat4 VP);
    glm::vec3 getPos() { return pos; }
    GLuint addFrame(Frame *, const char *, GLuint = 0);
    GLfloat getWidth() { return width; }
    GLfloat getHeight() { return height; }
  protected:
    glm::mat4 VP, MVP, model;
    glm::vec3 pos;
    GLfloat height, width;
  private:
    GLuint textured;
    static const GLuint frame_delay = 5;
    GLuint Texture;
    GLuint number_of_vertices;
    Shader shader;
    GLuint vao, colorbuffer, vertexbuffer;
    GLuint cnt, cnt2, number_of_frames, direction;
    Frame *frames;
    std::vector<glm::vec3> g_vertex_buffer_data;
    std::vector<glm::vec3> color_buff;
};
#endif
