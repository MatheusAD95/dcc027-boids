#include "object.h"
#include "texture.hpp"
#include "obj_model.h"
#include <iostream>
#include <cfloat>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>
#include <cstdio>
#include <cstdlib>
#include <ctime>
double dRand() {
  return (((double)rand())/RAND_MAX);
}
///
///
///
void Object::setVP(glm::mat4 VP) {
  this->VP = VP;
  MVP = VP*model;
}
///
///
///
Object::Object(glm::mat4 VP, glm::vec3 pos, const char *path, int n,
    const char *text) {
  textured = 1;
  Texture = loadBMP_custom(text);
  cnt = cnt2 = 0;
  direction = 1;
  number_of_frames = n;
  srand(time(NULL));
  shader.compileFromPath("../src/TransformVertexShader.vertexshader",
      "../src/TextureFragmentShader.fragmentshader");
  frames = (Frame *)malloc(n*sizeof(Frame));
  for (int i = 0; i < n; ++i) {
    char frame_path[256];
    sprintf(frame_path, "%s%d.obj", path, i);
    number_of_vertices = addFrame(frames + i, frame_path, 1);
  }
  model = glm::mat4(1.0f);
  model = glm::translate(model, pos);
  MVP = VP*model;
  this->VP = VP;
  this->pos = pos;
}
///
///
///
Object::Object(glm::mat4 VP, glm::vec3 pos, const char *path, int n) {
  width = height = textured = 0;
  cnt = cnt2 = 0;
  direction = 1;
  number_of_frames = n;
  shader.compileFromPath("../src/TransformVertexShader.vs",
      "../src/ColorFragmentShader.fs");
  frames = (Frame *)malloc(n*sizeof(Frame));
  for (int i = 0; i < n; ++i) {
    char frame_path[256];
    sprintf(frame_path, "%s%d.obj", path, i);
    number_of_vertices = addFrame(frames + i, frame_path);
  }
  model = glm::mat4(1.0f);
  model = glm::translate(model, pos);
  MVP = VP*model;
  this->VP = VP;
  this->pos = pos;
}
///
///
///
GLuint Object::addFrame(Frame *f, const char *path, GLuint tex) {
  ObjModel O(path);
  glGenVertexArrays(1, &f->vao);
  glBindVertexArray(f->vao);
  std::vector<glm::vec3> vertex_data = O.getVertices();
  double min_x = DBL_MAX, max_x = DBL_MIN,
      min_y = min_x, max_y = max_x,
      min_z = min_x, max_z = max_x;
  for (int i = 0, ii = vertex_data.size(); i < ii; ++i) {
    int x = vertex_data[i].x,
        y = vertex_data[i].y,
        z = vertex_data[i].z;
    if (x < min_x) min_x = x;
    if (x > max_x) max_x = x;

    if (y < min_y) min_y = y;
    if (y > max_y) max_y = y;

    if (z < min_z) min_z = z;
    if (z > max_z) max_z = z;
  }
  double dx = (max_x - min_x),
         dy = (max_y - min_y),
         dz = (max_z - min_z);
  if (dz > width) width = dz;
  if (dx > width) width = dx;
  if (dy > height) height = width;


  glGenBuffers(1, &f->vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, f->vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, vertex_data.size()*sizeof(glm::vec3),
      &vertex_data[0], GL_STATIC_DRAW);
  if (tex) {
    std::vector<glm::vec2> uv_data = O.getUV();
    glGenBuffers(1, &f->uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, f->uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, uv_data.size()*sizeof(glm::vec2),
        &uv_data[0], GL_STATIC_DRAW);
    std::vector<glm::vec3> normals = O.getNormals();
    glGenBuffers(1, &f->normalbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, f->normalbuffer);
    glBufferData(GL_ARRAY_BUFFER, normals.size()*sizeof(glm::vec3),
        &normals[0], GL_STATIC_DRAW);
    return vertex_data.size();
  }
  std::vector<glm::vec3> color_data;
  if (color_buff.empty()) {
    for (int i = 0, ii = vertex_data.size(); i < ii; ++i)
      color_data.push_back(glm::vec3(dRand(), dRand(), dRand()));
    color_buff = color_data;
  }
  color_data = color_buff;
  glGenBuffers(1, &f->colorbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, f->colorbuffer);
  glBufferData(GL_ARRAY_BUFFER, color_data.size()*sizeof(glm::vec3),
      &color_data[0], GL_STATIC_DRAW);
  return vertex_data.size();
}
///
///
///
void Object::move(glm::vec3 d) {
  pos += d;
  model = glm::translate(model, d);
  MVP = VP*model;
}
///
///
///
void Object::drawTxt() {
  if (cnt2++ == frame_delay && number_of_frames > 1) {
    cnt += direction, cnt2 = 0;
    if (!(cnt%(number_of_frames - 1))) direction *= -1;
  }
  Frame g = frames[cnt%number_of_frames];
  glUseProgram(shader.getID());
  glBindVertexArray(g.vao);
  // MVP uniform
  GLuint MatrixID = glGetUniformLocation(shader.getID(), "MVP");
  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
  // model uniform
  GLuint ModelID = glGetUniformLocation(shader.getID(), "model");
  glUniformMatrix4fv(ModelID, 1, GL_FALSE, &model[0][0]);
  // rot uniform
  GLuint RotID = glGetUniformLocation(shader.getID(), "rot");
  glUniformMatrix4fv(RotID, 1, GL_FALSE, &rot[0][0]);
  // texture uniform
  GLuint TextureID = glGetUniformLocation(shader.getID(), "myTextureSampler");
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, Texture);
  glUniform1i(TextureID, 0);
  // pos
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, g.vertexbuffer);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  // uvs
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, g.uvbuffer);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
  // normals
  glEnableVertexAttribArray(2);
  glBindBuffer(GL_ARRAY_BUFFER, g.normalbuffer);
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  glDrawArrays(GL_TRIANGLES, 0, number_of_vertices);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glBindVertexArray(0);
}
///
///
///
void Object::drawColor() {
  if (cnt2++ == frame_delay && number_of_frames > 1) {
    cnt += direction, cnt2 = 0;
    if (!(cnt%(number_of_frames - 1))) direction *= -1;
  }
  Frame g = frames[cnt%number_of_frames];
  glUseProgram(shader.getID());
  glBindVertexArray(g.vao);
  GLuint MatrixID = glGetUniformLocation(shader.getID(), "MVP");
  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, g.vertexbuffer);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, g.colorbuffer);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glDrawArrays(GL_TRIANGLES, 0, number_of_vertices);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glBindVertexArray(0);
}
///
///
///
void Object::draw() {
  if (textured) drawTxt();
  else drawColor();
}
Object::~Object() {
  //glDeleteVertexArrays(1, &f.vao);
  //glDeleteBuffers(1, &f.colorbuffer);
  //glDeleteBuffers(1, &f.vertexbuffer);
  //TODO for each frame delete vao, colorbuffer and vertexbuffer
  free(frames);
}
