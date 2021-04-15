//
//  Rock.cpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 09/04/2021.
//

#include "Rock.h"


void Rock::setup(int _slowness = 100, float _geneValue = 0.5){
    geneValue = _geneValue;
    slowness = _slowness;
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY);
    mesh.enableColors();
    mesh.enableIndices();
    
    diffuseColor = ofColor(255, 0, 238);
    diffuseColor = ofColor(57, 75, 27);
    
    emissiveColor = ofColor(157, 184, 162);
    emissiveColor = ofColor(55, 66, 23);
    numOfPoints = 0;
    connectionDistance = 200;
    
    for(int i = 0; i < maxNumOfPoints; i++) {
        offsets.push_back(ofVec3f(ofRandom(0,100000), ofRandom(0,100000), ofRandom(0,100000)));
    }
}

void Rock::makeOscilate(){
    int numVerts = mesh.getNumVertices();
    for (int i=0; i<numVerts; ++i) {
        ofVec3f vert = mesh.getVertex(i);

        float time = ofGetElapsedTimef();
        float timeScale = 5.0;
        
        float displacementScale = 0.75;
        displacementScale = 0.9;
        ofVec3f timeOffsets = offsets[i];

        vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
        vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
        vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
        mesh.setVertex(i, vert);
    }
}

void Rock::createMesh(){
    //    for(int i = 0; i < numOfPoints; i++){
    //        ofVec3f pos(ofRandom(-400,400), ofRandom(400, 800), ofRandom(-400,400));
    //        mesh.addVertex(pos);
    //        mesh.addColor(ofColor(diffuseColor, 255));
    //
    //        float connectionDistance = 80;
    //        int numVerts = mesh.getNumVertices();
    //        for (int a=0; a<numVerts; ++a) {
    //            ofVec3f verta = mesh.getVertex(a);
    //            for (int b=a+1; b<numVerts; ++b) {
    //                ofVec3f vertb = mesh.getVertex(b);
    //                float distance = verta.distance(vertb);
    //                if (distance <= connectionDistance) {
    //                    // In OF_PRIMITIVE_LINES, every pair of vertices or indices will be
    //                    // connected to form a line
    //                    mesh.addIndex(a);
    //                    mesh.addIndex(b);
    //                }
    //            }
    //        }
    //    }
}

void Rock::update(){
    mat.setDiffuseColor(ofColor(diffuseColor));
    mat.setEmissiveColor(ofColor(emissiveColor));
    if( ofGetFrameNum() % slowness==0 && mesh.getNumVertices() < maxNumOfPoints){
          // Add random vertex and color
        ofVec3f pos(ofRandom(-400,400), ofRandom(800, 1200), ofRandom(-400,400));
        mesh.addVertex(pos);
        mesh.addColor(ofColor(diffuseColor, 255));
        int numVerts = mesh.getNumVertices();
        for (int a=0; a<numVerts; ++a) {
            ofVec3f verta = mesh.getVertex(a);
            for (int b=a+1; b<numVerts; ++b) {
                ofVec3f vertb = mesh.getVertex(b);
                float distance = verta.distance(vertb);
                if (distance <= connectionDistance) {
                    // In OF_PRIMITIVE_LINES, every pair of vertices or indices will be
                    // connected to form a line
                    mesh.addIndex(a);
                    mesh.addIndex(b);
                }
            }
        }
    }
    
    makeOscilate();
    
}
void Rock::draw(){
    mat.begin();
    mesh.draw(OF_MESH_FILL);
    mat.end();
}

void Rock::reset(float _geneValue){
    geneValue = _geneValue;
    connectionDistance = ofMap(geneValue, 0, 1, 100, 300);
    mesh.clear();
}
