#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    grabber.setup(1080, 720, true);
    
    
    haarFinderOgen.setup("haarcascade_eyes.xml");
    haarFinderMond.setup("haarcascade_mouth.xml");

    
    //image.load("eyes.png");
    

    }

//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    
    if (grabber.isFrameNew()){
        
        haarFinderOgen.findHaarObjects(grabber.getPixels(), 100, 100 ); // 100 en 100 betekent dat er niet een gezicht gaat komen wat kleiner is dan 100x100 pixels
    
        haarFinderMond.findHaarObjects(grabber.getPixels(), 100, 100 ); // 100 en 100 betekent dat er niet een gezicht gaat komen wat kleiner is dan 100x100 pixels

    }
    

    
}

//--------------------------------------------------------------
void ofApp::draw(){
   
    grabber.draw(0,0);
    
    ofNoFill();
    
    for (int i=0; i<haarFinderOgen.blobs.size(); i++){
        ofRectangle blobBoundingRect = haarFinderOgen.blobs[i].boundingRect;
        
        if (drawBox){ofDrawRectangle(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
       
    }
    
        image.draw(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
    
    }
    
    
    for (int i=0; i<haarFinderMond.blobs.size(); i++){
        ofRectangle blobBoundingRect = haarFinderMond.blobs[i].boundingRect;
        
        if (drawBox){ofDrawRectangle(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
            
        }
        
        image.draw(blobBoundingRect.x, blobBoundingRect.y, blobBoundingRect.width, blobBoundingRect.height);
        
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'b'){
        
        drawBox = !drawBox;
    }
    
}


