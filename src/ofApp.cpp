#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ball.setup();
    
//    ofSetBackgroundAuto(false);
//    ofBackground(0,0,0);
//    ofEnableAlphaBlending();
//    ofSetFrameRate(150);
}

//--------------------------------------------------------------
void ofApp::update(){
    ball.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ball.draw();
    
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
            ofRect( i, j, step-1, step-1 );
        }
    }

    
//    ofSetColor(0,0,0,20);
//    ofRect(0,0,ofGetWidth(),ofGetHeight());
//    ofSetColor(255,255,255,50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
