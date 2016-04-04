#include "ofApp.h"

//-----------------------------------------------------------------------------------------------------------------------------
void ofApp::setup(){	 


    // SETUP ALGEMENE SHIZ
	ofSetVerticalSync(true);
	soundStream.printDeviceList();
	int bufferSize = 256;
	
    
    // MICROFOON INPUT SETUP                                //  Zie voorbeeld OF.
    
    
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    

    
    //  HOME - RESONANCE
    
    
    
    low.load("resonance_low.wav");                          // Laden van elke track
    mid.load("resonance_mid.wav");
    hi.load("resonance_high.wav");
    
    
    low.play();                                             // Spelen van elke track, mid en hi worden var
    mid.play();
    hi.play();
   
    
    //  BART ON THE ROAD . MOV.  -------------
    
    bart.loadMovie("bart.mp4");                             // Inladen
    bart.setVolume(0);                                      // Volume uit
    bart.play();                                            // Spelen maar
}

//------------------------------------------------------------------------------------------------------------------------------
void ofApp::update(){
	
    
    hi.setVolume(0.1f * (smoothedVol) * 150);                // Volume van bart van elk kanaal
    mid.setVolume(0.1f * (smoothedVol) * 150);
   
    bart.update();                                          // Bart.mov elk frame updaten (is belangrijk diederik)
    
    
    
    // MICROFOON INPUT SETUP                                //  Zie voorbeeld OF.
    
    
    //lets scale the vol up to a 0-1 range
	scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);

	//lets record the volume into an array
	volHistory.push_back( scaledVol );
	
	//if we are bigger the the size we want to record - lets drop the oldest value
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}
}

//-----------------------------------------------------------------------------------------------------------------------------
void ofApp::draw(){
	
//    ofLog(OF_LOG_NOTICE) << "SCALED VOL =" << smoothedVol ;   // check of smoothed geluid werkt.


    bart.draw(0, 0);
    
    ofSetColor(200 * (scaledVol) * 20);
    ofFill();                                                 // teken vlak over de video heen, en laat hem faden adh van hoeveelheid input geluid :D
}

//-----------------------------------------------------------------------------------------------------------------------------
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

// Eyooo hij doet het. _______/\________\o/_______________

