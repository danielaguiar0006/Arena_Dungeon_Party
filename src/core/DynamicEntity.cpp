#include "DynamicEntity.h"

extern TextureManager textureManager; // Assume this is defined in main.cpp

DynamicEntity::DynamicEntity(const std::string &texture_file_path) : Entity(texture_file_path)
{
}

void DynamicEntity::ApplyMovement(Vector2 targetVelocity, float acceleration, float deltaTime)
{
    velocity.x = CaclulateApproachDelta(velocity.x, targetVelocity.x, acceleration * deltaTime);
    velocity.y = CaclulateApproachDelta(velocity.y, targetVelocity.y, acceleration * deltaTime);
}

void DynamicEntity::ApplyFriction(float frictionAdjustment, float deltaTime)
{
    velocity.x = CaclulateApproachDelta(velocity.x, 0.0f, frictionAdjustment * deltaTime);
    velocity.y = CaclulateApproachDelta(velocity.y, 0.0f, frictionAdjustment * deltaTime);
}

float DynamicEntity::CaclulateApproachDelta(float current, float target, float maxDelta)
{
    float delta = target - current;
    if (delta > maxDelta)
        delta = maxDelta;
    if (delta < -maxDelta)
        delta = -maxDelta;
    return current + delta;
}

bool DynamicEntity::IsWithinRange(const Vector2 &targetPosition, float rangeRadius) const
{
    float distanceToTarget = Vector2Distance(pixelPosition, targetPosition);
    if (distanceToTarget <= rangeRadius)
        return true;
    else
        return false;
}