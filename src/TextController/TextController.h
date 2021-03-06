//
//  TextController.hpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 12/04/2021.
//

#ifndef TextController_h
#define TextController_h

#include <stdio.h>
#include "ofMain.h"

class TextController {
    public:
        ofTrueTypeFont font;
        int fontSize;
        ofColor textColour;
        float radius;
        float circleAlpha;
        bool showFont;
        string text;
        vector<string> words;
        float fontTimestamp = 0;
        float fontDelayTime = 40.0f;
        float secondsPerWord = 1.0f;
        int index;
        
    
        ofVec2f currentPos;
    
        vector<vector<string>> divinationText;
    
        void setup();
        void setupDivinationText();
        void update();
        void draw();
        void showDisplay(float num);
        void moveCircle();
    
};

#endif /* TextController_hpp */
