//
//  Terrain.hpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 14/04/2021.
//

#ifndef Terrain_h
#define Terrain_h
#include <stdio.h>
#include "ofMain.h"

class Terrain {
    public:
        ofMesh mainMesh;
        ofVec3f position;
        int width, height;
        bool b_messyMesh, b_perlinMesh, b_drawWireFrame;
        float perlinRange, perlinHeight;
        ofColor terrainColour;
        int density = 10;
        ofLight light;
        ofColor lightColor;
        float speed;
        void setup();
        void update();
        void draw();
};


#include <stdio.h>

#endif /* Terrain_hpp */
