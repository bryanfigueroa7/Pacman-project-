#include "PauseState.h"

PauseState::PauseState() {
    resumeButton = new Button(ofGetWidth()/2-32, ofGetHeight()/3, 64, 50, "Resume");
    quitButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2, 64, 50, "Quit");
}

void PauseState::tick() {
	resumeButton->tick();
	quitButton->tick();
	if(quitButton->wasPressed()){
		ofExit(0);
	}
    if(resumeButton->wasPressed()){
		setFinished(true);
        setNextState("Game");
    }
	
}

void PauseState::render() {
	string title = "PAUSE";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(255, 255, 255);
	resumeButton->render();
    quitButton->render();


}

void PauseState::keyPressed(int key){

}

void PauseState::mousePressed(int x, int y, int button){
	resumeButton->mousePressed(x, y);
    quitButton->mousePressed(x, y);
}

void PauseState::reset(){
	setFinished(false);
	setNextState("");
	resumeButton->reset();
	quitButton->reset();
}

PauseState::~PauseState(){
	delete resumeButton;
	delete quitButton;
}