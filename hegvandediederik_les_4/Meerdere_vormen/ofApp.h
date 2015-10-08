#pragma once

#include "ofMain.h"

#include "Balletje_vorm.h"
#include "Bouncing_Object.h"
#include "Balletje_vorm.h"
#include "Triangle_vorm.h"
#include "Vierkant_vorm.h"


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
    
    
        vector <Balletje> VeelBallen ;
        vector <Triangle> VeelTriangles;
        vector <Vierkant> VeelVierkant;
        int Aantal = 1000;
};
