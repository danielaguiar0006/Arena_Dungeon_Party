#pragma once

#include <map>
#include <string>
#include <memory>
#include <mutex>
#include "raylib.h"
#include "Logger.h"

class TextureManager
{
public:
    static TextureManager &GetInstance()
    {
        static TextureManager instance;
        return instance;
    }
    static std::shared_ptr<Texture2D> GetTexture(const std::string &textureFilename);
    static void RemoveTexture(const std::string &textureFilename);
    static void ForceRemoveTexture(const std::string &textureFilename);
    static void UnloadAllTextures();

private:
    TextureManager() {}                              // Private constructor
    TextureManager(const TextureManager &) = delete; // Prevent copy-construction
    void operator=(const TextureManager &) = delete; // Prevent assignment

    static void LoadDefaultTexture();
    static void ApplyTextureParameters(Texture2D &texture);

    static std::mutex mutex;
    static std::map<std::string, std::shared_ptr<Texture2D>> textures;
    static std::shared_ptr<Texture2D> defaultTexture;
};