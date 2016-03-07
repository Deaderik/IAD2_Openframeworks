#pragma once

#include "ofMain.h"

class Ball {

public:

    Ball();

    void setup();
    void update();
    void draw();

    int radius;
    ofColor color;

    // variables
    ofPoint position;
    ofVec3f speed;

private:

};
