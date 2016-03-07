#include "ofApp.h"

void ofApp::setup() {
    // set listener - call ofApp::setupArduino when arduino is ready for use
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

    isArduinoInitialized = false;

    // connect to the Arduino
    // use the same device name used in the Arduino IDE
    // the number is the speed of the connection (the baudrate) - you can leave it as is
    arduino.connect("/dev/cu.usbmodem1411", 57600);
}

void ofApp::update() {
    arduino.update();
}

void ofApp::draw() {
}

void ofApp::setupArduino(const int& version) {
    // remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

    // set flag: Arduino now ready for use
    isArduinoInitialized = true;

    // print firmware name and version to the console
    ofLogNotice() << "Arduino firmware found: " << arduino.getFirmwareName()
                  << " v" << arduino.getMajorFirmwareVersion() << "."  << arduino.getMinorFirmwareVersion();

    arduino.sendDigitalPinMode(13, ARD_OUTPUT);

    // set listeners for pin events
    ofAddListener(arduino.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::digitalPinChanged(const int& pinNum) {
    // get value with arduino.getDigital(pinNum)
}

void ofApp::analogPinChanged(const int& pinNum) {
    // get value with arduino.getAnalog(pinNum));
}


void ofApp::mousePressed(int x, int y, int button) {
    arduino.sendDigital(13, ARD_HIGH); // this will switch the on-board Arduino LED on
}

void ofApp::mouseReleased(int x, int y, int button) {
    arduino.sendDigital(13, ARD_LOW); // this will switch the on-board Arduino LED off
}
