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
    map<string, float> constants;
    constants.insert(make_pair("R", 1.456));


    tree.setAxiom("A(100)");
//    tree.setAxiom("B(100)");
//    tree.setRules({"A(s) -> F(s)[+A(s/R)]"});
    tree.setRules({"A(s) -> F(s)[+A(s/R)][-A(s/R)]"});
//    tree.setRules({"B(s) -> F(s)[+B(2s/R)][-B(2s/R)]"});
    tree.setRandomYRotation(true);
    tree.setConstants(constants);
    tree.setStep(5);
    tree.setScaleWidth(true);
    tree.setStepLength(90);
    tree.setStepWidth(5.0);
    tree.setTheta(80);
    tree.build();
    
}

void Network::update(){
    
}

void Network::draw(){
    treeMaterial.begin();
    tree.draw();
    treeMaterial.end();
}
