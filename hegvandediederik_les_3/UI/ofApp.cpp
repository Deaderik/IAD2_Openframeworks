#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    gui.setup("Instellingen","settings.xml");
    gui.add(radius.setup("size",50,0,200));
    gui.add(speedX.setup("speedX",10,0,40));
    gui.add(speedY.setup("speedY",10,0,40));
    gui.loadFromFile("settings.xml");

    color.set(29,59,200);
   
    
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
    


    gui.draw();

}

void ofApp::exit() {
    gui.saveToFile("settings.xml");
}
