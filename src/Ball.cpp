//
//  Ball.cpp
//  homework
//
//  Created by Jane Mitchell on 11/10/15.
//
//

#include "Ball.h"
#include "ofApp.h"

int xPos;
int yPos;
int xVel;
int yVel;

int xPos2;
int yPos2;
int xVel2;
int yVel2;

ofSoundPlayer sound;
ofSoundPlayer sound2;

float mouseXPercent, mouseYPercent;

//--------------------------------------------------------------
void Ball::setup(){
    
    ofBackground(0,0,0);
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    
    ofSetFrameRate(60);
    
    xPos = 250;
    yPos = 250;
    xVel = 5;
    yVel = 5;
    
    xPos2 = 150;
    yPos2 = 150;
    xVel2 = 10;
    yVel2 = 10;
    
    sound.loadSound("sounds/Mario.mp3");
    sound2.loadSound("sounds/Hop.mp3");
    
    mouseXPercent = 0.5f;
    mouseYPercent = 0.5f;
}

void Ball::update(){
    if (xPos >= ofGetWidth()){
        xVel = xVel + ofRandom(-5);
        sound.play();
    }
    
    if(xPos < -1){
        xVel = xVel + ofRandom(5);
        sound.play();
    }
    
    if (yPos >= ofGetHeight()){
        yVel = yVel + ofRandom(-5);
        sound.play();
    }
    
    if(yPos < -1){
        yVel = yVel + ofRandom(5);
        sound.play();
    }
    
    if (xPos2 >= ofGetWidth()){
        xVel2 = xVel2 + ofRandom(-5);
        sound2.play();
    }
    
    if(xPos2 < -1){
        xVel2 = xVel2 + ofRandom(5);
        sound2.play();
    }
    
    if (yPos2 >= ofGetHeight()){
        yVel2 = yVel2 + ofRandom(-5);
        sound2.play();
    }
    
    if(yPos2 < -1){
        yVel2 = yVel2 + ofRandom(5);
        sound2.play();
    }
}

//--------------------------------------------------------------
void Ball::draw(){
    float hue = fmodf(ofGetElapsedTimef()*10,255);
    
    int step = 5;
    // step through horizontally
    for ( int i=0; i<ofGetWidth(); i+=step )
    {
        // step through vertically
        for ( int j=0; j<ofGetHeight(); j+=step )
        {
            // set HSB using our hue value that changes over time, saturation from the X position (i),
            // and brightness from the Y position (j). we also invert the Y value since it looks
            // nicer if the dark/black colors are along the bottom.
            ofColor c;
            // the range of each of the arguments here is 0..255 so we map i and j to that range.
            c.setHsb( hue, ofMap(i, 0,ofGetWidth(), 0,255), ofMap(j, ofGetHeight(),0, 0,255 ) );
            
            // assign the color and draw a rectangle
            ofSetColor( c );
        }
    }
    
    ofColor color = ofColor::fromHsb(hue,
                                     ofMap( mouseX, 0,ofGetWidth(), 0,255 ),
                                     ofMap( mouseY, ofGetHeight(),0, 0,255 ) );
    ofSetColor( color );
    ofFill();
    ofCircle(xPos, yPos, 30);
    
    ofNoFill();
    ofSetHexColor(0xFFFFFF);
    ofCircle(xPos, yPos, 30);
    ofFill();
    
    xPos = xPos + xVel;
    yPos = yPos + yVel;
    
    ofSetColor( color );
    ofFill();
    ofCircle(xPos2, yPos2, 30);
    
    ofNoFill();
    ofSetHexColor(0xFFFFFF);
    ofCircle(xPos2, yPos2, 30);
    ofFill();
    
    xPos2 = xPos2 + xVel2;
    yPos2 = yPos2 + yVel2;

    
}

//--------------------------------------------------------------
void Ball::keyPressed(int key){
    
}

//--------------------------------------------------------------
void Ball::keyReleased(int key){
    
}

//--------------------------------------------------------------
void Ball::mouseMoved(int x, int y ){
    mouseXPercent = float(x) / ofGetWidth();
    mouseYPercent = float(y) / ofGetHeight();
}

//--------------------------------------------------------------
void Ball::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Ball::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Ball::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Ball::windowResized(int w, int h){
    
}
