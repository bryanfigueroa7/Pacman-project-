#include "GameOverState.h"

GameOverState::GameOverState() {
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start");
	ChoosePlayerButton = new Button(ofGetWidth()/2, ofGetHeight()/2+100, 64, 50, "Choose your Player");
	img1.load("images/pacman.png");
	music8.load("music/determination.mp3");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
	anim = new Animation(10,rightAnimframes);

}
void GameOverState::tick() {
	startButton->tick();
	ChoosePlayerButton->tick();
	anim->tick();
	if(!music8.isPlaying()){
					music8.play();
			}
	if(startButton->wasPressed()){
		setNextState("Game");
		music8.stop();
		setFinished(true);

	}
	if(ChoosePlayerButton->wasPressed()){
		setNextState("ChoosePlayerState");
		music8.stop();
		setFinished(true);
	}
}
void GameOverState::render() {
	ofDrawBitmapString("Score: " + to_string(score), ofGetWidth()/2, ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2, ofGetHeight()/2-100, 100, 100);
	startButton->render();
	ChoosePlayerButton->render();


}

void GameOverState::keyPressed(int key){
	
}

void GameOverState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
	ChoosePlayerButton->mousePressed(x, y);
}

void GameOverState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
	ChoosePlayerButton->reset();
}

void GameOverState::setScore(int sc){
    score = sc;
}

GameOverState::~GameOverState(){
	music8.stop();
	delete startButton;
	delete ChoosePlayerButton;
	delete anim;
}