//
//  TextController.cpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 12/04/2021.
//

#include "TextController.h"


void TextController::setup(){
    fontSize = 14;
    font.load("font.ttf", fontSize);
    text = "This is text";
    setupDivinationText();
    textColour = ofColor(57, 75, 27);
}

void TextController::setupDivinationText(){

    divinationText.push_back({
        "No one knows the beginning and the end of things",
        "ONE B"
    });
    divinationText.push_back({
        "True change occurs when a being is transformed from the inside out. Everything else is ephemeral and superfluous.",
        "Not all losses are bad. Some are even necessary for renewal and constant living."
    });
    divinationText.push_back({
        "THREE A",
        "THREE B"
    });
    divinationText.push_back({
        "FOUR A",
        "FOUR B"
    });
    divinationText.push_back({
        "FIVE A",
        "FIVE B"
    });
    divinationText.push_back({
        "SIX A",
        "SIX B"
    });
    divinationText.push_back({
        "SEVEN A",
        "SEVEN B"
    });
    divinationText.push_back({
        "EIGHT A",
        "EIGHT B"
    });
    divinationText.push_back({
        "NINE A",
        "NINE B"
    });
    divinationText.push_back({
        "TEN A",
        "TEN B"
    });
}

void TextController::update(){
    
}


void TextController::draw(){
    if(showFont){
        ofSetColor(textColour);
//        ofRectangle r = font.getStringBoundingBox(text, 0, 0);
//        font.drawString(text, ofGetWidth()/2 - (r.width/2), ofGetHeight()/2 );
        float radius = 200;
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        for(int i=0; i<words.size(); i++) {
            float t = -HALF_PI + ofMap(i, 0, (words.size()), 0, TWO_PI);
            float x = cos( t ) * radius;
            float y = sin( t ) * radius;
            float a = ofRadToDeg(atan2(y, x));
            
            ofPushMatrix();
            
            ofTranslate(x, y );
            ofRotateZDeg(a );
            font.drawString(words[i], 0, 20);
            ofPopMatrix();
        }
        ofPopMatrix();

        if(showFont && (ofGetElapsedTimef() - fontTimestamp > fontDelayTime) ){
            showFont = false;
        }
        
    }

}

void TextController::showDisplay(float num){
    int firstVal = ofMap(num, 0, 1, 0,divinationText.size()-1, true);
    int secondVal= ofRandom(0, 1);
    text = divinationText[1][secondVal];
    words = ofSplitString(text, " ");
    showFont = true;
    fontTimestamp = ofGetElapsedTimef();
}
