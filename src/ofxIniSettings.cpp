/**
*  ofxIniSettings
 *  ofxIniSettings.cpp
 *
 *  Created by Aashish Vasudevan on 07 Sept 2022
 */

#include "ofxIniSettings.h"

ofxIniSettings::ofxIniSettings()
{
}

ofxIniSettings::~ofxIniSettings()
{
}

bool ofxIniSettings::load(string file)
{
	// Create a INIFile instance
	const mINI::INIFile filepath(file);
	
	return filepath.read(structure_);
}

bool ofxIniSettings::save(string file, bool prettyPrint)
{
	// Create a INIFile instance
	const mINI::INIFile filepath(file);
	
	return filepath.generate(structure_, prettyPrint);
}
