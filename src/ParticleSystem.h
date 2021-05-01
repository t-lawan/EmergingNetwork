//
//  ParticleSystem.hpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 01/05/2021.
//

#ifndef ParticleSystem_h
#define ParticleSystem_h

#include <stdio.h>
#include "ofMain.h"
#include "Particle.h"

class ParticleSystem {
    public:
        int numOfParticles;
        float geneValue;
        vector<Particle> particles;
        void setup(float _geneValue);
        void update();
        void draw();
        void reset(float _geneValue);
};
#endif /* ParticleSystem_hpp */
