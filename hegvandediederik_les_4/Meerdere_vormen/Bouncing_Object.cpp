//
//  Bouncing_Object.cpp
//  Les_1
//
//  Created by Diederik on 08/10/15.
//
//


#include "Bouncing_Object.h" 

Bouncing_Object::Bouncing_Object()
{
    
}

void Bouncing_Object::setup()
{
    
    
    x = ofRandom(0, ofGetWidth()); // dit geeft die nigguh een random positie om te beginnen.
    y = ofRandom(0, ofGetHeight()); // dit geeft hem een random y positie nigguh.
    
    speedY = ofRandom(-10, 10);
    speedX = ofRandom(-10, 10);
   
    radius = 20;
    
    color.set(ofRandom(50, 100), 30, 30 );

}

void Bouncing_Object::update()
{
    
    if (x < 0 ){
        x = 0;
        speedX *= -1; // bouncen als je de kant raakt nigguh.
    } else if (x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    }
    
    if(y < 0){
        y = 0;
        speedY *= -1;
    }else if(y > ofGetHeight()){
        
        y = ofGetHeight();
        speedY *= -1;
    }
    
    x+=speedX;
    y+=speedY;
}

void Bouncing_Object::draw()
{
    
    
    
}
