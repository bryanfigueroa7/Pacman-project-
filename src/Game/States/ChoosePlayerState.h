#pragma once

#include "GameState.h"
#include "State.h"
#include "Button.h"
#include "Player.h"
#include "Animation.h"

class ChoosePlayerState : public State {

    private:
    ofImage img1;
	Button *PacManButton;
    Button *SANSButton;
    Animation* anim1;
    Animation* anim2;
    ofImage img2;


    public:
	ChoosePlayerState();
	~ChoosePlayerState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	string selChar = "";
	string getChar() { return selChar; }
	void setChar(string c) { selChar = c; }

};