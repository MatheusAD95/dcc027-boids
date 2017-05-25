#include "terrain.h"
#include <glm/ext.hpp>
#include <iostream>
Terrain::Terrain(glm::mat4 VP, glm::vec3 pos)
  : Object(VP, pos, "../assets/plane", 1) {
    // rescale to make the terrain bigger
    model = glm::scale(model, glm::vec3(20.0f, 20.0f, 20.0f));
    MVP = VP*model;
}
