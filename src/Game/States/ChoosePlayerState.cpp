#include "ChoosePlayerState.h"

ChoosePlayerState::ChoosePlayerState() {
    PacManButton = new Button(ofGetWidth()/2-226, ofGetHeight()/2, 64, 50, "PacMan");
    SANSButton = new Button(ofGetWidth()/2+174, ofGetHeight()/2, 64, 50, "SANS");
    img1.load("images/pacman.png");
	vector<ofImage> PrightAnimframes;
    ofImage temp1;
	for(int i=0; i<3; i++){
        temp1.cropFrom(img1, i*16, 0, 16, 16);
        PrightAnimframes.push_back(temp1);
    }
	anim1 = new Animation(10,PrightAnimframes);

    img2.load("images/pacmanS.png");
    vector<ofImage> PSrightAnimframes;
    ofImage temp2;
	for(int i=0; i<3; i++){
        temp2.cropFrom(img2, i*16, 0, 16, 16);
        PSrightAnimframes.push_back(temp2);
    }
    anim2 = new Animation(10,PSrightAnimframes);

}

void ChoosePlayerState::tick() {
	PacManButton->tick();
    SANSButton->tick();
	anim1->tick();
    anim2->tick();

	if(PacManButton->wasPressed()){
		string selChar = "PacMan";
		setNextState("Menu");
		setFinished(true);

	} else if (SANSButton->wasPressed()){
		selChar = "SANS";
		setNextState("Menu");
		setFinished(true);
	}
}

void ChoosePlayerState::render() {
	string title = "Pacman Project";
	ofDrawBitmapString(title, ofGetWidth()/2-4*title.size(), ofGetHeight()/2-300, 50);
	ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
	anim1->getCurrentFrame().draw(ofGetWidth()/2-232, ofGetHeight()/2-100, 100, 100);
    ofSetBackgroundColor(0, 0, 0);
	ofSetColor(256, 256, 256);
    anim2->getCurrentFrame().draw(ofGetWidth()/2+168, ofGetHeight()/2-100, 100, 100);
	PacManButton->render();
	SANSButton->render();


}

void ChoosePlayerState::keyPressed(int key){
	
}

void ChoosePlayerState::mousePressed(int x, int y, int button){
	PacManButton->mousePressed(x,y);
	SANSButton->mousePressed(x,y);
}

void ChoosePlayerState::reset(){
	setFinished(false);
	setNextState("");
	PacManButton->reset();
	SANSButton->reset();
}

ChoosePlayerState::~ChoosePlayerState(){
	delete PacManButton;
	delete SANSButton;
	delete anim1;
    delete anim2;
    
}