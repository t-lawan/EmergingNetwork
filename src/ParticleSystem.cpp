//
//  ParticleSystem.cpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 01/05/2021.
//

#include "ParticleSystem.h"

void ParticleSystem::setup(float _geneValue){
    numOfParticles = 8;
    
    for(int i=0; i < numOfParticles; i++){
        Particle particle;
        particles.push_back(particle);
    }
    
    
    for (int i=0; i < particles.size(); i++){
        float z = ofMap(i, 0, particles.size(), -600, 600);
        ofVec3f pos(0,0,z);
        
        particles[i].setup(pos);
    }
    

}

void ParticleSystem::update(){
    for (int i=0; i < particles.size(); i++){
        particles[i].update();
    }
}

void ParticleSystem::draw(){
    for (int i=0; i < particles.size(); i++){
        particles[i].draw();
    }
}

void ParticleSystem::reset(float _geneValue){
    for (int i=0; i < particles.size(); i++){
        particles[i].reset(_geneValue);
    }
}

