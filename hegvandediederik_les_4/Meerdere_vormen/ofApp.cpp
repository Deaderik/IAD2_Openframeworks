#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    for (int t = 0; t < Aantal; t++ ){
        
        Balletje newBalletje;
        newBalletje.setup();
        VeelBallen.push_back(newBalletje);
    }
    
    for (int t = 0; t < Aantal; t++ ){
        
        Triangle newTriangle;
        newTriangle.setup();
        VeelTriangles.push_back(newTriangle);
        }
    
    for (int t = 0; t < Aantal; t++ ){
        
        Vierkant newVierkant;
        newVierkant.setup();
        VeelVierkant.push_back(newVierkant);
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::update() {

     for (int t = 0; t < Aantal; t++ ){
         VeelBallen[t].update();
     }

    for (int t = 0; t < Aantal; t++ ){
        VeelTriangles[t].update();
    }

    for (int t = 0; t < Aantal; t++ ){
        VeelVierkant[t].update();
    }


    

}

//--------------------------------------------------------------
void ofApp::draw() {
    for (int t = 0; t < Aantal; t++){
        VeelBallen[t].draw();
    }

    
    for (int t = 0; t < Aantal; t++ ){
        VeelTriangles[t].draw();
    }

    for (int t = 0; t < Aantal; t++ ){
        VeelVierkant[t].draw();
    }

    
    

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
