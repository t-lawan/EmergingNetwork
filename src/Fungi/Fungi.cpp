//
//  Fungi.cpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 11/04/2021.
//

#include "Fungi.h"

void Fungi::setup(glm::vec4 _rootPosition, glm::vec3 _rootDirection, int _slowness = 50, float _geneValue = 0.5){
    geneValue = _geneValue;
    slowness = _slowness;
    rootPosition = _rootPosition;
    rootDirection = _rootDirection;
    
    setupValues();

    mat.setDiffuseColor(ofColor(diffuseColor));
    mat.setEmissiveColor(ofColor(emissiveColor));
    
    setupObject();
}

void Fungi::setupValues(){
    selectedMaxDist = ofMap(geneValue, 0, 1, 150, 300); //300
    selectedMinDist = ofMap(geneValue, 0, 1, 10, 20); //13
    selectedLength = ofMap(geneValue, 0, 1, 25, 5); //3
    radius =  ofMap(geneValue, 0, 1, 9.0f, 21.0); //11.0
    radiusScale = ofMap(geneValue, 0, 1, 0.97, 0.997); //0.995
    
    diffuseColor = ofColor(57, 75, 27);
    emissiveColor = ofColor(55, 66, 23);
}

void Fungi::setupObject(){
    auto opt = ofxSpaceColonizationOptions({
        selectedMaxDist,                 // max_dist
        selectedMinDist,                 // min_dist
        0,                             // trunk_length
        rootPosition, // rootPosition
        rootDirection,     // rootDirection
        selectedLength,                  // branchLength
        false,                           // done growing
        true,                           // cap
        radius,                          // radius;
        8,                              // resolution;
        1,                               // textureRepeat;
        radiusScale,                     // radiusScale;
        0.0                              // padding
    });
    obj.setup(opt);
    obj.build();
}

void Fungi::update(){
    mat.setDiffuseColor(ofColor(diffuseColor));
    mat.setEmissiveColor(ofColor(emissiveColor));
    if( ofGetFrameNum() % slowness==0 && obj.getLeaves().size() > 0){
           obj.grow();
    }
}

void Fungi::draw(){
    mat.begin();
    if (showWireframe) {
        obj.drawWireframe();
    } else {
        ofPushMatrix();
        ofRotateDeg(180);
        obj.draw();
        ofPopMatrix();
    }
    mat.end();

}

void Fungi::reset(float _geneValue){
    geneValue = _geneValue;
    obj.clear();
    obj.build();
}

