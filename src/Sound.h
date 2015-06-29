//
//  Sound.h
//  soundPlayerExample
//
//  Created by 石松春菜 on 2014/08/15.
//
//

#ifndef __soundPlayerExample__Sound__
#define __soundPlayerExample__Sound__

#include "ofMain.h"
#include <iostream>

class SoundPlayer{
public:
    void setup();
    void update();
    void load(int soundNum);
    void play(int soundNum);
    
#define num 7
    ofSoundPlayer sound[num];
};
#endif /* defined(__soundPlayerExample__Sound__) */
