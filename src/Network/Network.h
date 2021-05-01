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
        ofVec3f pos;
        float geneValue;
        ofxLSystem tree;
        ofMaterial treeMaterial;
        ofColor diffuseColor;
        ofColor emissiveColor;
        map<string, float> constants;
        int step;
        float stepLength;
        float stepWidth;
        void setup();
        void update();
        void draw();
        void reset(float _geneValue);
        int maxNumOfSteps;
        float slowness;
};

#endif /* Network_hpp */
