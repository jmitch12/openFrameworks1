//
//  Ball.h
//  homework
//
//  Created by Jane Mitchell on 11/10/15.
//
//

#pragma once

#ifndef Ball_h
#define Ball_h

#include "ofMain.h"

class Ball : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    int xPos;
    int xVel;
    

};

#endif /* Ball_h */
