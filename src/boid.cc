#include "boid.h"
#include <iostream>
#include <glm/ext.hpp>
#define BOIDS_PI 3.1415f
const GLfloat STEERING = 0.02f;
Boid::Boid(glm::mat4 VP, glm::vec3 pos)
  //: Object(VP, pos + glm::vec3(0.0f, 3.0f, 0.0f), "../assets/tt", 6) {
  //: Object(VP, pos + glm::vec3(0.0f, 3.0f, 0.0f), "../assets/teteu_texture",
  //    1, "../assets/BirdText.bmp") {

  //: Object(VP, pos + glm::vec3(0.0f, 3.0f, 0.0f), "../assets/tt",
  //    6, "../assets/teteu_text.bmp") {  //doesnt work because tt0 doesnt
                                          // map uvs
  //: Object(VP, pos + glm::vec3(0.0f, 3.0f, 0.0f), "../assets/teteu_text",
  : Object(VP, pos + glm::vec3(0.0f, 3.0f, 0.0f), "../assets/tt_text",
      5, "../assets/teteu_text.bmp") {

  //: ObjectTx(VP, pos + glm::vec3(0.0f, 3.0f, 0.0f), "../assets/teteu_texture", 1) {
  trans = glm::translate(trans, pos + glm::vec3(0.0f, 3.0f, 0.0f));
  sca = glm::scale(sca, glm::vec3(0.5f, 0.5f, 0.5f));
  model = trans*rot*sca;
  MVP = VP*model;
  vel = glm::vec3(0.0f, 0.0f, 0.3f);
  ivel = vel;
}
void Boid::move() {
  pos += vel;
  trans = glm::translate(trans, vel);
  model = trans*rot*sca;
  MVP = VP*model;
}
void Boid::rotate(glm::vec3 axis, GLfloat steering) {
  rot = glm::rotate(rot, BOIDS_PI*steering, axis);
  glm::vec4 v4 = glm::vec4(ivel.x, ivel.y, ivel.z, 1);
  v4 = rot*v4;
  vel = glm::vec3(v4.x, v4.y, v4.z);
  model = trans*rot*sca;
  MVP = VP*model;
}
//void Boid::rotateModel(GLfloat rotX, GLfloat rotY, GLfloat rotZ) {
//  glm::mat4 id;
//  rot = glm::rotate(id, rotY, glm::vec3(0.0f, 1.0f, 0.0f));
//  rot = glm::rotate(rot, rotX, glm::vec3(1.0f, 0.0f, 0.0f));
//  rot = glm::rotate(rot, rotZ, glm::vec3(0.0f, 0.0f, 1.0f));
//  model = trans*rot*sca;
//  MVP = VP*model;
//}
void Boid::setRotateMatrix(glm::mat4 rot) {
  this->rot = rot;
  model = trans*rot*sca;
  MVP = VP*model;
}
