#include "game.h"
#include <cstdlib>
#include <iostream>
static const char WINDOW_NAME[] = "Boids";
static bool change_camera = false;
static void
key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
/// initialize the glfw and glew libraries
/// 
/// exits on any error during initialization
void Game::init(int width, int height) {
  this->width = width;
  this->height = height;
  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW\n";
    exit(-1);
  }
  // hint GLFW version 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  // hint OpenGL version
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  this->window = glfwCreateWindow(width, height, WINDOW_NAME, NULL, NULL);
  if (!this->window) {
    std::cerr << "Failed to open GLFW window.";
    glfwTerminate();
    exit(-1);
  }
  glfwMakeContextCurrent(this->window);
  glfwSetKeyCallback(window, key_callback);
  glfwSetWindowSizeCallback(window, ws_callback);
  //glfwSetMouseButtonCallback(window, mouse_button_callback);
  // mouse input configuration
  glfwSetInputMode(window, GLFW_CURSOR, 0);
  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cerr << "Failed to initialize GLEW\n";
    glfwTerminate();
    exit(-1);
  }
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  // anti aliasing
  //glfwWindowHint(GLFW_SAMPLES, 4);
  //glEnable(GL_MULTISAMPLE);
}
/// 
/// 
/// 
void Game::start() {
  int width, height;
  glfwGetFramebufferSize(window, &width, &height);  
  // define the viewport dimensions
  glViewport(0, 0, width, height);
  // creates 3 cameras to offer 3 different view points
  Camera *c0 = new Camera(glm::vec3(4, 3, -3), glm::vec3(0, 0, 0));
  Camera *c1 = new Camera(glm::vec3(8, 3, -3), glm::vec3(0, 0, 0));
  Camera *c2 = new Camera(glm::vec3(0, 8, -4), glm::vec3(0, 0, 0));
  cameras.push(c2);
  cameras.push(c0);
  cameras.push(c1);
  // uses  the first camera as the starting view
  view = c0->getView();
  // aspect ratio set to 4.0/3.0 (since we are using 800x600 res)
  projection = glm::perspective(45.0f, 4.0f/3.0f, 0.1f, 100.0f);
  VP = projection*view;
  Object *o = new Object(VP, glm::vec3(0, 0, 0));
  objects.push_back(o);
  loop();
}
/// game loop
/// 
/// 
void Game::loop() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glfwSetCursorPos(window, width/2, height/2);
  while (!glfwWindowShouldClose(window)) {
    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // cycles through one of the cameras
    if (change_camera) change_camera = false, changeCamera();
    // draws objects on the scene
    for (int i = 0, ii = objects.size(); i < ii; ++i)
      objects[i]->draw();
    for (int i = 0, ii = objects.size(); i < ii; ++i)
      objects[i]->move(glm::vec3(0.05f, 0, 0));
    cameras.front()->lookAt(objects[0]->getPos());
    view = cameras.front()->getView();
    VP = projection * view; 
    for (int i = 0, ii = objects.size(); i < ii; ++i)
      objects[i]->setVP(VP);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  end();
}
/// terminate the game and free memory
///
///
void Game::end() {
  for (int i = 0, ii = objects.size(); i < ii; ++i)
    delete objects[i];
  while (!cameras.empty())
    delete cameras.front(), cameras.pop();
  glfwTerminate();
}
/// cycles through the cameras in the game
///
///
void Game::changeCamera() {
  Camera *c = cameras.front();
  cameras.pop();
  cameras.push(c);
  view = cameras.front()->getView();
  VP = projection*view;
  for (int i = 0, ii = objects.size(); i < ii; ++i)
    objects[i]->setVP(VP);
}
/// adjusts window size
///
///
void Game::changeSize(int width, int height) {
  glViewport(0, 0, width, height);
  GLfloat aspect_ratio = (width*1.0f)/(height*1.0f);
  projection = glm::perspective(45.0f, aspect_ratio, 0.1f, 100.0f);
  VP = projection*view;
  for (int i = 0, ii = objects.size(); i < ii; ++i)
    objects[i]->setVP(VP);
}
static void
key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
  if (key == GLFW_KEY_C && action == GLFW_PRESS)
    change_camera = true;
}
