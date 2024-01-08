#pragma once

#include "raylib.h"
#include "string"

class Entity
{
public:
    Entity() : id(nextID++) {}
    virtual ~Entity() = default;
    int GetID() const { return id; } // Getter for entity's ID

    virtual void Update(float deltaTime) = 0;
    virtual void Draw() const = 0;

    bool IsActive() const { return isActive; }
    void SetActive(bool active) { isActive = active; }
    Vector2 GetPosition() const { return position; }
    void SetPosition(const Vector2 &pos) { position = pos; }
    Rectangle GetHitBox() const { return hitBox; }
    void SetHitBox(const Rectangle &box) { hitBox = box; }

protected:
    bool isActive{true};
    Vector2 position{0.0f, 0.0f};
    Rectangle hitBox{0.0f, 0.0f, 0.0f, 0.0f};

private:
    static int nextID; // Static variable to hold the next available ID
    int id;            // Unique ID for this entity
};