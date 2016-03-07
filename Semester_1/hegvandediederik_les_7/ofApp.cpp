#include "ofApp.h"

void ofApp::setup() {
    ofSetFrameRate(60);

    drawGrid = true;

    // zet de GUI op
    gui.setup(); // paneel
    gui.add(rotateSpeedX.set("X",0,0,9.0)); // slider voor X toevoegen
    gui.add(rotateSpeedY.set("Y",0,0,9.0)); // slider voor X toevoegen
    gui.add(rotateSpeedZ.set("Z",0,0,9.0)); // slider voor X toevoegen
}

void ofApp::update() {
    // neem de huidige rotatie waarden, en voeg daar de waardes uit de sliders aan toe
    rotationX += rotateSpeedX;
    rotationY += rotateSpeedY;
    rotationZ += rotateSpeedZ;
}

void ofApp::draw() {
    gui.draw();

    // verplaats het 0-punt naar 't midden van 't scherm
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    // draai het grid om de x-as
    ofRotateX(rotationX);

    ofSetColor(255,0,0);
    ofCircle(-300,0,130);

    // draai het grid om de y-as
    ofRotateY(rotationY);

    ofSetColor(0,255,0);
    ofCircle(0,0,130);

    // draai het grid om de z-as
    ofRotateZ(rotationZ);

    ofSetColor(0,0,255);
    ofCircle(300,0,130);

    // als het 'drawGrid' vlaggetje op 'true' staat, teken dan 't grid
    if (drawGrid) ofDrawGrid(200);
}

void ofApp::keyPressed(int key) {
    if (key=='g') { // als op de 'g' toets gedrukt wordt...
        // verander de boolean in de tegenovergestelde waarde: true->false, false->true
        drawGrid=!drawGrid;
    } else if (key=='r') { // toets 'r': reset de rotatie
        rotationX = 0;
        rotationY = 0;
        rotationZ = 0;
    } else if (key=' ') { // spatiebalk: zet de rotatie stil
        rotateSpeedX = 0;
        rotateSpeedY = 0;
        rotateSpeedZ = 0;
    }
}
