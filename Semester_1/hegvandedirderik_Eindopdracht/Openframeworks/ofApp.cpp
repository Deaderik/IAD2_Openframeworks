#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	serial.setup("COM4", 9600);
	ofSetColor(0);
	ofSetFrameRate(10);
	de_waarde = 0;
	soundStream.listDevices();
    soundStream.setup(this, 2, 0, 44100, 512, 4);
    phase = 0;
	afstandf = 0;

	
	sphere.setResolution(MESH_SIZE);
	ofMesh& mesh = sphere.getMesh();
	for ( int index = 0; index < mesh.getNumVertices(); index++){
		ofPoint vertex = mesh.getVertex(index);
		origZ.push_back(vertex.z); 

}
	light.setPointLight();
	light.setPosition(400,400,400); 
	light.enable(); 
	ofColor color = ofColor(ofRandom(225),ofRandom(225),ofRandom(225)); 
	mesh.addColor(color);

	ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){
	sphere.setRadius(10*de_waarde); 
	
	if (serial.available() > 0) //staat er eigenlijk wel iets in de inkomende buffer wat ik kan lezen?
	{
		if (
			//startbytes lezen "Start"
				serial.readByte() == 0x53 &&
				serial.readByte() == 0x74 &&
				serial.readByte() == 0x61 &&
				serial.readByte() == 0x72 &&
				serial.readByte() == 0x74
				)
		{
			uint8_t hi = serial.readByte();
			uint8_t lo = serial.readByte();
			de_waarde = mergeInt(hi, lo);
			afstandf = (float)de_waarde / 50;
			afstandf = ofClamp(afstandf, 0, 1);
			serial.flush(); //emmer leeggooien, buffer leegmaken zodat je alleen naar de meest recente data van de arduino kijkt.
		}
	}
	
	ofMesh& mesh = sphere.getMesh();
	ofColor color = ofColor(ofRandom(255),ofRandom(225),ofRandom(225)); 
	mesh.addColor(color); 

for (int y = 0; y<MESH_SIZE*2; y++){
        
        for (int x = 0; x<MESH_SIZE; x++){
            int index = x +MESH_SIZE*y;
            ofPoint vertex = mesh.getVertex(index);
            vertex.z = origZ[index] +
				ofNoise(x * de_waarde, y*de_waarde, ofGetElapsedTimef()* 0.5) * 100 - 25 ;
            mesh.setVertex(index, vertex);
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	ofSetColor(255, 255, 255, 100);
	ofRect(0,0,ofGetWidth(), ofGetHeight());
	ofSetColor(255, 255, 255);
	ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);

	cam.setVFlip(true); 
	cam.begin(); 
	//ofEnableDepthTest();
	sphere.drawWireframe();
	sphere.drawFaces();
	//ofDisableDepthTest();
	cam.end(); 

	ofDrawBitmapString(ofToString(de_waarde) + " cm", 50, 50);

	
}

//--------------------------------------------------------------


void ofApp::exit() {
	//geef poort vrij
	serial.close();
	soundStream.close();
}

int ofApp::mergeInt(uint8_t hi, uint8_t lo)
{
	//int 8 - uint8_t - byte - unsigned char - Zijn synoniemen en gaan allen van 0-255

	uint16_t intHigh = (uint8_t)hi << 8; //schuif de high byte 8 plekken op naar links, in een nieuwe 16-bits container

	//32 bit
	int j = (uint16_t)intHigh + (uint8_t)lo;
	return j; // eigenlijk zoiets als 10101010 00000000 + 01010101 = 10101010 01010101
}

void ofApp::audioOut(float* output, int bufferSize, int nChannels ) {
	for (int i = 0; i < bufferSize * nChannels; i += 2) {
        float sample = sin(phase);
        output[i] = sample;
        output[i+1] = sample;
		phase += 0.1 * afstandf;
    }
}