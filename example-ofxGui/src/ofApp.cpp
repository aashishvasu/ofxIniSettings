#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetVerticalSync(true);

	// Setup buttons
	loadBtn_.addListener(this, &ofApp::loadSettings);
	saveBtn_.addListener(this, &ofApp::saveSettings);

	// Load settings file if it exists. if it doesnt, create one with some default values.
	ofFile settingsFile(ofToDataPath("settings.ini"));
	if(settingsFile.exists())
	{
		// Load settings
		loadSettings();
	}
	else
	{
		// Save settings
		saveSettings();
	}

	// Setup gui panel
	guiPanel_.setup("panel");
	guiPanel_.disableHeader();
	guiPanel_.add(bIsChecked_);
	guiPanel_.add(floatSlider_);
	guiPanel_.add(color_);
	guiPanel_.add(loadBtn_.setup("Load Button"));
	guiPanel_.add(saveBtn_.setup("Save Button"));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	// Draw the gui panel
	guiPanel_.draw();
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

bool ofApp::loadSettings()
{
	// Load the ini settings. By default it looks for 'settings.ini' in the data path. Usage = settings.load("my_ini_file.ini");
	if(!settings.load(ofToDataPath("settings.ini")))
		return false;

	// Set all ofParameter values after loading settings
	bIsChecked_.set("Checkbox", settings.getBool("settings", "bIsChecked"));
	floatSlider_.set("Slider", settings.getFloat("settings", "floatSlider"));
	color_.set("Color picker", settings.getColor("settings", "color"));

	return true;
}

bool ofApp::saveSettings()
{
	// Save all params to ini structure, getting the values from the respective ofParameters
	settings.setBool("settings", "bIsChecked", bIsChecked_.get());
	settings.setFloat("settings", "floatSlider", floatSlider_.get());
	settings.setColor("settings", "color", color_.get());

	// Save ini structure to file. By default it looks for a 'settings.ini'.
	return settings.save(ofToDataPath("settings.ini"));
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
