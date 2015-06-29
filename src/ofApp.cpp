#include "ofApp.h"
#define screenW 1280
#define screenH 720
#define frame 30
//--------------------------------------------------------------
void ofApp::setup(){
    //ofSetWindowPosition(1300, 0);
    //設定
    ofBackground(0, 0, 0);
    ofEnableAlphaBlending();
    ofSetFrameRate(frame);
    ofEnableSmoothing();
    
    allPos.loadImage("images/scale.png");
    
    mainS.setup();
    
    ballPos.x = 0;
    subPos[0].set(128,720);
    subPos[1].set(1024, 720);
    
    count = 0;
    beat = 20;
    mode = 0;
    count123 = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    mainS.update();
    count++;
    if (mode == 0) {
//        float sa = 210.000/beat;
//        cout << sa << endl;
//        if (mainS.bPos >= 0) {
//            mainS.bPos = mainS.bPos-sa;
//            cout << mainS.bPos << endl;
//        } else {
//            mainS.bPos = 0;
//        }
//        mainS.subS.now = mainS.music(mainS.track.maxPos.x*(-960.00/640.00)+(480.00+960.00),mainS.track.maxPos.y);
        mainS.LeyePos[6] = mainS.LEYE(ofPoint(mainS.track.maxPos.x*(-960.00/640.00)+(480.00+960.00),mainS.track.maxPos.y));
    }else if(mode == 1){
        
        
    }else if (mode == 2){
        float sa = 210.000/beat;
        cout << sa << endl;
        if (mainS.bPos >= 0) {
            mainS.bPos = mainS.bPos-sa;
            cout << mainS.bPos << endl;
        } else {
            mainS.bPos = 0;
        }
        mainS.subS.now = mainS.music(mainS.track.maxPos.x*(-960.00/640.00)+(480.00+960.00),mainS.track.maxPos.y);
        mainS.LeyePos[6] = mainS.LEYE(ofPoint(mainS.track.maxPos.x*(-960.00/640.00)+(480.00+960.00),mainS.track.maxPos.y));
        mainS.subS.mentaiPos = ofPoint((mainS.track.maxPos.x*(-960.00/640.00)+(480.00+960.00))/960.00*578.00-270.00,100+mainS.subS.syu_y);
            int shoki = 25;
            int haba0 = 110;
            int haba1 = 115;
        mainS.colorRect.set(mainS.track.maxPos.x*(-960.00/640.00)+(960.00-50), 210, 105,287);
 //       mainS.colorRect2.set(0, 0, 0,0);
//        mainS.colorRect2.set(shoki+ haba0+haba1*(key-49-7), 210, (shoki + haba0+haba1*(key-48-7))-(shoki+ haba0+haba1*(key-49-7)),287);

        if (mainS.subS.b_animation && mainS.subS.gyaku == 0) {
            mainS.subS.syu_y += 100;
        } else {
            mainS.subS.syu_y = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    float s_x = 1.000*screenW/1920;
    float s_y = 1.000*screenH/1080;
    cout << s_x << endl;
    ofScale(s_x, s_y);
    if (mode == 0) {
        allPos.draw(0, 0);
        ofSetColor(255, 255, 255);
        mainS.track.cam.draw(0, 0);
        //screen描画
        ofSetColor(255, 255, 255);
        mainS.subS.draw(subPos[0].x, subPos[0].y, 0);
        mainS.subS.draw(subPos[1].x, subPos[1].y, 1);
        ofSetColor(255, 255, 255);
        mainS.draw(480, 104);
        ofSetColor(255, 0, 0);
        ofCircle(mouseX, mouseY, 10);
        // ofCircle(mainS.track.maxPos.x*(960.00/640.00)+480.00,mainS.track.maxPos.y, 20);
        if (count == beat) {
            // ofCircle(ofGetWidth()/2, ofGetHeight()/2, 10);
            //mainS.subS.sound.play(0);
            count = 0;
            mainS.bPos = 210;
        }
    } else if (mode == 1){
        allPos.draw(0, 0);
        ofSetColor(255, 255, 255);
        mainS.track.cam.draw(0, 0);
        //screen描画
        ofSetColor(255, 255, 255);
        mainS.subS.draw(subPos[0].x, subPos[0].y, 0);
        mainS.subS.draw(subPos[1].x, subPos[1].y, 1);
        ofSetColor(255, 255, 255);
        mainS.draw(480, 104);
        ofSetColor(255, 0, 0);
        ofCircle(mouseX, mouseY, 10);
        ofSetColor(255, 255, 255);
        if (count123 > 0) {
            mainS.mS[10-count123].draw(710+480,50+104);
        }
        // ofCircle(mainS.track.maxPos.x*(960.00/640.00)+480.00,mainS.track.maxPos.y, 20);
        if (count == beat) {
            // ofCircle(ofGetWidth()/2, ofGetHeight()/2, 10);
            //mainS.subS.sound.play(0);
            count = 0;
            mainS.bPos = 210;
            count123++;
            if (count123 > 3) {
                mode = 2;
            }
        }
    
    } else if (mode == 2){
        allPos.draw(0, 0);
        ofSetColor(255, 255, 255);
        mainS.track.cam.draw(0, 0);
        //screen描画
        ofSetColor(255, 255, 255);
        mainS.subS.draw(subPos[0].x, subPos[0].y, 0);
        mainS.subS.draw(subPos[1].x, subPos[1].y, 1);
        ofSetColor(255, 255, 255);
        mainS.draw(480, 104);
        ofSetColor(255, 0, 0);
        ofCircle(mouseX, mouseY, 10);
        // ofCircle(mainS.track.maxPos.x*(960.00/640.00)+480.00,mainS.track.maxPos.y, 20);
        
        if (count == beat) {
            // ofCircle(ofGetWidth()/2, ofGetHeight()/2, 10);
            //mainS.subS.sound.play(0);
            count = 0;
            mainS.bPos = 210;
            mainS.subS.b_animation = true;
        }
    }
    //ofSetColor(0, 0, 0);
    //ofRect(0, 976, ofGetWidth(), 104);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofSetFullscreen(true);
            break;
            
        case 'g':
            ofSetFullscreen(false);
            break;
        case ' ':
            mode = 1;
            break;
        case 'z':
            mode = 0;
            mainS.mSnum = 10;
            mainS.subS.mentaiPos.set(ofGetWidth(), ofGetHeight());
            mainS.colorRect.set(0, 0, 0,0);
            mainS.colorRect2.set(0, 0, 0,0);
            break;
        case 'x':
            mode = 1;
            count123 = 0;
            mainS.LeyePos[mainS.test].set(390-20, 125-5);//右端
            mainS.subS.mentaiPos.set(ofGetWidth(), ofGetHeight());
            mainS.colorRect.set(0, 0, 0,0);
            mainS.colorRect2.set(0, 0, 0,0);
            break;
        case 'c':
            mode = 2;
            break;
        default:
            
            break;
    }
    if (key >= 49 && key < 56) {
        mainS.mSnum = key-49;
//        int shoki = 25;
//        int haba0 = 110;
//        int haba1 = 115;
//        mainS.colorRect.set(shoki+ haba0+haba1*(key-49), 210, (shoki + haba0+haba1*(key-48))-(shoki+ haba0+haba1*(key-49)),287);
//        mainS.colorRect2.set(0, 0, 0,0);
//        if (key == 55) {
//            mainS.colorRect2.set(shoki+ haba0+haba1*(key-49-7), 210, (shoki + haba0+haba1*(key-48-7))-(shoki+ haba0+haba1*(key-49-7)),287);
//        }
    }
    
    mainS.track.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//    mainS.LeyePos[6] = mainS.LEYE(ofPoint(x,y));
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    ballPos.x = x;
//    mainS.subS.now = mainS.music(x,y);
    mainS.track.mousePressed(x, y, button);
 //   count = 0;
//    mainS.subS.speed = (mainS.subS.handPos.y-mainS.subS.sHand(mainS.subS.now).y)/frame;
//    if (mainS.subS.speed < 0) {
//        mainS.subS.speed = mainS.subS.speed * (-1);
//    }
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
