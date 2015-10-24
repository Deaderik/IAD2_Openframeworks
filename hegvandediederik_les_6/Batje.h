//
//  Batje.h
//  hegvandediederik_les_6_pong_
//
//  Created by Diederik on 21/10/15.
//
//

#pragma once

#include "ofMain.h"

class Batje {
    
public:
    
    Batje();
    
    void setup();
    void update();
    void draw();
    
    // variables
    float x;
    float y;
    float speedY;
       
    ofColor color;
    
    int width;
    int height;
    
    void up() ;
    void down (); 
    
    
    private:
    
};
