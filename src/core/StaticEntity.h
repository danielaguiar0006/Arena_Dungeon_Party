#pragma once

#include "Entity.h"

class StaticEntity : public Entity
{
public:
    enum class TileType
    {
        Floor,
        Wall,
        Door,
        Chest,
        Trap,
    };

    StaticEntity(TileType tile_type, const std::string &texture_file_path) : Entity(texture_file_path), tileType(tile_type) {}
    virtual ~StaticEntity() = default;

    virtual void Update(float deltaTime) override;
    virtual void Draw() const override;

    bool IsSolid() const { return isSolid; }
    void SetSolid(bool solid) { isSolid = solid; }
    bool IsBreakable() const { return isBreakable; }
    void SetBreakable(bool breakable) { isBreakable = breakable; }
    TileType GetTileType() const { return tileType; }
    void SetTileType(TileType type) { tileType = type; }

protected:
    bool isSolid{true};
    bool isBreakable{false};
    TileType tileType;
};

// TODO: FINISH AND IMPLEMENT THIS