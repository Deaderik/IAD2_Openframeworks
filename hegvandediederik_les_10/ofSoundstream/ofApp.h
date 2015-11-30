#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
        void update();
        void draw();
		void audioOut(float* output, int bufferSize, int nChannels);
		ofSoundStream soundStream;
		float phase;
    
        ofxPanel gui;
        ofxFloatSlider saus;
    
};
