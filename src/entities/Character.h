#pragma once

#include "../core/DynamicEntity.h"

class Character : public DynamicEntity
{
public:
    Character(const std::string &textureFilePath);
    virtual ~Character() = default;

    virtual void Update(float deltaTime) = 0;
    virtual void Draw() const = 0;

    virtual void UpdateCooldowns(float deltaTime) = 0;
    virtual void Attack(Character *target) = 0;
    virtual void TakeDamage(float damageAmount) = 0;
    virtual void Die() = 0;

    bool IsAlive() const { return isAlive; }
    bool IsHostile() const { return isHostile; }
    float GetCurrentHealth() const { return health; }
    void SetCurrentHealth(float newHealth) { health = newHealth; }
    float GetMaxHealth() const { return maxHealth; }
    void SetMaxHealth(float newMaxHealth) { maxHealth = newMaxHealth; }
    float GetWalkAcceleration() const { return walkAcceleration; }
    void SetWalkAcceleration(float newWalkAcceleration) { walkAcceleration = newWalkAcceleration; }
    float GetRunAcceleration() const { return runAcceleration; }
    void SetRunAcceleration(float newRunAcceleration) { runAcceleration = newRunAcceleration; }
    float GetMaxWalkSpeed() const { return maxWalkSpeed; }
    void SetMaxWalkSpeed(float newMaxWalkSpeed) { maxWalkSpeed = newMaxWalkSpeed; }
    float GetMaxRunSpeed() const { return maxRunSpeed; }
    void SetMaxRunSpeed(float newMaxRunSpeed) { maxRunSpeed = newMaxRunSpeed; }
    float GetBaseAttackDamage() const { return baseAttackDamage; }
    void SetBaseAttackDamage(float newBaseAttackDamage) { baseAttackDamage = newBaseAttackDamage; }
    float GetAttackRange() const { return attackRange; }
    void SetAttackRange(float newAttackRange) { attackRange = newAttackRange; }

protected:
    bool isAlive{true};
    bool isHostile{true};
    float health{100.0f};
    float maxHealth{200.0f};
    float walkAcceleration = 2000.0f;
    float runAcceleration = 4000.0f;
    float maxWalkSpeed = 200.0f;
    float maxRunSpeed = 400.0f;
    float baseAttackDamage = 20.0f;
    float attackRange = 50.0f;

    void CheckHealth();
    virtual void DropLoot() = 0;
};