#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	vector<ofVideoDevice> devices;
	ofVideoGrabber input1, input2;
	unsigned long int input1ID, input2ID, prevInput1ID, prevInput2ID;
};
