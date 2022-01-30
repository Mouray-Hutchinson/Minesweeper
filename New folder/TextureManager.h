
#include <SFML/Graphics.hpp>
#pragma once //only includes files one
#include <unordered_map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using std::unordered_map;
using std::string;

class TextureManager {
    static unordered_map<string, sf::Texture> textures;
public:

    static void LoadTexture(string texture);
    static sf::Texture& GetTexture (string texName);
    static void Clear();
};

