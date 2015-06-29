//
//  track.h
//  sora_mokkinD
//
//  Created by 石松春菜 on 2014/09/03.
//
//

#ifndef __sora_mokkinD__track__
#define __sora_mokkinD__track__

#include <iostream>
#include "ofMain.h"
#include "ofxCv.h"

class track {
public:
	void setup();
	void update();
	void draw(float x, float y, float w, float h);
	void mousePressed(int x, int y, int button);
	void keyPressed(int key);
    
    bool bhind;
    
	ofVideoGrabber cam;
	ofxCv::ContourFinder contourFinder;
	float threshold;
	ofxCv::TrackingColorMode trackingColorMode;
	ofColor targetColor;
    
    cv::Point2f ballpos;
    
    ofPoint maxPos;
    ofPoint maxSize;
    int maxNum;
};


#endif /* defined(__sora_mokkinD__track__) */