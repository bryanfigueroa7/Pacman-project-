#include "CherryPowerUp.h"

CherryPowerUp::CherryPowerUp(int x, int y, int width, int height, ofImage spriteSheet){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    sprite.cropFrom(spriteSheet, 488,48,16,16);
}

int CherryPowerUp::activate(){
    return 0;
}

CherryPowerUp::CherryPowerUp(){

}