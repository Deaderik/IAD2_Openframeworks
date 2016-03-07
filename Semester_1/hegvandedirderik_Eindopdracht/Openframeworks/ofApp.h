#pragma once
#include "ofMain.h"
#define MESH_SIZE 10


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void audioOut(float* output, int bufferSize, int nChannels);
		void exit();
		
		float phase;
		float afstandf;
		int de_waarde;
		int mergeInt(uint8_t hi, uint8_t lo);
		
		ofSoundStream soundStream;
		ofSerial serial;
		ofEasyCam cam;
		ofLight light; 
		ofSpherePrimitive sphere;
		vector <int> origZ; 

};
