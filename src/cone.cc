#include "cone.h"
Cone::Cone(glm::mat4 VP, glm::vec3 pos, glm::vec3 s)
  : Object(VP, pos, "../assets/cone", 1) {
    // assuming that scales through x and z equally TODO change
    width *= s.x;
    height *= s.y;
    // rescale to make the terrain bigger
    model = glm::scale(model, s);
    MVP = VP*model;
}
