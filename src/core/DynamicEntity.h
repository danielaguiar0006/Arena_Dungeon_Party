#pragma once

#include "Entity.h"
#include "raymath.h"

class DynamicEntity : public Entity
{
public:
    DynamicEntity() = default;
    virtual ~DynamicEntity() = default;

    Vector2 GetVelocity() const { return velocity; }
    void SetVelocity(const Vector2 &vel) { velocity = vel; }

protected:
    Vector2 velocity{0.0f, 0.0f};

    // void CheckCollision(const Rectangle &other); //TODO: Implement this
    void UpdateHitBox();
    void ApplyMovement(Vector2 targetVelocity, float acceleration, float deltaTime);
    void ApplyFriction(float frictionAdjustment, float deltaTime);
    float CaclulateApproachDelta(float current, float target, float maxDelta);
    bool IsWithinRange(const Vector2 &targetPosition, float rangeRadius) const;
};