#pragma once

#include "ofMain.h"

#include "screen_main.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		
    //インスタンス化
    mainS mainS;
    
    
    ofPoint ballPos;
    ofPoint subPos[2];
    int count;
    int beat;
    int mode;
    int count123;
    ofImage allPos;
		
};

