#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
    
		void audioIn(float * input, int bufferSize, int nChannels); 
	
		vector <float> left;
		vector <float> right;
		vector <float> volHistory;
		
		int 	bufferCounter;
		int 	drawCounter;
		
		float smoothedVol;
		float scaledVol;
		
		ofSoundStream soundStream;
    
 
        ofSoundPlayer low;
        ofSoundPlayer mid;
        ofSoundPlayer hi;
        ofVideoPlayer bart;

    
};
