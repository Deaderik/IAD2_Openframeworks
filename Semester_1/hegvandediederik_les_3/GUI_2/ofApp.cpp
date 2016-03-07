#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	gui.setup("Ballen");
	gui.add(sliderSize.setup("Size",25,1,200));
	gui.add(sliderSpeedX.setup("Horizontale Snelheid",3,1,100));
    gui.add(sliderSpeedY.setup("Verticale Snelheid",3,1,100));
    ofBackground(ofRandom(0,225), ofRandom(0,225), ofRandom(0,225));
}

//--------------------------------------------------------------
void ofApp::update() {
    for (int i=0; i<balls.size(); i++) {
        balls[i].update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    for (int i=0; i<balls.size(); i++) {
        balls[i].draw();
    }
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ')
	{
		Ball newBall(sliderSize, sliderSpeedX, sliderSpeedY);
        balls.push_back(newBall);
	}
	else if ((key == OF_KEY_BACKSPACE) && (balls.size() > 0))
	{
		balls.pop_back();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

