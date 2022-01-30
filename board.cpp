//
// Created by 15617 on 7/23/2021.
#include "board.h"

board::board (int w, int h, int m) { //generate a board if given parameters
    width = w;
    height = h;
    mines = m;
    //randomBoard();
}

void board::reset() {
    height = 0;
    //get dimensions
    //2d Array of tiles
    //random tile location using the last lab thing
    // --> place mines
    //place the neighbor ptrs for each tile (using vectors)

};

void board::loadTestInfo (string file) { //For example tests
    ifstream inFile(file);
    string data;
    inFile >> data;
    int hCounter = 0;
    while (getline(inFile, data)) {

        string temp;

        istringstream stream(temp); //data stream coming form a string
        getline(stream, temp);
        for (int unsigned i = 0; i < temp.length(); i++) {
            string a = to_string(temp[i]); //check
            width = temp.length();
            tiles[i].push_back(tile(stoi(a)));
            if (stoi(a)==1) {
                cAdjCount (hCounter,i);
            }
        };
        hCounter++; //add whenever gets a new line

    };



};

void board::cAdjCount (int _h, int _w) { //changes the value of the adjacent count   tiles[_h-1][_w].adCount++;


};

void board::randomBoard () {  //generate random number & creates a board by adding one row at a time
    for ( int h = 0; h<height; h++) {
       vector<tile> ts;
        for (int w = 0; w<width; w++) {
            ts.push_back(tile());
        };
        tiles.push_back(ts);
    };

    //Place mines
    for (int i = 0; i<mines; i++) {
        int minew = std::rand() % width;
        int mineh = std::rand() % height;

        if (tiles[mineh][minew].value == 1) {
            i--;
        }
        else {
            tiles[mineh][minew].value = 1;
            cAdjCount (mineh,minew);
        }
    }};



