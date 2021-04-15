#pragma once

#include "ofMain.h"
#include "Tree.h"
#include "Rock.h"
#include "Fungi.h"
#include "TextController.h"
#include "Terrain.h"
#include "Network.h"

class ofApp : public ofBaseApp{

	public:
        ofColor bgColor;
        ofColor lightColor;
        ofMaterial mat;
        ofLight light;

        ofEasyCam camera;
        bool rotateCamera = true;
    
        vector<Tree> trees;
        Tree tree;
        Fungi fungi;
        Rock rock;
        Terrain terrain;
        Network network;
        TextController textController;
    
        ofTrueTypeFont font;
        int fontSize;
        ofColor textColour;
        bool showFont;
        string text;
        float fontTimestamp = 0;
        float fontDelayTime = 5.0f;
        
        float geneValue;
    
		void setup();
		void update();
		void draw();
    
        void drawFont();
    
        void setupForest();
        
        void restart(float _geneValue, float _divinationValue);
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
