//
//  Rock.hpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 09/04/2021.
//

#ifndef Rock_h
#define Rock_h

#include <stdio.h>
#include "ofMain.h"

class Rock {
    public:
        ofMesh mesh;
        ofColor diffuseColor;
        ofColor emissiveColor;
        ofMaterial mat;
        vector<ofVec3f> offsets;
        int slowness = 100;
        int numOfPoints;
        int maxNumOfPoints = 100;
        float geneValue;
        float connectionDistance;
        void setup(int _slowness, float _geneValue);
        void update();
        void draw();
        void reset(float _geneValue);
        void createMesh();
    
        void makeOscilate();
};

#endif /* Rock_h */
