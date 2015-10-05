#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    // kies random start coordinaten
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());

    // random snelheid
    speedX = ofRandom(-10, 10);
    speedY = ofRandom(-10, 10);

    // grootte van cirkel
    radius = 40;

    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
}

//--------------------------------------------------------------
void ofApp::update() {

    // links/ rechts tegen de rand aan? keer om!
    if(x < 0 ) {
        x = 0;
        speedX = -speedX;
    } else if(x > ofGetWidth()) {
        x = ofGetWidth();
        speedX = -speedX;
    }

    // boven/onder tegen de rand aan? keer om!
    if(y < 0 ) {
        y = 0;
        speedY = -speedY;
    } else if(y > ofGetHeight()) {
        y = ofGetHeight();
        speedY = -speedY;
    }

    // bereken nieuwe coordinaten
    x+=speedX;
    y+=speedY;
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(color);
    ofCircle(x, y, radius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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