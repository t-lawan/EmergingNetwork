#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofxTCPSettings settings("127.0.0.1", 11324);
    server.setVerbose(true);
    server.setup(settings);
    simulation.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    simulation.update();
    checkForMessages();

}

void ofApp::checkForMessages(){
//    cout << "checkForMessages" << endl;
    for(int i = 0; i < server.getLastID(); i++) // getLastID is UID of all clients
    {

            if( server.isClientConnected(i) ) { // check and see if it's still around
              // maybe the client is sending something
              string str = server.receive(i);
//              server.send(i, "You sent: "+str);
                cout << str << endl;
            }
    }
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
