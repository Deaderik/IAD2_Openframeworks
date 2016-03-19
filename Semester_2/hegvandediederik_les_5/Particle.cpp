#include "Particle.h"
#include "Parameters.h"
#include "ofApp.h"


Particle::Particle(Parameters* parameters) {
  isAlive = false;
  param = parameters;
}

void Particle::setup() {
    
//    gui.add(kleur.setup("kleur", 1, 0, 2));

    
    position = param->startingPoint + randomPointOnCircle(param->radius);
    speed = randomPointOnCircle(param->maxSpeed);
    age = 0;
    maxAge = param->lifeTime;
    isAlive = true;
    
    
}



void Particle::update(float elapsedTime){
    if (!isAlive) return;
    speed.rotate(0, 0, param->rotate * elapsedTime);
    position += speed * elapsedTime;
    age += elapsedTime;
    if (age >= maxAge) isAlive = false;
    
}



void Particle::draw(){
    ofColor color = ofColor::blue;
    float hue = ofMap(age, 0, maxAge, 64, 127);
    color.setHue(hue);
    ofSetColor(color  );
    float size = ofMap(maxAge - age, 0, maxAge, 3, 1);
    ofDrawCircle(position, size);
    
    
    
}


// huiswerk gui toevoegen, interactief maken moet met OFPARAMETER!!!!NOIGUUUH1








ofPoint Particle::randomPointOnCircle(float maxRadius) {
  ofPoint point;
  float radius = ofRandom(0, maxRadius);
  float angle = ofRandom(0, M_TWO_PI );

  point.x = cos(angle) * radius;
  point.y = sin(angle) * radius;

  return point;
}