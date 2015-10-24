#include "ofApp.h"
#include "Ball.h"

Ball ball;
ofSoundPlayer lose;
ofSoundPlayer boink;
ofSoundPlayer up;
ofSoundPlayer down;



//--------------------------------------------------------------
void ofApp::setup() {
    
    myFont.loadFont("font.ttf", 32);
    score = 0;
    keyup = false;
    keydown = false;
    ball.setup();
    speler.setup();
    lose.loadSound("lose.wav");
    boink.loadSound("boink.wav");
    up.loadSound("up.wav");
    down.loadSound("down.wav");
    levend = true;
    
    
}

//--------------------------------------------------------------
void ofApp::update() {
    ofBackground(ofRandom(200, 225), ofRandom(200, 225), ofRandom(200, 225));
    
    if (levend)
    {
        ball.update();
        
        if (keyup){
            speler.up();
            up.play();
            down.stop();
        }
        else if (keydown){
            speler.down();
            down.play();
            up.stop();
        }
    }
    
    if(ball.x < 0 ){
        ball.x = 0;
        levend = false;
        lose.play();
    }
    
    if (ball.x < speler.x + (speler.width))
    {
        if (ball.y > speler.y - (speler.height/2) && ball.y < speler.y + (speler.height /  2))
            //als de y van de bal tussen de bovenkant EN EN onderkant van het batje zit
        {
            ball.speedX = - ball.speedX; //boing
            score ++;
            boink.play();
            //win
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw() {
        ball.draw();
        speler.draw();
        //myFont.drawString(std::to_string(score), ((ofGetWidth() / 2) - 30), 50);
        //struggles met c++ op mac :S kent std::to_string niet
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    if (key == OF_KEY_UP){
        keyup = true;
    }
    
    else if (key == OF_KEY_DOWN){
        keydown = true;
    }
    
    else if (key == 's' && !levend)
    {
        levend = true;
        //nieuwe bal maken
            ball.setup();
            score = 0;
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

    if (key == OF_KEY_UP){
        keyup = false;
    }
    
   else if (key == OF_KEY_DOWN){
        keydown = false;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
