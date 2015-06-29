//
//  screen_sub.cpp
//  soundPlayerExample
//
//  Created by 石松春菜 on 2014/09/01.
//
//

#include "screen_sub.h"

void subS::setup(){
    sound.setup();
    subBack.loadImage("images/mokkin.png");
    handL.loadImage("images/hand_L.png");
    handR.loadImage("images/hand_R.png");
    mentai.loadImage("images/mentai.png");
    for (int i=0; i<3; i++) {
        hand[i].loadImage("images/hand/te"+ofToString(i)+".png");
    }
    
    handPos.set(768/2-131/2, -230);//中央
    
    LR = 0;
    RR = 0;
    now = kara;
    b_animation = false;
    countA = 0;
    gyaku = 0;
    mentaiPos.set(ofGetWidth(), ofGetHeight());
    syu_y = 0;
    
}

void subS::update(){
    sound.update();
    if (b_animation && gyaku == 0) {
        countA++;
    } else if(b_animation && gyaku == 1){
        countA--;
    }
}

void subS::draw(float x, float y, int Snum){
//    move(now, speed);
    ofSetColor(255,255,255);
    ofTranslate(x,y);
    subBack.draw(0, 0, 768, 256);
    mentai.draw(mentaiPos);
//    if (Snum == 0) {
//        ofTranslate(handPos);
//        ofRotateZ(LR);
//        handL.draw(0,0, 131, 265);
//        ofRotateZ(-LR);
//        ofTranslate(-handPos);
//    } else {
//        ofTranslate(handPos);
//        ofRotateZ(RR);
//        handR.draw(0,0, 131, 265);
//        ofRotateZ(-RR);
//        ofTranslate(-handPos);
//    }
    if (b_animation) {
        //now = RE;
        Countdraw(sHand(now).x, 0, countA);
        if (countA==2 && gyaku == 0) {
            gyaku = 1;
        } else if(gyaku == 1 && countA == 0){
            b_animation = false;
            countA = 0;
            gyaku = 0;
        }
    }
//    ofSetColor(0, 0, 0);
//    //ofRect(0, -500, 1000, 500);
    ofTranslate(-x,-y);
    
}

void subS::Countdraw(float x, float y, int Dnum){
    ofTranslate(x,y);
    ofSetColor(255, 255, 255);
    hand[Dnum].draw(0, 0);
    ofTranslate(-x,-y);
    if (Dnum == 2) {
        sound.play(now);
    }
}

ofPoint subS::musicPos(musicScale mScale){
    float haba0 = 70;
    float haba1 = 73;
    ofPoint shoki = ofPoint(95, 30);
    
    return ofPoint(shoki.x + haba0 + haba1/2*mScale, shoki.y);
    
}

ofPoint subS::sHand(musicScale mScale){
    int shoki = 95;
    int haba0 = 70;
    int haba1 = 73;
    for (int i=0; i<8; i++) {
        if ((mScale == (enum musicScale) i) && i > 0 && i < 8) {
            return ofPoint(shoki+haba0+haba1*(i-1), -150);
        } else if(i==0 && (mScale == (enum musicScale) i)){
            return ofPoint(shoki, -150);
        }
    }
    
//    if (mScale == DO) {
//        return ofPoint(shoki, -150);//ド
//    } else if (mScale == RE){
//        return ofPoint(shoki, -150);//レ
//    } else if (mScale == MI){
//        return ofPoint(shoki, -150);//ミ
//    } else if (mScale == FA){
//        return ofPoint(shoki, -150);//ファ
//    }else if (mScale == SO){
//        return ofPoint(shoki, -150+35);//ソ
//    } else if (mScale == LA){
//        return ofPoint(shoki, -150+100);//ラ
//    } else if (mScale==L){
//        return ofPoint(shoki, 0);//L
//    } else if (mScale == R){
//        return ofPoint(shoki, -150+100);//R
//    } else {
//        return ofPoint(shoki, -230);//何もなし
//    }
}

ofPoint subS::rHand(musicScale mScale){
    if (mScale == DO) {
        return ofPoint(35, 20);//ド
    } else if (mScale == RE){
        return ofPoint(25, 15);//レ
    } else if (mScale == MI){
        return ofPoint(15, 3);//ミ
    } else if (mScale == FA){
        return ofPoint(0, -15);//ファ
    }else if (mScale == SO){
        return ofPoint(-15, -30);//ソ
    } else if (mScale == LA){
        return ofPoint(-30, -45);//ラ
    } else if (mScale==L){
        return ofPoint(45, 35);//L
    } else if (mScale == R){
        return ofPoint(-35, -45);//R
    }else{
        return ofPoint(0, 0);//R
    }
}

void subS::move(musicScale mScale, float speed){
    
    if (handPos.x < sHand(mScale).x-speed) {
        handPos.x += speed;
    } else if (handPos.x > sHand(mScale).x+speed){
        handPos.x -= speed;
    }
    
    if (handPos.y < sHand(mScale).y-speed) {
        handPos.y += speed;
    }else if(handPos.y > sHand(mScale).y+speed){
        handPos.y -= speed;
    }
    
    if (LR < rHand(mScale).x-speed) {
        LR += speed;
    } else if (LR > rHand(mScale).x+speed){
        LR -= speed;
    }
    
    if (RR < rHand(mScale).y-speed) {
        RR += speed;
    } else if(RR > rHand(mScale).y+ speed){
        RR -= speed;
    }
}

