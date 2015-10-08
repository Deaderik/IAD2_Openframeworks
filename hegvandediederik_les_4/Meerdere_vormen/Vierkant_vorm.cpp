//
//  Rectangle_vorm.cpp
//  Les_1
//
//  Created by Diederik on 08/10/15.
//
//

#include "Bouncing_Object.h"
#include "Vierkant_vorm.h"

Vierkant::Vierkant(){
}

void Vierkant::draw()
{
    
    ofSetColor(color);
    ofSetCircleResolution(4);
    
    ofCircle(x, y, radius);
    ofSetCircleResolution(100);
}
