#pragma once

#include "PowerUp.h"

class ApplePowerUp : public PowerUp{
    public:
        ApplePowerUp(int,int,int,int,ofImage);
        int activate();
        ApplePowerUp();
};