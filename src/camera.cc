#include "camera.h"
/// Returns the view matrix corresponding to this camera
///
///
glm::mat4 Camera::getView() {
  return view;
}
/// Creates a new camera at the position p, looking
///
///
Camera::Camera(glm::vec3 position, glm::vec3 look_at) {
  this->position = position;
  this->look_at = look_at;
  view = glm::lookAt(position, look_at, glm::vec3(0, 1, 0));
}
void Camera::lookAt(glm::vec3 look_at) {
  this->look_at = look_at;
  view = glm::lookAt(position, look_at, glm::vec3(0, 1, 0));
}
void Camera::setPos(glm::vec3 pos) {
  position = pos;
  view = glm::lookAt(position, look_at, glm::vec3(0, 1, 0));
}
