#pragma once

#include "ofMain.h"
#include "ofxIniSettings.h"
#include "ofxPanel.h"

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	bool loadSettings();
	bool saveSettings();
public:
	ofxIniSettings settings;

private:
	// Gui
	ofxPanel guiPanel_;

	// Interactibles
	ofParameter<float> floatSlider_ = 0;	
	ofParameter<bool> bIsChecked_ = false;
	ofParameter<ofColor> color_ = ofColor::blue;

	ofxButton loadBtn_;
	ofxButton saveBtn_;
};
