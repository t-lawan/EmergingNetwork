//
//  Simulation.cpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 22/04/2021.
//

#include "Simulation.h"
void Simulation::setup(){
    rotateCamera = true;
    
    bgColor = ofColor(190, 220, 200);
//    bgColor = ofColor(0, 0, 255);
    lightColor = ofColor(255, 255, 235);
    lightColor = ofColor::blue;
    
    light.setPosition(-600, 700, 0);
    light.setAmbientColor(ofColor(lightColor));
    
    camera.setTarget(glm::vec3(0,0,0));
    
    light.enable();
    

    rock.setup(100, geneValue);
    tree.setup(
               glm::vec4(0.0f,0.0f,0.0f,1.0),
               glm::vec3(0.0f, 1.0f, 0.0f),
               40,
               geneValue);
    fungi.setup(
                glm::vec4(0.0f,-10.0f,0.0f,1.0),
                glm::vec3(0.0f, -1.0f, 0.0f),
                40,
                geneValue);
    terrain.setup();
    network.setup();
    particles.setup(geneValue);
    textController.setup();
    
    
}


void Simulation::update(){
    light.setAmbientColor(ofColor(lightColor));
    ofSetBackgroundColor(bgColor);

    tree.update();
    fungi.update();
    rock.update();
    particles.update();
    
    terrain.update();

    if(rotateCamera){
        float size = 3000.0f;
        float speed = 0.001;
        float x = sin(ofGetFrameNum() * speed) * size;
        float z = cos(ofGetFrameNum() * speed) * size;
        camera.setPosition(x,size - 1500,z);
        camera.lookAt(glm::vec3(0,0,0));
    }
}

void Simulation::draw(){
//        ofSetBackgroundColor(ofColor(bgColor));
        ofEnableDepthTest();
        camera.begin();
        light.draw();
        tree.draw();
//        fungi.draw();
        rock.draw();
        terrain.draw();
        particles.draw();
        network.draw();
//        ofDisableDepthTest();
        camera.end();
        ofDisableDepthTest();
        textController.draw();

}


void Simulation::restart(float _geneValue, float _divinationValue){
    geneValue = _geneValue;
    tree.reset(geneValue);
    fungi.reset(geneValue);
    rock.reset(geneValue);
    network.reset(geneValue);
    particles.reset(geneValue);
    textController.showDisplay(_divinationValue);
}
