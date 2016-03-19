#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

#define GRABBER_WIDTH 320
#define GRABBER_HEIGHT 240
#define HUE_MARGIN 5

class ofApp : public ofBaseApp {
 public:
  void setup();
  void update();
  void draw();

  void mousePressed(int x, int y, int button);
  void keyPressed(int key);

  ofVideoGrabber grabber;

    
    
  ofxCvColorImage rgbImage;  // het originele beeld van de camera
  ofxCvColorImage hsvImage;  // HSV versie van het RGB plaatje

  //---------KLEUR 1 --------------/
    
    ofxCvGrayscaleImage hue;         // hue-kanaal van 't HSV plaatje
  ofxCvGrayscaleImage saturation;  // saturation-kanaal " "
  ofxCvGrayscaleImage brightness;  // brightness-kanaal " "
    
  ofxCvGrayscaleImage filtered;  // het hue-kanaal, gefilterd op de selecteerde hue

  ofxCvContourFinder contours;

    //---------KLEUR 2 --------------/
 // We voegen alles opnieuw toe, zodat er een tweede kleur kan worden getracked. Die je gaat zoeken met left mouse click bijvoorbeeld.
    
    ofxCvGrayscaleImage hue2;         // hue-kanaal van 't HSV plaatje
    ofxCvGrayscaleImage saturation2;  // saturation-kanaal " "
    ofxCvGrayscaleImage brightness2;  // brightness-kanaal " "

    ofxCvGrayscaleImage filtered2;  // het hue-kanaal, gefilterd op de selecteerde hue
    
    ofxCvContourFinder contours2;
    
    
    
    
    int findHue;  // de hue die gebruikt wordt om de contouren te vinden
    
  bool showHSVComponents = true;
  bool showFiltered = true;
  bool showContours = true;
};
