#pragma once

#include "ofMain.h"

class Parameters {
 public:
  Parameters();

  ofPoint startingPoint;
  float radius = 5;
  float maxSpeed = 600;
  float lifeTime = 2.0;
  float rotate = 18;
    float force = 1000;
    float spinning = 1000;
    float friction = 0.10;
};
