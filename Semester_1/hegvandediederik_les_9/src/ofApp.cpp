#include "ofApp.h"

void ofApp::setup() {

    ofSetFrameRate(60);

    ofBackground(30,30,30);

    // plaats een light in de 3d ruimte
    light.setPointLight();
    light.setPosition(200,200,200);

    image.loadImage("water.jpg");
//    ofDisableArbTex();
    ofEnableDepthTest();
}

void ofApp::update() {
}

void ofApp::draw() {

    // dit zorgt er voor dat de texture passend gescaled wordt
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    ofScale(image.getWidth(),image.getHeight());
    glMatrixMode(GL_MODELVIEW);

    // camera aan
    cam.begin();

    // light hier pas aanzetten heeft tot gevolg dat 'ie meedraait met de cam
    light.enable();
    light.draw();

    // 'bind' 't image als een texture - dit maakt de texture ook meteen 'actief'
    // (is trouwens verkort voor image.getTextureRef().bind())
    image.bind();
    // teken de sphere, gebruikmakend van de actieve texture
    ofDrawSphere(200);
    // texture weer uitzetten
    image.unbind();

    // light weer uit
    light.disable();

    // camera uit
    cam.end();

    // dit maakt de texture-schaal-instellingen van boven weer ongedaan
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}
