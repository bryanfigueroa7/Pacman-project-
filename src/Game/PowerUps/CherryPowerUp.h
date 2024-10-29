#pragma once

#include "PowerUp.h"

class CherryPowerUp : public PowerUp{
    public:
        CherryPowerUp(int,int,int,int,ofImage);
        int activate();
        CherryPowerUp();
};