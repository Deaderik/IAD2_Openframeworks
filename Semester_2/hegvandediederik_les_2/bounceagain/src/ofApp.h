#pragma once

#include "ofMain.h"
#include "Ball.h"

#define MAXBALLS 15

class ofApp : public ofBaseApp {
 public:
  void setup();
  void update();
  void draw();

  Ball ball;
};
