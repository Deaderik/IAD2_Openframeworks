#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.loadImage("lighthouse.jpg");
    sphere.setRadius(100);
//    sphere.setResolution(60);
    sphere.setResolution(MESH_SIZE);
    sphere.mapTexCoordsFromTexture(image.getTextureReference());
    ofMesh& mesh = sphere.getMesh() ;
    for (int index=0; index<mesh.getNumVertices(); index++){
        ofPoint vertex = mesh.getVertex(index);
        origZ.push_back(vertex.z);
    }
    
    light.setPointLight();
    light.setPosition(400, 400, 400);
    light.enable();
}

//--------------------------------------------------------------
void ofApp::update(){
  
        ofMesh& mesh = sphere.getMesh();
    
    ofColor color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    mesh.addColor(color);

    
    
    for (int y = 0; y<MESH_SIZE*2; y++){
        
        for (int x = 0; x<MESH_SIZE; x++){
            int index = x +MESH_SIZE*y;
            ofPoint vertex = mesh.getVertex(index);
            
            vertex.z = origZ[index] +
            ofNoise(x * 0.05, y*0.5, ofGetElapsedTimef()* 0.5) * 100 - 25 ;
            mesh.setVertex(index, vertex);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0);
    cam.setVFlip(true);
    cam.begin();
    ofEnableDepthTest();
//    image.bind();
    sphere.drawWireframe();
//    image.unbind();
    ofDisableDepthTest();
    cam.end();
    
}

