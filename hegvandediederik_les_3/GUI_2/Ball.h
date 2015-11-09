#pragma once //zelfde als ifndef

#include "ofMain.h"

class Ball {

public:

    Ball(int size, int speedx, int speedy);

    void setup();
    void update();
    void draw();

    // variables
    
    float x;
    float y;
    float speedY;
    float speedX;
    int radius;
    ofColor color;

private:

};