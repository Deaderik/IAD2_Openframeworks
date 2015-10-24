//
//  Bouncing_Object.h
//  Les_1
//
//  Created by Diederik on 08/10/15.
//
//



#pragma once
#include "ofMain.h"

class Bouncing_Object {
    
public:
    
    
    Bouncing_Object();
    void setup();
    void update();
    virtual void draw();
    
    // variabelen
    
    float x;
    float y;
    float speedY;
    float speedX;
    int radius;
    ofColor color; 
};