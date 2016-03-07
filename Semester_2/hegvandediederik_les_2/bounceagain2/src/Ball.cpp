#include "Ball.h"
Ball::Ball() {}

void Ball::setup() {
  position.x = ofRandomWidth();
  position.y = ofRandomHeight();

  speed.x = ofRandom(-10, 10);
  speed.y = ofRandom(-10, 10);

  radius = 100;

  color.set(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Ball::update() {
  if (position.x < 0) {
    position.x = 0;
    speed.x *= -1;
  } else if (position.x > ofGetWidth()) {
    position.x = ofGetWidth();
    speed.x *= -1;
  }

  if (position.y < 0) {
    position.y = 0;
    speed.y *= -1;
  } else if (position.y > ofGetHeight()) {
    position.y = ofGetHeight();
    speed.y *= -1;
  }

  position = position + speed;
}

void Ball::draw() {
  ofSetColor(color);
  ofDrawCircle(position.x, position.y, radius);
}
