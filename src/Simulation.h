//
//  Simulation.hpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 22/04/2021.
//

#ifndef Simulation_h
#define Simulation_h

#include <stdio.h>
#include "ofMain.h"
#include "Tree.h"
#include "Rock.h"
#include "Fungi.h"
#include "TextController.h"
#include "Terrain.h"
#include "Network.h"
#include "ofxNetwork.h"

class Simulation {
    public:
        ofColor bgColor;
        ofColor lightColor;
        ofMaterial mat;
        ofLight light;
    
        ofEasyCam camera;
        bool rotateCamera = true;
    
    
        Tree tree;
        Fungi fungi;
        Rock rock;
        Terrain terrain;
        Network network;
        TextController textController;
    
        float geneValue;
    
        void setup();
        void update();
        void draw();
        void restart(float _geneValue, float _divinationValue);
};

#endif /* Simulation_hpp */
