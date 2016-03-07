#pragma once

#include "ofMain.h"
#define MESH_WIDTH 50
#define MESH_HEIGHT 50
#define MESH_SIZE 10
#define IMAGE_WIDTH 480
#define IMAGE_HEIGHT 300


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        ofMesh mesh;
        ofEasyCam cam;
        ofImage plaatje;
		
};
