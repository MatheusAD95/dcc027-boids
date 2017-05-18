#ifndef _BOIDS_GAME_H_
#define _BOIDS_GAME_H_
#include "camera.h"
#include "object.h"
#include <GL/glew.h>
#include <glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <queue>
class Game {
  public:
    static void ws_callback(GLFWwindow *win, int w, int h) {
      getGame().changeSize(w, h);
    }
    static Game& getGame() {
      static Game g;
      return g;
    }
    void init(int w, int h);
    void start();
  private:
    //Game(Game const&);
    void operator=(Game const&);
    Game() {};
    GLFWwindow *window;
    int width, height;
    void loop();
    void end();
    void changeSize(int, int);
    std::vector<Object *> objects;
    std::queue<Camera *> cameras;
    void changeCamera();
    glm::mat4 view, projection, VP;
};
#endif
