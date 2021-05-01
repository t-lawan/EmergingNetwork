//
//  Particle.h
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 01/05/2021.
//

#ifndef Particle_h
#define Particle_h

#include <stdio.h>
#include "ofMain.h"

class Particle {
    public:
        ofNode baseNode;
        ofNode childNode;
        ofNode grandChildNode;
        ofPolyline line;
        ofMaterial material;
        ofColor diffuseColor;
        ofColor emissiveColor;
        ofColor specularColor;
        ofVec3f basePosition;
        float panValue;
        float tiltValue;
        float geneValue;
        void setup(ofVec3f position);
        void update();
        void draw();
        void reset(float _geneValue);
    
};
#endif /* Particle_h */
