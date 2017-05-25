#ifndef _BOIDS_TERRAIN_H_
#define _BOIDS_TERRAIN_H_
#include "object.h"
#include <glm/gtc/matrix_transform.hpp>
class Terrain : public Object {
  public:
    Terrain(glm::mat4, glm::vec3);
  private:
};
#endif
