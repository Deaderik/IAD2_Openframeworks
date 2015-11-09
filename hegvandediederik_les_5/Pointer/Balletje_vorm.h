//
//  Balletje_vorm.h
//  Les_1
//
//  Created by Diederik on 07/10/15.
//
//

#pragma once
#include "ofMain.h"

class Balletje {
    
public:
    
    Balletje();
    
    void setup();
    void update();
    void draw();
    
    // variabelen
    
    float x;
    float y;
    float speedY;
    float SpeedX;
    int radius;
    ofColor color;
};

