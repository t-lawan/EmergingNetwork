//
//  Tree.hpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 08/04/2021.
//

#ifndef Tree_hpp
#define Tree_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxSpaceColonization.h"

class Tree {
    public:
        int selectedMaxDist;
        int selectedMinDist;
        int selectedLength;
        int slowness;

    
        float geneValue;
    
        float radius;
        float radiusScale;
        glm::vec4 rootPosition;
        glm::vec3 rootDirection;
        bool showWireframe;
        ofColor diffuseColor;
        ofColor emissiveColor;
        ofColor lightColor;
        ofColor bgColor;
    
        ofxSpaceColonization obj;
        ofMaterial mat;
        ofLight light;
    
        void setup(glm::vec4 _rootPosition, glm::vec3 _rootDirection, int _slowness, float _geneValue);
        void setupValues();
        void setupObject();
        void update();
        void draw();
        void reset(float _geneValue);
};

#endif /* Tree_hpp */
