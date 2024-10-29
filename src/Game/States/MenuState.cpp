#include "MenuState.h"

MenuState::MenuState() {
	startButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2, 64, 50, "Start");
	ChoosePlayerButton = new Button(ofGetWidth()/2-32, ofGetHeight()/2+100, 64, 50, "Choose your Player");
	img1.load("images/pacman.png");
	music7.load("music/pacmanworldrally.mp3");
	vector<ofImage> rightAnimframes;
    ofImage temp;
	for(int i=0; i<3; i++){
        temp.cropFrom(img1, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
	anim = new Animation(10,rightAnimframes);

}
void MenuState::tick() {
	startButton->tick();
	ChoosePlayerButton->tick();
	anim->tick();
	if(!music7.isPlaying()){
				music7.play();
		}
	if(startButton->wasPressed()){
		setNextState("Game");
		music7.stop();
		setFinished(true);
	} else if(ChoosePlayerButton->wasPressed()){
		setNextState("ChoosePlayerState");
		setFinished(true);
	}
}
void MenuState::render() {
	string title = "Pacman Project";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim->getCurrentFrame().draw(ofGetWidth()/2-50, ofGetHeight()/2-100, 100, 100);
	startButton->render();
	ChoosePlayerButton->render();


}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
	ChoosePlayerButton->mousePressed(x,y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
	ChoosePlayerButton->reset();
}

MenuState::~MenuState(){
	music7.stop();
	delete startButton;
	delete ChoosePlayerButton;
	delete anim;
}