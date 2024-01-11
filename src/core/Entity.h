#pragma once

#include "raylib.h"
#include "string"
#include "../utils/TextureManager.h"
#include "../utils/Globals.h"
#include "../utils/Logger.h"

class Entity
{
public:
    Entity(const std::string &texture_file_path);
    virtual ~Entity() = default;
    int GetID() const { return id; } // Getter for entity's ID

    virtual void Update(float deltaTime) = 0;
    virtual void Draw() const = 0;

    bool IsActive() const { return isActive; }
    void SetActive(bool active) { isActive = active; }
    Vector2 GetPixelPosition() const { return pixelPosition; }
    void SetPixelPosition(const Vector2 &pos);
    Vector2 GetGridPosition() const { return gridPosition; }
    void SetGridPosition(const Vector2 &pos);
    Vector2 GetCenterOrigin() const { return centerOrigin; }
    Rectangle GetHitBox() const { return hitBox; }
    void SetHitBox(const Rectangle &box) { hitBox = box; }

protected:
    bool isActive{true};
    Vector2 pixelPosition{0.0f, 0.0f};
    Vector2 gridPosition{0.0f, 0.0f};
    Vector2 centerOrigin{0.0f, 0.0f};
    Rectangle hitBox{0.0f, 0.0f, 0.0f, 0.0f}; // Hitbox origin is at the top left corner
    std::string textureFilePath;
    std::shared_ptr<Texture2D> texture;
    void UpdateHitBox();
    void UpdateGridPosition();

private:
    static int nextID; // Static variable to hold the next available ID
    int id;            // Unique ID for this entity
};