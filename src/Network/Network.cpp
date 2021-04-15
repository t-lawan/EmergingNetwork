//
//  Network.cpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 14/04/2021.
//

#include "Network.h"

void Network::setup(){
    treeMaterial.setDiffuseColor(ofFloatColor::blueSteel);
    tree.setPosition(0, -300, 0);
    tree.setAxiom("A(100)");
    tree.setRules({"A(s) -> F(s)[+A(s/R)][-A(s/R)]"});
    tree.setRandomYRotation(true);
    tree.setConstants(constants);
    tree.setStep(4);
    tree.setScaleWidth(true);
    tree.setStepLength(90);
    tree.build();
    
}

void Network::draw(){
    treeMaterial.begin();
    tree.draw();
    treeMaterial.end();
}
