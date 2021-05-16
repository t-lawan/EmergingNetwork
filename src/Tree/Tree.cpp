//
//  Tree.cpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 08/04/2021.
//

#include "Tree.h"



void Tree::setup(glm::vec4 _rootPosition, glm::vec3 _rootDirection, int _slowness = 50, float _geneValue = 0.5){
    geneValue = _geneValue;
    slowness = _slowness;
    rootPosition = _rootPosition;
    rootDirection = _rootDirection;
    
    setupValues();
    
    selectedMaxDist = 600;
    selectedMinDist = 3;
    selectedLength = 6;
    radius = 11.0;
    
    radiusScale = 0.98;
    
    diffuseColor = ofColor(190, 230, 230);
    diffuseColor = ofColor(57, 75, 27);
//    diffuseColor = ofColor(0, 255, 0);
    emissiveColor = ofColor(0, 52, 87);
    emissiveColor = ofColor(55, 66, 23);
    
    mat.setDiffuseColor(ofColor(diffuseColor));
    mat.setEmissiveColor(ofColor(emissiveColor));
    
    setupObject();
}

void Tree::setupValues(){
    selectedMaxDist = ofMap(geneValue, 0, 1, 600, 400); //600
    selectedMinDist = ofMap(geneValue, 0, 1, 2, 10); //3
    selectedLength = ofMap(geneValue, 0, 1, 3, 15); //6
    radius =  ofMap(geneValue, 0, 1, 9.0f, 13.0f); //11.0
    radiusScale = ofMap(geneValue, 0, 1, 0.97, 0.997); //0.98

    diffuseColor = ofColor(57, 75, 27);
    emissiveColor = ofColor(55, 66, 23);
}

void Tree::setupObject(){
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

void Tree::update(){
    mat.setDiffuseColor(ofColor(diffuseColor));
    mat.setEmissiveColor(ofColor(emissiveColor));
//    ofSetBackgroundColor(ofColor(bgColor));
    if( ofGetFrameNum() % slowness==0 && obj.getLeaves().size() > 0){
           obj.grow();
    }
}

void Tree::draw(){
    mat.begin();
    if (showWireframe) {
        obj.drawWireframe();
    } else {
        obj.draw();
    }
    mat.end();
}

void Tree::reset(float _geneValue){
    geneValue = _geneValue;
    setupValues();
    obj.clear();
    obj.build();
}

