#include "Character.h"

Character::Character(const std::string &textureFilePath) : DynamicEntity(textureFilePath)
{
}

void Character::CheckHealth()
{
    if (health <= 0.0f)
    {
        health = 0.0f;
        Die();
    }
    if (health > maxHealth)
        health = maxHealth;
}