#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h" 

class MenuState : public State {
private:
	ofImage img1;
	Button *startButton;
	Animation* anim;
	Button *ChoosePlayerButton;
	ofSoundPlayer music7;

public:
	MenuState();
	~MenuState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
