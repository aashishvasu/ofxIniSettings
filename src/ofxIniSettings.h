/**
 *  ofxIniSettings
 *  ofxIniSettings.h
 *
 *  Created by Aashish Vasudevan on 07 Sept 2022
 */

# pragma once

#include "ofMain.h"
#include <string.h>
#if (_MSC_VER)
#include "../libs/mini/ini.h"
#else
#include "mini/ini.h"
#endif

using namespace std;
/**
 * Define: DEFAULT_SETTINGS_FILE
 * The default name of the file that will be accessed.
 */
#define DEFAULT_SETTINGS_FILE "settings.ini"

/**
 * Class: ofxIniSettings
 * Top level class to create an ofxIniSettings object, which will handle all the loading, saving and editing of the data that needs to be stored in the
 * ini file.
*/
class ofxIniSettings
{
public:
	ofxIniSettings();
	~ofxIniSettings();
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
	 * prettyPrint - Whether white spaces should be added (true) or ignored (false) in the output file.
	 *
	 * Returns:
	 * True if file was successfully saved.
	 *
	 * See also:
	 * <structure_>
	 */
	bool save(string file = DEFAULT_SETTINGS_FILE, bool prettyPrint = true);
	
private:
	/**
	 * Variable: structure_
	 * This ini structure will store all the values needed by the ini file 
	 */
	mINI::INIStructure structure_;
};
