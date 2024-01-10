#pragma once

#include <map>
#include <string>
#include <memory>
#include <mutex>
#include "raylib.h"
#include "Logger.h"

// *Singleton class*
class TextureManager
{
public:
    static TextureManager &GetInstance()
    {
        static TextureManager instance; // Guaranteed to be destroyed.
                                        // Instantiated on first use.
        return instance;
    }
    TextureManager(TextureManager const &) = delete; // Don't Implement
    void operator=(TextureManager const &) = delete; // Don't implement

    std::shared_ptr<Texture2D> GetTexture(const std::string &textureFilePath);
    void RemoveTexture(const std::string &textureFilePath);
    void ForceRemoveTexture(const std::string &textureFilePath);
    void UnloadAllTextures();

private:
    TextureManager() {} // Private constructor

    void LoadDefaultTexture();
    void ApplyTextureParameters(Texture2D &texture);

    static std::mutex mutex;
    static std::map<std::string, std::shared_ptr<Texture2D>> textures;
    static std::shared_ptr<Texture2D> defaultTexture;
};