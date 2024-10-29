#pragma once

#include "Entity.h"

class PowerUp : public Entity{
    public:
        virtual int activate() = 0;
        PowerUp(){ };
};