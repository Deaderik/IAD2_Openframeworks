#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);

    ofBackground(30,30,30);

    drawGrid = false;
    drawLight = false;

    planet01.setup("planet 1");
    planetParams.add(planet01.planetParamGroup);

    planet02.setup("planet 2");
    planetParams.add(planet02.planetParamGroup);
    
    planet03.setup("planet 3");
    planetParams.add(planet03.planetParamGroup);
    
    gui.setup(planetParams);

    // plaats een light in de 3d ruimte
    light.setPointLight();
    light.setPosition(200,200,200);
}

void ofApp::update(){
    planet01.update();
    planet02.update();
}

void ofApp::draw(){

    light.enable();
    gui.draw();
    light.disable();

    // zorg ervoor dat OF rekening houdt met de 'diepte' (z-coord) van alle objecten
    ofEnableDepthTest();

    // start de camera
    cam.begin();

    light.enable();

    // als je een camera gebruikt, hoef je geen translate te doen
    // om het 0-punt naar het midden van 't scherm te verplaatsen

    if (drawGrid) ofDrawGrid(200);
    if (drawLight) light.draw();

    // teken eerste planeet
    planet01.draw();

    // verplaats het 0-punt naar de positie van de 1e planeet...
    ofTranslate(planet01.distance,0);
    // ... en teken de tweede planeet
    planet02.draw();

    planet03.draw();
    
    light.disable();

    // eindig het camera blok
    cam.end();

    // schakel de diepte-test weer uit
    ofDisableDepthTest();
}

void ofApp::keyPressed(int key) {
    if (key=='g') {
        drawGrid = !drawGrid;
    } else if (key=='l') {
        drawLight = !drawLight;
    }
}
