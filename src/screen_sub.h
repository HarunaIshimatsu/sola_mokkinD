//
//  screen_sub.h
//  soundPlayerExample
//
//  Created by 石松春菜 on 2014/09/01.
//
//

#ifndef __soundPlayerExample__screen_sub__
#define __soundPlayerExample__screen_sub__

#include <iostream>
#include "ofMain.h"
#include "Sound.h"

enum musicScale{
    L=0,
    DO,
    RE,
    MI,
    FA,
    SO,
    LA,
    R,
    kara
};
class subS{
public:
    void setup();
    void update();
    void draw(float x, float y, int Snum);
    void Countdraw(float x, float y, int Dnum);
    ofPoint musicPos(musicScale mScale);
    ofPoint sHand(musicScale mScale);
    ofPoint rHand(musicScale mScale);
    void move(musicScale mScale, float speed);
    
    ofImage subBack;
    ofImage handL;
    ofImage handR;
    ofImage hand[3];
    ofImage mentai;
    
    ofPoint handPos;
    ofPoint center;
    ofPoint mentaiPos;
    float syu_y;
    musicScale now;
    
    float LR, RR;
    float speed;
    
    //アニメーションにいるやつ
    bool b_animation;
    int countA;
    bool gyaku;
    
    //インスタンス化
    SoundPlayer sound;
    
#define onkai 8
};

#endif /* defined(__soundPlayerExample__screen_sub__) */
