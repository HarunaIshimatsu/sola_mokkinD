//
//  screen_main.h
//  soundPlayerExample
//
//  Created by 石松春菜 on 2014/09/01.
//
//

#ifndef __soundPlayerExample__screen_main__
#define __soundPlayerExample__screen_main__

#include <iostream>
#include "ofMain.h"
#include "screen_sub.h"
#include "track.h"
class mainS{
public:
    void setup();
    void update();
    void draw(float x, float y);
    ofPoint LEYE(ofPoint ball);
    musicScale music(int x, int y);
    
    ofImage neko[3];
    ofImage eye[2];
    ofImage mS[10];
    ofImage back[3];
    
#define eyeNUM 10
    ofPoint LeyePos[eyeNUM];
    ofPoint ReyePos[eyeNUM];
    ofVec4f colorRect;
    ofVec4f colorRect2;
    
    float bPos;
    
    int test;
    int mSnum;
    
    subS subS;
    track track;
    
private:
    int count3;
};

#endif /* defined(__soundPlayerExample__screen_main__) */
