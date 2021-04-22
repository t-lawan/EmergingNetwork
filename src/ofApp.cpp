#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    simulation.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    simulation.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    simulation.draw();
}


void ofApp::restart(float _geneValue, float _divinationValue){
    simulation.restart(_geneValue, _divinationValue);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'b') {
        float val = ofRandom(1);
        restart(val, val);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}


//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
