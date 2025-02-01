#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);

    devices = input1.listDevices();
    if (devices.size() > 0)
    {
        input1ID = 0;
    }
    input1.setDeviceID(input1ID);
    input1.setup(1280, 720);

    if (devices.size() > 1)
    {
        input1ID = 1;
        input2ID = 1;
        prevInput2ID = 1;
    }
    else
    {
        input2ID = 0;
        prevInput2ID = 0;
    }
    input2.setDeviceID(input2ID);
    input2.setup(1280, 720);
}

//--------------------------------------------------------------
void ofApp::update()
{
    input1.update();
    input2.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    input1.draw(0, 0, ofGetWidth(), ofGetHeight());
    input2.draw(ofGetWidth() - (ofGetWidth() / 5) - 20, 10, ofGetWidth() / 5, ofGetHeight() / 5);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == '1')
    {
        if (input1ID < devices.size())
        {
            input1ID++;
        }
        else
        {
            input1ID = 0;
        }
    }
    if (key == '2')
    {
        if (input2ID < devices.size())
        {
            input2ID++;
        }
        else
        {
            input2ID = 0;
        }
    }
    if (key == 'f')
    {
        ofToggleFullscreen();
    }
}
