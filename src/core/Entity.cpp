#include "Entity.h"

int Entity::nextID = 0; // Initialize static member variable

void Entity::UpdateHitBox()
{
    hitBox.x = position.x;
    hitBox.y = position.y;
    centerOrigin.x = position.x - (hitBox.width / 2.0f);
    centerOrigin.y = position.y - (hitBox.height / 2.0f);
}