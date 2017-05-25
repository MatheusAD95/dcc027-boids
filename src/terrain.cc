#include "terrain.h"
#include <glm/ext.hpp>
#include <iostream>
Terrain::Terrain(glm::mat4 VP, glm::vec3 pos)
  : Object(VP, pos, "../assets/plane", 1) {
    // rescale to make the terrain bigger
    model = glm::scale(model, glm::vec3(100.0f, 100.0f, 100.0f));
    MVP = VP*model;
}
