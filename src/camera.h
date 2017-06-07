#ifndef _BOIDS_CAMERA_H_
#define _BOIDS_CAMERA_H_
#include <glm/gtc/matrix_transform.hpp>
class Camera {
  public:
    Camera(glm::vec3, glm::vec3);
    glm::mat4 getView();
    void rotate();
    void lookAt(glm::vec3);
    void setPos(glm::vec3);
  private:
    glm::vec3 position, look_at;
    glm::mat4 view;
};
#endif
