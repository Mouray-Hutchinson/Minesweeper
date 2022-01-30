//
// Created by 15617 on 7/23/2021.
#pragma once //only includes files one
#include <SFML/Graphics.hpp>
#include <string>
#include "TextureManager.h"
#include <random>
using namespace std;

class tile {

public:

    int value;
    string sPath = "tile_hidden";
    sf::Sprite s;
    bool rev = false;
    int adCount;

    tile() {
       value = 0;
       adCount = 0;
    };

    tile(int val) {
        value = val;
        adCount = 0;
        s.setTexture(TextureManager::GetTexture("tile_hidden"));

    };

    void changePath (string imgNam) {
        sPath = imgNam;

    }

};


