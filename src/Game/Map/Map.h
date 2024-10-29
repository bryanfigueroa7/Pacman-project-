#pragma once

#include "Player.h"
#include "GhostSpawner.h"

class Map{
    public:
      Map(EntityManager*);
      ~Map();
      void addBoundBlock(BoundBlock*);
      void addEntity(Entity*);
      Player* getPlayer();
      void setPlayer(Player*);
      void setGhostSpawner(GhostSpawner*);
      void tick();
      void render();
      void keyPressed(int key);
		  void mousePressed(int x, int y, int button);
		  void keyReleased(int key);
      Player* getPlayer2();
      void setPlayer2(Player*);
      Player* getPlayer3();
      void setPlayer3(Player*);
      int dotcount = 0;
      void setDotCount(int n) { dotcount = n; }
      int getdotcount() { return dotcount; }

    private:
      EntityManager *entityManager;
      Player *player;
      Player *player2;
      Player *player3;
      GhostSpawner* gs;
};