/**
 *  ofxIniSettings
 *  ofxIniSettings.h
 *
 *  Created by Aashish Vasudevan on 07 Sept 2022
 */

# pragma once

#include "ofMain.h"
#include <string>
#if (_MSC_VER)
#include "../libs/mini/ini.h"
#else
#include "mini/ini.h"
#endif

using namespace std;
/**
 * Define: <DEFAULT_SETTINGS_FILE>
 * The default name of the file that will be accessed.
 */
#define DEFAULT_SETTINGS_FILE ofToDataPath("settings.ini")

/**
 * Class: ofxIniSettings
 * Top level class to create an ofxIniSettings object, which will handle all the loading, saving and editing of the data that needs to be stored in the
 * ini file.
*/
class ofxIniSettings
{
public:
	// Constructor: ofxIniSettings
	ofxIniSettings();
	// Destructor: ~ofxIniSettings
	~ofxIniSettings();

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// Group: File IO
	// Saving and loading files from this addon is relatively safe without checking if the file exists.
	//
	// If <load> is called without the file existing, this will simply generate an empty <structure_> to
	// which sections and keys can be added.
	// If <save> is called without the file existing, then the operation simply creates a file at that
	// path and writes the existing <structure_> to it, regardless if it is empty or not.
	//
	/**
	 * Function: load
	 * Load an INI structure into memory to access it. If no file exists, ini structure will be empty.
	 *
	 * Parameters:
	 * file - The file path to the file. Relative to the executable directory.
	 *
	 * Returns:
	 * True if file was successfully loaded.
	 *
	 * See also:
	 * <structure_>
	 */
	bool load(string file = DEFAULT_SETTINGS_FILE);
	/**
	 * Function: save
	 * Save the INI structure <structure_> to file.
	 *
	 * Parameters:
	 * file - The file path to the .ini file. Relative to the executable directory.
	 * bPrettyPrint - Whether white spaces should be added (true) or ignored (false) in the output file. Defaults to true.
	 * bOverwrite - Whether the file should be overwritten on save, or appended. Defaults to false.
	 *
	 * Returns:
	 * True if file was successfully saved.
	 *
	 * See also:
	 * <structure_>
	 */
	bool save(string file = DEFAULT_SETTINGS_FILE, bool bPrettyPrint = true, bool bOverwrite = false);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// Group: Data getters
	// All data getters call <getString> and then convert to their various types and have the same
	// function parameters. Do note that this is not a safe	// operation and will result in empty return
	// values if the keys don't exist in the ini.
	//
	// Parameters:
	// string section - The name of the section in the ini file.
	// string key - The name of the key in the section above in the ini file.
	/**
	 * Function: getString
	 *
	 * Returns:
	 * String value at the current section and key in the ini.
	 */
	string getString(string section, string key);
	/**
	 * Function: getBool
	 *
	 * Returns:
	 * Boolean value at the current section and key in the ini.
	 */
	bool getBool(string section, string key);
	/**
	 * Function: getInt
	 *
	 * Returns:
	 * Integer value at the current section and key in the ini.
	 */
	int getInt(string section, string key);
	/**
	 * Function: getFloat
	 *
	 * Returns:
	 * Floating point value at the current section and key in the ini.
	 */
	float getFloat(string section, string key);
	/**
	 * Function: getVec2f
	 *
	 * Returns:
	 * <ofVec2f:https://openframeworks.cc/documentation/math/ofVec2f/> structure at the current section and key in the ini.
	 */
	ofVec2f getVec2f(string section, string key);
	/**
	 * Function: getVec3f
	 *
	 * Returns:
	 * <ofVec3f:https://openframeworks.cc/documentation/math/ofVec3f/> structure at the current section and key in the ini.
	 */
	ofVec3f getVec3f(string section, string key);
	/**
	 * Function: getVec4f
	 *
	 * Returns:
	 * <ofVec4f:https://openframeworks.cc/documentation/math/ofVec4f/> structure at the current section and key in the ini.
	 */
	ofVec4f getVec4f(string section, string key);
	/**
	 * Function: getColor
	 *
	 * Returns:
	 * <ofColor:https://openframeworks.cc/documentation/types/ofColor/> structure at the current section and key in the ini.
	 */
	ofColor getColor(string section, string key);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// Group: Data setters
	// All data setters call <setString> at the end after their data types have been converted to string.
	//
	// Parameters:
	// string section - The name of the section in the ini file.
	// string key - The name of the key in the section above in the ini file.
	/**
	 * Function: setString
	 *
	 * Parameters:
	 * inString - Reference to the input string.
	 */
	void setString(string section, string key, string inString);
	/**
	 * Function: setBool
	 *
	 * Parameters:
	 * inBool - Reference to the input bool.
	 */
	void setBool(string section, string key, bool inBool);
	/**
	 * Function: setInt
	 *
	 * Parameters:
	 * inInt - Reference to the input bool.
	 */
	void setInt(string section, string key, int inInt);
	/**
	 * Function: setFloat
	 *
	 * Parameters:
	 * inFloat - Reference to the input float.
	 */
	void setFloat(string section, string key, float inFloat);
	/**
	 * Function: setVec2f
	 *
	 * Parameters:
	 * inVec2f - Reference to the input ofVec2f.
	 *
	 * See also:
	 * <ofVec2f:https://openframeworks.cc/documentation/math/ofVec2f/>
	 */
	void setVec2f(string section, string key, ofVec2f inVec2f);
	/**
	 * Function: setVec3f
	 *
	 * Parameters:
	 * inVec3f - Reference to the input ofVec3f.
	 *
	 * See also:
	 * <ofVec3f:https://openframeworks.cc/documentation/math/ofVec3f/>
	 */
	void setVec3f(string section, string key, ofVec3f inVec3f);
	/**
	 * Function: setVec4f
	 *
	 * Parameters:
	 * inVec4f - Reference to the input ofVec4f.
	 *
	 * See also:
	 * <ofVec4f:https://openframeworks.cc/documentation/math/ofVec4f/>
	 */
	void setVec4f(string section, string key, ofVec4f inVec4f);
	/**
	 * Function: setColor
	 *
	 * Parameters:
	 * inColor - Reference to the input ofColor.
	 *
	 * See also:
	 * <ofColor:https://openframeworks.cc/documentation/types/ofColor/>
	 */
	void setColor(string section, string key, ofColor inColor);

	/////////////////////////////////////////////////////////////////////////////////////////////////////
	// Group: Data checks
	/**
	 * Function: exists
	 *
	 * Parameters:
	 * section - Name of the section in the ini structure.
	 *
	 * Returns:
	 * True if section exists, false if not.
	 */
	bool exists(string section);
	/**
	 * Function: exists
	 *
	 * Parameters:
	 * section - Name of the section in the ini structure.
	 * key - Name of the key in the section above.
	 *
	 * Returns:
	 * True if the key exists, returns false if either the section or the key doesn't exist.
	 */
	bool exists(string section, string key);
	
private:
	// Group: Variables
	/**
	 * Variable: structure_
	 * This ini structure will store all the values needed by the ini file.
	 */
	mINI::INIStructure structure_;
};
