#include "ofApp.h"
#include "Ball.h"

Ball ball;

void ofApp::setup() {
  ball.setup();
}

void ofApp::update() {
  ball.update();
}

void ofApp::draw() {
  ball.draw();
}
