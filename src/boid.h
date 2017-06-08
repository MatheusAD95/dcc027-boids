#ifndef _BOIDS_BOID_H_
#define _BOIDS_BOID_H_
//#include "object_texture.h"
#include "object.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/ext.hpp>
#include <iostream>
//class Boid : public ObjectTx {
class Boid : public Object {
  public:
    Boid(glm::mat4, glm::vec3);
    void move();
    void rotate(glm::vec3, GLfloat = 0.02f);
    //void rotateModel(GLfloat, GLfloat, GLfloat);
    glm::vec3 getVel() { return vel; }
    glm::mat4 getRot() { return this->rot; }
    void setVel(glm::vec3 v) { vel = v; }
    void setRotateMatrix(glm::mat4);
    /// makes the boid move toward the point o
    void setObjective(glm::vec3 o) {
      vel = (0.02f)*(o - pos);
    }
    glm::vec3 normalizeVec3(glm::vec3 dv) {
      GLfloat distf = sqrt(dv.x*dv.x + dv.y*dv.y + dv.z*dv.z);
      glm::vec3 unit_dv = (1.0f/distf)*dv;
      return unit_dv;
    }
    /// makes the boid avoid collision with another boid at point r
    void addRepulsion(glm::vec3 r, GLfloat factor = 1.0f) {
      glm::vec3 dv = (r - pos);
      GLfloat distf = sqrt(dv.x*dv.x + dv.y*dv.y + dv.z*dv.z);
      glm::vec3 unit_dv = (1.0f/distf)*dv;
      GLfloat dist_factor = factor*2.56f/(distf*distf);
      vel -= dist_factor*unit_dv;
    }
    void rotateToVel() {
      glm::vec3 vel_xz = vel;
      vel_xz.y = 0;
      glm::vec3 unit_vel = normalizeVec3(vel_xz),
        unit_ivel = normalizeVec3(ivel);
      glm::vec3 axis = glm::cross(unit_ivel, unit_vel);
      GLfloat angle = acos(glm::dot(unit_vel, unit_ivel));
      glm::mat4 id;
      rot = glm::rotate(id, angle, axis);
      model = trans*rot*sca;
      MVP = VP*model;
    }
    void limitVel() {
      //vel = 0.9f*normalizeVec3(vel);
    }
  private:
    glm::vec3 objective;
    glm::vec3 vel, ivel;
    glm::mat4 id; //controls the rotation
};
#endif
