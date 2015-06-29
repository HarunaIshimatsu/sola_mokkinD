//
//  screen_main.cpp
//  soundPlayerExample
//
//  Created by 石松春菜 on 2014/09/01.
//
//

#include "screen_main.h"

void mainS::setup(){
    subS.setup();
    track.setup();
    for (int i=0; i<10; i++) {
        mS[i].loadImage("images/musicScale/"+ofToString(i)+".png");
    }
    for (int i=0; i<3; i++) {
        neko[i].loadImage("images/n_"+ofToString(i)+".png");
        back[i].loadImage("images/m_"+ofToString(i)+".png");
    }

//    mS[9].loadImage("images/musicScale/9.png");
    test = 6;
    eye[0].loadImage("images/eyeL.png");
    eye[1].loadImage("images/eyeR.png");
//    LeyePos[0].set(355, 128);//左端
//    LeyePos[1].set(360, 130);//ド
//    LeyePos[2].set(365, 130);//レ
//    LeyePos[3].set(370, 130);//ミ
//    LeyePos[4].set(375, 130);//ファ
//    LeyePos[5].set(380, 130);//ソ
//    LeyePos[test].set(385, 128);//ラ
//    LeyePos[test].set(390-20, 125-5);//右端
    mSnum = 10;
    for (int i=0; i<eyeNUM; i++) {
        ReyePos[i].set(LeyePos[test].x+140, LeyePos[test].y-5);
    }
    count3 = 0;
    bPos = 210.00;
    colorRect.set(0,0,0,0);
    colorRect2.set(0,0,0,0);
}
void mainS::update(){
    subS.update();
    track.update();
}
void mainS::draw(float x, float y){

    ofTranslate(x, y);
    for (int i=0; i<eyeNUM; i++) {
        ReyePos[i].set(LeyePos[test].x+140, LeyePos[test].y-5);
    }
    ofSetColor(255, 255, 255);
    track.draw(0, 0,960,512);

    ofFill();
    int bai3 = 4;
    ofSetColor(255, 255, 255);
    back[count3/bai3].draw(0, 0);
    ofSetColor(255, 0, 0);
    ofRect(0, bPos, 960, 210-bPos);//メーター
    ofSetColor(255, 0, 0,100);
    ofRect(colorRect.x, colorRect.y, colorRect.z, colorRect.w);
    if (colorRect2.x != 0) {
        ofRect(colorRect2.x, colorRect2.y, colorRect2.z, colorRect2.w);
    }
    ofSetColor(255,255,255);
    neko[count3/bai3].draw(0,0);//neko

    eye[0].draw(LeyePos[test], 10, 10);
    eye[1].draw(ReyePos[test], 10, 10);
    
    if (mSnum < 7) {
        mS[mSnum].draw(710,50);//吹き出し
    }
    
    ofTranslate(-x, -y);
    count3++;
    if (count3 >= 3*bai3) {
        count3 = 0;
    }
}

ofPoint mainS::LEYE(ofPoint ball){
    
    if (ball.x > 505 && ball.x <= 935+480) {
        return ofPoint(ball.x * 25/910+345 , 125);
    } else if (ball.x <= 505){
        return ofPoint(505 * 25/910+345 , 125);
    } else if (ball.x > 935+480){
        return ofPoint((935+480) * 25/910+345 , 125);
    }
}

musicScale mainS::music(int x, int y){
    int shoki = 505;
    int haba0 = 110;
    int haba1 = 115;

    for (int i= 0; i<8; i++) {
        if (i > 0 && (x > shoki+ haba0+haba1*(i-1)) && (x <= shoki + haba0+haba1*i)) {
            return (enum musicScale) i;
            //colorRect.set(shoki+ haba0+haba1*(i-1), 333, (shoki + haba0+haba1*i)-(shoki+ haba0+haba1*(i-1)),267);
        } else if(i==0 && (x > shoki) && (x <= shoki + haba0)){
            return (enum musicScale) 0;
        }
    }
}
