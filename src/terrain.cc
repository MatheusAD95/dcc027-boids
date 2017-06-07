#include "terrain.h"
#include <glm/ext.hpp>
#include <iostream>
Terrain::Terrain(glm::mat4 VP, glm::vec3 pos)
  : Object(VP, pos, "../assets/plane", 1) {
    // rescale to make the terrain bigger
    GLfloat size = 200.0f;
    model = glm::scale(model, size*glm::vec3(1.0f, 1.0f, 1.0f));
    MVP = VP*model;
}
