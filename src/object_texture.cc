#include "object_texture.h"
#include "texture.hpp"
#include "obj_model.h"
#include <glm/gtc/matrix_transform.hpp>
#include <cstdio>
#include <cstdlib>
#include <ctime>
///
///
///
void ObjectTx::setVP(glm::mat4 VP) {
  this->VP = VP;
  MVP = VP*model;
}
///
///
///
ObjectTx::ObjectTx(glm::mat4 VP, glm::vec3 pos, const char *path, int n) {
  Texture = loadBMP_custom("../assets/BirdText.bmp");
  cnt = cnt2 = 0;
  direction = 1;
  number_of_frames = n;
  srand(time(NULL));
  shader.compileFromPath("../src/TransformVertexShader.vertexshader",
      "../src/TextureFragmentShader.fragmentshader");
  frames = (Frame2 *)malloc(n*sizeof(Frame2));
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
GLuint ObjectTx::addFrame(Frame2 *f, const char *path) {
  ObjModel O(path);
  glGenVertexArrays(1, &f->vao);
  glBindVertexArray(f->vao);
  std::vector<glm::vec3> g_vertex_buffer_data = O.getVertices();

  std::vector<glm::vec2> uv_data = O.getUV();
  // One color for each vertex. They were generated randomly.
  std::vector<glm::vec3> g_color_buffer_data;

  glGenBuffers(1, &f->vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, f->vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, g_vertex_buffer_data.size()*sizeof(glm::vec3),
      &g_vertex_buffer_data[0], GL_STATIC_DRAW);

  glGenBuffers(1, &f->uvbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, f->uvbuffer);
  glBufferData(GL_ARRAY_BUFFER, uv_data.size()*sizeof(glm::vec2),
      &uv_data[0], GL_STATIC_DRAW);

  return g_vertex_buffer_data.size();
}
///
///
///
void ObjectTx::move(glm::vec3 d) {
  pos += d;
  model = glm::translate(model, d);
  MVP = VP*model;
}
///
///
///
void ObjectTx::draw() {
  printf("In here\n");

  if (cnt2++ == frame_delay && number_of_frames > 1) {
    cnt += direction, cnt2 = 0;
    if (!(cnt%(number_of_frames - 1))) direction *= -1;
    //printf("%d %d\n", cnt, number_of_frames);
  }

  Frame2 g = frames[cnt%number_of_frames];

  glUseProgram(shader.getID());
  glBindVertexArray(g.vao);
  GLuint MatrixID = glGetUniformLocation(shader.getID(), "MVP");
  glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

  GLuint TextureID = glGetUniformLocation(shader.getID(), "myTextureSampler");

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, Texture);
  glUniform1i(TextureID, 0);


  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, g.vertexbuffer);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

  glEnableVertexAttribArray(1);
  glBindBuffer(GL_ARRAY_BUFFER, g.uvbuffer);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
  glDrawArrays(GL_TRIANGLES, 0, number_of_vertices);

  //g_vertex_buffer_data.size());

  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glBindVertexArray(0);
}
ObjectTx::~ObjectTx() {
  //glDeleteVertexArrays(1, &f.vao);
  //glDeleteBuffers(1, &f.colorbuffer);
  //glDeleteBuffers(1, &f.vertexbuffer);
  //TODO for each frame delete vao, colorbuffer and vertexbuffer
  free(frames);
}
