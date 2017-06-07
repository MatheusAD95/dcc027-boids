#ifndef _BOIDS_CONE_H_
#define _BOIDS_CONE_H_
#include "object.h"
#include <glm/gtc/matrix_transform.hpp>
class Cone : public Object {
  public:
    Cone(glm::mat4, glm::vec3, glm::vec3);
  private:
};
#endif
