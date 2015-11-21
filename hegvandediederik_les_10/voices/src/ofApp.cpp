#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (int i = 0; i <VOICES; i++)
    {
        voicePaused[i]=true;
        ofLogNotice() << "Loading voice" << i << endl;
        voicePlayer[i].loadSound("vox"+ofToString(i+1)+".wav");
        voicePlayer[i].setLoop(true);
        voicePlayer[i].play();
        voicePlayer[i].setVolume(1);
        voicePlayer[i].setPaused(true);
    }
    ofSoundSetVolume(0.2);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    float time = ofGetElapsedTimef();
    float x = time*0.1 + 30;
    for (int i=0; i<VOICES; i++){
        float y = i * 0.02;
        float volume = ofNoise(x,y);
        voicePlayer[i].setVolume(volume);
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(30,30,30);
    for (int i=0; i<VOICES;i++){
        if (!voicePaused[i]){
            ofSetColor(128+1*20, i*40, i*30+2);
            ofRect(100, i*30+50, voicePlayer[i].getVolume()*300, 5);
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   
    if(key =='1'){
        voicePaused[0]  = !voicePaused[0];
        voicePlayer[0].setPaused(voicePaused[0]);
    }
    
    if(key =='2'){
        voicePaused[1]  = !voicePaused[1];
        voicePlayer[1].setPaused(voicePaused[1]);
    }
    
    if(key =='3'){
        voicePaused[2]  = !voicePaused[2];
        voicePlayer[2].setPaused(voicePaused[2]);
    }
    
    if(key =='4'){
        voicePaused[3]  = !voicePaused[3];
        voicePlayer[3].setPaused(voicePaused[3]);
    }
    
    if(key =='5'){
        voicePaused[4]  = !voicePaused[4];
        voicePlayer[4].setPaused(voicePaused[4]);
    }
    
    if(key =='6'){
        voicePaused[5]  = !voicePaused[5];
        voicePlayer[5].setPaused(voicePaused[5]);
    }
}


