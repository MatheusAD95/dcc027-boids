/// Loads obj files into memory
/// Inspired on:
/// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading
///
#ifndef _BOIDS_OBJ_MODEL_H_
#define _BOIDS_OBJ_MODEL_H_
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
class ObjModel {
  public:
    ObjModel(const char *);
    std::vector<glm::vec3> getVertices() { return vertices; }
    std::vector<glm::vec2> getUV() { return uvs; }
  private:
    std::vector<glm::vec3> vertices, normals;
    std::vector<glm::vec2> uvs;
    void parseFace(char *, unsigned *, unsigned *, unsigned *);
};
#endif
