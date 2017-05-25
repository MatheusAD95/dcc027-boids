#ifndef _BOIDS_BOID_H_
#define _BOIDS_BOID_H_
#include "object.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>
#include <iostream>
class Boid : public Object {
  public:
    Boid(glm::mat4, glm::vec3);
    void move();
    void rotate(glm::vec3);
    void rotateModel(GLfloat, GLfloat, GLfloat);
    glm::vec3 getVel() { return vel; }
    void setVel(glm::vec3 v) { vel = v; }
    GLfloat getRotX() { return rotX; }
    GLfloat getRotY() { return rotY; }
    GLfloat getRotZ() { return rotZ; }
    glm::mat4 getRot() { return this->rot; }
    void setRotateMatrix(glm::mat4);
    void setObjective(glm::vec3 o) {
      vel = (0.02f)*(o - pos);
    }
    void addRepulsion(glm::vec3 r) {
      glm::vec3 dv = (r - pos);
      GLfloat distf = sqrt(dv.x*dv.x + dv.y*dv.y + dv.z*dv.z);
      glm::vec3 unit_dv = (1.0f/distf)*dv;
      GLfloat dist_factor = 2.56f/(distf*distf);
      vel -= dist_factor*unit_dv;
    }
    void draw();
  private:
    glm::vec3 objective;
    glm::mat4 trans, rot, sca;
    glm::vec3 vel, ivel, velrotX, velrotY;
    GLfloat rotX, rotY, rotZ;
    glm::mat4 id; //controls the rotation
};
#endif
