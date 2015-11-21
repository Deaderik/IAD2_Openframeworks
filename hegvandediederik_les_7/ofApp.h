#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    // gui om de rotatie te kunnen controleren
    ofxPanel gui;
    ofParameter<float> rotateSpeedX;
    ofParameter<float> rotateSpeedY;
    ofParameter<float> rotateSpeedZ;

    // vlaggetje: wel of niet het grid tekenen
    bool drawGrid;

    // de huidige rotatie om de x, y en z assen
    float rotationX;
    float rotationY;
    float rotationZ;
};
