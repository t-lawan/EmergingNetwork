//
//  Particle.cpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 01/05/2021.
//

#include "Particle.h"

void Particle::setup(ofVec3f position){
    panValue = ofRandom(-0.6, 0.6);
    tiltValue = ofRandom(2.5, 3.5);
//    0, 0, 0
    ofEnableDepthTest();
    baseNode.setPosition(position);
    
    ofVec3f childPos = position;
    childPos.z += 300;
//    0, 0, 300
    childNode.setParent(baseNode);
    childNode.setPosition(childPos);
//    0,50,0
    ofVec3f grandChildPos = position;
    grandChildPos.y += 100;
    grandChildNode.setParent(childNode);
    grandChildNode.setPosition(grandChildPos);
    
    diffuseColor = ofColor(57, 75, 27, 100);
    emissiveColor = ofColor(55, 66, 23, 50);
    emissiveColor.setBrightness(50);
//    emissiveColor = ofColor(255, 255);
    
    
    specularColor = ofColor(190, 220, 200, 10);
    
    material.setDiffuseColor(specularColor);
    material.setEmissiveColor(emissiveColor);
    material.setSpecularColor(specularColor);
    material.setShininess(10.0);
}

void Particle::update(){
    float noise=ofNoise(ofGetElapsedTimef());
    panValue += noise * 0.01;
    tiltValue += noise * 0.01;
    
    baseNode.pan(panValue);
    childNode.tilt(tiltValue);

    line.addVertex(grandChildNode.getGlobalPosition());
    if (line.size() > 100){
        line.getVertices().erase(
                                 line.getVertices().begin()
                                 );
    }
}

void Particle::draw(){
    material.begin();
    line.draw();
    material.end();
}

void Particle::reset(float _geneValue){
    geneValue = _geneValue;
}
