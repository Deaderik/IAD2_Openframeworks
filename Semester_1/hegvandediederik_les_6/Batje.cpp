//
//  Batje.cpp
//  hegvandediederik_les_6_pong_
//
//  Created by Diederik on 21/10/15.
//
//

#include "Batje.h"
Batje::Batje(){
}

void Batje::setup(){
    
    x = 50;      // give some random positioning
    y = ofGetHeight() / 2;
    
    speedY = 10;
    
    color.set(40,60,224);
    
    width = 40;
    height = 200;
}


void Batje::update(){
  

    
}

void Batje::draw(){
   
    
    ofRect(x, y - (height/2), width, height);
    
   
}

void Batje::up(){
    if (y - speedY >= height / 2) {
        y = y - speedY;
    }
    
}


void Batje::down(){
    if (y + speedY <= ofGetHeight() - (height / 2)) {
        y = y + speedY;
    }
}
