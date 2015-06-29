//
//  Sound.cpp
//  soundPlayerExample
//
//  Created by 石松春菜 on 2014/08/15.
//
//

#include "Sound.h"

void SoundPlayer::setup(){
    for (int i=0; i<num; i++) {
        load(i);
    }
}

void SoundPlayer::update(){
    ofSoundUpdate();
}

void SoundPlayer::load(int soundNum){
    if (soundNum > 0) {
        sound[soundNum].loadSound("sounds/mokkin/"+ofToString(soundNum-1)+".wav");
    } else if(soundNum == 0){
        sound[soundNum].loadSound("sounds/metro01.wav");
    }
    sound[soundNum].setVolume(1.0f);
    sound[soundNum].setLoop(false);
    sound[soundNum].setMultiPlay(false);
}

void SoundPlayer::play(int soundNum){
    if (soundNum < 7) {
        sound[soundNum].play();
    } else if(soundNum == 7){
        sound[0].play();
    }
}