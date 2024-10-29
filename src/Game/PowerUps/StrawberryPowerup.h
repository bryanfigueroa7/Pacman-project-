#pragma once

#include "PowerUp.h"

class StrawberryPowerUp : public PowerUp{
    public:
        StrawberryPowerUp(int,int,int,int,ofImage);
        int activate();
        StrawberryPowerUp();
};