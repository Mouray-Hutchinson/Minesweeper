//
// Created by 15617 on 7/23/2021.
#pragma once //only includes files one
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <sstream>
#include <random>
#include "tile.h"
#include "TextureManager.h"

using namespace std;


 class board {

public :

     int width;
     int height;
     int mines;
     vector<vector<tile>> tiles;
     string test;

    board (int w, int h, int m);
    void reset();
    void loadTestInfo (string file);
    void cAdjCount (int _h, int _w);
    void randomBoard ();
};