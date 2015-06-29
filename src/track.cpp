//
//  track.cpp
//  sora_mokkinD
//
//  Created by 石松春菜 on 2014/09/03.
//
//

#include "track.h"
#define camW 640
#define camH 480
using namespace ofxCv;
using namespace cv;

void track::setup() {
	cam.initGrabber(camW, camH);
    
	contourFinder.setMinAreaRadius(10);
	contourFinder.setMaxAreaRadius(150);
    ofSetFrameRate(10);
    //contourFinder.setInvert(true); // find black instead of white
	trackingColorMode = TRACK_COLOR_HSV;
    
    threshold = 10;
    
    bhind = true;
    
    maxPos.set(0,0);
    maxSize.set(0,0);
    maxNum = 0;
    
}

void track::update() {
	cam.update();
	if(cam.isFrameNew()) {
		//threshold = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
		contourFinder.setThreshold(threshold);
		contourFinder.findContours(cam);
        
        
	}
}

void track::draw(float x, float y,float w, float h) {
    ofTranslate(x+w, y);
    ofScale(-w/camW, h/camH);
	ofSetColor(255);
	cam.draw(0, 0);
	
    //	ofSetLineWidth(2);
    //	contourFinder.draw();
	
	ofNoFill();
	int n = contourFinder.size();
    maxPos.set(0,0);
    maxSize.set(0,0);
    maxNum = 0;
	for(int i = 0; i < n; i++) {
		// smallest rectangle that fits the contour
        //		ofSetColor(cyanPrint);
        //		ofPolyline minAreRect = toOf(contourFinder.getMinAreaRect(i));
        //		minAreRect.draw();
		
		// ellipse that best fits the contour
		ofSetColor(magentaPrint);
		cv::RotatedRect ellipse = contourFinder.getFitEllipse(i);
        //		ofPushMatrix();
		ofVec2f ellipseCenter = toOf(ellipse.center);
		ofVec2f ellipseSize = toOf(ellipse.size);
        ofVec2f centroid = toOf(contourFinder.getCentroid(i));   //重心
        if ((maxSize.x * maxSize.y) < (ellipseSize.x * ellipseSize.y)) {
            maxSize = ellipseSize;
            maxNum = i;
            maxPos = centroid;
        }
        
        //		ofTranslate(ellipseCenter.x, ellipseCenter.y);
        //		ofRotate(ellipse.angle);
        //		ofEllipse(0, 0, ellipseSize.x, ellipseSize.y);
        //		ofPopMatrix();
		
		// minimum area circle that encloses the contour
        //		ofSetColor(cyanPrint);
        //		float circleRadius;
        //		ofVec2f circleCenter = toOf(contourFinder.getMinEnclosingCircle(i, circleRadius));
        //		ofCircle(circleCenter, circleRadius);
		
		// convex hull of the contour
        //		ofSetColor(yellowPrint);
        //		ofPolyline convexHull = toOf(contourFinder.getConvexHull(i));
        //		convexHull.draw();
		
		// defects of the convex hull
        //		vector<cv::Vec4i> defects = contourFinder.getConvexityDefects(i);
        //		for(int j = 0; j < defects.size(); j++) {
        //			ofLine(defects[j][0], defects[j][1], defects[j][2], defects[j][3]);
        //		}
		
		// some different styles of contour centers
		//ofVec2f centroid = toOf(contourFinder.getCentroid(i));   //重心
        
        //		ofVec2f average = toOf(contourFinder.getAverage(i));
        
        //		ofVec2f center = toOf(contourFinder.getCenter(i));
        //		ofSetColor(cyanPrint);
        //		ofCircle(centroid, 1);
        //		ofSetColor(magentaPrint);
        //		ofCircle(average, 1);
        //		ofSetColor(yellowPrint);
        //		ofCircle(center, 1);
		
		// you can also get the area and perimeter using ofPolyline:
		// ofPolyline::getArea() and ofPolyline::getPerimeter()
		double area = contourFinder.getContourArea(i);
		double length = contourFinder.getArcLength(i);
		
		// balance is useful for detecting when a shape has an "arm" sticking out
		// if balance.length() is small, the shape is more symmetric: like I, O, X...
		// if balance.length() is large, the shape is less symmetric: like L, P, F...
        //		ofVec2f balance = toOf(contourFinder.getBalance(i));
        //		ofPushMatrix();
        //		ofTranslate(centroid.x, centroid.y);
        //		ofScale(5, 5);
        //		ofLine(0, 0, balance.x, balance.y);
        //		ofPopMatrix();
	}
    ofSetColor(255, 0, 0);
    ofCircle(maxPos, 10);
    //    if(bhind == true){
    //	ofSetColor(255);
    //	drawHighlightString(ofToString((int) ofGetFrameRate()) + " fps", 10, 10);
    //	drawHighlightString(ofToString((int) threshold) + " threshold", 10, 30);
    //	drawHighlightString(trackingColorMode == TRACK_COLOR_RGB ? "RGB tracking" : "hue tracking", 10, 50);
    //
    //	ofTranslate(8, 75);
    //	ofFill();
    //	ofSetColor(0);
    //	ofRect(-3, -3, 64+6, 64+6);
    //	ofSetColor(targetColor);
    //	ofRect(0, 0, 64, 64);
    //   }
    ofScale(-camW/w, camH/h);
    ofTranslate(-x-w, -y);
}

void track::mousePressed(int x, int y, int button) {
	targetColor = cam.getPixelsRef().getColor(x, y);
	contourFinder.setTargetColor(targetColor, trackingColorMode);
}

void track::keyPressed(int key) {
    
    if(key == 'w') {
		threshold += 1.0;
	}
    
    
    if(key == 's') {
		threshold -= 1.0;
	}
    
    if(key == 'd') {
		threshold += 10.0;
	}
    
    
    if(key == 'a') {
		threshold -= 10.0;
	}
    
    
    if(key == 'b') {
		bhind = !bhind;
	}
    
	if(key == 'h') {
		trackingColorMode = TRACK_COLOR_HSV;
	}
	if(key == 'r') {
		trackingColorMode = TRACK_COLOR_RGB;
	}
	contourFinder.setTargetColor(targetColor, trackingColorMode);
    
}