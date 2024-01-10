#pragma once

#include "Entity.h"

class StaticEntity : public Entity
{
public:
    StaticEntity() = default;
    virtual ~StaticEntity() = default;

protected:
    bool isCollidable{true};
};