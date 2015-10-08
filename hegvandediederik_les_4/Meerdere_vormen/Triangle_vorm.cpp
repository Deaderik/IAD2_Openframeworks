//
//  Triangle_vorm.cpp
//  Les_1
//
//  Created by Diederik on 08/10/15.
//
//

#include "Bouncing_Object.h"
#include "Triangle_vorm.h"

Triangle::Triangle(){
}

void Triangle::draw()
{
    
    ofSetColor(color);
    ofSetCircleResolution(3);
    
    ofCircle(x, y, radius);
    ofSetCircleResolution(100);
}
