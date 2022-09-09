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

bool ofxIniSettings::save(string file, bool bPrettyPrint, bool bOverwrite)
{
	// Create a INIFile instance
	const mINI::INIFile filepath(file);
	
	return bOverwrite ? filepath.generate(structure_, bPrettyPrint) : filepath.write(structure_, bPrettyPrint);
}

// Getters
string ofxIniSettings::getString(const string section, const string key)
{
	return structure_.get(section).get(key);
}

bool ofxIniSettings::getBool(const string section, const string key)
{
	return ofToBool(getString(section, key));
}

int ofxIniSettings::getInt(const string section, const string key)
{
	return ofToInt(getString(section, key));
}

float ofxIniSettings::getFloat(const string section, const string key)
{
	return ofToFloat(getString(section, key));
}

// Setters
void ofxIniSettings::setString(const string section, const string key, const string inString)
{
	structure_[section][key] = inString;
}

void ofxIniSettings::setBool(const string section, const string key, const bool inBool)
{
	setString(section, key, inBool ? "true" : "false");
}

void ofxIniSettings::setInt(const string section, const string key, const int inInt)
{
	setString(section, key, ofToString(inInt));
}

void ofxIniSettings::setFloat(const string section, const string key, const float inFloat)
{
	setString(section, key, ofToString(inFloat));
}
