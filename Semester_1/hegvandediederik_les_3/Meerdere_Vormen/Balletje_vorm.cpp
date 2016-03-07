//
//  Balletje_vorm.cpp
//  Les_1
//
//  Created by Diederik on 07/10/15.
//
//
#include "Balletje_vorm.h"
#include "Bouncing_Object.h"



Balletje::Balletje(){
}

void Balletje::draw()
{    
    ofSetColor(color);
    ofCircle(x, y, radius);
}

