//
//  TextController.cpp
//  EmergingNetwork
//
//  Created by Thomas Lawanson on 12/04/2021.
//

#include "TextController.h"


void TextController::setup(){
    index = 0;
    fontSize = 14;
    radius = 200;
    circleAlpha = 255;
    font.load("font.ttf", fontSize);
    text = "This is text";
    setupDivinationText();
    textColour = ofColor(57, 75, 27);
}

void TextController::setupDivinationText(){

    divinationText.push_back({
        "If you dream of the sea, you will not drown. You don't have to be afraid of its depths.",
        "A sea extinghuishes a great fire because great problems are solved with great solutions."
    });
    divinationText.push_back({
        "True change occurs when a being is transformed from the inside out.",
        "Death to the King; Long live the king"
    });
    divinationText.push_back({
        "Why do you ask if you already know the answer? Revelation is within you",
        "The heart and the brain make things fair and just. If any fail, the imbalance brings defeat and failure"
    });
    divinationText.push_back({
        "The fisherman can guide you in the great mysteries.",
        "The fisherman can guide you in the great mysteries."
    });
    divinationText.push_back({
        "Good fortune may be within your reach but certain obstacles prevent it from reaching you with it's royal splendour",
        "Good fortune may be within your reach but certain obstacles prevent it from reaching you with it's royal splendour"
    });
    divinationText.push_back({
        "In spite of having four cardinal points, you'll not be able to walk in four directions at the same time.",
        "In spite of having four cardinal points, you'll not be able to walk in four directions at the same time."
    });
    divinationText.push_back({
        "Do not waste time on futile and unnecessary things. Not everythign that is presented to you is appealing or good to consume.",
        "Do not waste time on futile and unnecessary things. Not everythign that is presented to you is appealing or good to consume."
    });
    divinationText.push_back({
        "EIGHT A",
        "EIGHT B"
    });
    divinationText.push_back({
        "Do not deny what your eyes see or ignore what your ears hear",
        "Do not deny what your eyes see or ignore what your ears hear"
    });
    divinationText.push_back({
        "Fears only create false images that contradict reality",
        "Reality is there and you cannot hide it the same way you can't hide the sun with your finger"
    });
    divinationText.push_back({
        "Fears only create false images that contradict reality",
        "Reality is there and you cannot hide it the same way you can't hide the sun with your finger"
    });
    divinationText.push_back({
        "Learn to listen to the sound of silence",
        "Beyond you there is a world where fury and placidness coexist, the dualities of defeaning silences and calming noises."
    });
    divinationText.push_back({
        "There are no solitary joys or unrecognised reqards. A true celebration is the one that is shared.",
        "There are no solitary joys or unrecognised reqards. A true celebration is the one that is shared."
    });
    divinationText.push_back({
        "Open yourself, leave the confinement and you will see everything differently.",
        "Open yourself, leave the confinement and you will see everything differently."
    });
    divinationText.push_back({
        "Live well every minute of your life",
        "Nobility is a condition of the true wise"
    });
    divinationText.push_back({
        "Excessive use is abuse and abusing leads to destruction.",
        "Excessive use is abuse and abusing leads to destruction."
    });
    divinationText.push_back({
        "Take many turns to realise that everything was there close, very close",
        "Take many turns to realise that everything was there close, very close"
    });
}

void TextController::update(){
    
}

void TextController::draw(){
    if(showFont){
        ofSetColor(textColour);
//        ofRectangle r = font.getStringBoundingBox(text, 0, 0);
//        font.drawString(text, ofGetWidth()/2 - (r.width/2), ofGetHeight()/2 );
//        float radius = 200;
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
            ofSetColor(ofColor(55, 66, 23));
            font.drawString(words[i], 0, 0);
            ofPopMatrix();
        }
        ofPopMatrix();

        if(showFont && (ofGetElapsedTimef() - fontTimestamp > fontDelayTime) ){
            showFont = false;
        }
        
        moveCircle();
        

        
    }

}

void TextController::showDisplay(float num){
    int firstVal = ofMap(num, 0, 1, 0,divinationText.size()-1, true);
    int secondVal= ofRandom(0, 1);
    text = divinationText[firstVal][secondVal];
    words = ofSplitString(text, " ");
    showFont = true;
    fontDelayTime = words.size() * secondsPerWord;
    fontTimestamp = ofGetElapsedTimef();
    index = 0;
}

void TextController::moveCircle(){
            ofPushMatrix();
            ofPushStyle();
            float t = -HALF_PI + ofMap(index, 0, (words.size()), 0, TWO_PI);
    //        float t = -HALF_PI + TWO_PI;
            float extendedRadius = radius + 150.0;
            float x = cos( t ) * extendedRadius;
            float y = sin( t ) * extendedRadius;
    //        cout << x << " : " << y << endl;
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
           float a = ofRadToDeg(atan2(y, x));
            ofTranslate(x, y );
            ofRotateZDeg(a );
            ofSetColor(ofColor(55, 66, 23));
            ofDrawCircle(0, 0, 7.5);
            ofPopStyle();
            ofPopMatrix();
    
    
//    float numOfSecondsPerWord = fontDelayTime/words.size();
    float num = index  + 1;
    if(ofGetElapsedTimef() - fontTimestamp > (num * secondsPerWord)){
        index++;
    }
            
    
//            if(ofGetElapsedTimef())
}
