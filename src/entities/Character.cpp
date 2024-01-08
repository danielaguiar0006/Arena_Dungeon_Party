#include "Character.h"

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