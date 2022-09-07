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

class ofxIniSettings
{
public:
    ofxIniSettings();
    ~ofxIniSettings();

    bool load(string file = "settings.ini");
    bool save(string file = "settings.ini");
    
private:
    /* data */
};
