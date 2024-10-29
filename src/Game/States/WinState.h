#pragma once

#include "State.h"
#include "Button.h"
#include "GameState.h"
#include "Player.h"

class WinState: public State{
    private:
    Button *quit;
    Button *playAgain;
    int score ;
    GameState *gamestate;
    Player *player;
    ofSoundPlayer music6;

    public:
        WinState();
        ~WinState();
        void reset();
        void tick();
        void render();
        void keyPressed(int key);
        void mousePressed(int x, int y , int button);
        void keyReleased(int key);
        void setScore(int sc);

};