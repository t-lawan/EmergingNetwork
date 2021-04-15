#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    rotateCamera = false;
    geneValue = ofRandom(1);
    
    bgColor = ofColor(190, 220, 200);
    lightColor = ofColor(0, 0, 235);
    lightColor = ofColor::blue;
    textColour = ofColor(57, 75, 27);
    
    light.setPosition(-600, 700, 0);
    light.setAmbientColor(ofColor(lightColor));
    
    camera.setTarget(glm::vec3(0,0,0));
    
    light.enable();
    
    
//    fontSize = 18;
//    font.load("font.ttf", fontSize);

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
//    network.setup();
    textController.setup();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    light.setAmbientColor(ofColor(lightColor));
    ofSetBackgroundColor(bgColor);
//    for (int i = 0; i < trees.size(); i++) {
//        trees[i].update();
//    }
    tree.update();
    fungi.update();
    rock.update();
    terrain.update();

    if(rotateCamera){
        float size = 3000.0f;
        float speed = 0.001;
        float x = sin(ofGetFrameNum() * speed) * size;
        float z = cos(ofGetFrameNum() * speed) * size;
        camera.setPosition(x,size - 1500,z);
        camera.lookAt(glm::vec3(0,0,0));
    }

//    camera.rotateAroundDeg(0.1f, camera.getYAxis(), glm::vec3(100.0f,100.0f,100.0f));
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//        ofSetBackgroundColor(ofColor(bgColor));
        ofEnableDepthTest();
        camera.begin();
        light.draw();
        tree.draw();
        fungi.draw();
        rock.draw();
        terrain.draw();
//        for (int i = 0; i < trees.size(); i++) {
//            trees[i].draw();
//        }
        ofDisableDepthTest();
        camera.end();
        textController.draw();

//        drawFont();
        

}


void ofApp::drawFont(){
    if(showFont){
        ofSetColor(textColour);
        text = "This is text";
        ofRectangle r = font.getStringBoundingBox(text, 0, 0);
        font.drawString(text, ofGetWidth()/2 - (r.width/2), ofGetHeight()/2 );
        
    }

    if(showFont && (ofGetElapsedTimef() - fontTimestamp > fontDelayTime) ){
        showFont = false;
    }
}

void ofApp::restart(float _geneValue, float _divinationValue){
    geneValue = _geneValue;
    tree.reset(geneValue);
    fungi.reset(geneValue);
    rock.reset(geneValue);
    textController.showDisplay(_divinationValue);
    showFont = true;
    fontTimestamp = ofGetElapsedTimef();
}

void ofApp::setupForest(){
        int numOfTrees = 6;
        
        for(int i = 0; i < numOfTrees; i++) {
            Tree tr;
            trees.push_back(tr);
        }
    
        for (int i = 0; i < trees.size(); i++) {
            trees[i].setup(glm::vec4(
                                     ofRandom(0.0f, 2000.0f),
                                     0.0f,
                                     ofRandom(0.0f, 2000.0f),
                                     1.0),
                           glm::vec3(0.0f, 1.0f, 0.0f), 40, geneValue);
        }
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
