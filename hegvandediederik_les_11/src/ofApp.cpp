#include "ofApp.h"

void ofApp::setup(){
	ofBackground(255,255,255);
	ofSetVerticalSync(true);
    player.loadSound("yayalorde.mp3");
	video.loadMovie("video.m4v");
	video.play();
	video.setLoopState(OF_LOOP_NORMAL);
    player.play();
	rotate =0;
    grabber.setDeviceID(0);
    grabber.setDesiredFrameRate(30);
    grabber.initGrabber(400,400);
}

void ofApp::update(){
    video.update();
    grabber.update();
    rotate++;
}

void ofApp::draw(){

    ofSetColor(ofColor::white);

    video.draw(0,0);
    
	ofSetColor(ofColor::red);

    ofScale(0.7,0.7,0.7);
    ofTranslate(400,200);
    ofRotateX(rotate);
    ofRotateY(rotate);
    video.draw(0,0);
    grabber.draw(0,0);

	ofSetColor(ofColor::green);

    ofScale(0.7,0.7,0.7);
    ofTranslate(400,200);
    ofRotateX(rotate*3);
    ofRotateY(rotate);
    video.draw(0,0);
    grabber.draw(0,0);

	ofSetColor(ofColor::blue);

    ofScale(0.7,0.7,0.7);
    ofTranslate(400,200);
    ofRotateX(rotate);
    ofRotateY(rotate*3);
    video.draw(0,0);
    
    grabber.draw(0,0);
}

void ofApp::keyPressed(int key){
    switch(key){
        case '1':
            video.setSpeed(1);
            break;
        case '2':
            video.setSpeed(1.5);
            break;
        case '3':
            video.setSpeed(-2);
            break;
        case '0':
            video.firstFrame();
            break;
    }
}
