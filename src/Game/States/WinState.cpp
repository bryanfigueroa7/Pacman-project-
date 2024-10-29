#include "WinState.h"

WinState::WinState() {
    playAgain = new Button(ofGetWidth()/2+15, ofGetHeight()/2 + 10, 64, 50, "Play Again");
    quit = new Button(ofGetWidth()/2+15, ofGetHeight()/2 + 50, 64, 50, "Quit");
    music6.load("music/tem.mp3");
}
void WinState::tick() {
    playAgain->tick();
    quit->tick();
    if(!music6.isPlaying()){
		music6.play();
	}

    if(playAgain->wasPressed()){
        setNextState("Menu");
        music6.stop();
        setFinished(true);
    }
    if(quit->wasPressed()){
        ofExit(0);
    }
}
void WinState::render() {
    ofDrawBitmapString("You won!", ofGetWidth()/2, ofGetHeight()/2-150);
    ofDrawBitmapString("Make sure you didn't cheat.", ofGetWidth()/2-60, ofGetHeight()/2-100);
    ofDrawBitmapString("Youre score is:" + to_string(this->score), ofGetWidth()/2-25, ofGetHeight()/2 - 50);
    playAgain->render();
    quit->render();
}

void WinState::keyPressed(int key){
}

void WinState::setScore(int sc){
    score = sc;
}

void WinState::mousePressed(int x, int y, int button){
    playAgain->mousePressed(x,y);
    quit->mousePressed(x,y);
}

void WinState::keyReleased(int key){
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
    playAgain->reset();
    quit->reset();
}

WinState::~WinState(){
    music6.stop();
    delete playAgain;
    delete quit;
}