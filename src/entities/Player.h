#pragma once

#include "Character.h"
#include <iostream>

class Player : public Character
{
public:
    enum class PlayerState
    {
        Idle,
        Walking,
        Running,
        Dashing,
        Attacking,
        Hurt,
        Dying
    };

    Player();
    virtual ~Player() = default;

    void Update(float deltaTime) override;
    void Draw() const override;
    std::string GetCurrentState(PlayerState state) const;
    void Attack(Character *target) override;
    void TakeDamage(float damageAmount) override;
    void Die() override;

private:
    void UpdateCooldowns(float deltaTime) override;
    Vector2 HandleInputs();
    void DropLoot() override;

    PlayerState currentState{PlayerState::Idle};
    void SetState(PlayerState newState);

    void Dash(Vector2 inputDirection);
    float dashAcceleration = 600.0f;
    float lastDashTimeSec = 0.0f;
    float dashCooldownSec = 1.0f;
    float dashDurationSec = 0.25f;
    Vector2 targetDashVelocity = {0.0f, 0.0f};
};