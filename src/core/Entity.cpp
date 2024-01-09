#include "Entity.h"

int Entity::nextID = 0; // Initialize static member variable

void Entity::SetPixelPosition(const Vector2 &pos)
{
    pixelPosition = pos;
    UpdateHitBox();
    UpdateGridPosition();
}

void Entity::SetGridPosition(const Vector2 &pos)
{
    gridPosition = pos;
    pixelPosition.x = gridPosition.x * (TILE_WIDTH * TILE_SCALE_FACTOR);
    pixelPosition.y = gridPosition.y * (TILE_WIDTH * TILE_SCALE_FACTOR);
    UpdateHitBox();
}

void Entity::UpdateHitBox()
{
    hitBox.x = pixelPosition.x;
    hitBox.y = pixelPosition.y;
    centerOrigin.x = pixelPosition.x - (hitBox.width / 2.0f);
    centerOrigin.y = pixelPosition.y - (hitBox.height / 2.0f);
}

void Entity::UpdateGridPosition()
{
    gridPosition.x = pixelPosition.x / (TILE_WIDTH * TILE_SCALE_FACTOR);
    gridPosition.y = pixelPosition.y / (TILE_WIDTH * TILE_SCALE_FACTOR);
}
