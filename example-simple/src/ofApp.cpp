#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	// Log all values before loading settings
	ofLogWarning("Before loading settings");
	ofLog(OF_LOG_NOTICE, "setString = " + setString);
	ofLog(OF_LOG_NOTICE) << "setBool = " << (setBool ? "true" : "false");
	ofLog(OF_LOG_NOTICE, "setInt = " + ofToString(setInt));
	ofLog(OF_LOG_NOTICE, "setFloat = " + ofToString(setFloat));
	ofLog(OF_LOG_NOTICE, "setVec2f = " + ofToString(setVec2f));
	ofLog(OF_LOG_NOTICE, "setVec3f = " + ofToString(setVec3f));
	ofLog(OF_LOG_NOTICE, "setVec4f = " + ofToString(setVec4f));

	// Load settings file if it exists. if it doesnt, create one with some default values that are different from the class default values for testing.
	ofFile settingsFile(ofToDataPath("settings.ini"));
	if(!settingsFile.exists())
	{
		settings.setString("SETTINGS", "setString", "String set");
		settings.setBool("SETTINGS", "setBool", true);
		settings.setInt("SETTINGS", "setInt", 1337);
		settings.setFloat("SETTINGS", "setFloat", 3.14f);
		settings.setVec2f("SETTINGS", "setVec2f", ofVec2f(1, 2));
		settings.setVec3f("SETTINGS", "setVec3f", ofVec3f(1, 2, 3));
		settings.setVec4f("SETTINGS", "setVec4f", ofVec4f(1, 2, 3, 4));

		// Create the settings file simply by calling save
		settings.save(ofToDataPath("settings.ini"));
	}
	
	// Load the ini settings. By default it looks for 'settings.ini' in the data path. Usage = settings.load("my_ini_file.ini");
	settings.load(ofToDataPath("settings.ini"));

	// Now we can read the settings that have been loaded. For this example, all these settings are stored under the section "SETTINGS"
	setString = settings.getString("SETTINGS", "setString");
	setBool = settings.getBool("SETTINGS", "setBool");
	setInt = settings.getInt("SETTINGS", "setInt");
	setFloat = settings.getFloat("SETTINGS", "setFloat");
	setVec2f = settings.getVec2f("SETTINGS", "setVec2f");
	setVec3f = settings.getVec3f("SETTINGS", "setVec3f");
	setVec4f = settings.getVec4f("SETTINGS", "setVec4f");

	// Log all the values after loading settings
	ofLogWarning("After loading settings");
	ofLog(OF_LOG_NOTICE, "setString = " + setString);
	ofLog(OF_LOG_NOTICE) << "setBool = " << (setBool ? "true" : "false");
	ofLog(OF_LOG_NOTICE, "setInt = " + ofToString(setInt));
	ofLog(OF_LOG_NOTICE, "setFloat = " + ofToString(setFloat));
	ofLog(OF_LOG_NOTICE, "setVec2f = " + ofToString(setVec2f));
	ofLog(OF_LOG_NOTICE, "setVec3f = " + ofToString(setVec3f));
	ofLog(OF_LOG_NOTICE, "setVec4f = " + ofToString(setVec4f));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
