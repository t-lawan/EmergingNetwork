#pragma once

#include "ofMain.h"
#include "Simulation.h"
#include "ofxNetwork.h"

class ofApp : public ofBaseApp{

	public:
        Simulation simulation;
        ofxTCPServer server;
    
		void setup();
		void update();
		void draw();
    
        void checkForMessages();
    
    
        void setupForest();
        
        void restart(float _geneValue, float _divinationValue);
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
