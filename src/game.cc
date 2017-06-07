#include "game.h"
#include "cone.h"
#include <cstdlib>
#include <iostream>
#include <glm/ext.hpp>
static const char WINDOW_NAME[] = "Boids";
static bool change_camera = false;
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
  //glfwSetKeyCallback(window, key_callback);
  glfwSetKeyCallback(window, key_evh);
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
  // TODO anti aliasing
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
  c0 = new Camera(glm::vec3(0, 46.25, 0), glm::vec3(0, 0, 0));
  camera_zoom = 40;
  c1 = new Camera(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
  c2 = new Camera(glm::vec3(80, 8, -80), glm::vec3(0, 0, 0));
  cameras.push(c0);
  cameras.push(c1);
  cameras.push(c2);
  // uses  the first camera as the starting view
  view = c0->getView();
  // aspect ratio set to 4.0/3.0 (since we are using 800x600 res)
  GLfloat aspect_ratio = width*1.0f/height;
  projection = glm::perspective(45.0f, aspect_ratio, 0.1f, 600.0f);
  VP = projection*view;
  guide = new Boid(VP, glm::vec3(0, 0, 0));
  flock_position = glm::vec3(0, 0, 0);
  objects.push_back(guide);
  // terrain is modeled as a plane
  Object *o = new Terrain(VP, glm::vec3(0, 0, 0));
  objects.push_back(o);

  o = new Cone(VP, glm::vec3(0, 0, 0), glm::vec3(15.0f, 15.0f, 15.0f));
  central_tower = o;
  obstacles.push_back(o);

  int number_of_cones = 100;
  int max = 1000;
  srand(time(NULL));
  for (int i = 0; i < number_of_cones; ++i) {
    int pos_x = rand()%max,
        pos_z = rand()%max;
    pos_x *= (rand()%2) ? 1 : -1;
    pos_z *= (rand()%2) ? 1 : -1;
    int width_s = 4 + rand()%4,
        height_s = 5 + rand()%6;
    o = new Cone(VP, glm::vec3(pos_x, 0, pos_z),
        glm::vec3(width_s, height_s, width_s));
    obstacles.push_back(o);
  }
  loop();
}
///
///
///
void Game::addNewBoid() {
  glm::vec3 g = guide->getVel();
  //const int MULT = 40;
  //g = guide->getPos() - glm::vec3(MULT*g.x, MULT*g.y, MULT*g.z);
  //g += glm::vec3(0.0f, 10.0f, 0.0f);
  //std::cout << "Adding new boid at " << glm::to_string(g) << "\n";
  Boid *b = new Boid(VP, glm::vec3(100.0f, 0.0f, 100.0f));
  objects.push_back(b);
  boids.push_back(b);
}
void Game::removeSomeBoid() {
  Boid *b = boids.back();
  boids.pop_back();
  objects.pop_back();
  delete b;
}
/// game loop
/// 
/// 
void Game::loop() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glfwSetCursorPos(window, width/2, height/2);
  bool moving = !false;
  while (!glfwWindowShouldClose(window)) {
    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    flock_position = guide->getPos();
    for (int i = 0, ii = boids.size(); i < ii; ++i)
      flock_position += boids[i]->getPos();
    flock_position = (1.0f/(boids.size() + 1))*flock_position;

    for (int i = 0, ii = objects.size(); i < ii; ++i)   objects[i]->draw();
    for (int j = 0, jj = obstacles.size(); j < jj; ++j) obstacles[j]->draw();

    guide->move();
    for (int i = 0, ii = boids.size(); i < ii; ++i) {
      boids[i]->setObjective(guide->getPos());
      // add repulsion between boids to make them not colide with each other
      for (int j = 0, jj = boids.size(); j < jj; ++j) {
        if (j == i) continue;
        boids[i]->addRepulsion(boids[j]->getPos());
      }
      // terrain repulsion
      // pretend that the center of the plane is below the boid
      glm::vec3 terrain_repulsion = boids[i]->getPos();
      terrain_repulsion.y = 0.0f;
      boids[i]->addRepulsion(terrain_repulsion);
      // repulsion between obstacles and boid
      for (int j = 0, jj = obstacles.size(); j < jj; ++j) {
        GLfloat h = obstacles[j]->getHeight();
        GLfloat y = boids[i]->getPos().y;
        if (y > h) continue;
        glm::vec3 obstacle_pos = obstacles[j]->getPos();
        obstacle_pos.y = boids[i]->getPos().y;
        obstacle_pos = obstacle_pos;
        GLfloat w = obstacles[j]->getWidth();
        boids[i]->addRepulsion(obstacle_pos, w*4.5*(h - 0.5f*y)/h);
        // TODO calculate angle between vel and (obstacle_pos - boid_pos)
        // if it's zero, we should tilt the boid (tilt more the close it is)
      }
      boids[i]->rotateToVel();
      boids[i]->move();

    }
    cameras.front()->lookAt(guide->getPos());
    glm::vec3 gvel = guide->getVel(),
      gpos = guide->getPos(),
      up = glm::vec3(0.0f, 1.0f, 0.0f); //TODO change this so it doesnt
                                        // zoom in when guide does a loop
    c1->setPos(gpos - camera_zoom*gvel + glm::vec3(0.0f, 10.0f, 0.0f));
    glm::vec3 vel = guide->getVel();
    glm::vec3 c3_pos = guide->getPos() -
      (1.0f*camera_zoom)*glm::cross(vel, glm::vec3(0.0f, 1.0f, 0.0f));
    c2->setPos(gpos - camera_zoom*glm::cross(vel, up));
    // recalculate VP
    view = cameras.front()->getView();
    VP = projection * view; 
    for (int i = 0, ii = objects.size(); i < ii; ++i)
      objects[i]->setVP(VP);
    for (int i = 0, ii = obstacles.size(); i < ii; ++i)
      obstacles[i]->setVP(VP);
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
  projection = glm::perspective(45.0f, aspect_ratio, 0.1f, 600.0f);
  VP = projection*view;
  for (int i = 0, ii = objects.size(); i < ii; ++i)
    objects[i]->setVP(VP);
}
