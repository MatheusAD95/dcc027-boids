#ifndef _BOIDS_GAME_H_
#define _BOIDS_GAME_H_
#include "boid.h"
#include "camera.h"
#include "object.h"
#include "terrain.h"
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <queue>
#include <iostream>
class Game {
  public:
    static void ws_callback(GLFWwindow *win, int w, int h) {
      getGame().changeSize(w, h);
    }
    static void key_evh(GLFWwindow* w, int key, int sc, int action, int m) {
      // esc quits
      if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(getGame().window, GL_TRUE);
      // m moves the guide
      if (key == GLFW_KEY_M && action == GLFW_PRESS)
        getGame().guide->move();
      //if (key == GLFW_KEY_R && action == GLFW_PRESS)
      //  getGame().guide->rotate();
      if (key == GLFW_KEY_A)
        getGame().guide->rotate(glm::vec3(0.0f, 1.0f, 0.0f));
      if (key == GLFW_KEY_D)
        getGame().guide->rotate(glm::vec3(0.0f, -1.0f, 0.0f));
      if (key == GLFW_KEY_W)
        getGame().guide->rotate(glm::vec3(1.0f, 0.0f, 0.0f));
      if (key == GLFW_KEY_S)
        getGame().guide->rotate(glm::vec3(-1.0f, 0.0f, 0.0f));
      if (key == GLFW_KEY_E)
        getGame().guide->rotate(glm::vec3(0.0f, 0.0f, 1.0f));
      if (key == GLFW_KEY_Q)
        getGame().guide->rotate(glm::vec3(0.0f, 0.0f, -1.0f));
      if (key == GLFW_KEY_C && action == GLFW_PRESS)
        getGame().changeCamera();
      if (key == GLFW_KEY_KP_ADD && action == GLFW_PRESS)
        getGame().addNewBoid();
      if (key == GLFW_KEY_KP_SUBTRACT && action == GLFW_PRESS)
        getGame().removeSomeBoid();
      if (key == GLFW_KEY_Z && action == GLFW_PRESS)
        getGame().camera_zoom += 20;
      if (key == GLFW_KEY_X && action == GLFW_PRESS)
        getGame().camera_zoom -= 20;
    }
    static Game& getGame() {
      static Game g;
      return g;
    }
    void init(int w, int h);
    void start();
  private:
    Object *central_tower;
    Game(Game const&);
    void operator=(Game const&);
    glm::vec3 flock_position;
    Game() {};
    GLFWwindow *window;
    int width, height;
    void loop();
    void end();
    void addNewBoid();
    void removeSomeBoid();
    void changeSize(int, int);
    void changeCamera();
    Boid *guide;
    Terrain *terrain;
    GLfloat camera_zoom;
    std::vector<Object *> objects, obstacles;
    std::vector<Boid *> boids;
    std::queue<Camera *> cameras;
    glm::mat4 view, projection, VP;
    Camera *c0, *c1, *c2;
};
#endif
