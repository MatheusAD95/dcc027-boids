#include "boid.h"
#include <iostream>
#include <glm/ext.hpp>
#define BOIDS_PI 3.1415f
const GLfloat STEERING = 0.02f;
Boid::Boid(glm::mat4 VP, glm::vec3 pos)
  : Object(VP, pos + glm::vec3(0.0f, 3.0f, 0.0f), "../assets/tt", 6) {
  trans = glm::translate(trans, pos + glm::vec3(0.0f, 3.0f, 0.0f));
  model = trans*rot*sca;
  MVP = VP*model;
  vel = glm::vec3(0.0f, 0.0f, 0.3f);
  ivel = vel;
  rotX = 0.0f;
  rotY = 0.0f;
  rotZ = 0.0f;
}
void Boid::move() {
  pos += vel;
  trans = glm::translate(trans, vel);
  model = trans*rot*sca;
  MVP = VP*model;
}
void Boid::rotate(glm::vec3 axis) {
  rotX += axis.x*BOIDS_PI*STEERING;
  rotY += axis.y*BOIDS_PI*STEERING;
  rotZ += axis.z*BOIDS_PI*STEERING;
  rot = glm::rotate(rot, BOIDS_PI*STEERING, axis);
  glm::vec4 v4 = glm::vec4(ivel.x, ivel.y, ivel.z, 1);
  v4 = rot*v4;
  vel = glm::vec3(v4.x, v4.y, v4.z);
  model = trans*rot*sca;
  MVP = VP*model;
}
void Boid::rotateModel(GLfloat rotX, GLfloat rotY, GLfloat rotZ) {
  glm::mat4 id;
  rot = glm::rotate(id, rotY, glm::vec3(0.0f, 1.0f, 0.0f));
  rot = glm::rotate(rot, rotX, glm::vec3(1.0f, 0.0f, 0.0f));
  rot = glm::rotate(rot, rotZ, glm::vec3(0.0f, 0.0f, 1.0f));
  model = trans*rot*sca;
  MVP = VP*model;
}
void Boid::setRotateMatrix(glm::mat4 rot) {
  this->rot = rot;
  model = trans*rot*sca;
  MVP = VP*model;
}
