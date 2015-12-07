#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    plaatje.loadImage("lighthouse.jpg");
    for (int y = 0; y < MESH_HEIGHT; y++){
        for (int x=0; x < MESH_WIDTH; x++){
            ofPoint vertex = ofPoint((x - MESH_WIDTH/2)*MESH_SIZE, (y - MESH_HEIGHT/2)*MESH_SIZE,0);
            mesh.addVertex(vertex);
            
            
            mesh.addTexCoord(ofPoint (x * (IMAGE_WIDTH/MESH_WIDTH), y * (IMAGE_HEIGHT/MESH_HEIGHT)));
            
                   }
    }
    for (int y = 0; y < MESH_HEIGHT-1; y++){
        for (int x = 0; x<MESH_WIDTH; x++){
            int vertext1 = x + MESH_WIDTH * y;
            int vertext2 = x +1+ MESH_WIDTH * y;
            int vertext3 = x + MESH_WIDTH * (y+1);
            int vertext4 = x + 1 + MESH_WIDTH * (y+1);

            mesh.addTriangle(vertext1, vertext2, vertext3);
            mesh.addTriangle(vertext2, vertext4, vertext3);
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    ofColor color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    mesh.addColor(color);

    
    for (int y = 0; y < MESH_WIDTH; y++){
        for(int x = 0; x < MESH_WIDTH; x++) {
            int index = x+ MESH_HEIGHT*y;
            ofPoint vertex = mesh.getVertex(index);
            vertex.z = ofNoise(x*5000, y * 0.05, ofGetElapsedTimef()* 0.05)*100;
            mesh.setVertex(index, vertex);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    

    
    cam.setVFlip(true);
//    plaatje.bind();
    cam.begin();
    //mesh.draw();
    mesh.drawWireframe();
   
//    plaatje.unbind();
    cam.end();
    
}


