#include "ofApp.h"
#include "Ball.h"

void ofApp::setup() {
  ball1.setup();
  ball2.setup();
}

void ofApp::update() {
  ball1.update();
  ball2.update();

  // collision!
  if (ball1.position.distance(ball2.position) < ball1.radius * 2) {
    ball1.speed *= -1;
    ball1.speed *= ofRandom(-0.8, -1.2);

    ball2.speed *= -1;
    ball2.speed *= ofRandom(-0.8, -1.2);
  }
}

void ofApp::draw() {
  ball1.draw();
  ball2.draw();
}
