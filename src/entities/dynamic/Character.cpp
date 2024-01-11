#include "Character.h"

Character::Character(const std::string &texture_file_path) : DynamicEntity(texture_file_path)
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