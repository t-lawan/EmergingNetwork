//
//  Network.hpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 14/04/2021.
//

#ifndef Network_h
#define Network_h

#include <stdio.h>
#include "ofMain.h"
#include "ofxLSystem.h"

class Network {
    public:
        ofxLSystem tree;
        ofMaterial treeMaterial;
        map<string, float> constants;
        void setup();
        void update();
        void draw();
    
};

#endif /* Network_hpp */
