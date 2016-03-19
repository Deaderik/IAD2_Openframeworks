#pragma once

#include "ofMain.h"
#include "Parameters.h"
#include "Particle.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
 public:
  void setup();
  void update();
  void draw();
    ofFbo fbo; 
    float time;
    Parameters parameters;
    vector<Particle> particles;
    float birthRate = 300;
    
    ofxPanel gui;
    ofxIntSlider snelheid;

    
    
};
