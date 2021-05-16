//
//  Network.cpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 14/04/2021.
//

#include "Network.h"

void Network::setup(){
    diffuseColor = ofColor(57, 75, 27);
    emissiveColor = ofColor(55, 66, 23);
    treeMaterial.setDiffuseColor(diffuseColor);
    treeMaterial.setEmissiveColor(emissiveColor);
    treeMaterial.setShininess(0.8);
    pos = ofVec3f(0, 0, 400);
    if(!geneValue){
        geneValue = ofRandom(0,1);
    }

    stepLength = ofMap(geneValue, 0, 1, 57.0, 90.0);
    stepWidth= ofMap(geneValue, 0, 1,10.0, 2.0);
    stepWidth = 5.0;
    stepLength = 150.0;
    step = (int) ofMap(geneValue, 0, 1, 2, 4);
//    tree.setPosition(pos);
    map<string, float> constants;
    constants.insert(make_pair("R", 1.456));
    tree.setAxiom("F-F-F-F");
//    tree.setAxiom("F F F F");
    tree.setRules({"F->F[--F][++F]"});
    
    
//    tree.setAxiom("A(100)");
//    tree.setAxiom("B(100)");
//    tree.setRules({"A(s) -> F(s)[+A(s/R)]"});
//    tree.setRules({"A(s) -> F(s)[+A(s/R)][-A(s/R)][+A(s/R)]"});
//    tree.setRules({"B(s) -> F(s)[+B(2s/R)][-B(2s/R)]"});
    tree.setRandomYRotation(false);
//    tree.setConstants(constants);
    tree.setStep(step);
    tree.setScaleWidth(true);
    tree.setStepLength(stepLength);
    tree.setStepWidth(stepWidth);
    tree.setTheta(40);
    tree.build();
    
}

void Network::update(){
    
}

void Network::draw(){
    ofPushMatrix();
    
    treeMaterial.begin();
    ofRotateXDeg(90);
    ofTranslate(pos);
    tree.draw();
    treeMaterial.end();
    ofPopMatrix();
}

void Network::reset(float _geneValue){
    geneValue = _geneValue;
    setup();
}
