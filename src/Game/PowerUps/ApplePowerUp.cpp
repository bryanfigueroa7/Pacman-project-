#include "ApplePowerUp.h"

ApplePowerUp::ApplePowerUp(int x, int y, int width, int height, ofImage spriteSheet){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    sprite.cropFrom(spriteSheet, 535,48,16,16);
}

int ApplePowerUp::activate(){
    return 1;
}

ApplePowerUp::ApplePowerUp(){
    
}