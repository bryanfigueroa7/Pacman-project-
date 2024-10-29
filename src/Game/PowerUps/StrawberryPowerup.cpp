#include "StrawberryPowerUp.h"

StrawberryPowerUp::StrawberryPowerUp(int x, int y, int width, int height, ofImage spriteSheet){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    sprite.cropFrom(spriteSheet, 503,48,16,16);
}

int StrawberryPowerUp::activate(){
    return 2;
}

StrawberryPowerUp::StrawberryPowerUp(){
    
}