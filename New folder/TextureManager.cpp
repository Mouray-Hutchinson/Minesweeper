#include "TextureManager.h"

 //redeclare variable
 unordered_map<string, sf::Texture> TextureManager::textures;


 void TextureManager::LoadTexture(string texName) {
    string path = "images/" + texName + ".png";
    textures[texName].loadFromFile(path);
};

 sf::Texture& TextureManager::GetTexture (string texName) {

    if (textures.find(texName)==TextureManager::textures.end()) {
        LoadTexture(texName);
    };

    return textures[texName];
};

void TextureManager::Clear() {
    textures.clear();
};