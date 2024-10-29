#pragma once

#include "State.h"
#include "Player.h"
#include "MapBuilder.h"

class GameState: public State{
    public: 
        GameState();
		~GameState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		int getFinalScore();
		Map* map;
	
	private:
		ofSoundPlayer music1;
		ofSoundPlayer music2;
		ofSoundPlayer music3;
		ofSoundPlayer music4;
		ofImage mapImage;
		int finalScore=0;

};