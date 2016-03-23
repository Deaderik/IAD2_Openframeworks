#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){	 
	
	ofSetVerticalSync(true);
	ofSetCircleResolution(4);
	ofBackground(255);
	
	// 0 output channels, 
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	
	soundStream.printDeviceList();
	
	//if you want to set a different device id 
	//soundStream.setDeviceID(0); //bear in mind the device id corresponds to all audio devices, including  input-only and output-only devices.
	
	int bufferSize = 256;
	
	
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;

	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    
    low.load("resonance_low.wav");
    mid.load("resonance_mid.wav");
    hi.load("resonance_high.wav");
    
    
    hi.play();
    mid.play();
    hi.play();
   
    bart.loadMovie("bart.mp4");
    bart.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	
    hi.setVolume(0.1f * (scaledVol) * 40); //Sets volume at 10% of maximum
    mid.setVolume(0.1f * (scaledVol) * 40); //Sets volume at 10% of maximum
    bart.update();
    
    
    box.set(400 * (2*scaledVol));

    
    //lets scale the vol up to a 0-1 range
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);

	//lets record the volume into an array
	volHistory.push_back( scaledVol );
	
	//if we are bigger the the size we want to record - lets drop the oldest value
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}
    
    spinX = (scaledVol * 10);
    

}

//--------------------------------------------------------------
void ofApp::draw(){
	
    ofLog(OF_LOG_NOTICE) << "SCALED VOL =" << scaledVol ;
    
    cam.begin();
	
    
		
	
		
//	//  draw the average volume:
//      ofPushStyle();
//		ofPushMatrix();
//		ofTranslate( 0, 0, 0);
//    ofFill();
//    ofSetColor(180 - (scaledVol*10),100 / (scaledVol * 10),60 / (scaledVol * 5));
//				ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, scaledVol * 190.0f);
		

//    //lets draw the volume history as a graph
//		ofBeginShape();
//		
//    for (unsigned int i = 0; i < volHistory.size(); i++){
//			if( i == 0 ) ofVertex(i, 400);
//
//			ofVertex(i, 500 - volHistory[i] * 700);
//			
//			if( i == volHistory.size() -1 ) ofVertex(i, ofGetWidth()/2);
//		}
//		ofEndShape(false);
//			
//		ofPopMatrix();
//      ofPopStyle();
//
//	
//    
//    drawCounter++;
//    ofBeginShape();
		
    
    

    
    box.setPosition(ofGetWidth() /2, ofGetHeight()/2, 0);
    
    box.rotate(spinX, 1.0, 0.0, 0.0);
    box.rotate(spinY, 0, 1.0, 0.0);
    
    ofSetColor(100, 20, 255);

    box.draw();
   
    cam.end();
    bart.draw(0, 0);
  
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){	
	
	float curVol = 0.0;
	
	// samples are "interleaved"
	int numCounted = 0;	

	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume	
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;

		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}
	
	//this is how we get the mean of rms :) 
	curVol /= (float)numCounted;
	
	// this is how we get the root of rms :) 
	curVol = sqrt( curVol );
	
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	
	bufferCounter++;
	
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

