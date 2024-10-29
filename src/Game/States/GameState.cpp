#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	music1.load("music/pacman_chomp.wav");
	music2.load("music/youre-gonna-have-a-bad-time.mp3");
	music3.load("music/hopesndreams.mp3");
	music4.load("music/Pacman-Theme.mp3");
	mapImage.load("images/map2.png");
	map = MapBuilder().createMap(mapImage);
}
void GameState::tick() {
	if(map->getPlayer() == map->getPlayer3()){
		if(!music1.isPlaying()){
				music1.play();
		}
		if(map->getPlayer()->getDotGrabbed() >= 0.50*map->getdotcount()){
			music1.stop();
			if(!music4.isPlaying()){
					music4.play();
			}
		}
	} else if (map->getPlayer() == map->getPlayer2()){
		if(!music2.isPlaying()){
			music2.play();
		}
		if(map->getPlayer()->getDotGrabbed() >= 0.50*map->getdotcount()){
			music2.stop();
			if(!music3.isPlaying()){
					music3.play();
			}
		}

	}
	map->tick();
	if(map->getPlayer()->getHealth() == 0){
		map = MapBuilder().createMap(mapImage);
		setFinished(true);
		setNextState("over");
		map->getPlayer()->setHealth(3);
		finalScore = map->getPlayer()->getScore();
		map->getPlayer()->setScore(0);
		music2.stop();
		music3.stop();
		music4.stop();
	}
	if(map->getPlayer()->getDotGrabbed() == map->getdotcount()){
		finalScore = map->getPlayer()->getScore();
		map = MapBuilder().createMap(mapImage);
		map->getPlayer()->setHealth(3);
		music2.stop();
		music3.stop();
		music4.stop();
		setFinished(true);
		setNextState("Win");
	}

}
void GameState::render() {
	map->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
	if (key == 'p' || key == 'P'){
		setFinished(true);
		setNextState("Pause");
	}
	else if (key == 'y'|| key == 'Y'){
		finalScore = map->getPlayer()->getScore();
		map = MapBuilder().createMap(mapImage);
		map->getPlayer()->setHealth(3);
		music2.stop();
		music3.stop();
		music4.stop();
		setFinished(true);
		setNextState("Win");
		
	}
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}

int GameState::getFinalScore(){
	return finalScore;
}

GameState::~GameState(){
	delete map;
}