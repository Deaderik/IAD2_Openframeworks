#pragma once

#include "ofMain.h"

#define MAXBALLS 10

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        float x[MAXBALLS];
        float y[MAXBALLS];
        float speedY[MAXBALLS];
        float speedX[MAXBALLS];
        int radius[MAXBALLS];
        ofColor color[MAXBALLS];
};
