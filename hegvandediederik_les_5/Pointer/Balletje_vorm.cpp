//
//  Balletje_vorm.cpp
//  Les_1
//
//  Created by Diederik on 07/10/15.
//
//
#include "Balletje_vorm.h"
Balletje::Balletje(){
}

void Balletje::setup(){
    
    
    
    x = ofRandom(0, ofGetWidth()); // dit geeft die nigguh een random positie om te beginnen.
    y = ofRandom(0, ofGetHeight()); // dit geeft hem een random y positie nigguh.
    
    speedY = ofRandom(-40,190);
    SpeedX = ofRandom(-40, 140);
    radius = 10;
    
    color.set(225, 30, 30);
}

void Balletje::update(){
    if (x < 0 ){
        x = 0;
        SpeedX *= -1; // bouncen als je de kant raakt nigguh.
    } else if (x > ofGetWidth()){
        x = ofGetWidth();
        SpeedX *= -1;
    }
    
    if(y < 0){
        y = 0;
        speedY *= -1;
    }else if(y > ofGetHeight()){
        
        y = ofGetHeight();
        speedY *= -1;
    }
    
    x+=SpeedX;
    y+=speedY;
    
    }
void Balletje::draw(){
    
    ofSetColor(color);
    ofCircle(x, y, radius);
}

