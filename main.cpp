#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include "TextureManager.h"


using namespace std;

//recursive showing test
//s is hidden;  j is whats shown; n is number
//left & up left

void Counter(sf::Sprite &counter1,sf::Sprite &counter2,sf::Sprite &counter3,int remain, sf::Texture &tex,sf::Texture &tex1,sf::Texture &tex2) {

    int hunds = remain / 100;
    int tens = remain / 10 - hunds * 10;
    int ones = remain % 10;

//hunds
    tex.loadFromFile("images/digits.png", sf::IntRect(hunds* 21, 0, 21, 32));
    counter1.setTexture(tex);

    tex1.loadFromFile("images/digits.png", sf::IntRect(tens * 21, 0, 21, 32));
    counter2.setTexture(tex1);


    tex2.loadFromFile("images/digits.png", sf::IntRect(ones * 21, 0 ,21, 32));
    counter3.setTexture(tex2);

}
void showOthersL(vector<vector<sf::Sprite>> &s,int x ,int y,vector<vector<sf::Sprite>> &j,vector<vector<sf::Sprite>> &n) {

    //left
            if (x > 0 && x < s[0].size() && s[x - 1][y].getTexture() == j[x][y].getTexture()) {
                j[x - 1][y] = s[x - 1][y]; //make it plain
                showOthersL(s, (x - 1), y, j, n);//keep checking
            }
            //for the numbers
            else if (x > 0 && x < s[0].size() && x < s[0].size() && x < s[0].size() && s[x - 1][y].getTexture() == n[x - 1][y].getTexture()) {
                j[x - 1][y] = n[x - 1][y]; //make it the number & stop
            }

            //up left
    if (x > 0 && x < s[0].size() &&  y > 0 && y < s.size() && s[x - 1][y+1].getTexture() == j[x][y].getTexture()) {
        j[x - 1][y+1] = s[x - 1][y+1]; //make it plain
        showOthersL(s, (x - 1), y+1, j, n);//keep checking
    }
        //for the numbers
    else if (x > 0 && x < s[0].size() &&  s[x - 1][y+1].getTexture() == n[x - 1][y+1].getTexture()) {
        j[x - 1][y+1] = n[x - 1][y+1]; //make it the number & stop
    }
};
//right and down right
void showOthersR(vector<vector<sf::Sprite>> &s,int x,int y,vector<vector<sf::Sprite>> &j,vector<vector<sf::Sprite>> &n) {

    //right
    //for hidden values
    if (x > 0 && x < s[0].size() && s[x + 1][y].getTexture() == j[x][y].getTexture()) {
        j[x + 1][y] = s[x + 1][y]; //make it plain
        showOthersR(s, (x + 1), y, j, n);//keep checking
    }
        //for the numbers
    else if (x > 0 && x < s[0].size() && s[x + 1][y].getTexture() == n[x + 1][y].getTexture()) {
        j[x + 1][y] = n[x + 1][y]; //make it the number & stop
    }

    // dr
    //for hidden values
    if (x > 0 && x < s[0].size() && y > 0 && y < s.size() && s[x + 1][y-1].getTexture() == j[x][y].getTexture()) {
        j[x + 1][y-1] = s[x + 1][y-1]; //make it plain
        showOthersR(s, (x + 1), y-1, j, n);//keep checking
    }
        //for the numbers
    else if (x > 0 && x < s[0].size() && y > 0 && y < s.size() &&  s[x + 1][y-1].getTexture() == n[x + 1][y-1].getTexture()) {
        j[x + 1][y-1] = n[x + 1][y-1]; //make it the number & stop
    }

};
//down and down left
void showOthersD(vector<vector<sf::Sprite>> &s,int x ,int y,vector<vector<sf::Sprite>> &j,vector<vector<sf::Sprite>> &n) {
    //down
    //for hidden values
    if (y > 0 && y < s.size() && s[x][y-1].getTexture() == j[x][y].getTexture()) {
        j[x][y-1] = s[x][y-1]; //make it plain
        showOthersD(s, x, y-1, j, n);//keep checking
    }
        //for the numbers
    else if (y > 0 && y < s.size() && s[x][y-1].getTexture() == n[x][y-1].getTexture()) {
        j[x][y-1] = n[x][y-1]; //make it the number & stop
    }

    //down left
    if (x > 0 && x < s[0].size() && y > 0 && y < s.size() && s[x - 1][y-1].getTexture() == j[x][y].getTexture()) {
        j[x - 1][y-1] = s[x - 1][y-1]; //make it plain
        showOthersD(s, (x - 1), y-1, j, n);//keep checking
    }
        //for the numbers
    else if (x > 0 && x < s[0].size() && y > 0 && y < s.size() && s[x - 1][y-1].getTexture() == n[x - 1][y-1].getTexture()) {
        j[x - 1][y-1] = n[x - 1][y-1]; //make it the number & stop
    }
};
//up and up right
void showOthersU(vector<vector<sf::Sprite>> &s,int x ,int y,vector<vector<sf::Sprite>> &j,vector<vector<sf::Sprite>> &n) {
    //up
    //for hidden values
    if (y > 0 && y < s.size()  && s[x][y+1].getTexture() == j[x][y].getTexture()) {
        j[x][y+1] = s[x][y+1]; //make it plain
        showOthersU(s, x, y+1, j, n);//keep checking
    }
        //for the numbers
    else if (y > 0 && y < s.size() && s[x][y+1].getTexture() == n[x][y+1].getTexture()) {
        j[x][y+1] = n[x][y+1]; //make it the number & stop
    }
//upright
    if (y > 0 && y < s.size()  && s[x+1][y+1].getTexture() == j[x][y].getTexture()) {
        j[x+1][y+1] = s[x][y+1]; //make it plain
        showOthersU(s, x, y+1, j, n);//keep checking
    }
        //for the numbers
    else if (y > 0 && y < s.size() && s[x+1][y+1].getTexture() == n[x+1][y+1].getTexture()) {
        j[x+1][y+1] = n[x+1][y+1]; //make it the number & stop
    }
};

int main() {
    //Get config info
    vector<string> d;
    string l;
    ifstream file("boards/config.cfg");

    while (getline(file, l)) {

        istringstream stream(l);
        getline(stream, l);
        d.push_back(l);
    };

//end config data
//load texture arrays
    vector<vector<sf::Sprite>> s; //always showing
    vector<vector<sf::Sprite>> blank; //all hidden
    vector<vector<sf::Sprite>> r; //revealed plain tile

    vector<vector<sf::Sprite>> h; //hidden value final tile
    vector<vector<sf::Sprite>> f; //flag tile
    vector<vector<sf::Sprite>> m; //mine tile
    vector<vector<sf::Sprite>> n; //number tile


    bool rev[std::stoi(d[0])][std::stoi(d[1])];
    int adCt[std::stoi(d[0])][std::stoi(d[1])];

    vector<vector<string>> names;
    sf::Sprite fk;
    //MAKEVECTORS
    for (int i = 0; i < stoi(d[0]); i++) {
        vector<sf::Sprite> temp;
        vector<sf::Sprite> tempr;
        vector<sf::Sprite> temph;
        vector<sf::Sprite> tempf;
        vector<sf::Sprite> tempm;
        vector<sf::Sprite> tempn;

//load texture arrays
        for (int j = 0; j < stoi(d[1]); j++) {
            adCt[i][j] = 0;
            fk.setTexture(TextureManager::GetTexture("tile_hidden"));
            fk.setPosition(32.f * i, 32.f * j);
            temp.push_back(fk);


            fk.setTexture(TextureManager::GetTexture("tile_hidden"));
            fk.setPosition(32.f * i, 32.f * j);
            temph.push_back(fk);

            fk.setTexture(TextureManager::GetTexture("tile_revealed"));
            fk.setPosition(32.f * i, 32.f * j);
            tempr.push_back(fk);

            fk.setTexture(TextureManager::GetTexture("flag"));
            fk.setPosition(32.f * i, 32.f * j);
            tempf.push_back(fk);

            fk.setTexture(TextureManager::GetTexture("mine"));
            fk.setPosition(32.f * i, 32.f * j);
            tempm.push_back(fk);


            fk.setTexture(TextureManager::GetTexture("tile_hidden"));
            fk.setPosition(32.f * i, 32.f * j);
            tempn.push_back(fk);
        }
        blank.push_back(temp); //store a blank one
        s.push_back(temp);
        r.push_back(tempr);
        h.push_back(temph);
        f.push_back(tempf);
        m.push_back(tempm);
        n.push_back(tempn);
    }

    //Set buttons
    sf::Sprite debugB;
    debugB.setTexture(TextureManager::GetTexture("debug"));
    debugB.setPosition((32.f * stoi(d[0]) / 2) + 64, stoi(d[1]) * 32.f + 1);

    sf::Sprite fH;
    fH.setTexture(TextureManager::GetTexture("face_happy"));
    fH.setPosition(32.f * stoi(d[0]) / 2, stoi(d[1]) * 32.f + 1);

    sf::Sprite test1;
    test1.setTexture(TextureManager::GetTexture("Test_1"));
    test1.setPosition((32.f * stoi(d[0]) / 2) + 128, stoi(d[1]) * 32.f + 1);

    sf::Sprite test2;
    test2.setTexture(TextureManager::GetTexture("Test_2"));
    test2.setPosition((32.f * stoi(d[0]) / 2) + 64 * 3, stoi(d[1]) * 32.f + 1);

    sf::Sprite test3;
    test3.setTexture(TextureManager::GetTexture("Test_3"));
    test3.setPosition((32.f * stoi(d[0]) / 2) + 64 * 4, stoi(d[1]) * 32.f + 1);


    sf::Sprite counter1;
    sf::Sprite counter2;
    sf::Sprite counter3;
    sf::Sprite negat;


    sf::Texture tex1;
    sf::Texture tex2;
    sf::Texture tex3;
    sf::Texture neg;

    negat.setPosition(0, stoi(d[1]) * 32.f + 1);
    counter1.setPosition(30, stoi(d[1]) * 32.f + 1);
    counter2.setPosition(30+20, stoi(d[1]) * 32.f + 1);
    counter3.setPosition(30+40, stoi(d[1]) * 32.f + 1);

    int minCt = stoi(d[2]);

    Counter(counter1, counter2, counter3,0,tex1,tex2,tex3);

    //Randomly Place mines
    for (int i = 0; i <minCt; i++) {
        int minew = std::rand() % stoi(d[1]);
        int mineh = std::rand() % stoi(d[0]);


        if (h[mineh][minew].getTexture() == m[mineh][minew].getTexture()) {
            i--;

        } else {
            h[mineh][minew] = m[mineh][minew];
            adCt[mineh][minew] = -1;

            //Change adjacent count
            //left
            int *r = &adCt[mineh - 1][minew];
            if (r != nullptr && adCt[mineh - 1][minew]!=-1) {
                adCt[mineh - 1][minew]++;
            }

            //up left
            r = &adCt[mineh-1][minew + 1];
            if (r != nullptr && adCt[mineh-1][minew + 1]!=-1)
                adCt[mineh-1][minew + 1]++;

            //up
            r = &adCt[mineh][minew + 1];
            if (r != nullptr && adCt[mineh][minew + 1]!=-1)
                adCt[mineh][minew + 1]++;

            //up right
            r = &adCt[mineh + 1][minew+1];
            if (r != nullptr && adCt[mineh + 1][minew+1]!=-1)
                adCt[mineh + 1][minew+1]++;

            //right
            r = &adCt[mineh + 1][minew];
            if (r != nullptr && adCt[mineh + 1][minew]!=-1)
                adCt[mineh + 1][minew]++;

            //down right
            r = &adCt[mineh+1][minew + 1];
            if (r != nullptr && adCt[mineh+1][minew + 1]!=-1)
                adCt[mineh+1][minew + 1]++;

            //down
            r = &adCt[mineh][minew - 1];
            if (r != nullptr && adCt[mineh][minew - 1]!=-1)
                adCt[mineh][minew - 1]++;

            //down left
            r = &adCt[mineh-1][minew - 1];
            if (r != nullptr && adCt[mineh-1][minew - 1]!=-1)
                adCt[mineh-1][minew - 1]++;

        }
    }

    // Place numbers sprites in h vec<vec<>>
    for (int i = 0; i<stoi(d[0]); i++) {
        for (int j = 0; j < stoi(d[1]); j++) {
            if (adCt[i][j] > 0 && adCt[i][j] < 9) {
                string b = "number_" + to_string(adCt[i][j]);
                n[i][j].setTexture(TextureManager::GetTexture(b));
                h[i][j] = n[i][j]; }

                else if (h[i][j].getTexture()!=m[i][j].getTexture())
                h[i][j].setTexture(TextureManager::GetTexture("tile_revealed"));
            }
    }

    int flagCt=0;

    //make window
    sf::RenderWindow window(sf::VideoMode(std::stoi(d[0])*32, (std::stoi(d[1]))*32+88), "Will change this");

    while (window.isOpen()) {
            sf::Event event;
            window.clear(sf::Color(33, 0, 0, 255));

        while (window.pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    window.close();
            }

            for (int i = 0; i < stoi(d[0]); i++) {
                for (int j = 0; j < stoi(d[1]); j++) {
                    window.draw(r[i][j]); //background flat tiles
                    window.draw(s[i][j]); //switches from raised -> numb or mine
                };
            };


        //if I start clicking....
        int x = (sf::Mouse::getPosition(window).x)/32;
        int y = (sf::Mouse::getPosition(window).y)/32;


//right click flag
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)==true && x < stoi(d[0]) && y < stoi(d[1]) ){

            if (s[x][y].getTexture() == f[x][y].getTexture()) {
                s[x][y]=blank[x][y];
                flagCt--;
            }
            else {
                flagCt++;
                s[x][y] = f[x][y];
                int remain = minCt-flagCt;
                Counter(counter1, counter2, counter3,remain,tex1,tex2,tex3);
            }

            window.draw(s[x][y]);
        }

        //Load tests
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)==true && y >= stoi(d[1]) && y < stoi(d[1])+88 && x<22.5 && x>16.5) {

            //Load Tests
            fH.setTexture(TextureManager::GetTexture("face_happy"));

            s=blank;
            h=r;
            minCt = 0;
            flagCt=0;

            //this isnt hard coded; it is for the buttons functionality

            string testfiles;
            if (x<18.5 && x>16.5) {
                testfiles = "boards/testboard1.brd";
            }
            if (x>18.5 && x<20.5) {
                testfiles = "boards/testboard2.brd";
            }
            if (x>20.5 && x<22.5) {
                testfiles = "boards/testboard3.brd";
            }

            ifstream inFile (testfiles);
            string file;
            int fileHeight=0;
            vector<vector<int>> boardval;

            while(getline(inFile,file)){
                vector<int> boardv;
                for (int i=0; i< file.length();i++) {
                    int temp=0; //resets it
                    char check = file[i];

                    if (check=='1'){
                        temp=-1;
                        minCt++;
                    }
                    boardv.push_back(temp);
                }
                getline(inFile,file);
                boardval.push_back(boardv);
                fileHeight++;
            }

            int nAdCt[file.length()][fileHeight];

            for (int mineh = 0; mineh < fileHeight; mineh++) {
                for (int minew = 0; minew < file.length(); minew++) {
                    //initalize new ad count
                    nAdCt[mineh][minew]=boardval[mineh][minew];
                }}


            // Place new mines based on file
            for (int mineh = 0; mineh < fileHeight; mineh++) {
                for (int minew = 0; minew < file.length(); minew++) {

                    if (nAdCt[mineh][minew] == -1) {

                        h[mineh][minew] = m[mineh][minew];

                        //Change adjacent count
                        //left
                        int *r = &nAdCt[mineh - 1][minew];
                        if (r != nullptr && nAdCt[mineh - 1][minew] !=-1 ) {
                            nAdCt[mineh - 1][minew]++;
                        }

                        //up
                        r = &nAdCt[mineh][minew + 1];
                        if (r != nullptr && nAdCt[mineh][minew+1] !=-1 )
                            nAdCt[mineh][minew + 1]++;

                        //left top
                        r = &nAdCt[mineh - 1][minew];
                        if (r != nullptr && nAdCt[mineh - 1][minew + 1] !=-1 ) {
                            nAdCt[mineh - 1][minew +1]++;
                        }

                        //right top
                        r = &nAdCt[mineh + 1][minew+1];
                        if (r != nullptr && nAdCt[mineh + 1][minew+1] !=-1 )
                            nAdCt[mineh + 1][minew+1]++;


                        //right
                        r = &nAdCt[mineh + 1][minew];
                        if (r != nullptr && nAdCt[mineh + 1][minew] !=-1 )
                            nAdCt[mineh + 1][minew]++;

                        //down right
                        r = &nAdCt[mineh +1][minew - 1];
                        if (r != nullptr && nAdCt[mineh +1][minew-1] !=-1 )
                            nAdCt[mineh+1][minew - 1]++;

                        //down
                        r = &nAdCt[mineh][minew - 1];
                        if (r != nullptr && nAdCt[mineh][minew-1] !=-1 )
                            nAdCt[mineh][minew - 1]++;

                        //down left
                        r = &nAdCt[mineh-1][minew - 1];
                        if (r != nullptr && nAdCt[mineh-1][minew-1] !=-1 )
                            nAdCt[mineh-1][minew - 1]++;

                    }
                }
            }

            // Place numbers & set textures
            for (int i = 0; i<fileHeight; i++) {
                for (int j = 0; j < file.length(); j++) {

                        if (nAdCt[i][j] > 0 && nAdCt[i][j] < 9){
                            string b = "number_" + to_string(nAdCt[i][j]);
                            n[i][j].setTexture(TextureManager::GetTexture(b));
                            h[i][j] = n[i][j];
                        }
                        else if (nAdCt[i][j] == -1)
                            h[i][j]=m[i][j];
                        else
                            h[i][j]=r[i][j];

                }
            }

            //   s=h;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)==true && y >= stoi(d[1]) && y < stoi(d[1])+88 && x<22.5 && x>16.5) {

            //Load Tests
            fH.setTexture(TextureManager::GetTexture("face_happy"));

            s=blank;
            h=r;
            minCt = 0;
            flagCt=0;

            //this isnt hard coded; it is for the buttons functionality

            string testfiles;
            if (x<18.5 && x>16.5) {
                testfiles = "boards/testboard1.brd";
            }
            if (x>18.5 && x<20.5) {
                testfiles = "boards/testboard2.brd";
            }
            if (x>20.5 && x<22.5) {
                testfiles = "boards/testboard3.brd";
            }

            ifstream inFile (testfiles);
            string file;
            int fileHeight=0;
            vector<vector<int>> boardval;

            while(getline(inFile,file)){
                vector<int> boardv;
                for (int i=0; i< file.length();i++) {
                    int temp=0; //resets it
                    char check = file[i];

                    if (check=='1'){
                        temp=-1;
                        minCt++;
                    }
                    boardv.push_back(temp);
                }
                getline(inFile,file);
                boardval.push_back(boardv);
                fileHeight++;
            }

            int nAdCt[file.length()][fileHeight];

            for (int mineh = 0; mineh < fileHeight; mineh++) {
                for (int minew = 0; minew < file.length(); minew++) {
                    //initalize new ad count
                    nAdCt[mineh][minew]=boardval[mineh][minew];
                }}


            // Place new mines based on file
            for (int mineh = 0; mineh < fileHeight; mineh++) {
                for (int minew = 0; minew < file.length(); minew++) {

                    if (nAdCt[mineh][minew] == -1) {

                        h[mineh][minew] = m[mineh][minew];

                        //Change adjacent count
                        //left
                        int *r = &nAdCt[mineh - 1][minew];
                        if (r != nullptr && nAdCt[mineh - 1][minew] !=-1 ) {
                            nAdCt[mineh - 1][minew]++;
                        }

                        //up
                        r = &nAdCt[mineh][minew + 1];
                        if (r != nullptr && nAdCt[mineh][minew+1] !=-1 )
                            nAdCt[mineh][minew + 1]++;

                        //left top
                        r = &nAdCt[mineh - 1][minew];
                        if (r != nullptr && nAdCt[mineh - 1][minew + 1] !=-1 ) {
                            nAdCt[mineh - 1][minew +1]++;
                        }

                        //right top
                        r = &nAdCt[mineh + 1][minew+1];
                        if (r != nullptr && nAdCt[mineh + 1][minew+1] !=-1 )
                            nAdCt[mineh + 1][minew+1]++;


                        //right
                        r = &nAdCt[mineh + 1][minew];
                        if (r != nullptr && nAdCt[mineh + 1][minew] !=-1 )
                            nAdCt[mineh + 1][minew]++;

                        //down right
                        r = &nAdCt[mineh +1][minew - 1];
                        if (r != nullptr && nAdCt[mineh +1][minew-1] !=-1 )
                            nAdCt[mineh+1][minew - 1]++;

                        //down
                        r = &nAdCt[mineh][minew - 1];
                        if (r != nullptr && nAdCt[mineh][minew-1] !=-1 )
                            nAdCt[mineh][minew - 1]++;

                        //down left
                        r = &nAdCt[mineh-1][minew - 1];
                        if (r != nullptr && nAdCt[mineh-1][minew-1] !=-1 )
                            nAdCt[mineh-1][minew - 1]++;

                    }
                }
            }

            // Place numbers & set textures
            for (int i = 0; i<fileHeight; i++) {
                for (int j = 0; j < file.length(); j++) {

                    if (nAdCt[i][j] > 0 && nAdCt[i][j] < 9){
                        string b = "number_" + to_string(nAdCt[i][j]);
                        n[i][j].setTexture(TextureManager::GetTexture(b));
                        h[i][j] = n[i][j];
                    }
                    else if (nAdCt[i][j] == -1)
                        h[i][j]=m[i][j];
                    else
                        h[i][j]=r[i][j];

                }
            }

            //   s=h;
        }

        //reveal if tile is clicked in tilespace (NO FLAGS)
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)==true && x < stoi(d[0]) && y < stoi(d[1]) && s[x][y].getTexture() != f[x][y].getTexture()) {

            //check for mine
            if (adCt[x][y] == -1 && h[x][y].getTexture() == m[x][y].getTexture()) { //its a mine
                fH.setTexture(TextureManager::GetTexture("face_lose"));
                s = h; //show everything
                flagCt;

            } else {
                s[x][y] = h[x][y]; //reassign s  to show hidden tile

                //if whats showing is the blank revealed tile cascade
                if (s[x][y].getTexture() == r[x][y].getTexture()) {
                    showOthersU(h, x, y, s, n);
                    showOthersL(h, x, y, s, n);
                    showOthersR(h, x, y, s, n);
                    showOthersD(h, x, y, s, n);
                }
            }

            window.draw(s[x][y]);
        }

    //reset/smile face
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)==true && y >= stoi(d[1]) && y < stoi(d[1])+88 && x<14.5 && x>12.5) {
             //show all then reset?
            fH.setTexture(TextureManager::GetTexture("face_happy"));
            s=blank;
            h=r;
            flagCt = 0;

            //reset ad count
            for (int i = 0; i<stoi(d[0]); i++) {
                for (int j = 0; j < stoi(d[1]); j++) {
                    adCt[i][j]=0;
                }}

            //Randomly Place new mines
            for (int i = 0; i < minCt; i++) {
                int minew = std::rand() % stoi(d[1]);
                int mineh = std::rand() % stoi(d[0]);


                if (h[mineh][minew].getTexture() == m[mineh][minew].getTexture()) {
                    i--;

                } else {
                    h[mineh][minew] = m[mineh][minew];
                    adCt[mineh][minew] = -1;

                    //Change adjacent count
                    //left
                    int *r = &adCt[mineh - 1][minew];
                    if (r != nullptr && adCt[mineh - 1][minew] !=-1 ) {
                        adCt[mineh - 1][minew]++;
                    }

                    //right
                    r = &adCt[mineh + 1][minew];
                    if (r != nullptr && adCt[mineh + 1][minew] !=-1)
                        adCt[mineh + 1][minew]++;

                    //down
                    r = &adCt[mineh][minew - 1];
                    if (r != nullptr && adCt[mineh][minew -1 ] !=-1)
                        adCt[mineh][minew - 1]++;

                    //up
                    r = &adCt[mineh][minew + 1];

                    if (r != nullptr && adCt[mineh][minew + 1] !=-1)
                        adCt[mineh][minew + 1]++;

                    //right down
                    r = &adCt[mineh + 1][minew -1 ];
                    if (r != nullptr && adCt[mineh + 1][minew -1] !=-1)
                        adCt[mineh + 1][minew-1]++;

                    //right up
                    r = &adCt[mineh + 1][minew +1 ];
                    if (r != nullptr && adCt[mineh + 1][minew +1] !=-1)
                        adCt[mineh + 1][minew+1]++;

                    //down left
                    r = &adCt[mineh -1 ][minew - 1];
                    if (r != nullptr && adCt[mineh-1][minew -1 ] !=-1)
                        adCt[mineh-1][minew - 1]++;

                    //up left
                    r = &adCt[mineh -1][minew + 1];

                    if (r != nullptr && adCt[mineh -1][minew + 1] !=-1)
                        adCt[mineh+1][minew + 1]++;
                }
            }

            // Place numbers
            for (int i = 0; i<stoi(d[0]); i++) {
                for (int j = 0; j < stoi(d[1]); j++) {
                    if (adCt[i][j] !=-1) {

                        if (adCt[i][j]>0 && adCt[i][j]<9 ){
                            string b = "number_" + to_string(adCt[i][j]);
                            n[i][j].setTexture(TextureManager::GetTexture(b));
                            h[i][j] = n[i][j];
                        }
                        else
                            h[i][j].setTexture(TextureManager::GetTexture("tile_revealed"));
                    }
                    else
                        h[i][j].setTexture(TextureManager::GetTexture("mine"));



                }
            }
        }

        //debug
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)==true && y >= stoi(d[1]) && y < stoi(d[1])+88 && x<16.5 && x>14.5) {
            //show all mines
            for (int i = 0; i<stoi(d[0]); i++) {
                for (int j = 0; j < stoi(d[1]); j++) {
                        if (adCt[i][j]==-1 ){
                            s[i][j]=m[i][j];
                }
            }
            }
            // Place numbers
            for (int i = 0; i<stoi(d[0]); i++) {
                for (int j = 0; j < stoi(d[1]); j++) {
                    if (adCt[i][j] !=-1) {
                        if (adCt[i][j]>0 && adCt[i][j]<9 ){
                            string b = "number_" + to_string(adCt[i][j]);
                            n[i][j].setTexture(TextureManager::GetTexture(b));
                            h[i][j] = n[i][j];
                        }
                        else
                            h[i][j].setTexture(TextureManager::GetTexture("tile_revealed"));
                    }
                    else
                        h[i][j].setTexture(TextureManager::GetTexture("mine"));

                }
            }
        }

        window.draw(debugB);
        window.draw(fH);
        window.draw(test1);
        window.draw(test2);
        window.draw(counter1);
        window.draw(test3);
        window.draw(counter2);
        window.draw(counter3);
        window.display();

        }
        return 0;
};