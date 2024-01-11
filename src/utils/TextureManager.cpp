#include "TextureManager.h"

// Static Member Initialization
std::shared_ptr<Texture2D> TextureManager::defaultTexture = nullptr;
std::map<std::string, std::shared_ptr<Texture2D>> TextureManager::textures;
std::mutex TextureManager::mutex;

/**
 * @brief A smart pointer that manages the lifetime of a Texture2D object.
 *
 * std::shared_ptr<Texture2D> is a smart pointer that provides shared ownership of a Texture2D object.
 * It automatically releases the memory allocated for the Texture2D object when it is no longer needed.
 * Multiple std::shared_ptr objects can share ownership of the same Texture2D object, and the object
 * will be deleted only when the last std::shared_ptr owning it is destroyed or reset.
 */
std::shared_ptr<Texture2D> TextureManager::GetTexture(const std::string &textureFilePath)
{
    // Lock the mutex to ensure thread safety
    std::lock_guard<std::mutex> lock(mutex);

    // If the texture filename is empty, load the default texture
    if (textureFilePath.empty())
    {
        Logger::Error("Texture filename is empty!");
        LoadDefaultTexture();

        return defaultTexture;
    }
    // If the texture is not already loaded, load it
    else if (textures.count(textureFilePath) == 0)
    {
        Logger::Info("Loading texture: " + textureFilePath);

        // Load the texture and wrap it in a shared_ptr
        std::shared_ptr<Texture2D> texture = std::make_shared<Texture2D>(LoadTexture(textureFilePath.c_str()));
        textures[textureFilePath] = texture;

        // for debugging output every texture loaded inside textures map
        /*for (auto &texture : textures)
        {
            Logger::Info(texture.first);
        }*/

        // Set the texture parameters
        ApplyTextureParameters(*textures[textureFilePath]);

        // If the texture failed to load, remove it from the map and load the default texture
        if (texture->id <= 0)
        {
            // throw std::runtime_error("Failed to load texture: " + textureFilePath);

            Logger::Error("Failed to load texture: " + textureFilePath);
            textures.erase(textureFilePath);
            LoadDefaultTexture();

            return defaultTexture;
        }
    }
    else
    {
        Logger::Info("Texture already loaded: " + textureFilePath);
    }

    // Return the texture
    return textures[textureFilePath];
}

void TextureManager::RemoveTexture(const std::string &textureFilePath)
{
    // Lock the mutex to ensure thread safety
    std::lock_guard<std::mutex> lock(mutex);

    auto it = textures.find(textureFilePath);
    if (it != textures.end())
    {
        // Check if there are other references to the texture
        if (it->second.use_count() > 1)
        {
            Logger::Error("Texture still in use: " + textureFilePath);
            return;
        }

        // Unload the texture using Raylib's UnloadTexture function
        ::UnloadTexture(*it->second.get());
        // Remove it from the map
        textures.erase(it);
    }
}

void TextureManager::ForceRemoveTexture(const std::string &textureFilePath)
{
    // Lock the mutex to ensure thread safety
    std::lock_guard<std::mutex> lock(mutex);

    auto it = textures.find(textureFilePath);
    if (it != textures.end())
    {
        // Unload the texture using Raylib's UnloadTexture function
        ::UnloadTexture(*it->second.get());
        // Remove it from the map
        textures.erase(it);
    }
}

void TextureManager::UnloadAllTextures()
{
    // Force remove all textures
    for (auto &texture : textures)
    {
        ForceRemoveTexture(texture.first);
    }

    textures.clear();

    // Unload the default texture if it exits
    if (defaultTexture != nullptr)
    {
        ::UnloadTexture(*defaultTexture.get());
        defaultTexture = nullptr;
    }
}

void TextureManager::LoadDefaultTexture()
{
    // std::lock_guard<std::mutex> lock(mutex); // ! This causes a deadlock

    // If the default texture is not loaded, load it
    if (defaultTexture == nullptr)
    {
        Texture2D texture = LoadTexture("assets/textures/default.png");
        if (texture.id <= 0)
        {
            Logger::Error("Failed to load default texture");
            // Handle the error (e.g., stop the program, load a different texture, etc.)
            return;
        }

        defaultTexture = std::make_shared<Texture2D>(texture);
        ApplyTextureParameters(*defaultTexture);
    }
}

void TextureManager::ApplyTextureParameters(Texture2D &texture)
{
    // Set the texture wrap and filter parameters
    SetTextureWrap(texture, TEXTURE_WRAP_CLAMP);
    SetTextureFilter(texture, TEXTURE_FILTER_POINT);
}
