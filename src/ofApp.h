#pragma once

#include "ofMain.h"
#include "Tree.h"
#include "Rock.h"
#include "Fungi.h"
#include "TextController.h"
#include "Terrain.h"
#include "Network.h"
#include "Simulation.h"
#include "ofxNetwork.h"

class ofApp : public ofBaseApp{

	public:
        Simulation simulation;
    
		void setup();
		void update();
		void draw();
    
    
        void setupForest();
        
        void restart(float _geneValue, float _divinationValue);
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
