//
//  Terrain.cpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 14/04/2021.
//

#include "Terrain.h"

void Terrain::setup(){
    //set the width and height for our mesh and initial rendering values
    width = 800;
    height = 800;
    speed = 1.0f;
    lightColor = ofColor(0, 0, 235);
    // set our rendering styles to false
    b_messyMesh = false;
    b_perlinMesh = true;
    b_drawWireFrame = false;
    // set the initial values to use for our perlinNoise
    perlinRange =10.0f;
    perlinHeight = 20.0f;
//    mainMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP_ADJACENCY);
    mainMesh.enableColors();
    mainMesh.enableIndices();
    
    terrainColour = ofColor(57, 75, 27);
    
    position = ofVec3f(0.0f, 1250.0f, 0.0f);

    light.setPosition(position);
    light.setAmbientColor(ofColor(lightColor));
    
    light.enable();
    
    // here we make the points inside our mesh
       // add one vertex to the mesh across our width and height
       // we use these x and y values to set the x and y co-ordinates of the mesh, adding a z value of zero to complete the 3d location of each vertex
    
    for (int z = 0; z < height; z+=density){
        for (int x = 0; x<width; x+=density){
            mainMesh.addVertex(ofPoint(
                                       x-width/2,
                                       0,
                                       z-height/2) - position);    // mesh index = x + y*width
            // this replicates the pixel array within the camera bitmap...
            mainMesh.addColor(terrainColour);  // placeholder for colour data, we'll get this from the camera
        }
    }
    
    // here we loop through and join the vertices together as indices to make rows of triangles to make the wireframe grid
//    for (int y = 0; y<height-density; y+=density){
//        for (int x=0; x<width-density; x+=density){
//            mainMesh.addIndex(x+y*width);                // 0
//            mainMesh.addIndex((x+1)+y*width);            // 1
//            mainMesh.addIndex(x+(y+1)*width);            // 10
//
//            mainMesh.addIndex((x+1)+y*width);            // 1
//            mainMesh.addIndex((x+1)+(y+1)*width);        // 11
//            mainMesh.addIndex(x+(y+1)*width);            // 10
//        }
//    }
}

void Terrain::update(){
    // change the z value for each vertex in our mesh
     if (b_messyMesh) {
         for (int i = 0; i < mainMesh.getNumVertices(); i++){ // find the total of all the vertices in the mesh and loop through them
             ofVec3f newPosition = mainMesh.getVertex(i); // get the current x,y,z position of this vertex
             newPosition.y = ofRandom(-1.0, 1.0); // set the z value of it to a new random number
             mainMesh.setVertex(i, newPosition); // update the position of the vertex with the new co-ordinates
             
         }
     }
     
     if (b_perlinMesh){
         // distort the z value of each point in our mesh with perlinNoise
         int i=0;
         for (int y = 0; y<height; y+=density){
             for (int x=0; x<width; x+=density){
                 ofVec3f newPosition = mainMesh.getVertex(i);
                 // use the ofMap function to map our x,y inputs to a variable outpur range so we can see different levels of complexity / density in the perlinNoise. then multiply the z distortion by our perlinHeight value to get amplitude of distortion.
                 float heightNoiseValue = ofNoise(ofMap(x + ofGetFrameNum() * speed, 0, width, 0, perlinRange),  ofMap(y, 0, height, 0, perlinRange) );
                 newPosition.y = heightNoiseValue * perlinHeight;
                 
                 mainMesh.setVertex(i, newPosition - position); // update the position of the vertex with the new
                 ofColor col = terrainColour;
                 col.setBrightness (ofMap(heightNoiseValue, 0, 1, 100, 250));
                 mainMesh.setColor(i, col);
                 i++;
             }
         }
     }
}

void Terrain::draw(){
    ofSetColor(terrainColour);
    light.draw();
//    mainMesh.drawVertices();
    mainMesh.draw(OF_MESH_POINTS);
//
}

