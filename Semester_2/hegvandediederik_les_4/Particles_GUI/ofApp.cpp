#include "ofApp.h"
#include "Particle.h"


void ofApp::setup() {
    ofSetFrameRate(60);
    ofEnableSmoothing();
    
    gui.setup("Julius");
    gui.add(snelheid.setup("snelheid", 3, 0, 6));
        
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
    fbo.begin();
    ofBackground(0);
    fbo.end();
    time = ofGetElapsedTimef();
   
    

}

void ofApp::update() {
    
    float currentTime = ofGetElapsedTimef();
    float elapsedTime = ofClamp(currentTime - time, 0, 0.1);
    time = currentTime / snelheid;
    
    int i = 0;
    while (i < particles.size()){
        if(!particles[i].isAlive){
            particles.erase(particles.begin() + i );
        }else{
            i++;
        }
    }
    
    if(particles.size() < 4000){
        
        Particle newParticle(&parameters);
        newParticle.setup();
        particles.push_back(newParticle);
    }
    for (int i=0; i<particles.size(); i++){
        particles[i].update(elapsedTime);
    }

}

void ofApp::draw() {
    ofBackground(0);
   
    fbo.begin();
    
    ofEnableAlphaBlending();
    ofSetColor(ofColor::black,2);
    
    ofDrawRectangle(0,0, ofGetWidth(), ofGetHeight());
    ofDisableAlphaBlending();
    ofFill();
    for (int i=0; i < particles.size(); i++){
        particles[i].draw();
        gui.draw();
        
    }

    
    
    fbo.end();
    ofSetColor(ofColor::white);
    fbo.draw(0,0);
    
}
