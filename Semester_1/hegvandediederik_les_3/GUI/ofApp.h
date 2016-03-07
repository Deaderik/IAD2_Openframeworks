#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();

    ofxPanel gui;
    ofxIntSlider radius;
    ofxFloatSlider speedX;
    ofxFloatSlider speedY;

    float x;
    float y;

    ofColor color;

};
