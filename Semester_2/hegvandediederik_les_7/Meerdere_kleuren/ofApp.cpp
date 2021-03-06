#include "ofApp.h"

void ofApp::setup() {
  ofBackground(ofColor::black);

  // start de video grabber
  grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT, true);

  // maak de verschillende formaten plaatjes aan
  rgbImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
  hsvImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
  
    hue.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
  saturation.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
  brightness.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
  filtered.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
    
    // lijst maken voor de tweede kleur
    
    hue2.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
    saturation2.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
    brightness2.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
    filtered2.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
    
    
}

void ofApp::update() {
  grabber.update();

  if (grabber.isFrameNew()) {
    // vul het RGB formaat plaatje met 't beeld van de camera
    rgbImage.setFromPixels(grabber.getPixels().getData(), GRABBER_WIDTH, GRABBER_HEIGHT);
    rgbImage.mirror(false, true); // plaatje spiegelen (handig om te onthouden)

    // maak van het originele RGB formaat plaatje een HSV formaat plaatje
    hsvImage = rgbImage;
    hsvImage.convertRgbToHsv();
    
    // splits de dir H, S, V kanalen in afzonderlijke plaatjes
    hsvImage.convertToGrayscalePlanarImages(hue, saturation, brightness);

      
      
      // -------------------- KLEUR 1 ZOEKEN! ------------------------
      

   
    // maak een zwart-wit masker op basis van de geselecteerde Hue (met marge)
    for (int i = 0; i < GRABBER_WIDTH * GRABBER_HEIGHT; i++) {
      if (ofInRange(hue.getPixels()[i], findHue - HUE_MARGIN, findHue + HUE_MARGIN)) {
        filtered.getPixels()[i] = 255;
      } else {
        filtered.getPixels()[i] = 0;
      }
    }
    filtered.flagImageChanged();

    // laat de contour finder van OpenCV los op het zwart-wit masker, en zoek naar 1 contour
    contours.findContours(filtered, 50, GRABBER_WIDTH * GRABBER_HEIGHT / 2, 1, false);
  }

    
    
    // -------------------- KLEUR 2 ZOEKEN! ------------------------
   
    for (int i = 0; i < GRABBER_WIDTH * GRABBER_HEIGHT; i++) {
        if (ofInRange(hue2.getPixels()[i], findHue - HUE_MARGIN, findHue + HUE_MARGIN)) {
            filtered2.getPixels()[i] = 255;
        } else {
            filtered2.getPixels()[i] = 0;
        }
    }
    filtered2.flagImageChanged();
    
    // laat de contour finder van OpenCV los op het zwart-wit masker, en zoek naar 1 contour
    contours2.findContours(filtered2, 50, GRABBER_WIDTH * GRABBER_HEIGHT / 2, 1, false);
}









void ofApp::draw() {
  ofSetColor(ofColor::white);

  // teken de verschillende plaatjes
  rgbImage.draw(640, 0);
  hsvImage.draw(0, 0);

    
  //-----kleur 1 aanpassen en tekenen!----------------------
    
  if (showHSVComponents) {
    hue.draw(0, 240);
    saturation.draw(320, 240);
    brightness.draw(640, 240);
  }

  if (showFiltered) {
    filtered.draw(0, 480);
    if (showContours) contours.draw(0, 480);
  }

  // teken de contouren bovenop het originele RGB plaatje
  if (showContours) {
    contours.draw(640, 0);
  }

  // teken een cirkel op het 'middelpunt' van de gevonden contour
  ofSetColor(ofColor::blue, 100);
  ofFill();
  for (int i = 0; i < contours.nBlobs; i++) {
    ofDrawCircle(contours.blobs[i].centroid.x + 640, contours.blobs[i].centroid.y, 20);
  }
  
    //-----kleur 2 aanpassen en tekenen!----------------------
   
    if (showHSVComponents) {
        hue2.draw(0, 240);
        saturation2.draw(320, 240);
        brightness2.draw(640, 240);
    }
    
    if (showFiltered) {
        filtered2.draw(0, 480);
        if (showContours) contours2.draw(0, 480);
    }
    
    // teken de contouren bovenop het originele RGB plaatje
    if (showContours) {
        contours2.draw(640, 0);
    }
    
    // teken een cirkel op het 'middelpunt' van de gevonden contour
    ofSetColor(ofColor::red, 100);
    ofFill();
    for (int i = 0; i < contours2.nBlobs; i++) {
        ofDrawCircle(contours2.blobs[i].centroid.x + 640, contours2.blobs[i].centroid.y, 20);
    }


}

void ofApp::keyPressed(int key) {
  if (key == 'h') {
    showHSVComponents = !showHSVComponents;
  } else if (key == 'f') {
    showFiltered = !showFiltered;
  } else if (key == 'c') {
    showContours = !showContours;
  }
    
}

void ofApp::mousePressed(int x, int y, int button) {
  // in het HSV plaatje, selecteer een kleur om een contour op te zoeken
  
    ofLog() << "klik:" << button << endl;
    
    if (button == OF_MOUSE_BUTTON_LEFT) {
        ofLog() << "klikte links " << endl;
        findHue = hue.getPixels()[y * GRABBER_WIDTH + x];

        
        // hier de code voor de linker muis button
        
    } else if (button == OF_MOUSE_BUTTON_RIGHT) {
        ofLog() << "klikte rechts" << endl;
        findHue = hue2.getPixels()[y * GRABBER_WIDTH + x];

        
        // hier de code voor de rechter muis button
    
    // ik kan nergens vinden hoe ik de rechter en linker muisknop aanspreek :( 
    }
}
